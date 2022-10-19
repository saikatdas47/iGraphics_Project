
#ifndef SCORE_INCLUDED
#define SCORE_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 

#include<iostream>
#include "Variables.h"
#include<stdio.h>
#include<fstream>
using namespace std;

int killscore = 0;
int coinscore = 0;
int heartscore = 0;
int flyscore = 0;
int bombscore = 0;




char  ch;


/*FILE *file;
char pt[10], Player_Name[30], High_score[10];
int len = 0;*/

///for start new game
/*void filled_new_game()
{
	file = fopen("point.txt", "r");
	for (i = 0; i<21; i++)
	{
		for (j = 0; j<19; j++)
		{
			fscanf(file, "%d", &Point[i][j]);
		}
	}
	fclose(file);
	point = 0, life = 3, p300 = 0, p750 = 0, p1500 = 0, p2000 = 0, c = 0;
	for (i = 0; i<len; i++)
		Player_Name[i] = '\0';
	for (i = 0; i<10; i++)
		pt[i] = '\0';
	len = 0, save_game = 0;
}








void savedGame()
{
	file = fopen("load_game.txt", "w");
	fprintf(file, "1 ");
	fprintf(file, "%d %d ", point, life);
	fprintf(file, "%d %d %d %d ", p300, p750, p1500, p2000);
	fprintf(file, "%d %d ", Dead, Dc);
	fprintf(file, "%d %d %d ", fruit, fflug, ffcount);
	fprintf(file, "%lf %lf ", ghost_speed, Pacman_Speed);
	fprintf(file, "%lf %lf %d ", Ball_X, Ball_Y, Ball_Direction);
	fprintf(file, "%lf %lf %d ", Binky_X, Binky_Y, Binky_Direction);
	fprintf(file, "%lf %lf %d ", Inky_X, Inky_Y, Inky_Direction);
	fprintf(file, "%lf %lf %d ", Pinky_X, Pinky_Y, Pinky_Direction);
	fprintf(file, "%lf %lf %d ", Clyde_X, Clyde_Y, Clyde_Direction);
	fprintf(file, "%d ", Power_Mood);
	fprintf(file, "%d %d %d ", Binky_Mood, Binky_Power_Mood, btf);
	fprintf(file, "%d %d %d ", Inky_Mood, Inky_Power_Mood, itf);
	fprintf(file, "%d %d %d ", Pinky_Mood, Pinky_Power_Mood, ptf);
	fprintf(file, "%d %d %d ", Clyde_Mood, Clyde_Power_Mood, ctf);
	if (Power_Mood == 1)
	{
		fprintf(file, "%d %d ", Time, ghost_count);
		fprintf(file, "%d %d ", flug, fcount);
		if (btf == 1)
		{
			fprintf(file, "%lf %lf %d ", btx, bty, btd);
		}
		if (itf == 1)
		{
			fprintf(file, "%lf %lf %d ", itx, ity, itd);
		}
		if (ptf == 1)
		{
			fprintf(file, "%lf %lf %d ", ptx, pty, ptd);
		}
		if (ctf == 1)
		{
			fprintf(file, "%lf %lf %d ", ctx, cty, ctd);
		}
	}
	fclose(file);
	file = fopen("load_point.txt", "w");
	fprintf(file, "%d ", c);
	for (i = 0; i<21; i++)
	{
		for (j = 0; j<19; j++)
		{
			fprintf(file, "%d ", Point[i][j]);
		}
	}
	fclose(file);
}

///load save game
void loadGame()
{
	file = fopen("load_game.txt", "r");
	fscanf(file, "%d", &save_game);
	fscanf(file, "%d %d ", &point, &life);
	fscanf(file, "%d %d %d %d ", &p300, &p750, &p1500, &p2000);
	fscanf(file, "%d %d ", &Dead, &Dc);
	fscanf(file, "%d %d %d ", &fruit, &fflug, &ffcount);
	fscanf(file, "%lf %lf ", &ghost_speed, &Pacman_Speed);
	fscanf(file, "%lf %lf %d ", &Ball_X, &Ball_Y, &Ball_Direction);
	fscanf(file, "%lf %lf %d ", &Binky_X, &Binky_Y, &Binky_Direction);
	fscanf(file, "%lf %lf %d ", &Inky_X, &Inky_Y, &Inky_Direction);
	fscanf(file, "%lf %lf %d ", &Pinky_X, &Pinky_Y, &Pinky_Direction);
	fscanf(file, "%lf %lf %d ", &Clyde_X, &Clyde_Y, &Clyde_Direction);
	fscanf(file, "%d ", &Power_Mood);
	fscanf(file, "%d %d %d ", &Binky_Mood, &Binky_Power_Mood, &btf);
	fscanf(file, "%d %d %d ", &Inky_Mood, &Inky_Power_Mood, &itf);
	fscanf(file, "%d %d %d ", &Pinky_Mood, &Pinky_Power_Mood, &ptf);
	fscanf(file, "%d %d %d ", &Clyde_Mood, &Clyde_Power_Mood, &ctf);
	if (Power_Mood == 1)
	{
		fscanf(file, "%d %d ", &Time, &ghost_count);
		fscanf(file, "%d %d ", &flug, &fcount);
		if (btf == 1)
		{
			fscanf(file, "%lf %lf %d ", &btx, &bty, &btd);
		}
		if (itf == 1)
		{
			fscanf(file, "%lf %lf %d ", &itx, &ity, &itd);
		}
		if (ptf == 1)
		{
			fscanf(file, "%lf %lf %d ", &ptx, &pty, &ptd);
		}
		if (ctf == 1)
		{
			fscanf(file, "%lf %lf %d ", &ctx, &cty, &ctd);
		}
	}
	fclose(file);
	file = fopen("load_point.txt", "r");
	fscanf(file, "%d ", &c);
	for (i = 0; i<21; i++)
	{
		for (j = 0; j<19; j++)
		{
			fscanf(file, "%d ", &Point[i][j]);
		}
	}
	fclose(file);
	if (Power_Mood == 0)
	{
		Time = 0, flug = 0, ghost_count = 0, fcount = 0;
	}
	for (i = 0; i<len; i++)
		Player_Name[i] = '\0';
	for (i = 0; i<10; i++)
		pt[i] = '\0';
	len = 0, save_game = 0;
	if (sound)
		PlaySound("music\\pacman_beginning.wav", NULL, SND_ASYNC);
	pa_in = 0, pi_in = 0, bi_in = 0, in_in = 0, cl_in = 0, T = 0;
}

typedef struct
{
	char name[30];
	char score[10];
} Highscore;
Highscore h[11];

void getHighscore()
{
	file = fopen("highscore.txt", "r");
	for (i = 0; i<10; i++)
	{
		fgets(h[i].name, 30, file);
	}
	for (i = 0; i<10; i++)
	{
		fgets(h[i].score, 10, file);
	}
	fclose(file);
}

void putHighscore()
{
	file = fopen("highscore.txt", "w");
	for (i = 0; i<10; i++)
	{
		fputs(h[i].name, file);
	}
	for (i = 0; i<10; i++)
	{
		fputs(h[i].score, file);
	}
	fclose(file);
}

void Sort_Highscore()
{
	char t1[10], t2[30];
	for (i = 0; i<11; i++)
	{
		for (j = i + 1; j<11; j++)
		{
			if (atoi(h[i].score)<atoi(h[j].score))
			{
				strcpy(t1, h[i].score);
				strcpy(t2, h[i].name);
				strcpy(h[i].score, h[j].score);
				strcpy(h[i].name, h[j].name);
				strcpy(h[j].score, t1);
				strcpy(h[j].name, t2);
			}
		}
	}
}

*/







