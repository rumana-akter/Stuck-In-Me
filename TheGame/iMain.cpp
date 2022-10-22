#include "iGraphics.h"
#include"bitmap_loader.h"
#include "myheader.h "
#include"hero.h"
#include "enemy.h"
#include"boss.h"
#include"score.h"
void change3();
void bulletmove();
 
//variable declaration
int intro,menu,credits,scores,instructions,charac,life,enemy,blast,blast1,heroblast,bossblast,death,win;
int flag = 0;
int w=1000,h=500;
int LIFE=5;
int token;
int fflag=0,jjs;
//lead character variable
int x=20,y=75;
//lead character initialize for movement
int lx=0,ly=0;
int move=0,move2=0;
 
//hero,boss_Energy
int in = 0;
int bbx[3] = {9999,9999,9999};
int bby[3]=  {9999,9999,9999};
int boss = 1;
int cnt = 0;
int count_timer;
int boss_bullet;
int bossLife = 10;
int bossflag = 0 ;
int gameover = 0;
int len = 0;
 
char str[20],str2[20];
 
//BALL variables
/*int bX1=950,bY1=355;
int bX2=890,bY2=355;
int bX3=1000,bY3=355;
//ball initialize
int cx=20,cy=20;*/
 
 
 
 
/*Background variables*/
int background[2];
int background_x[] = {0,0},background_y[]={0,0};
 
 
 
 
/*
Background Timer
 
*/

 
//hero bullet move

void bulletmove()
{
    for(int ii=0;ii<3;ii++)
    {
        bbx[ii]+=2;
        printf("%d\n",bbx[ii]);
    }
 
}
 
void change_background()
{ for(int i=0;i<2;i++)
    {
        background_x[i] -= 15; //left slide
        if(background_x[i]+500<0) //left slide out of frame
            background_x[i] = background_x[(i+1)%2]+500;
 
    }
}
 
 
 
 
 
 
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
 
