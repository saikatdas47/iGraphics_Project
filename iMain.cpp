#include<iostream>
using namespace std;
#include "iGraphics.h"
#include"variables.h"
#include"score.h"
#include <stdio.h>
#include <stdlib.h>
#include<fstream>
int i = 0;
////////////////////////////

// file
ofstream file;
ifstream readfile;
// onces file written
int filewrittenindicator = 1;

//score array from file

int sscore[6];
int p = 0;
int scorevalue;




///////////////////////////////////
void restart(){
	if (i == 7)
	{
		isstart = false;
		xball = 700;
		yball = yaxismargin;
		dx = 7;
		dy = 5;

		xboard = xball - 40;
		yboard = yball - 58;

	}
}
/////////////////////////////////////////////////////////////////////// Function /////////////////////////////////////////////////////////////////
void life(){
	if (lifevisible){
		iShowBMP2(1178, 700, lifepic[lifeindex], 0);
	}
}

void fireing(){
	for (int i = 0; i < 152; i++) {
		firex++;
		if (firex > screenwid) {
			fireshow = false;
			if (i == 3) {
				firex = maincx + 10000000000000000000;
				//firesound = true;
			}
		}
	}
}
void change(){
	if (jump){
		if (jumpUp){
			jumpy += 5;
			if (jumpy >= JUMPLIMIT){
				jumpUp = false;
				iShowBMP2(maincx, maincy + jumpy, mainjump[0], 0);
			}
		}
		else{
			jumpy -= 5;
			if (jumpy <= 0){

				jump = false;
				jumpy = 0;
				iShowBMP2(maincx, maincy + jumpy, mainjump[1], 0);
			}
		}
	}
}

void setbg(){
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		upperbg[i].y = 230;//230
		lowerbg[i].y = 0;
		upperbg[i].x = sum;
		lowerbg[i].x = sum;
		sum += 149;
	}
}
void bgchange(){
	if (front){
		for (int i = 0; i < 10; i++)
		{
			upperbg[i].x -= upperbgspeed;
			lowerbg[i].x -= lowerbgspeed;
			if (upperbg[i].x <= 0)
			{
				upperbg[i].x = screenwid;

			}
			if (lowerbg[i].x <= 0)
			{
				lowerbg[i].x = screenwid;

			}
		}
	}
	else if (back)
	{

		for (int i = 0; i < 10; i++){
			upperbg[i].x += upperbgspeed;
			if (upperbg[i].x >= screenwid) upperbg[i].x = 0;
			lowerbg[i].x += lowerbgspeed;
			if (lowerbg[i].x >= screenwid) lowerbg[i].x = 0;
		}


	}
}
void renderbg(){
	for (int i = 0; i < 10; i++)
	{
		iShowBMP(upperbg[i].x, upperbg[i].y, upperbackground[i]);
		iShowBMP(lowerbg[i].x, lowerbg[i].y, lowerbackground[i]);
	}
}


void flymove(){

	for (int i = 0; i < numberoffly; i++)
	{

		if (enemy[i].flyshow)
		{
			iShowBMP2(enemy[i].flyx, enemy[i].flyy, flyenemy[enemy[i].flyindex], 0);
		}
	}
}
void flychange(){

}
void setflyvatiables(){
	for (int i = 0; i < numberoffly; i++)
	{
		enemy[i].flyx = screenwid + rand() % 1000;
		enemy[i].flyy = 340 + rand() % 300;
		enemy[i].flyindex = rand() % 10;
		enemy[i].flyshow = true;
	}
}

void bombmove(){

	for (int i = 0; i < numberofbomb; i++)
	{

		if (bomb[i].bombshow)
		{
			iShowBMP2(bomb[i].bombx, bomb[i].bomby, bombpic[bomb[i].bombindex], 0);
		}
	}
}
void bombchange(){

}
void setbombvariables(){
	for (int i = 0; i < numberofbomb; i++)
	{
		bomb[i].bombx = screenwid + rand() % 3500;
		bomb[i].bomby = 150; + rand() % 10;
		bomb[i].bombindex = rand() % 6;
		bomb[i].bombshow = true;
	}
}


void coinmove(){

	for (int i = 0; i < numberofcoin; i++)
	{

		if (coin[i].coinshow)
		{
			iShowBMP2(coin[i].coinx, coin[i].coiny, coinpic[coin[i].coinindex], 0);
		}
	}
}
void coinchange(){

}
void setcoinvariables(){
	for (int i = 0; i < numberofcoin; i++)
	{
		coin[i].coinx = screenwid + rand() % 3500;
		coin[i].coiny = 150; +rand() % 10;
		coin[i].coinindex = rand() % 6;
		coin[i].coinshow = true;
	}
}