/*int score = killscore + coinscore + heartscore - flyscore - bombscore;

ofstream MyFile("bc\\score\\filename.txt");

// Write to the file
MyFile << score;

// Close the file
MyFile.close();*/
 //void scoreingame(){ iText(657, 705, buffer, GLUT_BITMAP_HELVETICA_18); }

/*void scoreinscore(){
	int i, x, y;
	ofstream myfile;
	myfile.open("example1.txt");
	for (int j; j < 3; j++)
	{
		myfile << i;
		myfile << " " << x;
		myfile << " " << y << endl;
		i++;
		x = x + 2;
		y = x + 1;
	}
	myfile.close();
}*/
/*iText(690, 450, "", GLUT_BITMAP_HELVETICA_18);
iText(690, 420, "5454", GLUT_BITMAP_HELVETICA_18);
iText(690, 390, "5454", GLUT_BITMAP_HELVETICA_18);
iText(690, 360, "5454", GLUT_BITMAP_HELVETICA_18);
iText(690, 330, "5454", GLUT_BITMAP_HELVETICA_18);
//
*/


	/*int len;
	int all_scores[100], max = 10;
	char score_text[100], c;
	class gamescores{
	public:
		int score;
	};
	gamescores gscore[100];
	char* stringConverter(int killPoint){
		char *ch = new char[200];
		itoa(killPoint, ch, 10);
		return ch;
	}
	void highscore(int kills){
		FILE *fp = fopen("images\\Score\\score.txt", "a");
		if (fp == NULL) {}
		else{
			fprintf(fp, "%s\n", stringConverter(kills));
			fclose(fp);
		}
	}
	void showScore(){
		int x = 100, y = 650;
		for (int i = 0; i <len; i++){
			cout << gscore[i].score << endl;
			strcpy(score_text, stringConverter(gscore[i].score));
			iSetColor(255, 0, 0);
			iText(x, y, score_text, GLUT_BITMAP_TIMES_ROMAN_24);
			y -= 50;
			max--;
			if (max <= 0) break;
		}
	}

	void highScores(){
		FILE* fp;
		//char str[50];
		fp = fopen("images\\Score\\score.txt", "a+"); // reading the file in append mode
		//string scores;
		int i = 0;

		if (NULL == fp) {
			printf("file can't be opened \n");
		}

		while (!feof(fp)){
			fscanf(fp, "%d", &gscore[i++].score);
		}
		fclose(fp);
		len = i; int a;


		for (int i = 0; i < len - 1; i++){
			for (int j = i + 1; j < len; j++){
				if (gscore[i].score < gscore[j].score){
					a = gscore[i].score;
					gscore[i].score = gscore[j].score;
					gscore[j].score = a;
				}
			}
		}
	}
	void scoreCounter(){
		iSetColor(255, 0, 0);
		iText(1400, 750, "Score :", GLUT_BITMAP_HELVETICA_18);
		iText(1480, 750, stringConverter(killScore), GLUT_BITMAP_HELVETICA_18);
	}*/

