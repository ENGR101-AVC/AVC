#include "robot.hpp"

bool maze; //simple boolean check to see if the robot is in a maze or is in core/completion

void drive(int whiteRatio){
	double vLeft = 30.0;
	double vRight = 30.0;
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
	if(whiteRatio==150){//completion turning 	
		vLeft = 5;
		vRight = 30;
	}
	if(whiteRatio==0){//completion turning 	
		vLeft = 5;
		vRight = 30;
	}	
    setMotors(vLeft,vRight);   
    std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
	
}

bool getRed(){
	bool red = false;
	for (int y = 0; y < cameraView.height; y++) { 
		for (int x = 0; x < cameraView.width; x++) { 
			if(get_pixel(cameraView, y, x, 0) == 255 && get_pixel(cameraView, y, x, 1) == 0 && get_pixel(cameraView, y, x, 2) == 0){
				red = true;
			}
		}
	}
	
	return red;
}

/* Modified Sam's challenge methods with some ideas of my (Dili) own to make movement a bit more efficient
 * 
 * 
 * 
*/   

bool wallLeft() { //checking if there is a wall to the left of the robot to follow
	bool wall = false;
	for(int y = 80; y < cameraView.height; y++){
		for(int x = 0; x < 15; x++){
			if(get_pixel(cameraView, y, x, 0) == 255 && get_pixel(cameraView, y, x, 1) == 0 && get_pixel(cameraView, y, x, 2) ==0){
					wall = true;
			}
		}
	}
	
	return wall;
}
	
bool wallMiddle() { //checking for wall in front of robot
	bool wall = false;
	for (int y = 80; y < cameraView.height; y++) {
		for (int x = 50; x < 100; x++) {
			if(get_pixel(cameraView, y, x, 0) == 255 && get_pixel(cameraView, y, x, 1) == 0 && get_pixel(cameraView, y, x, 2) ==0){
					wall = true;
			}
		}
	}
	
	return wall;
}

bool movingLeft(){//checking if the left wall has moved, robot should recorrect direction
	bool wall = false;
	for (int y = 70; y < cameraView.height; y++) {
		for (int x = 15; x < 30; x++) {
			if(get_pixel(cameraView, y, x, 0) == 255 && get_pixel(cameraView, y, x, 1) == 0){
				wall = true;
			}
		}
	}
	return wall; 
}

void driveRed(){ //main idea for robot is to try and follow a left line at all times
	double vLeft = 30.0;
	double vRight = 30.0;
	if(getRed()==true){
		if(wallLeft()==false){
			vLeft = 22;
			vRight = 30;
		}	
		else if(wallMiddle()==true){ 
			vLeft = 40;
			vRight = -40;
		}
		else if(movingLeft()==true){
			vLeft = 30;
			vRight = 20;
		}
		else{ 
			vLeft = 30;
			vRight = 30;
		}
	}else{
		vLeft 	= 300; //this is how the robot makes it out of the gap
		vRight 	= 300;	
		setMotors(vLeft,vRight); 
		vLeft 	= -35;
		vRight 	= 35;
	}
    setMotors(vLeft,vRight);  
    std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
	
}	

int getWhite(int whitePixArray[]){
	int whiteRatio = 0;
	for (int i=0;i<cameraView.width;i++){
		int pix = get_pixel(cameraView,50,i,3);//getting the color value of the pixel (not individual colours)
		int boolWhite=0;
		if(pix==255){
			boolWhite =1;
		} 
		else if(pix!=255){
			boolWhite=0;
		}
		std::cout<<boolWhite<<" ";
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

int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
    takePicture();
    SavePPMFile("i0.ppm",cameraView);
    int whitePixArray[cameraView.width];//array capacity of cameraWindow.width set because robot.fovWidth = 150.0 
    while(1){
		takePicture();
		int whiteCount = 150;
		for (int i=0;i<cameraView.width;i++){
			int pix = get_pixel(cameraView,50,i,3);//getting the color value of the pixel (not individual colours)
			int bluePix = get_pixel(cameraView, 50 , i, 1);
			int boolWhite = 0;
			if(pix==255&&bluePix==255){
				boolWhite =1;
			} 
			else if(pix!=255&&bluePix!=255){
				boolWhite=0;
			}
			whitePixArray[i]=boolWhite;
		}
		
		for (int n=0;n<cameraView.width;n++){
			if(whitePixArray[n]==(0)){
				whiteCount = whiteCount - 1;   
			}	
		}
		if(getRed()==true){
			maze = 1;
		}	
		if(whiteCount > 0){
			maze = 0;
		}	
		if(maze == 0){
			int whiteRatio = getWhite(whitePixArray);
			drive(whiteRatio);
		}	
		if(maze == 1){
			driveRed();
		}
		std::cout<<maze<<std::endl;
       usleep(10000);
  } //while

} // main