void iDraw()
{
    iClear();
    //Menu informations
   
 
   
    if(flag == 0) //Start Page
    {
    iShowImage(0, 0, w, h, intro);
    iText(10,450,"click the IN to start", GLUT_BITMAP_HELVETICA_18);
    //iPauseTimer(count_timer);
    }
 
     else if(flag==1) //menu
        {
            iShowImage(0,0,w,h,menu);
 
            LIFE = 5;
            cnt = 0;
            bossLife = 10;
 
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<3;j++)
                {
                    if(gamer[j].score<gamer[j+1].score)
                    {
                        char use[10];
                        int temp;
                        temp = gamer[j].score;
                        gamer[j].score = gamer[j+1].score;
                        gamer[j+1].score = temp;
 
                        strcpy(use,gamer[j].name);
                        strcpy(gamer[j].name,gamer[j+1].name);
                        strcpy(gamer[j+1].name,use);
 
 
                    }
 
                }
 
            }
            gamer[3].score = 0;

			bossflag=0;
			boss=1;
			gameover=0;
 
 
        }
    else if(flag==2 ) //credits
        {
 
            iShowImage(0,0,w,h,credits);
 
        }
   
 
     else if(flag==3 ) //scores
        {
            iSetColor(0,0,0);
            iFilledRectangle(0,0,1000,500);
   
            char show[10];
            iSetColor(255,255,255);
            sprintf(show,"%d",gamer[0].score);
            iText(500,400,gamer[0].name);
            iText(700,400,show);
           
            sprintf(show,"%d",gamer[1].score);
            iText(500,300,gamer[1].name);
            iText(700,300,show);
 
               
            sprintf(show,"%d",gamer[2].score);
            iText(500,200,gamer[2].name);
            iText(700,200,show);
 
 
 
 
 
        }
 
     else if(flag==4 ) //instructions
        {
            iShowImage(0,0,w,h,instructions);
            iText(450,450,"Instructions", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(420,400,"Press F to fire", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(420,350,"Press Right Arrow to move Right", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(420,300,"Press Left Arrow to move Left", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(420,250,"Press Up Arrow to move Upwards", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(420,200,"Press Down Arrow to move Downwards", GLUT_BITMAP_TIMES_ROMAN_24);
        }
   
     else if(flag==5 ) //Game componenets
        {
            change3(); //enemy bullet collision

            //iResumeTimer(count_timer);
 
            //how many enemy
            if(cnt == 12)
                boss = 0;


            
       
 
 
 
            iResumeTimer(token);
            for(int i=0;i<2;i++)
            {
                 iShowImage(background_x[i],0,1000,500,background[i]);
            }
 
 
            //hero bullet input

			bulletmove();
        for( int jj=0;jj<3;jj++)
        iShowImage(bbx[jj],bby[jj],40,40,heroblast);
 
 
 
 
 
       
 
 
 
 
            //characters
            //iShowImage(lx,ly+75,w-900,h-400,charac);
 
            if(bbx[0]+20 >=eX &&  bbx[0]<=w-900+eX &&  bby[0]+20 >= eY  && bby[0]+20<=h-400+eY  )
                {
                    eX = 1000;
                    move = 5;
                    bbx[0]=9999;
                    cnt++;
                 }
 
            if(bbx[0]+20 >=e1X &&  bbx[0]<=w-900+e1X &&  bby[0]+20 >= e1Y  && bby[0]+20<=h-400+e1Y  )
                {
                    e1X = 1000;
                    move2 = 5;
                    bbx[0]=9999;
                    cnt++;
                 }
 
 
 
 
                if(bbx[1]+20 >=eX &&  bbx[1]<=w-900+eX &&  bby[1]+20 >= eY  && bby[1]+20<=h-400+eY  )
                {
                    eX = 1000;
                    move = 5;
                    bbx[1]=9999;
                    cnt++;
                 }
 
            if(bbx[1]+20 >=e1X &&  bbx[1]<=w-900+e1X &&  bby[1]+20 >= e1Y  && bby[1]+20<=h-400+e1Y  )
                {
                    e1X = 1000;
                    move2 = 5;
                    bbx[1]=9999;
                    cnt++;
                 }
 
 
                if(bbx[2]+20 >=eX &&  bbx[2]<=w-900+eX &&  bby[2]+20 >= eY  && bby[2]+20<=h-400+eY  )
                {
                    eX = 1000;
                    move = 5;
                    bbx[2]=9999;
                    cnt++;
                 }
 
            if(bbx[2]+20 >=e1X &&  bbx[2]<=w-900+e1X &&  bby[2]+20 >= e1Y  && bby[2]+20<=h-400+e1Y  )
                {
                    e1X = 1000;
                    move2 = 5;
                    bbx[2]=9999;
                    cnt++;
                 }
 
 
                    if(bbx[0]+20 >=bossx &&  bbx[0]<=bossx+300 &&  bby[0]+20 >= bossy  && bby[0]+20<=bossy+150  )
                {
                   
                    bossLife--;
                    bbx[0] = 9999;
 
 
                 }
 
 
                    if(bbx[1]+20 >=bossx &&  bbx[1]<=bossx+300 &&  bby[1]+20 >= bossy  && bby[1]+20<=bossy+150  )
                {
                   
                    bossLife--;
                    bbx[1] = 9999;
 
 
                 }
 
 
 
                    if(bbx[2]+20 >=bossx &&  bbx[2]<=bossx+300 &&  bby[2]+20 >= bossy  && bby[2]+20<=bossy+150  )
                {
                   
                    bossLife--;
                    bbx[2] = 9999;
 
 
                 }
 
 
 
 
 
 
                if(bossflag == 1)
                    {if(bossLife==10)
                    {
                        iShowImage(800,430,w-950,h-450,life);
                        iShowImage(810,430,w-950,h-450,life);
                        iShowImage(820,430,w-950,h-450,life);
                        iShowImage(830,430,w-950,h-450,life);
                        iShowImage(840,430,w-950,h-450,life);
                        iShowImage(850,430,w-950,h-450,life);
                        iShowImage(860,430,w-950,h-450,life);
                        iShowImage(870,430,w-950,h-450,life);
                        iShowImage(880,430,w-950,h-450,life);
                        iShowImage(890,430,w-950,h-450,life);
 
 
                    }
 
 
 
 
 
                    if(bossLife==9)
                    {
                        iShowImage(800,430,w-950,h-450,life);
                        iShowImage(810,430,w-950,h-450,life);
                        iShowImage(820,430,w-950,h-450,life);
                        iShowImage(830,430,w-950,h-450,life);
                        iShowImage(840,430,w-950,h-450,life);
                        iShowImage(850,430,w-950,h-450,life);
                        iShowImage(860,430,w-950,h-450,life);
                        iShowImage(870,430,w-950,h-450,life);
                        iShowImage(880,430,w-950,h-450,life);
                       
 
 
                    }
 
 
 
 
 
                    if(bossLife==8)
                    {
                        iShowImage(800,430,w-950,h-450,life);
                        iShowImage(810,430,w-950,h-450,life);
                        iShowImage(820,430,w-950,h-450,life);
                        iShowImage(830,430,w-950,h-450,life);
                        iShowImage(840,430,w-950,h-450,life);
                        iShowImage(850,430,w-950,h-450,life);
                        iShowImage(860,430,w-950,h-450,life);
                        iShowImage(870,430,w-950,h-450,life);
                       
 
 
                    }
 
 
 
 
 
                    if(bossLife==7)
                    {
                        iShowImage(800,430,w-950,h-450,life);
                        iShowImage(810,430,w-950,h-450,life);
                        iShowImage(820,430,w-950,h-450,life);
                        iShowImage(830,430,w-950,h-450,life);
                        iShowImage(840,430,w-950,h-450,life);
                        iShowImage(850,430,w-950,h-450,life);
                        iShowImage(860,430,w-950,h-450,life);
               
 
                    }
 
 
 
 
 
 
 
                    if(bossLife==6)
                    {
                        iShowImage(800,430,w-950,h-450,life);
                        iShowImage(810,430,w-950,h-450,life);
                        iShowImage(820,430,w-950,h-450,life);
                        iShowImage(830,430,w-950,h-450,life);
                        iShowImage(840,430,w-950,h-450,life);
                        iShowImage(850,430,w-950,h-450,life);
                   
 
 
                    }
 
 
 
 
 
 
                    if(bossLife==5)
                    {
                        iShowImage(800,430,w-950,h-450,life);
                        iShowImage(810,430,w-950,h-450,life);
                        iShowImage(820,430,w-950,h-450,life);
                        iShowImage(830,430,w-950,h-450,life);
                        iShowImage(840,430,w-950,h-450,life);
                       
 
 
                    }
 
 
 
 
 
 
                    if(bossLife==4)
                    {
                        iShowImage(800,430,w-950,h-450,life);
                        iShowImage(810,430,w-950,h-450,life);
                        iShowImage(820,430,w-950,h-450,life);
                        iShowImage(830,430,w-950,h-450,life);
                       
 
 
                    }
 
 
 
 
 
 
                    if(bossLife==3)
                    {
                        iShowImage(800,430,w-950,h-450,life);
                        iShowImage(810,430,w-950,h-450,life);
                        iShowImage(820,430,w-950,h-450,life);
                       
 
 
 
                    }
 
 
 
 
 
 
 
 
 
                    if(bossLife==2)
                    {
                        iShowImage(800,430,w-950,h-450,life);
                        iShowImage(810,430,w-950,h-450,life);
                       
                    }
 
 
 
 
 
 
 
                    if(bossLife==1)
                    {
                        iShowImage(800,430,w-950,h-450,life);
               
                    }
 
 
 
 
 
 
 
                    if(bossLife<=0)
                    {
                        gameover = 1;
                        flag = 12;
 
                    }
 
 
                    }
 
 
 

					
					
//enemy regenarate
					
					if(eX ==800)
                 move = 0;
            if(e1X ==750)
                 move2 = 0;
            if(boss==1)
            {iShowImage(eX-=move,eY,w-900,h-400,enemy);
            iShowImage(e1X-=move2,e1Y,w-900,h-400,enemy);

			//hero img show

            show_hero();
 
           
			//boss blasts
			iPauseTimer(boss_bullet);
 
                //enemy blasts
            iShowImage(bX1,bY1,w-975,h-475,blast);
            iShowImage(bX3,bY3,w-975,h-475,blast);
           
 
 
 
 
            //iShowImage(bX2,bY2,w-975,h-475,blast);
           
           
           
            }
 
        //boss appearance

			else
                {
                    bossflag = 1;
                    bX1 = 9999;
                    bX3 = 9999;
                    show_boss();
                    show_hero();
                    iResumeTimer(boss_bullet);
                    iShowImage(bX11,bY11,w-940,h-475,bossblast);
 
      //boss vs hero
					
					if(bX11<=herox+150 && bX11>=herox && bY11>=heroy && bY11+h-475<=heroy+150)
        {
            LIFE = LIFE - 2;
            bX11 = 607;
 
        }
 
                   
 
 
 
            }
 
            //HeroLife
           
            if(LIFE==5)
            {iShowImage(20,430,w-950,h-450,life);
            iShowImage(50,430,w-950,h-450,life);
            iShowImage(80,430,w-950,h-450,life);
            iShowImage(110,430,w-950,h-450,life);
            iShowImage(140,430,w-950,h-450,life);
            }
 
           
            if(LIFE==4)
            {iShowImage(20,430,w-950,h-450,life);
            iShowImage(50,430,w-950,h-450,life);
            iShowImage(80,430,w-950,h-450,life);
            iShowImage(110,430,w-950,h-450,life);
        }
 
 
           
            if(LIFE==3)
            {iShowImage(20,430,w-950,h-450,life);
            iShowImage(50,430,w-950,h-450,life);
            iShowImage(80,430,w-950,h-450,life);
            }
 
 
           
            if(LIFE==2)
            {iShowImage(20,430,w-950,h-450,life);
            iShowImage(50,430,w-950,h-450,life);
            }
 
 
           
            if(LIFE==1)
            {iShowImage(20,430,w-950,h-450,life);
        }
 
           
            if(LIFE<=0)
            {
                gameover = 1;
                flag = 11;
 
            }
     
     }
 
     else if(flag==6) //exit
        {
 
            exit(0);
 
        }
 
 
        //Death_Screen

        if(flag == 11)
        {
        gameover = 1;
        iShowImage(0,0,w,h,death);
        iSetColor(255,255,255);
        iFilledRectangle(450,200,120,20);
        iSetColor(0,0,0);
        iText(460,207,str);
 
            char ss[50];

			//counting scores without boss death


            gamer[3].score = (cnt * 10);
			sprintf(ss,"Your Score: %d",gamer[3].score);
            iSetColor(255,255,255);
            iText(450,99,ss);
 
 
        }
 
 
        //Win_Screen
        if (flag == 12 )
        {
                 
        iShowImage(0,0,w,h,win);
        iSetColor(192,192,192);
        iFilledRectangle(450,150,120,20);
        iSetColor(0,0,0);
        iText(460,157,str);
 
 
 
            char ss[50];


           //counting scores after boss death

			gamer[3].score = (cnt * 10)+100;
			sprintf(ss,"Your Score: %d",gamer[3].score);
            iSetColor(255,255,255);
            iText(450,99,ss);
       
        }
 
   
 
 
 /*
     if(hbx>=1000)
        {
            iPauseTimer(token);
        }
 
 */
}
 //movement of hero bullet
void bullet(void)
{
 
 
    bbx[in] = herox+80;
    bby[in] = heroy+120;
    in++;
    if(in>2)                    
        in = 0;
 
    printf("FUN");
 
}
  
/* void count()
{
    cnt++;
}
 
 */
 
 
/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
 
 
void iMouseMove(int mx, int my)
{
   
}
//***************************************************************s****ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
   
}
 
 
//----------------------------------------------------------------------------------------------------------------------------------------------------------
 
void iMouse(int button, int state, int mx, int my)
{
   
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        printf("\nx=%d \t y=%d\n", mx, my);
        if(mx>=448 && mx<=625 && my<=294 && my>=201 && flag==0)
    {
       
        flag=1; //shows menu
       
       
    }
        if(mx>=768 && mx<=902 && my>=243 && my<=273 && flag==1)
   
           
        {
       
            flag=2; //shows credits
           
        }
       
        if(mx>=73 && mx<=196 && my>=262 && my<=291 && flag==1)
   
           
        {
       
            flag=3; //shows scores
           
        }
       
            if(mx>=506 && mx<=707 && my>=134 && my<=154 && flag==1)
   
           
        {
       
            flag=4; //shows instructions
           
        }
 
            if(mx>=689 && mx<=991 && my>=366 && my<=416 && flag==1)
   
           
        {
       
            flag=5; //Gameplay
           
        }
 
            if(mx>=79 && mx<=254 && my>=146 && my<=187 && flag==1)
   
           
        {
       
            flag=6; //exit
           
        }
 
 
    }
   
   
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
       
    }
}
 
/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
 
//-------------------------------------------------------------------------------------------------------------------------------------------------
 
void iKeyboard(unsigned char key)
{
   
 
       
 
    if(gameover==1)
       
        {
            if(key == '\r')
        {
           
            strcpy(gamer[3].name, str);
            for(int i = 0; i < len; i++)
                str[i] = 0;
            len = 0;
            flag = 1;
        }
        else
        {
            str[len] = key;
            len++;
        }
 
 
   
    }
 
    else
    {
 
        if (key == 'f')
    {
 
        index_hero=1;
        if(hero_bool1==true)
        hero_timer=iSetTimer(50,hero_punch);
        else if(hero_bool1==false)
        {
            iResumeTimer(hero_timer);
 
        }

   //hero bullet move
		
		bullet();
 
 
    }
 
 
    /*if (key == 't' )
    {
 
        index_boss=1;
        if(boss_bool1==true)
            iPauseTimer(boss_timer);
        //boss_timer=iSetTimer(30,boss_punch);
        else if(boss_bool1==false)
        {
            iResumeTimer(boss_timer);
        }
 
    }*/
   
    }
 
}
 
/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
 
//------------------------------------------------------------------------------------------------------------------------------------------------
 
void iSpecialKeyboard(unsigned char key)
{
 
   
    if (key == GLUT_KEY_RIGHT)
    {
        if(herox<900) //LC forward
        {
            herox=herox+10;
        }
        else
        {
            herox=herox+0;
        }
       
       
    }
    if (key == GLUT_KEY_LEFT)
    {
           
        if(herox>1) //LC backward
        {
            herox=herox-10;
        }
        else
        {
            herox=herox-0;
        }
 
 
    }
    if (key == GLUT_KEY_UP)
    {
        if(heroy<360) //LC Up
        {
            heroy=heroy+10;
        }
        else
        {
            heroy=heroy+0;
        }
       
    }
   
    if (key == GLUT_KEY_DOWN)
    {
        if(heroy>1) //LC down
        {
            heroy=heroy-10;
        }
        else
        {
            heroy=heroy-0;
        }
       
    }
   
    if (key == GLUT_KEY_END)
    {
       
    }
 
if (key == GLUT_KEY_END)
    {
        flag=1; //back to main menu
    }
   
}
/*void change(){
 
 
    x+=dx;
    if(x>=1000||x<=0)
    {
        dx*=(-1);
    }
 
    if(y>=500||y<=0)
    {
        dy*=(-1);
    }
 
 
}*/
 
 
 
//Enemy_Energy_Collsion
 void change3(){
 
 
     //First enemy //bX1=first enemy bullet
    if(bX1<=herox+150 && bX1>=herox && bY1<=heroy+150 && heroy<=bY1)
    {
        printf("collision");
        LIFE--;
 
         bX1=820,bY1=455;
 
    }
    /*if(bX2<=herox+150 && bX2>=herox && bY2<=heroy+150 && heroy>=bY2)
    {
   
        printf("collision");
        LIFE--;
 
 bX2=89,bY2=355;
 
    }*/
 
    //Second_Enemy bX2=scnd enemy bullet
    if(bX3<=herox+150 && bX3>=herox && bY3<=heroy+150 && heroy<=bY3)
    {
   
        printf("collision");
        LIFE--;
 
        bX3=860,bY3=255;
    }
 }

int main()
{
    iInitialize(1000, 500, "Project Title");
   
 
    //Function_Timers
    iSetTimer(10,change2);
    iSetTimer(20,change_background);
    boss_bullet = iSetTimer(50,change21);
    boss_timer=iSetTimer(50,boss_punch);


   // token = iSetTimer(100,movement);
    //count_timer = iSetTimer(1000,count);
   
   
    heroimage();
    bossimage();
    dx = 5;
    dy = 7;
   
   
   
 
    ///srand((unsigned)time(NULL));
   
    //image implementations
   
    intro=iLoadImage("images\\IntroPage.jpg");
    menu=iLoadImage("images\\Menu1.jpg");
    credits=iLoadImage("images\\Credits1.png");
    scores=iLoadImage("images\\Score2.jpg");
    instructions=iLoadImage("images\\Instructions1.jpg");
    //charac=iLoadImage("images\\Character1.gif");
   
    enemy=iLoadImage("images\\Enemy1.gif");
    blast=iLoadImage("images\\eb1.png");
    blast1=iLoadImage("images\\Hearts1.png");
    life=iLoadImage("images\\Hearts1.png");
    heroblast=iLoadImage("images\\hb1.png");
    bossblast=iLoadImage("images\\bb1.png");
    death=iLoadImage("images\\goDeath.jpg");
    win=iLoadImage("images\\goWin.jpg");
 
   
   
    //Background array
    background[0] = iLoadImage("images\\bg3.png");
    background[1] = iLoadImage("images\\bg3.png");
   
 
 
 
    //score
 
    FILE *fp = fopen("scores.txt","r");
    for(int i=0;i<3;i++)
    {
        fscanf(fp,"%s %d",gamer[i].name,&gamer[i].score);
    }
    strcpy(gamer[3].name,"blank");
    gamer[3].score = 0;
 
 
 
 
 
 
 
 
 
 
   
    iStart();
    return 0;
}
