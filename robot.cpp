#include "robot.hpp"
int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	//set the initial L and R speeds
    double vLeft = 10.0;
    double vRight = 10.0;
    int MidRowValues[cameraView.width];
    //takePicture();
    //SavePPMFile("i0.ppm",cameraView);
    std::cout<<cameraView.width<<" "<<cameraView.height<<"  ";
    
    while(1){				
		takePicture();	
		
		double error = 0.0;
		int num_White = 0;
		for ( int i = 0; i < cameraView.width; i++ ){
			
			int pix = get_pixel(cameraView, 50, i, 3);
			int isWhite;			
			
			if (pix > 250){ isWhite = 1;				
				error = error + i - 75;	//calculate error value based on position of WHITE line
				num_White++;
			} else{ isWhite = 0; }
			//std::cout<<isWhite<<" ";
			//std::cout<<pix<<" ";
			
			MidRowValues[i] = isWhite;	//add the values into array (white or non-white)
			
			std::cout<<isWhite<<" ";
			
		}
	    	//Adjust position to maintain line in middle of frame
		//adjust left and right speeds, based on error
		if (num_White > 0){
			
			vLeft = 20 - 0.3 * (error/num_White);
			vRight = 20 + 0.3 * (error/num_White);
		//no white line detected...reverse
		} else { vLeft = -5; vRight = -5; }
							
		
		
		setMotors(vLeft,vRight);   
		std::cout<<"error ="<<error<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		
		usleep(10000);
  } //while

} // main