#endif

	//int score = 0;
	/*
	string scorestring = to_string(*playerscoreptr);
	char scoretext[100];
	strcpy_s(scoretext, scorestring.c_str());
	itext(111, 121, scoretext, GULT_BITMAP_TIMES_ROMAN_24);
	*/
	/*void highscores(){
	FILE *fp = fopen("images\\Score\\score.txt", "r");
	int j = 0;
	while (!feof(fp)){
	fgets(playernames[j], 500 , fp);
	fgets(scores[j], 500, fp);
	}

	char ch; int i = 0, k = 0, j = 0 ;
	while ((ch = fgetc(fp)) != EOF)
	cout << "!" << ch << "! ";
	cout <<"\n";
	while ((ch = fgetc(fp)) != EOF){
	//ut << i << "@\n";
	if (ch == '\n'){
	k = 0;
	if (i == 0) i = 1;
	else if (i == 1) {
	i = 0; j++;
	}
	cout << "!!\n";
	}
	if (i == 0){
	playernames[j][k] = ch;
	k++;
	}
	else{
	scores[j][k] = ch;
	k++;
	}
	//cout << j << "\n";
	//cout << playernames[j] << " " << scores[j] << endl;
	//cout << ch << endl;
	}

	fclose(fp);
	tem = j;
	if (i>10) FILE *fp = fopen("images\\Score\\score.txt", "w");
	}*/
	/*void showHighScore(){

	FILE* fp;
	char str[50];
	fp = fopen("images\\Score\\score.txt", "a+"); // reading the file in append mode
	string scores;
	int all_scores[100];
	int i = 0;

	if (NULL == fp) {
	printf("file can't be opened \n");
	}


	while (fgets(str, 50, fp) != NULL) {
	//printf("%s", str);
	//scores += str;
	if (str != "\n"){
	all_scores[i++] = atoi(str); //converting the string into integer and storing it in an array

	}
	}
	fclose(fp);
	int len = i, a;

	//sorting in descending order to determine high scores...

	for (i = 0; i < len; ++i){
	for (int j = i + 1; j < len; ++j)
	{
	if (all_scores[i] < all_scores[j])
	{
	a = all_scores[i];
	all_scores[i] = all_scores[j];
	all_scores[j] = a;
	}
	}

	}




	int space = 100, max_scores = 10;
	char score_text[1000], c;

	for (int i = 0; i < len; i++){
	strcpy_s(score_text, stringConverter(all_scores[i])); // converting the ints to string first and then char array
	iText(screenWidth / 2 - 50, screenHeight - (space), score_text, GLUT_BITMAP_TIMES_ROMAN_24); // rendering it on display
	space += 30; // space for the next score
	max_scores--; // if it reaches 0, it means total 10 scores have been painted
	if (max_scores <= 0){
	break;
	}

	}


	}*/
	//sorting in descending order to determine high scores...

	/*for (i = 0; i < len-1; i++){
	for (int j = i + 1; j < len; j++)
	{
	if (all_scores[i] < all_scores[j])
	{
	a = all_scores[i];
	all_scores[i] = all_scores[j];
	all_scores[j] = a;
	}
	}

	}*/
	/*while (fgets(str, 50, fp) != NULL) {
	//printf("%s", str);
	//scores += str;
	if (str != "\n"){
	all_scores[i++] = atoi(str); //converting the string into integer and storing it in an array
	}
	}*/