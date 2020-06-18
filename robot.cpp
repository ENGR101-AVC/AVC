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

bool wallLeft() {
	bool wall = false;
	for(int y = 0; y < cameraView.height; y++){
		for(int x = 0; x < cameraView.width/3; x++){
			if(get_pixel(cameraView, y, x, 0) == 255 && get_pixel(cameraView, y, x, 1) == 0 && get_pixel(cameraView, y, x, 2) ==0){
					wall = true;
			}
		}
	}
	
	return wall;
}
	
bool wallMiddle() {
	bool wall = false;
	for(int y = 0; y < cameraView.height; y++){
		for(int x = cameraView.width/3; x < (cameraView.width/3)*2; x++){
			if(get_pixel(cameraView, y, x, 0) == 255 && get_pixel(cameraView, y, x, 1) == 0 && get_pixel(cameraView, y, x, 2) ==0){
					wall = true;
			}
		}
	}
	
	return wall;
}
bool wallRight() {
	bool wall = false;
	for(int y = 0; y < cameraView.height; y++){
		for(int x = (cameraView.width/3)*2; x < (cameraView.width/3)*3; x++){
			if(get_pixel(cameraView, y, x, 0) == 255 && get_pixel(cameraView, y, x, 1) == 0 && get_pixel(cameraView, y, x, 2) ==0){
					wall = true;
			}
		}
	}
	
	return wall;
}

void drive(int whiteRatio){
	double vLeft = 30.0;
	double vRight = 30.0;
	
	if (wallLeft() == true){
		std::cout<<"\n Wall on left \n";
		vLeft = 40.0;
	}else{
		vLeft = 30;
	}
	if (wallRight() == true){
		std::cout<<"\n Wall on right \n";
		vRight = 40.0;
	}else{
		vRight = 30;
	}
	if (wallMiddle() == true){
		std::cout<<"\n Wall in middle \n";
		if (wallLeft() == true){
			std::cout<<"\n Wall in middle AND LEFT \n";
			vLeft = 40;
			vRight = 10;
		}
		if (wallRight() == true){
			std::cout<<"\n Wall in middle AND RIGHT \n";
			vLeft = 10;
			vRight = 40;
			
		}
		if (wallLeft() == true && wallRight() == true){
			std::cout<<"Wall ON ALL SIDES";
			vLeft = 10;
			vRight = -10;
		}
		if (wallLeft() == false && wallRight() == false){
			vLeft = 10;
			vRight = -10;
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
		drive(whiteRatio);
		usleep(10000);
  } //while

} // main
