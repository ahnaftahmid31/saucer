#pragma once
  #include<stdio.h>
  #include"motion.h"
  #define motion_h

	typedef struct{
		int x;
		int y;
	}shift;

	typedef struct{
		int x;
		int y;
		int no;     // number 
		int flag;   // flag value
		int lives;  //ship lives   
		int h, w; // height and weight
		int start, over, come, go;
		int lvl;
		char text[40];
		shift shift;
	}shiptype;

	typedef struct{
		char link[200];
		int no;
		int x;
		int y;
		int id;
		int t; //t = time for how much longer the explosion will be showed
	}gfx;	// gfx = graphics , gfx takes input of images that will be showed

	shiptype ship;
	shiptype star;
	shiptype enemy[20], en;
	shiptype enemy2[20], en2;
	shiptype bullet[60], bull;
	shiptype bullet2[60];
	shiptype enbullet[50];
	shiptype bsbullet[50];
	shiptype boss[5], bs; // 4 ta boss
	shiptype firstpage;
	shiptype games;
	shiptype highscore;
	shiptype hs[6];

	gfx ismallex[13]; // i = image 
	gfx ibigex[15];
	gfx ienex[13];
	gfx iship;
	gfx ien[10];
	gfx isaucer;
	gfx iboss[5];
	gfx ibullet;
	gfx ibg[5]; // bg = backgroud;
	gfx istar;
	gfx ilevel;
	gfx igover;


	int tym, tym2, x, n, gametime, c, bonus, dir, phase; // dir = direction
	int frate; // fire rate
	int shit, dhat;
	int i, j, k, bosstime;
	int score, temp, somoy;
	int ara[5];

	char scoreshow[10];
	char livesshow[5];


