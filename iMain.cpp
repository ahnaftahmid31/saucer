#pragma warning(disable:4996)
# include "iGraphics.h"
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include"variables.h" //variables( mainly structures..)
#include"loadgraphics.h" // loads images
#include"check.h"
#include"level.h"
#include"icoll.h"
#include"highscore.h"



int id, bx = 0, by = 0, bx2 = 964, id2;


void guli();
void menu();
void guli();
void gamestart();
void game();
void enemymove();
void collision();
void collision_render();


void iDraw()
{
	iClear();
	//first page or main menu
	
	if (firstpage.flag == 1) {
		iShowBMP(0, 0, "bg//first.bmp");
	}
	if (games.start == 1){
		//moving background
		id = iLoadImage("bg//bg1.bmp");
		iShowImage(bx, by, 966, 644, id);
		bx--;
		if (bx == -964) bx = 964;
		id2 = iLoadImage("bg//bg2.bmp");
		iShowImage(bx2, by, 966, 644, id2);
		bx2--;
		if (bx2 == -964) bx2 = 964;
	
		//gulis .. ibullet = image of bullet ..
		for (i = 1; i <= bull.no; i++){
			if (bullet[i].flag == 1)
			{
	
				iShowBMP2(bullet[i].x, bullet[i].y, ibullet.link, 0);
				iShowBMP2(bullet2[i].x, bullet2[i].y, ibullet.link, 0);
			}
		}

		//spaceship
		if (ship.flag == 0){
			iShowBMP2(ship.x, ship.y, iship.link, 0);
		}
	
		//showing which level
		iSetColor(255, 255, 255);
		if (games.lvl == 1)
		{
			iText(400, 320, "LEVEL 1", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		//star
		if (star.flag == 1){
			iShowBMP2(istar.x, istar.y, istar.link, 0);
		}
		//enemyship
		for (i = 1; i <= en.no; i++){
			if (enemy[i].flag == 1)
				iShowBMP2(enemy[i].x, enemy[i].y, isaucer.link, 0);
		}

		//boss
		if (boss[1].flag == 1){
			iShowBMP2(boss[1].x, boss[1].y, iboss[1].link, 0);
		}

		//collsion 

		if (ship.flag > 0) {
			iShowBMP2(iship.x, iship.y, ismallex[iship.no].link, 0);
		}
		for (i = 1; i < 10; i++){
			if (ien[i].t > 0){
				iShowBMP2(ien[i].x, ien[i].y, ienex[ien[i].no].link, 0);
			}
		}
		if (bosstime > 0){
			iShowBMP2(iboss[1].x, iboss[1].y, ibigex[iboss[1].no].link, 0);
		}
		// score showing
		itoa(score, scoreshow, 10);
		itoa(ship.lives, livesshow, 10);
		
		iText(650, 580, "Your Score  ", GLUT_BITMAP_HELVETICA_18);
		iText(770, 580, scoreshow, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(650, 610, "Your Life  ", GLUT_BITMAP_HELVETICA_18);
		iText(770, 610, livesshow, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (games.over == 1){
		iShowBMP(0, 0, igover.link);
		iSetColor(0, 0, 0);
		iText(400, 250, "Your Score  ", GLUT_BITMAP_HELVETICA_18);
		iText(500, 250, scoreshow, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (highscore.flag == 1){

		iSetColor(0, 0, 0);
		iFilledRectangle(0, 0, 1000, 640);
		
		for (i = 4; i >= 0; i--){
			itoa(ara[i], hs[i].text, 10);
		}
		iSetColor(255, 255, 255);
		iText(400, 500, hs[4].text, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(400, 400, hs[3].text, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(400, 300, hs[2].text, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(400, 200, hs[1].text, GLUT_BITMAP_TIMES_ROMAN_24); 
		iText(400, 100, hs[0].text, GLUT_BITMAP_TIMES_ROMAN_24);
		
	}
	
}

void iPassiveMouseMove(int mx, int my)
{
	ship.x = mx - ship.w / 2;
	ship.y = my - 3 * ship.h / 4;
	// ship does not go out of window
	if (ship.x <= 1) ship.x = 1;
	if (ship.y <= 1) ship.y = 1;
	if (ship.x + ship.w >= 999) ship.x = 999 - ship.w;
	if (ship.y + ship.h >= 639) ship.y = 639 - ship.h;
}

void iMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("%d %d\n", mx, my);
		if (mx >= 242 && mx <= 242 + 474 && firstpage.flag == 1){ // game start
			if (my >= 449 && my <= 509){
				games.start = 1;
				firstpage.flag = 0;
				games.over = 0;
				highscore.flag = 0;
				gamestart();
				printf("clicked");
			}
		}
		if (mx >= 242 && mx <= 242 + 474 && firstpage.flag == 1){ // high score
			if (my >= 367 && my <= 429){
				games.start = 0;
				firstpage.flag = 0;
				games.over = 0;
				highscore.flag = 1;
				high_score();

			}
		}
		//instruction x --> 241 y --> 283 , x --> 733 y --> 342
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

void iKeyboard(unsigned char key)
{
	if (key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
	}
	if (key == 'r')
	{
		iResumeTimer(0);
	}
	//place your codes for other keys here
	if (key == 'n'){
		if (games.over == 1){
			games.start = 0;
			firstpage.flag = 1;
			games.over = 0;
			highscore.flag = 0;
		}
		if (highscore.flag == 1){
			games.start = 0;
			firstpage.flag = 1;
			games.over = 0;
			highscore.flag = 0;

		}
	}
}

void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}

void guli(){
	if (games.start == 1){
		j++;
		if (j % frate == 0 && ship.flag == 0) {
			if (k >= bull.no){
				k = 0;
			}
			k++;
			set_selected_bullet_ini_pos(k);
			if (j == 500){
				j = 0;
			}
		}

		for (i = 1; i <= bull.no; i++){
			if (bullet[i].flag == 1){
				bullet_shift_x;
			}
			if (bullet[i].x > 1050) {
				bullet[i].flag = 0;
			}
		}
	}
}

void enemymove() {
	if (games.start == 1){
		for (i = 1; i <= en.no; i++){
			if (enemy[i].flag == 1){
				if (dir == 1){
					enemy[i].x -= en.shift.x;
					if (enemy[i].x < 0){
						enemy[i].flag = 0;

					}
				}

				if (dir == -1){
					enemy[i].x += en.shift.x;
					if (enemy[i].x > 1000){
						enemy[i].flag = 0;
					}
				}

			}
		}
		if (star.flag == 1) {
			istar.x--;
			if (istar.x <= 0) star.flag = 0;
		}
		if (phase == 4){

			for (i = 1; i <= en.no; i++){
				enemy[i].y += enemy[i].shift.y;
				if (enemy[i].y >= 420)
				{
					enemy[i].shift.y = -6;

				}
				if (enemy[i].y <= 220) {
					enemy[i].shift.y = 6;

				}
			}
		}
		if (bs.come == 1) {
			for (i = 1; i <= bs.no; i++){
				boss[1].x -= 10;
				if (boss[1].x == 800) bs.come = 0;
			}
		}
		if (bs.go == 1){
			for (i = 1; i <= bs.no; i++){
				boss[1].x -= 10;
				if (boss[1].x == 00){
					bs.go = 0;
					boss[i].flag = 0;
				}
			}
		}
		if (boss[1].flag == 1 && bs.come == 0){
			if (bs.go == 0) {
				if (boss[1].x > 901 || boss[1].x < 600) boss[1].shift.x = -boss[1].shift.x;
				boss[1].x += boss[1].shift.x;
			}
			if (boss[1].y > 320 || boss[1].y < 100) boss[1].shift.y = -boss[1].shift.y;
			
			boss[1].y += boss[1].shift.y;

		}
	}
}

void collision(){
	if (games.start == 1){
		for (i = 1; i <= bull.no; i++)
		{
			for (c = 1; c <= en.no; c++){
				if (check_en_bullet_flag){
					if (check_en_bullet_x){
						if (check_en_bullet_y){
							enemy[c].flag = 0;
							bullet[i].flag = 0;
							score += 10;
							icoll_en(c);
							if (phase == 2){
								bonus++;
								if (bonus == 6) {
									istar.x = enemy[c].x;
									istar.y = enemy[c].y;
									star.flag = 1;
									bonus = 0;
								}
							}
						}
					}
				}
			}
			for (c = 1; c <= bs.no; c++){
				if (check_bs_bullet_flag){
					if (check_bs_bullet_x){
						if (check_bs_bullet_y){
							boss[c].lives--;
							score += 10;
							bullet[i].flag = 0;
						}
					}
					if (boss[c].lives <= 0) {
						boss[c].flag = 0;
						bosstime = 48;
						iboss[c].no = 1;
						iboss[c].x = boss[c].x;
						iboss[c].y = boss[c].y;
					}
				}
			}
		}
		for (i = 1; i <= en.no; i++){
			if (check_en_flag){
				if (check_en_ship_x){
					if (check_en_ship_y){
						ship.lives--;
						score += 5;
						enemy[i].flag = 0;
						icoll_ship;
						icoll_en(i);
						if (phase == 2) bonus++;
					}
				}
			}
		}
		for (i = 1; i <= bs.no; i++)
		{
			if (check_bs_flag){
				if (check_bs_ship_x){
					if (check_bs_ship_y){
						ship.lives--;
						score += 5;
						boss[i].lives -= 100;
						icoll_ship;
					}
				}
			}
		}
		if (check_star_flag){
			if (check_star_ship_x){
				if (check_star_ship_y){
					frate -= 6;
					score += 20;
					star.flag = 0;
				}
			}
		}
	}
}

void collision_render(){
	if (games.start == 1){
		icoll_render_ship(5); // 4 meaning 4 ms por por image gulo change hobe
		icoll_render_en(5);
		icoll_render_boss;
	}
}

void somoycount(){
	somoy++;
}

void game(){
	if (games.start == 1){
		gametime++;
		//level 1
		if (gametime >= 0 && gametime <= 100) games.lvl = 1;
		//phase 1
		if (gametime == 100){
			games.lvl = 0;
			set_level1_phase1;
		}
		//phase 2
		if (gametime == 500){
			set_level1_phase2;
		}
		// phase 3
		if (gametime == 1000) {
			set_level1_phase3;
		}
		//phase 4

		if (gametime == 1500){
			set_level1_phase4;

		}

		//phase 5
		if (gametime == 2000) {
			en.no = 0;
			for (i = 1; i <= 10; i++) enemy[i].shift.y = 6;
		}
		if (gametime >= 2000 && gametime < 2600){
			set_level1_phase5;
		}
		//phase 6
		if (gametime == 2600){
			set_level1_phase6;
		}
		if (gametime >= 2600 + 5* 100){
			if (boss[1].flag == 1){
				bs.go = 1;
			}
		}
		//checking if game is over or not
		if (boss[1].lives <= 0 && boss[1].flag == 0 && gametime >= 2600 || ship.lives <= 0){
			if (temp == 0) temp = gametime;
			if (gametime == temp + 48){
				games.start = 0;
				firstpage.flag = 0;
				games.over = 1;
				highscore.flag = 0;
				high_score();
			}
		}
	}
}

void gamestart(){
	en_shift_y;                        //sets enemy[all].shift.y = 6
	set_all_bullet_flag_0;
	set_all_bullet_ini_pos;
	j = 0;
	k = 0;
	bull.no = 55;
	bull.shift.x = 17;
	gametime = 0;
	time_t t;
	srand((unsigned)time(&t));
	ship.w = 60;
	ship.h = 49;
	tym = 1;
	temp = 0;
	shit = 0;
	dhat = 1;
	en.no = 0;
	bs.no = 0;
	bonus = 0;
	frate = 10;
	boss[1].flag = 0;
	boss[1].lives = 200;
	boss[1].shift.x = 7;
	ship.lives = 3;
	boss[1].shift.y = 7;
	en.shift.x = 10;
	ship.flag = 0;
	score = 0;
	
}


int main()
{
	loadthemall;
	iInitialize(1000, 640, "Saucer");
	iStart();
	return 0;
}

/* short forms:

enemy --> en
boss --> bs
graphics --> gfx
image --> i___
collision --> coll
highscore --> hs

*/