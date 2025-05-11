#include<iostream>
#include<graphics.h>
#include <windows.h>
using namespace std;

main()
{

		initwindow(500, 500);
		

		rectangle(250, 50, 350, 350);
		
		circle(300, 100, 50);
		circle(300, 200, 50);
		circle(300, 300, 50);
		
		//creating animation
		
			for(int j=2; j>=0; j--){
			setfillstyle(1, RED);
			floodfill(300, 100, WHITE);
			outtextxy(280, 100, "STOP");
			delay(6000);
			
		
			
			
			setfillstyle(1, BLACK);
			floodfill(300, 100, WHITE);
			setfillstyle(1, YELLOW);
			floodfill(300, 200, WHITE);
			outtextxy(280, 200, "Wait");
			delay(5000);
			
			
			setfillstyle(1, BLACK);
			floodfill(300, 200, WHITE);
			setfillstyle(1, GREEN);
			floodfill(300, 300, WHITE);
			outtextxy(280, 300, "GO");
			delay(6000);
			
			setfillstyle(1, BLACK);
			floodfill(300, 300, WHITE);
			
			
		}	
	
}