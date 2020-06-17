#include "robot.hpp"

int getWhite(int whitePixArray[]){
	int whiteRatio = 0;
	for (int i=0;i<cameraView.width;i++){
		int pix = (get_pixel(cameraView,50,i,0)+get_pixel(cameraView,50,i,1)+get_pixel(cameraView,50,i,2));
		//determining whether the pixel is white
		int boolWhite=0;
		if(pix== 765){
			boolWhite =1;
		} 
		else if(pix != 765){
			boolWhite=0;
		}
		//std::cout<<boolWhite<<" ";
		whitePixArray[i]=boolWhite;
	}
	for (int n=0;n<cameraView.width;n++){
		if(whitePixArray[n]==1){
			whiteRatio=n; //finds first white pixel and exits for loop
			return whiteRatio;
		}
		
	}	
	for (int n=0;n<cameraView.width;n++){//comletion turning section
		if(whitePixArray[n]!=(1)){
			whiteRatio=n; 
		}	
	}	
	return whiteRatio;
	
}

int getRed(int redPixArray[]){
	int redRatio = 0;
	for (int i=0;i<cameraView.width;i++){
		int redpix = get_pixel(cameraView,50,i,0);//getting the red value of the pixel
		int boolRed=0;
		if(redpix==255){
			boolRed =1;
		} 
		else if(redpix!=255){
			boolRed=0;
		}
		//std::cout<<boolRed<<" ";
		redPixArray[i]=boolRed;
	}
	for (int n=0;n<cameraView.width;n++){
		if(redPixArray[n]==1){
			redRatio=n; //finds first white pixel and exits for loop
			return redRatio;
		}
		
	}	
	for (int n=0;n<cameraView.width;n++){//comletion turning section
		if(redPixArray[n]!=(1)){
			redRatio=n; 
		}	
	}	
	return redRatio;
	
}

void drive(int whiteRatio, int redRatio){
	double vLeft = 30.0;
	double vRight = 30.0;
	
	if(redRatio<30){//treats each image as if it has 5 sections if pixel is not in the middle section robot moves accordingly
		if(whiteRatio<30){
			vLeft = 20;
			vRight = 30;
			std::cout<<"\n WHITE detected HARD LEFT \n";
		}else{
			vLeft = 40;
			vRight = 15;
			std::cout<<"\n RED detected HARD LEFT \n";
		}
	}	
	if((redRatio>30)&&(redRatio<30)){
		if((whiteRatio>30)&&(whiteRatio<30)){
			vLeft = 40;
			vRight = 25;
			std::cout<<" \n WHITE detected MEDIUM LEFT \n";
		}else{
			vLeft = 50;
			vRight = 10;
			std::cout<<" \n RED detected MEDIUM LEFT \n";
		}
	}	
	if((redRatio>60)&&(redRatio<90)){//middle section of image
		if((whiteRatio>60)&&(whiteRatio<90)){//middle section of image
			vLeft = 30;
			vRight = 30;
			std::cout<<"\n WHITE detected MIDDLE \n";
		}else{
			vLeft = 40;
			vRight = -30;
			std::cout<<"\n RED detected MIDDLE  WE GOTTA SWERVEEEEEEEE\n";
		}
	}	
	if((redRatio>90)&&(redRatio<120)){
		if((whiteRatio>90)&&(whiteRatio<120)){
			vLeft = 25;
			vRight = 20;
			std::cout<<"\n WHITE detected MEDIUM RIGHT \n";
		}else{
			vLeft = 10;
			vRight = 50;
			std::cout<<"\n RED detected MEDIUM RIGHT \n";
		}
	}	
	if((redRatio>120)&&(redRatio<150)){
		if((whiteRatio>120)&&(whiteRatio<149)){
			vLeft = 30;
			vRight = 20;
			std::cout<<"\n WHITE detected HARD RIGHT \n";
		if (whiteRatio > 149){
			vLeft = 30;
			vRight = 20;
			std::cout<<"\n White detected in last pixel of the array (no real white) \n";
		}
		}else{
			vLeft = 15;
			vRight = 40;
			std::cout<<"\n RED detected HARD RIGHT \n";
		}
	}
	
    setMotors(vLeft,vRight);   
    std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
	
}	

int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
    takePicture();
    SavePPMFile("i0.ppm",cameraView);
    int whitePixArray[cameraView.width];//array capacity of cameraWindow.width set because robot.fovWidth = 150.0 
    int redPixArray[cameraView.width];
    while(1){
		takePicture();
		int whiteRatio = getWhite(whitePixArray);
		int redRatio = getRed(redPixArray);
		drive(whiteRatio, redRatio);
		usleep(10000);
  } //while

} // main