void heartmove(){
	if (i == 3){
		for (int i = 0; i < numberofheart; i++)
		{

			if (heart[i].heartshow)
			{
				iShowBMP2(heart[i].heartx, heart[i].hearty, heartpic[heart[i].heartindex], 0);

			}
		}
	}


}
//all change
void heartchange(){
	if (i == 3){
		for (int i = 0; i < numberofheart; i++){
			heart[i].heartx -= 6;
			if (heart[i].heartx <= 0)
			{
				heart[i].heartx = screenwid + rand() % 2500;


			}
			heart[i].heartindex++;
			if (heart[i].heartindex >= 0)
			{
				heart[i].heartindex = 0;
			}
		}
	}
	if (i == 3){
		for (int i = 0; i < numberofmonster; i++){
			if (menemy[i].monstershow){
				menemy[i].monsterx -= 6;
				if (menemy[i].monsterx <= 0)
				{
					menemy[i].monsterx = screenwid + rand() % 1000;


				}
				menemy[i].monsterindex++;
				if (menemy[i].monsterindex >= 6)
				{
					menemy[i].monsterindex = 0;
				}
			}
		}

	}
	if (i == 3){
		for (int i = 0; i < numberofcoin; i++){
			coin[i].coinx -= 13;
			if (coin[i].coinx <= 0)
			{
				coin[i].coinx = screenwid + rand() % 3500;


			}
			coin[i].coinindex++;
			if (coin[i].coinindex >= 0)
			{
				coin[i].coinindex = 0;
			}
		}
	}
	if (i == 3){
		for (int i = 0; i < numberofbomb; i++){
			bomb[i].bombx -= 13;
			if (bomb[i].bombx <= 0)
			{
				bomb[i].bombx = screenwid + rand() % 3500;


			}
			bomb[i].bombindex++;
			if (bomb[i].bombindex >= 0)
			{
				bomb[i].bombindex = 0;
			}
		}
	}
	if (i == 3){
		for (int i = 0; i < numberoffly; i++){
			enemy[i].flyx -= 8;
			if (enemy[i].flyx <= 0)
			{
				enemy[i].flyx = screenwid + rand() % 300;

			}
			enemy[i].flyindex++;
			if (enemy[i].flyindex >= 10)
			{
				enemy[i].flyindex = 0;
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (i == 7){
		if (isstart)
		{
			xball += dx;
			yball += dy;
			if (xball >= screenwid - 60 || xball <= 0){
				dx *= 9 - 10;
			}
			if (yball >= screenhei - 60 || yball <= 0)
			{
				dy *= (-1);
			}
			//// col ///////////
			for (int i = 0; i < totalbat; i++){
				if (batss[i].show){
					if (xball >= batss[i].x && xball <= batss[i].x + batss[i].dx)
					{
						if (yball >= batss[i].y && yball <= batss[i].y + batss[i].dy){
							batss[i].show = false;
							killscore += 5;
							batoff++;
							dy *= (-1);
						}
					}
					else if (yball >= batss[i].y && yball <= batss[i].y + batss[i].dy)
					{
						if (xball >= batss[i].x && xball <= batss[i].x + batss[i].dx){
							batss[i].show = false;
							killscore += 5;
							batoff++;
							dy *= (-1);
						}
					}
				}
			}
			////////////////////////////

			if (xball >= xboard - 20 && xball <= xboard + dxboard + 20 && yball >= yboard && yball <= yboard + dyboard + 30)
			{

				dy *= (-1);
			}
			else{
				if (yball < yboard)
				{
					killscore -= 2;
					restart();
					lifeindex += 1;
					if (lifeindex >= 5){

						lifeindex = 5;
						lifevisible = false;
						for (int i = 0; i < totalbat; i++){
							batss[i].show = false;
						}
						gameover = true;
					}
				}

			}
		}
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (i == 6){
		for (int i = 0; i < numberoflv3; i++){
			lv3[i].x -= 7;
			if (lv3[i].x <= 0)
			{
				lv3[i].x = screenwid + rand() % 3000;


			}
			lv3[i].index++;
			if (lv3[i].index >= 10)
			{
				lv3[i].index = 0;
			}
			////////////////

			////////////////
		}
	}
	if (i == 6){
		for (int i = 0; i < numberofboin; i++){
			boin[i].y -= 15;

			if (boin[i].y <= 0)
			{
				boin[i].y = screenhei + rand() % 2500;
			}
			boin[i].index++;
			if (boin[i].index >= 0)
			{
				boin[i].index = 0;
			}
		}
	}
}


void setheartvariables(){
	
		for (int i = 0; i < numberofheart; i++)
		{
			heart[i].heartx = screenwid + rand() % 2500;
			heart[i].hearty = 320 + rand() % 10;
			heart[i].heartindex = rand() % 6;
			heart[i].heartshow = true;
		}
	
	

}

void monstermove(){

	for (int i = 0; i < numberofmonster; i++)
	{

		if (menemy[i].monstershow)
		{
			iShowBMP2(menemy[i].monsterx, menemy[i].monstery, monsterenemy[menemy[i].monsterindex], 0);
		}
		else	if (menemy[i].monsterfightshow)
		{
			menemy[i].fightindex++;
			if (menemy[i].fightindex >= 3)
			{
				menemy[i].fightindex = 0;
			}
			iShowBMP2(menemy[i].monsterx, menemy[i].monstery, monstermellepic[menemy[i].fightindex], 0);

		}

	}
}
void monsterchange(){

}
void setmonstervatiables(){
	for (int i = 0; i < numberofmonster; i++)
	{

		menemy[i].monsterx = screenwid + rand() % 2000;
		menemy[i].monstery = 150;// +rand() % 10;
		menemy[i].monsterindex = rand() % 6;
		menemy[i].monstershow = true;
	}
}

void end(){
	if (gameover){ iShowBMP(0, 0, "bc\\end.bmp");
	iShowBMP2(600, 665, "bc\\scorebg.bmp", 0);
	int score = killscore + coinscore + heartscore - flyscore - bombscore;
	char buffer[50];
	sprintf_s(buffer, "%d", score);
	printf("%s", buffer);
	iText(657, 705, buffer, GLUT_BITMAP_HELVETICA_18);
	}
}
//all coll
void coll(){

	// fly //
	if (i == 3 && maincshow){
		for (int i = 0; i < numberoffly; i++){
			if (enemy[i].flyshow && maincshow){
				if ((maincx + 68 >= enemy[i].flyx&& maincx <= enemy[i].flyx + 75) && (maincy + jumpy >= enemy[i].flyy - 100 && maincy + jumpy <= enemy[i].flyy + 10)){
					lifeindex++;
					flyscore += 4;
					//enemy[i].flyshow = false;
					if (lifeindex >= 5){
						maincshow = false;
						lifeindex = 5;
						lifevisible = false;
						gameover = true;

					}
				}
			}
		}
	}
	// monster //
	if (i == 3 && maincshow){
		for (int i = 0; i < numberofmonster; i++){
			if (menemy[i].monstershow && maincshow){
				if ((maincx + 67 >= menemy[i].monsterx&& maincx <= menemy[i].monsterx + 135) && (maincy + jumpy >= menemy[i].monstery &&maincy + jumpy <= menemy[i].monstery + 135)){

					menemy[i].monstershow = false;
					menemy[i].monsterfightshow = true;
					menemy[i].monsterx = menemy[i].monsterx;
					menemy[i].monstery = menemy[i].monstery;
					lifeindex += 1;

					if (lifeindex >= 5){
						maincshow = false;
						lifeindex = 5;
						lifevisible = false;
						gameover = true;

					}
				}
			}
		}
	}
	// bomb //
	if (i == 3 && maincshow){
		for (int i = 0; i < numberofbomb; i++){
			if (bomb[i].bombshow && maincshow){
				if ((maincx + 67 >= bomb[i].bombx&& maincx <= bomb[i].bombx + 75) && (maincy + jumpy >= bomb[i].bomby &&maincy + jumpy <= bomb[i].bomby + 90)){
					lifeindex++;
					bombscore += 2;
					bomb[i].bombshow = false;
					if (lifeindex >= 5){
						maincshow = false;
						lifeindex = 5;
						lifevisible = false;
						gameover = true;


					}
				}
			}
		}
	}
	// heart //
	if (i == 3 && maincshow){
		for (int i = 0; i < numberofheart; i++){
			if (heart[i].heartshow && maincshow){
				if ((maincx + 68 >= heart[i].heartx&& maincx <= heart[i].heartx + 75) && (maincy + jumpy >= heart[i].hearty - 40 && maincy + jumpy <= heart[i].hearty + 0)){
					heart[i].heartshow = false;
					heartscore += 2;
					if (lifeindex == 5){ lifeindex = 4; }
					else if (lifeindex == 4){ lifeindex = 3; }
					else if (lifeindex == 3){ lifeindex = 2; }
					else if (lifeindex == 2){ lifeindex = 1; }
					else if (lifeindex == 1){ lifeindex = 0; }

				}
			}
		}
	}
	// fire to monster //
	if (i == 3 && fireshow){
		for (int i = 0; i < numberofmonster; i++){
			if (menemy[i].monstershow && fireshow){
				if ((firex + 2 >= menemy[i].monsterx&& firex <= menemy[i].monsterx + 135) && (firey >= menemy[i].monstery - 100 && firey <= menemy[i].monstery + 200)){
					menemy[i].monstershow = false;
					fireshow = false;
					killscore += 5;
					enemykilled += 1;
					menemy[i].monsterfightshow = false;
				}

			}
			if (menemy[i].monsterfightshow && fireshow){
				if ((firex + 4 >= menemy[i].monsterx&& firex <= menemy[i].monsterx + 135) && (firey >= menemy[i].monstery - 100 && firey <= menemy[i].monstery + 200)){
					menemy[i].monstershow = false;
					menemy[i].monsterfightshow = false;
					fireshow = false;
					killscore += 5;
					enemykilled += 1;
					menemy[i].monsterfightshow = false;
				}

			}

		}
	}
	// coin //
	if (i == 3 && maincshow){
		for (int i = 0; i < numberofcoin; i++){
			if (coin[i].coinshow && maincshow){
				if ((maincx + 67 >= coin[i].coinx&& maincx <= coin[i].coinx + 75) && (maincy + jumpy >= coin[i].coiny &&maincy + jumpy <= coin[i].coiny + 90)){
					coin[i].coinshow = false;
					coinscore += 10;
				}
			}
		}
	}
	// lv1 end logic//

	////////////////////////////////////////////////// lv 3 /////////////////////////////////
	if (i == 6 && targetshow){
		for (int i = 0; i < numberoflv3; i++){
			if (lv3[i].show&& targetshow){
				if ((p8x >= lv3[i].x&& p8x <= lv3[i].x + 75) && (p8y >= lv3[i].y - 100 && p8y <= lv3[i].y + 10)){
					killscore += 2;
					lv3[i].show = false;
					lv3enemykilled ++ ;
			    }
				else if ((ix < lv3[i].x && ix + 400 > lv3[i].x) && (iy-150  < lv3[i].y && iy + 600 > lv3[i].y)){

					lifeindex++;
					lv3[i].show = false;

					if (lifeindex >= 5){
						lifeindex = 5;
						lifevisible = false;
						gameover = true;


					}
				}
			}
		}

		for (int i = 0; i < numberofboin; i++){
			if (boin[i].show&& targetshow){
				if ((p8x >= boin[i].x&& p8x <= boin[i].x + 75) && (p8y >= boin[i].y - 100 && p8y <= boin[i].y + 10)){
					coinscore += 5;
					boin[i].show = false;
				}
			}
		}

	}
}


		
void endlevel(){
	if (i == 3)
	{
		if (enemykilled == 15){
			maincshow = true;
			
			if (i == 3 && maincshow){
				for (int i = 0; i < numberofmonster; i++){
					if (menemy[i].monstershow && maincshow){
						menemy[i].monstershow = false;
					}
				}
				for (int i = 0; i < numberofheart; i++){
					if (heart[i].heartshow && maincshow){
						heart[i].heartshow = false;
					}
				}
				for (int i = 0; i < numberofcoin; i++){
					if (coin[i].coinshow && maincshow){
						coin[i].coinshow = false;
					}
				}
				for (int i = 0; i < numberofbomb; i++){
					if (bomb[i].bombshow && maincshow){
						bomb[i].bombshow = false;
					}
				}
				for (int i = 0; i < numberoffly; i++){
					if (enemy[i].flyshow && maincshow){
						enemy[i].flyshow = false;
					}
				}
				i = 9;
				
			}
		

		}
	}
	if (i == 9 && maincshow){
		if ((maincx + 67 >= 1400 && maincx <= 1400 + 75) && (maincy + jumpy >= 150 && maincy + jumpy <= 150 + 90)){
			maincshow = false;
			
			i = 7;
		}
	}
	if (i == 7){
		if (batoff == 5){
			restart();
			if (i == 7){
				for (int i = 0; i < totalbat; i++){ batss[i].show = false; }
			}

			i = 11;
		}
	}
	 if (i == 11){
		 if ((ix < xboard && ix + 400 > xboard) && (iy - 150 < yboard && iy + 600 > yboard)){ 
			 i = 6;
			 targetshow = true; 
		 }
	
	 }
	 
	 if (i == 6){
		 if (lv3enemykilled == 15){
			 for (int i = 0; i < numberoflv3; i++){ lv3[i].show = false;  }
			 i = 10;
		 }
	 }
}

void bat(){
	int sumx = 50;
	int sumy = 500;
	for (int i = 0; i < totalbat; i++)
	{
		batss[i].x = sumx;
		batss[i].y = sumy;
		sumx += 200;
		if (sumx>1250){
			sumx = 50; sumy -= 100;
		}

	}
}
void lv3move(){
	if (i == 6){
		for (int i = 0; i < numberoflv3; i++)
		{

			if (lv3[i].show)
			{
				iShowBMP2(lv3[i].x, lv3[i].y, lv3enemypic[lv3[i].index], 0);

			}
		}
	}


}
void setlv3(){

	for (int i = 0; i < numberoflv3; i++)
	{
		lv3[i].x = screenwid + rand() % 3000;
		lv3[i].y = 150 + rand() % 350;
		lv3[i].index = rand() % 6;
		lv3[i].show = true;
	}


}


void boinmove(){
	if (i == 6){
		for (int i = 0; i < numberofboin; i++)
		{

			if (boin[i].show)
			{
				iShowBMP2(boin[i].x, boin[i].y, boinpic[boin[i].index], 0);
			}
		}
	}
}
void setboinvariable(){
	for (int i = 0; i < numberofboin; i++)
	{
		boin[i].x =  500 + rand() % 400;
		boin[i].y = screenhei + rand() % 2500;
		boin[i].index = rand() % 6;
		boin[i].show = true;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////
void iDraw()
{
	iClear();

	iShowBMP(0, 0, bc[0]);
	
	if (i == 0){
		iShowBMP(60, 450, bc[1]);//start

		iShowBMP(60, 310, bc[3]);//score
		iShowBMP(60, 240, bc[4]);//credit

		iShowBMP(60, 380, bc[2]);//controll

		iShowBMP(60, 170, bc[5]);//exit
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (i == 1){
		iClear();
		iShowBMP(0, 0, "bc\\credit.bmp");//credit

	}
	if (i == 2){
		iClear();
		iShowBMP(0, 0, "bc\\controlf.bmp");//controll
	}

	if (i == 4){
		iClear();
		
		iShowBMP(0, 0, "bc\\dd.bmp");//score
		iShowBMP2(560, 400, "bc\\redhs.bmp", 0);
		iShowBMP2(560,200, "bc\\index1.bmp", 0);



		iText(630, 450, "1st", GLUT_BITMAP_HELVETICA_18);
		iText(630, 420, "2nd", GLUT_BITMAP_HELVETICA_18);
		iText(630, 390, "3rd", GLUT_BITMAP_HELVETICA_18);
		iText(630, 360, "4th", GLUT_BITMAP_HELVETICA_18);
		iText(630, 330, "5th", GLUT_BITMAP_HELVETICA_18);
		
		int score = killscore + coinscore + heartscore - flyscore - bombscore;
		char buffer[50];
		sprintf_s(buffer, "%d", score);

		iText(690, 450, buffer, GLUT_BITMAP_HELVETICA_18);
		iText(690, 420, "50", GLUT_BITMAP_HELVETICA_18);
		iText(690, 390, "34", GLUT_BITMAP_HELVETICA_18);
		iText(690, 360, "10", GLUT_BITMAP_HELVETICA_18);
		iText(690, 330, "5", GLUT_BITMAP_HELVETICA_18);




		//////////////////////////////////////////
		/*int score = killscore + coinscore + heartscore - flyscore - bombscore;
		FILE *fp = fopen_s(fp,"bc\\score\\score.txt", "a");
		if (fp == NULL) {}
		else{
			fprintf(fp, "%d\n", score);
			fclose(fp);
		}*/






	}





	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	if (i == 5){
		iClear();
		iShowBMP(0, 0, "bc\\sd.bmp");

		iShowBMP2(680, 480, "bc\\lv1.bmp", 0);//lv1
		iShowBMP2(680, 380, "bc\\lv2.bmp", 0);
		iShowBMP2(680, 280, "bc\\lv3.bmp", 0);
		iShowBMP2(680, 180, "bc\\lv4.bmp", 0);

	}
		///////////////////level 1 screen/////////////////////
	if (i == 3){
		iClear();
		iShowBMP(0, 0, "bc\\v4.bmp");
		//renderbg();
		iShowBMP2(35, 685, "bc\\lv1.bmp", 0);
		iShowBMP2(600, 665, "bc\\scorebg.bmp", 0);
		//////////////////////
		int score = killscore + coinscore+heartscore-flyscore-bombscore;
		char buffer[50];
		sprintf_s(buffer, "%d", score);
		printf("%s", buffer);
		iText(657, 705, buffer, GLUT_BITMAP_HELVETICA_18);
		////////////////////////
		life();
		flymove();
		coinmove();
		bombmove();
		heartmove();
		monstermove();

		end();

		if (maincshow){
			if (jump){
				if (jumpUp){
					change();
					iShowBMP2(maincx, maincy + jumpy, mainjump[0], 0);

				}
				else
				{
					change();
					iShowBMP2(maincx, maincy + jumpy, mainjump[1], 0);
				}
			}
			else{
				if (!standpos)
				{
					iShowBMP2(maincx, maincy, mainc[maincIndex], 0);
					standcount++;
					if (standcount >= 20){
						standcount = 0;
						maincIndex = 0;
						standpos = true;
					}


				}
				else if (k == 1){ iShowBMP2(maincx, maincy, knife[knifeindex], 0); standpos = true; }
				else if (fireshow){
					iShowBMP2(maincx, maincy, "bc\\stand01.bmp", 0);
					iShowBMP2(firex, firey, firepic[0], 0); standpos = true;
				}

				else{ iShowBMP2(maincx, maincy, mains[standcount], 0); }

			}
		}
	}

			/////////////////// lv2 ///////////////////////////////////////
			if (i == 7)
			{
				iClear();
				iShowBMP(0, 0, "bc\\v5.bmp");
				iShowBMP2(35, 685, "bc\\lv2.bmp", 0);
				//iSetColor(r, g, b);
				//iFilledCircle(xball, yball, radiusball, 100);
				//iFilledRectangle(xboard,yboard,dxboard,dyboard);
				iShowBMP2(xboard, yboard, "bc\\bar.bmp", 0);
				iText(690, 199, "Press <Space> to Start", GLUT_BITMAP_HELVETICA_18);
				iShowBMP2(xball, yball, "bc\\kumra.bmp", 0);
				iShowBMP2(600, 665, "bc\\scorebg.bmp", 0);
				
				/////////////////////////////////////////////////////////////////////// 
				end();
				life();
				int score = killscore + coinscore + heartscore - flyscore - bombscore;
				char buffer[50];
				sprintf_s(buffer, "%d", score);
				printf("%s", buffer);
				iText(657, 705, buffer, GLUT_BITMAP_HELVETICA_18);
				///////////////////////////////////////////////////////////////////////
				for (int i = 0; i < totalbat; i++){
					if (batss[i].show){
						iShowBMP2(batss[i].x, batss[i].y,batpic[i], 0);
					}
				}

			}
			//////////////////////////////////////// lv 3 ////////////////////////////////////////
			if (i == 6){
				iClear();
				iShowBMP(0, 0, "bc\\sky.bmp");
				iShowBMP2(35, 685, "bc\\lv3.bmp", 0);
				iShowBMP2(ix, iy, "bc\\iceland.bmp", 0);
				lv3move();
				boinmove();
				if (targetshow){
					iShowBMP2(p8x, p8y, "bc\\target.bmp", 0);
				}
				 
				iShowBMP2(600, 665, "bc\\scorebg.bmp", 0);
				life();
				end();
				//////////////////////
				int score = killscore + coinscore + heartscore - flyscore - bombscore;
				char buffer[50];
				sprintf_s(buffer, "%d", score);
				printf("%s", buffer);
				iText(657, 705, buffer, GLUT_BITMAP_HELVETICA_18);
				////////////////////////
				int highscore(score);

			}
			//// lv4 ////
			if (i == 8)
			{
				iClear();
				iShowBMP(0, 0, "bc\\v10.bmp");
				//iShowBMP(0, 0, "bc\\v4.bmp");
				//iShowBMP2(35, 685, "bc\\lv4.bmp", 0);
				/*iShowBMP2(0, 0, "bc\\p1.bmp", 0);
				iShowBMP2(100, 0, "bc\\p2.bmp", 0);
				iShowBMP2(200, 0, "bc\\p3.bmp", 0);
				iShowBMP2(0, 100, "bc\\p4.bmp", 0);
				iShowBMP2(100, 100, "bc\\p5.bmp", 0);
				iShowBMP2(200, 100, "bc\\p6.bmp", 0);
				iShowBMP2(0, 200, "bc\\p7.bmp", 0);
				iShowBMP2(100, 200, "bc\\p8.bmp", 0);

				iShowBMP2(p1x, p1y, "bc\\p1.bmp", 0);
				iShowBMP2(p2x, p2y, "bc\\p2.bmp", 0);
				iShowBMP2(p3x, p3y, "bc\\p3.bmp", 0);
				iShowBMP2(p4x, p4y, "bc\\p4.bmp", 0);
				iShowBMP2(p5x, p5y, "bc\\p5.bmp", 0);
				iShowBMP2(p6x, p6y, "bc\\p6.bmp", 0);
				iShowBMP2(p7x, p7y, "bc\\p7.bmp", 0);
				iShowBMP2(p8x, p8y, "bc\\p8.bmp", 0);
				iShowBMP2(ex, ey, "bc\\bomb.bmp", 0);*/

			}

			if (i == 9)///////end logic lv 1 //////////
			{
				iClear();
				iShowBMP(0, 0, "bc\\v4.bmp");
				iShowBMP2(35, 685, "bc\\lv1.bmp", 0);
				iShowBMP2(1400, 150, "bc\\endkumra.bmp", 0);
				iShowBMP2(600, 665, "bc\\scorebg.bmp", 0);
				///////////////////////////////////////////////////////////////////////
				life();
				int score = killscore + coinscore + heartscore - flyscore - bombscore;
				char buffer[50];
				sprintf_s(buffer, "%d", score);
				printf("%s", buffer);
				iText(657, 705, buffer, GLUT_BITMAP_HELVETICA_18);
				///////////////////////////////////////////////////////////////////////
				if (maincshow){
					if (jump){
						if (jumpUp){
							change();
							iShowBMP2(maincx, maincy + jumpy, mainjump[0], 0);

						}
						else
						{
							change();
							iShowBMP2(maincx, maincy + jumpy, mainjump[1], 0);
						}
					}
					else{
						if (!standpos)
						{
							iShowBMP2(maincx, maincy, mainc[maincIndex], 0);
							standcount++;
							if (standcount >= 20){
								standcount = 0;
								maincIndex = 0;
								standpos = true;
							}


						}
						else if (k == 1){ iShowBMP2(maincx, maincy, knife[knifeindex], 0); standpos = true; }
						else if (fireshow){
							iShowBMP2(maincx, maincy, "bc\\stand01.bmp", 0);
							iShowBMP2(firex, firey, firepic[0], 0); standpos = true;
						}

						else{ iShowBMP2(maincx, maincy, mains[standcount], 0); }

					}
				}
			}
			if (i == 10){
				iShowBMP(0, 0, "bc\\congo.bmp");
				iShowBMP2(675, 30, "bc\\scorebg.bmp", 0);
				int score = killscore + coinscore + heartscore - flyscore - bombscore;
				char buffer[50];
				sprintf_s(buffer, "%d", score);
				printf("%s", buffer);
				iText(730, 70, buffer, GLUT_BITMAP_HELVETICA_18);
				iText(650, 120, "Press o to jump main menu ", GLUT_BITMAP_HELVETICA_18);
			}

			if (i == 11){   ////////////////// lv 2 end //////////////////

				iClear();
				iShowBMP(0, 0, "bc\\v5.bmp");
				iShowBMP2(35, 685, "bc\\lv2.bmp", 0);
				iShowBMP2(xboard, yboard, "bc\\bar.bmp", 0);
				iShowBMP2(xball, yball, "bc\\kumra.bmp", 0);
				iShowBMP2(ix, iy, "bc\\iceland2.bmp", 0);
				iShowBMP2(600, 665, "bc\\scorebg.bmp", 0);
				iText(690, 199, "Go Left Slowly", GLUT_BITMAP_HELVETICA_18);
				/////////////////////////////////////////////////////////////////////// 
				life();
				int score = killscore + coinscore + heartscore - flyscore - bombscore;
				char buffer[50];
				sprintf_s(buffer, "%d", score);
				printf("%s", buffer);
				iText(657, 705, buffer, GLUT_BITMAP_HELVETICA_18);
				///////////////////////////////////////////////////////////////////////



			}



		}
	
////////////////////////////////////////////////////////////// keys //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void iMouseMove(int mx, int my)
{
	
}

void iPassiveMouseMove(int mx, int my)
{
	if (i == 6){ p8x = mx-40; p8y = my-40; }
}

void iKeyboard(unsigned char key)
{
	if (key == 109)
	{
		if (musicon){
			musicon = false; if (!musicon)PlaySound(0, 0, 0);
		}
		else{ musicon = true; if (musicon)PlaySound("music\\1.wav", NULL, SND_LOOP | SND_ASYNC); }

	}

	if (key == '\b')
	{
		if (i == 1){ i = 0; }
		if (i == 2){ i = 0; }
		if (i == 5){ i = 0; }
		if (i == 3){ i = 5; }
		if (i == 4){ i = 0; }
		if (i == 6){ i = 5; }
		if (i == 7){ i = 5; }
		if (i == 8){ i = 5; }


	}

	if (key == '\o'){
		if (i == 10){ i = 0; }
	}

	if (key == 27){ exit(0); }//ese
	if (key == 97)//a
	{
		if (i == 3 || i == 9){
			if (maincx > 0){
				maincx -= 10;


				maincIndex++;

				if (maincIndex == 11){ maincIndex = 7; }
				standpos = false;
				front = false;
				back = true;
				bgchange();
			}
			
		}
	}
	if (key == 100)//d
	{
		if (i == 3 || i == 9){
			if (maincx < screenwid - 70){
				maincx += 10;

				maincIndex++;

				if (maincIndex >= 6){ maincIndex = 0; }
				standpos = false;
				front = true;
				back = false;
				bgchange();
			}
			
		}
	}
	if (key == 119)//w
	{
		if (i == 3 || i == 9){
			if (!jump){
				jump = true;
				jumpUp = true;
			}
		}
	}
	if (key == '\c')
	{
		if (i == 3 || i == 9){
			k = 1;
			knifeindex++;
			if (knifeindex >= 4){ knifeindex = 0; }
			standpos = true;
		}
	}

	if (key == 120)//x
	{
		if (i == 3 || i == 9){
			if (!fireshow){
				fireshow = true;
				firesound = true;

				firex = maincx + 105;
				if (jumpUp) { firey = maincy + jumpy + 100; }
				else { firey = maincy + 100; }
				if (firesound){
					PlaySound("music\\3.wav", NULL, SND_ASYNC);
				}

			}
		}

	}
	if (key == ' '){
		if (i == 7||i==11){
			if (!isstart){ isstart = true; }
		}
	}
}

void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_RIGHT)
	{
		if (i == 3||i==9){
			if (maincx < screenwid - 70){
				maincx += 10;
				maincIndex++;
				if (maincIndex >= 6){ maincIndex = 0; }
				standpos = false;
				front = true;
				back = false;
				bgchange();
			}
			
		}
		//////////////////////////
		if (i == 7||i==11){
			if (xboard <screenwid - dxboard){
				xboard += 20;
				if (!isstart)
				{
					xball += 20;
				}
			}
		}
		//////////////////////////
	}
	if (key == GLUT_KEY_LEFT)
	{
		if (i == 3 || i == 9){
			if (maincx > 0){
				maincx -= 10;
				maincIndex++;
				if (maincIndex == 11){ maincIndex = 7; }
				standpos = false;
				front = false;
				back = true;
				bgchange();
			}
		}
		//////////////////////////
		if (i == 7||i==11){
			if (xboard>0){
				xboard -= 20;
				if (!isstart)
				{
					xball -= 20;
				}
			}
		}
		//////////////////////////////////
	}
	if (key == GLUT_KEY_UP)
	{
		if (i == 3 || i == 9){
			if (!jump){
				jump = true;
				jumpUp = true;

			}
		}
		if (i == 6){}
	}
	if (key == GLUT_KEY_DOWN){
		if (i == 6){}
	}
}

void iMouse(int button, int state, int mx, int my)
{
	printf("%d.%d\n", mx, my);
	if (i == 0){//credit
		if (mx >= 60 && mx <= 183 && my >= 242 && my <= 295)
		{
			i++;
		}
	}
	if (i == 0){//exit
		if (mx >= 60 && mx <= 183 && my >= 175 && my <= 225)
		{
			exit(0);
		}
	}
	if (i == 0){//control
		if (mx >= 60 && mx <= 183 && my >= 385 && my <= 435)
		{
			i = 2;
		}
	}
	if (i == 0){//start
		if (mx >= 60 && mx <= 183 && my >= 454 && my <= 504)
		{
			i = 5;

		}
	}

	if (i == 0){//highscrore
		if (mx >= 60 && mx <= 183 && my >= 312 && my <= 364)
		{
			i = 4;
		}
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (i == 5){//lv1
		if (mx >= 686 && mx <= 820 && my >= 485 && my <= 526)
		{
			i = 3;
		}
	}
	if (i == 5){//
		if (mx >= 686 && mx <= 820 && my >= 385 && my <= 436)
		{
			i = 7;
			
			
		}
	}
	if (i == 5){//
		if (mx >= 686 && mx <= 820 && my >= 285 && my <= 326)
		{
			i = 6;
			targetshow = true;
		}
	}
	if (i == 5){//
		if (mx >= 686 && mx <= 820 && my >= 185 && my <= 226)
		{
			i = 8;
		}
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

	
	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}

}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{     




	iSetTimer(1, endlevel);
	iSetTimer(20, bat);
		iSetTimer(100, coll); //all coll
		

	//	iSetTimer(20, monsterchange);
		setmonstervatiables();
		iSetTimer(10, fireing);
	 //   setbg();
	//	iSetTimer(20, flychange);
		setflyvatiables();
	//	iSetTimer(20, bombchange); 
		setbombvariables();
		
	//   iSetTimer(20, coinchange);
		setlv3();
		setboinvariable();
		setcoinvariables();
		setheartvariables(); 
		iSetTimer(10, heartchange);// all change
		if (musicon)PlaySound("music\\1.wav", NULL, SND_LOOP | SND_ASYNC);
	//	if (gameovermusic){ PlaySound("music\\1.wav", NULL, NULL | SND_ASYNC); }
		iInitialize(screenwid, screenhei, "Champion");
		iStart();
		return 0;

}
