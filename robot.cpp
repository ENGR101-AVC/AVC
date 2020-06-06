#include "robot.hpp"
//Core Code for AVC
int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
    double vLeft = 40.0;
    double vRight = 30.0;
    takePicture();
    SavePPMFile("i0.ppm",cameraView);
    int whitePixArray[cameraView.width];//array capacity of cameraWindow.width set because robot.fovWidth = 150.0 
    while(1){
		takePicture();
		int whiteRatio = 0;
		for (int i=0;i<cameraView.width;i++){
			int pix = get_pixel(cameraView,50,i,3);//getting the color value of the pixel (not individual colours)
			int boolWhite;
			if(pix==255){
				boolWhite =1;
			} 
			else if(pix!=255){
				boolWhite=0;
			}
			std::cout<<boolWhite<<" ";
			whitePixArray[i]=boolWhite;
		}
		for (int n=0;n<150;n++){
			if(whitePixArray[n]==1){
				whiteRatio=n; //finds first white pixel and exits for loop
				break;
			}	
		}	
		if(whiteRatio<30){//treats each image as if it has 5 sections if pixel is not in the middle section robot moves accordingly
			vLeft = 20;
			vRight = 30;
		}	
		if((whiteRatio>30)&&(whiteRatio<30)){
			vLeft = 20;
			vRight = 25;
		}	
		if((whiteRatio>60)&&(whiteRatio<90)){//middle section of image
			vLeft = 30;
			vRight = 30;
		}	
		if((whiteRatio>90)&&(whiteRatio<120)){
			vLeft = 25;
			vRight = 20;
		}	
		if((whiteRatio>120)&&(whiteRatio<150)){
			vLeft = 30;
			vRight = 20;
		}	
      setMotors(vLeft,vRight);   
      std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
       usleep(10000);
  } //while

} // main
