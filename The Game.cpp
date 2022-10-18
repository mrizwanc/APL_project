#include "iGraphics.h"

int sx=0;				//shark
int sy=0;				//shark

int ex = 600;             //fish
int ey = rand() % 450;   //fish
int fn = rand() % 10;		//fish index
int speed = 2;

bool screen1 = true, screen2 = false, screen3 = false, screen4 = false;

char fish[10][20] = {"Image\\sf\\sf.bmp", "Image\\sf\\sf1.bmp", "Image\\sf\\sf2.bmp", "Image\\sf\\sf3.bmp", "Image\\sf\\sf4.bmp", "Image\\sf\\sf5.bmp", "Image\\sf\\sf6.bmp", "Image\\sf\\sf7.bmp", "Image\\sf\\sf8.bmp", "Image\\sf\\sf9.bmp"};
char scoreboard[100] = "Score is : "; 
char scorecount[100]; 
char lifeboard[100] = "Life : "; 
char lifecount[100]; 
int score = 0, life = 3;
int temp = 0;
void checkDie()
{
	if(((sx + 245) > ex) && (((sy + 80) > ey) && ((sy + 100) < ey + 200)) )
	{
		ex = 850;
		ey = rand() % 450;
		fn = rand() % 10;
		score++;
		temp++;
	}
	

	if(life==0)
	{
		screen3 = false;
		screen4 = true;
	}
	if(temp%3==0 && temp>0)
	{
		temp= 0;
		speed+=1;
		if(life < 3 && life > 0)
		{
			life++;
			
		}
		
	}
}



void iDraw()
{
	if(screen1)
	{
		iClear();
		iShowBMP(68,470,"Image\\logo.bmp");
		iShowBMP2(250,150,"Image\\mainbg.bmp",0);
		iShowBMP2(70,330,"Image\\start.bmp",0);
		iShowBMP(70,253,"Image\\insb.bmp");
		iShowBMP2(70,90, "Image\\exit.bmp",0);
	}

	if(screen2)
	{
		iClear();
		iShowBMP(0,0,"Image\\ins.bmp");

	}

	if(screen3)
	{
		iClear();
		iShowBMP(0,0,"Image\\bg.bmp");
		iText(645,535,scoreboard,GLUT_BITMAP_HELVETICA_18);
		_itoa_s(score,scorecount,10);
		iText(770,535,scorecount,GLUT_BITMAP_HELVETICA_18);
		
		iText(20,535,lifeboard,GLUT_BITMAP_HELVETICA_18);
		_itoa_s(life,lifecount,10);
		iText(70,535,lifecount,GLUT_BITMAP_HELVETICA_18);

		if(sy<0)
		{
			sy=0;
		}

		if(sx<0)
		{
			sx=0;
		}
	
		if(sx>555)
		{
			sx=555;
		}

		if(sy>450)
		{
			sy=450;
		}
		iShowBMP2(sx,sy,"Image\\s1.bmp",0);

		iShowBMP2(ex,ey,fish[fn],0);
		ex -= speed;
		if(ex < 0)
		{
			life--;
			speed--;
			temp=0;
			ex = 850;
			ey = rand() % 450;
			fn = rand() % 10;
		}
		checkDie();
	}

	if(screen4)
	{
		iClear();
		iShowBMP(200,300,"Image\\go.bmp");
		iSetColor(255,0,0);
		iText(310,225,"FINAL SCORE : ",GLUT_BITMAP_TIMES_ROMAN_24);
		_itoa_s(score,scorecount,10);
		iText(500,225,scorecount,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	

	

}




void iMouseMove(int mx, int my)
{

	if(screen1)
	{
		if((mx>65 && mx<220) && (my>325 && my<384))
		{
			screen1 = false;
			screen3 = true;
		}

		if((mx>70 && mx<220) && (my>255 && my<305))
		{
			screen1 = false;
			screen2 = true;
		}

		if((mx>80 && mx<210) && (my>95 && my<230))
		{
			exit(0);
		}
	}

	else if(screen2)
	{
		if(mx >= 0 && my >= 0)
		{
			screen2 = false;
			screen1 = true;
		}
	}
	
	else if(screen4)
	{
		if(mx >= 0 && my >= 0)
		{
			screen4 = false;
			screen1 = true;
		}
	}
}

void iMouse(int button, int state, int mx, int my)
{
	//place your codes here
}

void iKeyboard(unsigned char key)
{
	if(key == 'd' || key == 'D')
	{
		sx+=10;
	}

	if(key== 'a' || key == 'A')
	{
		sx-=10;
	}

	if(key== 'w' || key == 'W')
	{
		sy+=10;
	}

	if(key== 's' || key == 'S')
	{
		sy-=10;
	}
}

void iSpecialKeyboard(unsigned char key)
{
	//place your codes for other keys here
	if(key== GLUT_KEY_RIGHT)
	{
		sx+=10;
	}

	if(key== GLUT_KEY_LEFT)
	{
		sx-=10;
	}

	if(key== GLUT_KEY_UP)
	{
		sy+=10;
	}

	if(key== GLUT_KEY_DOWN)
	{
		sy-=10;
	}
}

int main()
{
	iInitialize(800, 570, "Hungry Shark");
	return 0;
}