
#include "robot.hpp"

bool run = true;

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

};

int middle[150];
double vLeft = 0.0;
double vRight = 0.0;
int blackpixels = 0;

double adjustMotors(double errorValue) { //Called for motor speed adjustment
	//Positive calculated error val will cause bot to turn right, negative error val will cause bot to turn left
	vLeft = 20 + (0.3 * errorValue);
	vRight = 20 - (0.3 * errorValue);
	setMotors(vLeft,vRight); 
}


int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
    vLeft = 20.0;
    vRight = 20.0;
    SavePPMFile("i0.ppm",cameraView);
    while(run){
	  takePicture();	
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
	  double error = lineMiddle(middle, blackpixels);
	  
	  //Calls for the robot's direction to be changed based on the error value found
	  adjustMotors(error);

	  //std::cout<<"Error: "<<error<<std::endl;  
  } //while

} // main 
