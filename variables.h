#ifndef VARIABLES_INCLUDED
#define VARIABLES_INCLUDED

#define screenwid 1520
#define screenhei 760
#define JUMPLIMIT 180
#define numberoffly 3
#define numberofmonster 15
#define numberofheart 3
#define numberofbomb 3
#define numberofcoin 15
#define upperbgspeed 10
#define lowerbgspeed 15//bg render
bool musicon = true;
bool pause = true;
//////////////////////////////   background   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char bc[8][15] = { "bc\\1.bmp", "bc\\play.bmp", "bc\\option.bmp", "bc\\Score.bmp", "bc\\au.bmp", "bc\\exit.bmp" };
///////////////////////////// background rendaring level 1/////////////////////////////////////////////////////////////////////////////////////////////////////////////
char upperbackground[15][40] = { "bc\\Background\\upperbg01.bmp", "bc\\Background\\upperbg02.bmp", "bc\\Background\\upperbg03.bmp", "bc\\Background\\upperbg04.bmp", "bc\\Background\\upperbg05.bmp", "bc\\Background\\upperbg06.bmp",
"bc\\Background\\upperbg07.bmp", "bc\\Background\\upperbg08.bmp", "bc\\Background\\upperbg09.bmp", "bc\\Background\\upperbg10.bmp" };

char lowerbackground[15][40] = { "bc\\Background\\lowerbg01.bmp", "bc\\Background\\lowerbg02.bmp", "bc\\Background\\lowerbg03.bmp", "bc\\Background\\lowerbg04.bmp", "bc\\Background\\lowerbg05.bmp", "bc\\Background\\lowerbg06.bmp",
"bc\\Background\\lowerbg07.bmp", "bc\\Background\\lowerbg08.bmp", "bc\\Background\\lowerbg09.bmp", "bc\\Background\\lowerbg10.bmp" };
typedef struct background
{
	int x;
	int y;

}background;
background upperbg[10];
background lowerbg[10];
bool front = false;
bool back = false;
/////////////////////////////  main charecter  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool maincshow = true;
//// stand ////
char mains[1][15] = { "bc\\stand01.bmp" };
bool standpos = true;
int standcount = 0;
//// Run ////
char mainc[15][20] = { "bc\\run01.bmp", "bc\\run02.bmp", "bc\\run03.bmp", "bc\\run04.bmp", "bc\\run05.bmp", "bc\\run06.bmp", "bc\\rev1.bmp", "bc\\rev2.bmp", "bc\\rev3.bmp", "bc\\rev5.bmp", "bc\\rev6.bmp" };
int maincx = 0;
int maincy = 150;
int maincIndex = 0;
//// jump ////
char mainjump[2][15] = { "bc\\jump1.bmp", "bc\\jump2.bmp" };
bool jump = false;
bool jumpUp = false;
int jumpy = 0;
////  knif  ////
char knife[4][15] = { "bc\\m1.bmp", "bc\\m2.bmp", "bc\\m3.bmp", "bc\\m4.bmp" };
int knifeindex = 0;
int k = 0;
//// fire ////
char firepic[1][15] = { "bc\\bullet.bmp" };
int firex;
int firey = maincy + 105;
bool fireshow = false;
bool firesound = false;
// life bar //
char lifepic[6][15] = { "bc\\l1.bmp", "bc\\l2.bmp", "bc\\l3.bmp", "bc\\l4.bmp", "bc\\l5.bmp", "bc\\l6.bmp" };
int lifeindex = 0;
int q = 0;
bool lifevisible = true;

//////////////////////////////////////////////////////  Level 1 Enemy //////////////////////////////////////////////////////////////////////////////////////////////////
///////// monster ///////////////////////



////////  fly  /////////////////////////
char flyenemy[10][20] = { "bc\\flying01.bmp", "bc\\flying02.bmp", "bc\\flying03.bmp", "bc\\flying04.bmp", "bc\\flying05.bmp", "bc\\flying06.bmp", "bc\\flying07.bmp", "bc\\flying08.bmp", "bc\\flying09.bmp", "bc\\flying10.bmp" };
struct fly
{
	int flyx;
	int flyy;
	int flyindex;
	bool flyshow;
};
fly enemy[numberoffly];
//////////// bomb  ///////////////////////////
char bombpic[1][12] = { "bc\\bomb.bmp" };
struct bm
{
	int bombx;
	int bomby;
	int bombindex;
	bool bombshow;
};
struct bm bomb[numberofbomb];
//////////// coin  ///////////////////////////
char coinpic[1][12] = { "bc\\coin.bmp" };
struct cm
{
	int coinx;
	int coiny;
	int coinindex;
	bool coinshow;
};
struct cm coin[numberofcoin];
////////// HEART  //////////////////////////////
char heartpic[1][15] = { "bc\\life.bmp" };
struct ht
{
	int heartx;
	int hearty;
	int heartindex;
	bool heartshow;
};
struct ht heart[numberofheart];

