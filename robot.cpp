
#include "robot.hpp"

double lineMiddle(int values[]){ //calculates the middle of white line
	int numwhites = 0;
	int whites = 0;
	for (int i = 0;i < 150;i++){
		if (values[i] > 0) {
			whites = whites+i;
			numwhites++;
		}
	}
	double whitelinelocation = whites/numwhites; //middle of white line location on line
	double camMiddle = cameraView.width/2; //the actual middle of the line
	double errors = whitelinelocation - camMiddle ; //calculates the how far of the line is from the middle
	return errors; 
};

int middle[150];

int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
    double vLeft = 20.0;
    double vRight = 20.0;
    SavePPMFile("i0.ppm",cameraView);
    while(1){
	  takePicture();	
	  for (int i =0; i<150;i++){
		  int pix = get_pixel(cameraView,50,i,3);
		  int isWhite;
		  if (pix >250){isWhite = 1;} else {isWhite = 0;}
		  middle[i] = isWhite;
		 // std::cout<<middle[i]<<" ";
		  }
	  double error = lineMiddle(middle);
	    //this is the code that made it work
		if (error > 0){
			vLeft = 20+0.3*error;
			vRight = 20-0.3*error;
		} else {
			vLeft = 20+0.3*error;
			vRight = 20-0.3*error;
			}
	//  std::cout<<"Error: "<<error<<std::endl;
      setMotors(vLeft,vRight);   
  } //while

} // main 


