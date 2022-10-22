#ifndef BOSS_H_INCLUDED
#define BOSS_H_INCLUDED

//Boss_variables
int img_boss[28];
int index_boss;
int bossx=600,bossy=75; //boss position
int boss_timer;
bool boss_bool1=true;
int bX11=607,bY11=153,cx1=300;

void bossimage(){

	img_boss[0]=iLoadImage("images\\p1.gif");
	img_boss[1]=iLoadImage("images\\p2.gif");
	img_boss[2]=iLoadImage("images\\p3.gif");
	img_boss[3]=iLoadImage("images\\p4.gif");
	img_boss[4]=iLoadImage("images\\p5.gif");
	img_boss[5]=iLoadImage("images\\p6.gif");
	img_boss[6]=iLoadImage("images\\p7.gif");
	img_boss[7]=iLoadImage("images\\p8.gif");
	img_boss[8]=iLoadImage("images\\p9.gif");
	img_boss[9]=iLoadImage("images\\p10.gif");
	img_boss[10]=iLoadImage("images\\p11.gif");
	img_boss[11]=iLoadImage("images\\p12.gif");
	img_boss[12]=iLoadImage("images\\p13.gif");
	img_boss[13]=iLoadImage("images\\p14.gif");
	img_boss[14]=iLoadImage("images\\p15.gif");
	img_boss[15]=iLoadImage("images\\p16.gif");
	img_boss[16]=iLoadImage("images\\p17.gif");
	img_boss[17]=iLoadImage("images\\p18.gif");
	img_boss[18]=iLoadImage("images\\p19.gif");
	img_boss[19]=iLoadImage("images\\p20.gif");
	img_boss[20]=iLoadImage("images\\p21.gif");
	img_boss[21]=iLoadImage("images\\p22.gif");
	img_boss[22]=iLoadImage("images\\p23.gif");
	img_boss[23]=iLoadImage("images\\p24.gif");
	img_boss[24]=iLoadImage("images\\p25.gif");
	







}

void show_boss()
{
	iShowImage(bossx,bossy,300,150,img_boss[index_boss]);
}

void boss_punch(){
	index_boss++;
	if(index_boss==24)
	{
		index_boss=0;
		boss_bool1= false;
		//iPauseTimer(boss_timer);
	}

}


//Boss_Energy_Function
void change21(){
	

		bX11=bX11+cx1;
			
	
		if(bX11>=700||bX11<=0)
		{
			cx1=(-10);
			if(bX11<0)
			{
				bX11=720+cx1;
				
				if(bX11>=720||bX11<=0)
					{
						cx1=(-10);
					}
			}
		}
	
		

}	


#endif // BOSS_H_INCLUDED