///// monster  /////////////
char monsterenemy[10][15] = { "bc\\enemy1.bmp", "bc\\enemy2.bmp", "bc\\enemy3.bmp", "bc\\enemy4.bmp", "bc\\enemy5.bmp", "bc\\enemy6.bmp" };
struct monster
{
	int monsterx;
	int monstery;
	int monsterindex;
	bool monstershow;
	bool monsterfightshow;
	int fightindex;
};
monster menemy[numberofmonster];
char monstermellepic[10][15] = { "bc\\mf1.bmp", "bc\\mf2.bmp", "bc\\mf3.bmp", "bc\\mf4.bmp"};
int enemykilled = 0;

bool gameover = false;
bool gameovermusic = false;



//////////////////// level 2 //////////////////////////////////////////////
#define yaxismargin 60;
#define totalbat  21

bool isstart = false;
int xball = 700;
int yball = yaxismargin;
int dx = 7;
int dy =5;
int radiusball = 10;
int r = 0;
int g = 0;
int b = 0;
int xboard = xball - 40;
int yboard = yball - 58;
int dxboard = 188;
int dyboard = 30;
int batoff = 0;
char batpic[21][20] = { "bc\\bat.bmp", "bc\\bat.bmp", "bc\\bat.bmp", "bc\\bat.bmp", "bc\\bat.bmp", "bc\\bat.bmp", "bc\\bat.bmp", "bc\\bat.bmp", "bc\\bat.bmp", "bc\\bat.bmp", "bc\\bat.bmp", "bc\\bat.bmp", "bc\\bat.bmp", "bc\\bat.bmp", "bc\\bat.bmp", "bc\\bat.bmp", "bc\\bat.bmp", "bc\\bat.bmp", "bc\\bat.bmp", "bc\\bat.bmp", "bc\\bat.bmp" };
struct bats{
	int x;
	int y;
	int dx=200;
	int dy=200;
	bool show = true;
};
bats batss[totalbat];
// int qeta=45;
// int valocity =10;
// dx = velocity* cos(qeta);
//dy= velocity*sin(qeta);

////////////////////////// level 3 /////////////////////////////////////////////////////////////////////////////////////////////////
////  puzzel  ////////////
/////////////////////////////  main charecter  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*bool pshow = false;
char pcpic[9][15] = { "bc\\p1.bmp", "bc\\p2.bmp", "bc\\p3.bmp", "bc\\p4.bmp", "bc\\p5.bmp", "bc\\p6.bmp", "bc\\p7.bmp", "bc\\p8.bmp", };
struct p
{
	int x;
	int y;
	int index;
	bool select;
};
char empty[1][10] = { "bc\\p8.bmp" };
int ex = 750;
int ey = 400;
int rx=0, ry=0;

int p1x = 550, p1y = 200;
int p2x = 650, p2y = 200;
int p3x = 750, p3y = 200;
int p4x = 550, p4y= 300;
int p5x = 650, p5y =300;
int p6x = 750, p6y = 300;
int p7x = 550, p7y = 400;*/
int p8x = 650, p8y = 400;


///// monster  /////////////
# define numberoflv3 30
char lv3enemypic[10][20] = { "bc\\flying01.bmp", "bc\\flying02.bmp", "bc\\flying03.bmp", "bc\\flying04.bmp", "bc\\flying05.bmp", "bc\\flying06.bmp", "bc\\flying07.bmp", "bc\\flying08.bmp", "bc\\flying09.bmp", "bc\\flying10.bmp" };
struct lv3enemy
{
	int x;
	int y;
	int index;
	bool show;
};
lv3enemy lv3[numberoflv3];
bool fire = false;
bool targetshow = false;
int lv3enemykilled = 0;
int ix = 0;
int iy = 150;



//////////// coin  ///////////////////////////
# define numberofboin 20
char boinpic[1][12] = { "bc\\coin.bmp" };
struct lm
{
	int x;
	int y;
	int index;
	bool show;
};
struct lm boin[numberofboin];

#endif