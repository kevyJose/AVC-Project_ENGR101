#include "robot.hpp"

bool run = true;
int middle[150];
double vLeft = 0.0;
double vRight = 0.0;

double lineMiddle(int values[], int blackPixelCount){ //calculates the middle of white line
	int numwhites = 0;
	int whites = 0;
	for (int i = 0;i < 150;i++){
		if (values[i] > 0) {
			whites = whites+i;
			numwhites++;
		}
	}
	if (numwhites > 0) { //Bot was breaking previously when dividing by 0 so this is required (also useful for the turning around function.
		double whitelinelocation = whites/numwhites; //middle of white line location on line
		double camMiddle = cameraView.width/2; //the actual middle of the line
		double errors = whitelinelocation - camMiddle ; //calculates the how far of the line is from the middle
		return errors; 
	} else {
		if (blackPixelCount > 5) { //If it detects the flag will do this in an attempt to not turn around - doesn't quite work for core, that still runs off 
			run = false;
			std::cout<<"Flag has been reached!"<<std::endl;
			std::cout<<"Maze has been completed!"<<std::endl;
			return 0;
		} else { //If the white line is not detected (and flag not seen) at the check point this will turn the bot around - Essentially handles dead ends.
			return(400/3); //This value is equivalent to 40 when multiplied by 0.3 as in adjustmotors() allows for swift turn arounds if no white pixel in front.
		}
	}

}


double adjustMotors(double errorValue) { //Called for motor speed adjustment
	//Positive calculated error val will cause bot to turn right, negative error val will cause bot to turn left
	std::cout<<errorValue;	
	vLeft = 20 + (0.3 * errorValue);
	vRight = 20 - (0.3 * errorValue);
	setMotors(vLeft,vRight); 
	return 0;
}


int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	
	int userSelection; //Just a variable to store the selected option in
	//This needs to be improved by actually ending the program properly if a differing input (e.g. 3) is choses (essentially providing a quit option)
	std::cout<<">> Please enter maze difficulty/type"<<std::endl;
	std::cout<<">> Enter 1 for CORE and COMPLETION maps"<<std::endl;
	std::cout<<">> Enter 2 for CHALLENGE map"<<std::endl;
	std::cin>>userSelection; //cin (console in or something like that)- input that stores the result in the userSelection variable
	//std::cout<<userSelection<<" input works correctly"<<std::endl; //Line that it just printing out the variable to check the input is correct
	
	
	int blackpixels = 0;
	SavePPMFile("i0.ppm",cameraView);
	
	while(run){
		takePicture();	
		double error;
		
		//Core/Completion section - runs only if user selects the 1st option
		if(userSelection == 1) { 
			for (int i =0; i<150;i++){
				int pix = get_pixel(cameraView,90,i,3);
				int isWhite;
				if (pix >250){isWhite = 1;} else {isWhite = 0;}
				middle[i] = isWhite;
		  
				//Checks for flag, will end while if flag is detected
				int blackPixelCheck = get_pixel(cameraView, 50, i, 3);
				if (blackPixelCheck < 20) { blackpixels++; }
				//std::cout<<middle[i]<<" ";
				}
			error = lineMiddle(middle, blackpixels);
		}
		
		//Challenge section of code - runs only if the user selects 2nd option
		else if (userSelection == 2) {	
			//This is essentially reusing the core code in it's current forn - This is NOT a good solution, breaking the view
			//into regions or something similar as discussed will provide a solution that actually does work, however
			//this can at least handle the first corner correctly.
			
			//All working is in here just because I was messing around - when actually created or cleaned
			//splitting into functions to not go over the command limit will be important
			
			int redLoc = 0;	  //tracks location of red pixels to find avg by dividing by total red pxl count
			int isRed = 0;

			for (int i =0; i<75;i++){ //Runs the search line (as in the core) for half of the robot camera view section
				//for (int j = 0; j < 15
				int curpix = get_pixel(cameraView,50,i,0); //0 finds red pixels
				int curpix2 = get_pixel(cameraView,50,i,2); //1 finds blue pixels

			
				if (curpix > 250 && curpix2 < 250){isRed++; redLoc+= i; } //If red > 250 wall probably - however checks blue value to not get confused with white lines
																		  //Checks that blue < 250 as that would confirm the reds checked are not a white line
																		  //redLoc += i adds the locations of found red together
			
				//This was just to check if it would corner on this inneficient method - essentially if red count > what would be expected on a single wall with a moderate distance
				//between bot and wall turn right.
				
				//Once again, this whole section needs to be rewritten with the regions, functions and new formulas - but this is to explain my thinking
				//about what this currently is.  
				if (isRed > 14) {
					error = 0 + (redLoc / isRed);
					std::cout<<isRed<<std::endl;
				} else { error = 0; } 
			}

		}
	  
	  //Calls for the robot's direction to be changed based on the error value found
		adjustMotors(error);
		

	  //std::cout<<"Error: "<<error<<std::endl;  
	} //while


} // main 
