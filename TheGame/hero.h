#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

//Hero_Variables
int img_hero[15];
int index_hero;
int herox=20,heroy=75; //hero position
int hero_timer;
bool hero_bool1=true;
int hbx,hby;



void heroimage(){

	img_hero[0]=iLoadImage("images\\c1.gif");
	img_hero[1]=iLoadImage("images\\c2.gif");
	img_hero[2]=iLoadImage("images\\c3.gif");
	img_hero[3]=iLoadImage("images\\c4.gif");
	img_hero[4]=iLoadImage("images\\c5.gif");
	img_hero[5]=iLoadImage("images\\c6.gif");
	img_hero[6]=iLoadImage("images\\c7.gif");
	img_hero[7]=iLoadImage("images\\c8.gif");
	img_hero[8]=iLoadImage("images\\c9.gif");
	img_hero[9]=iLoadImage("images\\c10.gif");
	img_hero[10]=iLoadImage("images\\c11.gif");
	img_hero[11]=iLoadImage("images\\c12.gif");
	






}
 //hero position function
void show_hero()
{
	iShowImage(herox,heroy,150,150,img_hero[index_hero]);
}


//Hero_Blast_Function
void hero_punch(){
	index_hero++;
	if(index_hero==11)
	{
		index_hero=0;
		hero_bool1= false;
		iPauseTimer(hero_timer);
	}

}






#endif // HERO_H_INCLUDED