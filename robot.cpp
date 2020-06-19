#include "robot.hpp"

int userSelection;
bool run = true;
bool lastTurnUTurn = false;

//arrays
int middle[150];
int front[150];
int back[150];
//left/right wheel speeds
double vLeft = 0.0;
double vRight = 0.0;
//string corneringPath;		 
int frontWhitePixelValue = 0;
int leftWhitePixelValue = 0;
int rightWhitePixelValue = 0;

//USER INTERFACE - ASK USER FOR CORE/COMP OR CHALLENGE ROUTE
//RUN THE SPECIFIED CODE
//CORE/COMP FOLLOWS THE WHITE LINE
//CHALLENGE FOLLOWS THE LEFT RED WALL

//Sets up the user Interface menu
int userInterface(){
	
	int userSelection; //Just a variable to store the selected option in
	std::cout<<">> "<<std::endl;
	std::cout<<">> Please enter maze difficulty/type"<<std::endl;
	std::cout<<">> Enter 1 for CORE and COMPLETION maps"<<std::endl;
	std::cout<<">> Enter 2 for CHALLENGE map"<<std::endl;
	std::cout<<">> Enter 3 to QUIT"<<std::endl;
	std::cin>>userSelection; //cin (console in or something like that)- input that stores the result in the userSelection variable
	//std::cout<<userSelection<<" input works correctly"<<std::endl; //Line that it just printing out the variable to check the input is correct
	return userSelection;
	
}

//Right turn
void right(int t){            //slowly turns right for "t" long
		for (int i =0; i< t;i++){
				setMotors(20,-20);
			}
}


//Left turn	
void left(int t){   //slowly turns left for "t" long
		for (int i =0; i< t;i++){
				setMotors(-20,+20);
			}
}
		
	
//Calculates how far the robot is from the wall
int howFar(){  
	int count =0;
	for (int i = 100;i>0;i--){
			int p1= get_pixel(cameraView,i,75,0);  
			int p2= get_pixel(cameraView,i-1,75,0);
					
			if ((p1<250) && (p2>250)){
					break;                //if it sees a red pixel it will stop counting
				}
			count++;      
			}
	return count;  //returns how far it is from the wall in front
	
}
	

//checks if there is a red pixel on the left
bool leftWallPresent(int values1[]){    
	for (int i =0;i<150;i++){
			if (values1[i] > 0){
					return true;    //if there is red pixel: there is a wall
				} else { return false;} //vise versa
		}
}


//calculates the distance from the left wall to the camera centre
double redMiddle(int values1[]){   
	int numreds1 = 0;             //similar to the white line middle
	int reds1 = 0;
	for (int i = 0;i < 150;i++){
		if (values1[i] > 0) {
			reds1 = reds1+i;
			numreds1++;
		}
	}		
	
	
	
	if (numreds1 > 10) { //Bot was breaking previously when dividing by 0 so this is required (also useful for the turning around function.
		double redlinelocation = reds1/numreds1; //red line location on line
		double camMiddle = cameraView.width/2; //the actual middle of the line
		double distFromWall = redlinelocation-camMiddle; //calculates the how far of the line is from the middle
		return distFromWall; 
	}
}


