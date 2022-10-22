#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED


//Enemy_blast_variable
int bX1=950,bY1=455;
//int bX2=890,bY2=355;
int bX3=1000,bY3=255;
int cx=30,cy=30;

//Enemy variable
int eX=800,eY=400;
int e1X =750 ,e1Y=200;




//Enemy_blast_functions
void change2(){
	
	//First enemy bullet movement
		bX1=bX1+cx;
			
	
		if(bX1>=700||bX1<=0)
		{
			cx=(-2);
			if(bX1<0)
			{
				bX1=720+cx;
				
				if(bX1>=720||bX1<=0)
					{
						cx=(-2);
					}
			}
		}
		

		
	//Second Enemy bullet movement
		bX3=bX3+cx;
			
	
		if(bX3>=700||bX3<=0)
		{
			cx=(-2);
			if(bX3<0)
			{
				bX3=800+cx;
				
				if(bX3>=800||bX3<=0)
					{
						cx=(-2);
				}
			}
		}
}









#endif // !MYHEADER_H_INCLUDED