//calculates the middle of white line
double lineMiddle(int values[], int blackPixelCount){ 
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


//Motor speed adjustment
double adjustMotors(double errorValue) { 
	//Positive calculated error val will cause bot to turn right, negative error val will cause bot to turn left
	//This if statement forces the bot to try the rightmost exit option when coming to an intersection
	if (frontWhitePixelValue > 0 && leftWhitePixelValue > 0 && rightWhitePixelValue == 0) {
		//std::cout<<"forced straightening occuring";
		vLeft = 20;
		vRight = 20;
	} else {
	
		//std::cout<<errorValue;	
		//1 is for coore and completion
		//2 is for challenge
		if (userSelection == 1){
					vLeft = 20 + (0.3 * errorValue);            //different error values for comp and challenge
					vRight = 20 - (0.3 * errorValue);
					setMotors(vLeft,vRight);
			}
		if (userSelection == 2){
					vLeft = 20 + (0.1 * errorValue);
					vRight = 20 - (0.1 * errorValue);
					setMotors(vLeft,vRight);
			}	
	}
	return 0;
}


int Challenge() {	
	
	int count = howFar(); //calls the howfar function for how far away the robot is from the wall
	int error_Val = 0;
			
			
	//stores all the pixels as 1 and 0 in the arrays for the front and back	
	for (int i=0;i<150;i++){
		int p3red = get_pixel(cameraView,90,i,0);
		int p3blue = get_pixel(cameraView,90,i,2);
		int p4red = get_pixel(cameraView,10,i,2); //////LEAVE IT AT TWO !!!!!!!!!!!!!!!!!!!!!!!!!!!
		int p4blue = get_pixel(cameraView,10,i,2);  //or try to fix it jk
		int isRed;				
		
		//the first if handles the white line at the start of the maze
		//else section handles normal part of maze
		if ((p4blue > 250) || (p3blue > 250)) {
			adjustMotors(0);
			
		} else {
			//add to back array
			if (p3red > 250 && p3blue < 250){
					isRed = 1;
				} else {isRed =0;}
			back[i]=isRed;	
			//add to front array
			if (p4red > 250 && p4blue < 250){
					isRed = 1;
				} else {isRed =0;}
			front[i]=isRed;
		}
	}

	//stores the two distance in the variables from the redmiddle	
	double distance1 = redMiddle(front);
	double distance2 = redMiddle(back); 
	error_Val = (distance1-distance2); //new error from the difference
	std::cout<<"error val: "<<error_Val<<std::endl;
	bool wallThere = true;                      //checks if there is a left wall from the leftwallpresent function 
	wallThere = leftWallPresent(back);
		
	//If last move was a u turn this code will try and force the bot to find a wall on the left.
	//Will keep turning left until another wall is found to follow OR a left/right turn has to be made
	//at a wall in front which will indicate walls are going to be found.
	//The left and right turns adjust lastTurnUTurn to ensure it only runs when the previous turn was a u-turn
	if(count > 75 && lastTurnUTurn == true && wallThere == false) {
		error_Val = -28; //value to turn to find left hand wall
	}
	
	//turns right when the wall is less than 25 pixels away
	if ((count < 25) && (!count == 0)){
		if (wallThere == true){      
		right(6);
		lastTurnUTurn = false;
		} else {
			left(6); 
			lastTurnUTurn = false; 
		}
	}
	
	//Completes the u turn if left/right turning can not result in a corrective turn.
	if (count < 10 && count != 0) {
			right(12); //Does a 180
			lastTurnUTurn = true;
	}
	
	std::cout<<"Count: "<<count<<std::endl;
	std::cout<<"Left Wall: "<<wallThere<<std::endl;
	
	return(error_Val);
	
}
	

int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	setMotors(40,40);
	
	userSelection = userInterface(); //Just a variable to store the selected option in
		
	//follow quit process
	if(userSelection == 3){
		//confirm if user wants to QUIT...
		std::cout<<">> ARE YOU SURE YOU WANT TO QUIT? (1 to quit / 2 to restart)"<<std::endl;
		std::cin>>userSelection;
		
		if(userSelection == 1){						
			setMotors(0,0);
			return 0;			
		} else if(userSelection == 2){						
			userSelection = userInterface();
			if (userSelection == 3){
				setMotors(0,0);
				return 0;
			}
		}		
	}
				
	SavePPMFile("i0.ppm",cameraView);
	lastTurnUTurn = false;
	
	while(run){
		takePicture();	
		double error;
		
		
		//Core/Completion section - runs only if user selects the 1st option
		if(userSelection == 1) { 
			int frontRegionCheck;
			int leftRegionCheck;
			int rightRegionCheck;
			frontWhitePixelValue = 0;
			leftWhitePixelValue = 0;
			rightWhitePixelValue = 0;
			int blackpixels = 0;
			
			for (int i = 0; i<150;i++){
				int pix = get_pixel(cameraView,90,i,3);
				int isWhite;
				if (pix >250){isWhite = 1;} else {isWhite = 0;}
				middle[i] = isWhite;
				
				//Checks for flag, will end while if flag is detected
				int blackPixelCheck = get_pixel(cameraView, 70, i, 3);
				if (blackPixelCheck < 20) { blackpixels++; }
				//std::cout<<middle[i]<<" ";
				}
				
			for (int j = 0; j < 20; j++) {
				leftRegionCheck = get_pixel(cameraView, 80 + j, 55, 3);
				if (leftRegionCheck > 250) { leftWhitePixelValue++; }
				rightRegionCheck = get_pixel(cameraView, 80 + j, 95, 3);
				if (rightRegionCheck > 250) { rightWhitePixelValue++; }
				frontRegionCheck = get_pixel(cameraView, 75, 65 + j, 3);
				if (frontRegionCheck > 250) { frontWhitePixelValue++; }
			}
			error = lineMiddle(middle, blackpixels);
		}
		
		//Challenge section of code - runs only if the user selects 2nd option
		else if (userSelection == 2) {
			
			error = Challenge();	
			
		
		//restart program if invalid input
		} else if( (userSelection != 1) && (userSelection != 2) && (userSelection != 3) ){
						
			userSelection = userInterface();//restart
						
			}		
	  
		//Calls for the robot's direction to be changed based on the error value found
		adjustMotors(error);
		
	  
	} //while


} // main
