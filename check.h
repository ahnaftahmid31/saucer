#define swap(a2,b2)   int temp=a2 ; a2=b2 ; b2=temp
#pragma once
#include"variables.h"
#include"enemyship.h"
//playerslife = 10;
int col_ball_plan(int shipx,int shipy,int planx,int plany)
{
       if(shipy <= plany +95  && shipx <= planx +100  &&  shipy  >= plany-22   &&  shipx>= planx -2)
            {
				return 1;
			}
	   else 
			{
				return 0;
			}
}
int col_bullet_ball(int bulletx[],int bullety[],int source[] ,int i,int shipx ,int shipy)
{
	int l;
	  for( l= i-100; l <= i ; l++)
			{
				if( bulletx[l] >= shipx -15  &&  bullety[l] >= shipy -15 &&  bulletx[l] <=shipx + 100  &&  bullety[l]<=shipy + 95  &&  source[l]!=0)
					{
						return l;
					}
			}
	return 0;
}


//ahnaf's part

// collision with enemy ship algo en = enemy , ship = player's ship

#define check_en_flag enemy[i].flag == 1 && ship.flag == 0 // every flag checking will include ship.flag
#define check_en_ship_x ship.x >= enemy[i].x && ship.x <= enemy[i].x + 59 || ship.x + ship.w >= enemy[i].x && ship.x + ship.w <= enemy[i].x + 59 && enemy[i].x <= 980
#define check_en_ship_y ship.y >= enemy[i].y && ship.y <= enemy[i].y + 35 || ship.y + ship.h >= enemy[i].y && ship.y + ship.h <= enemy[i].y + 35

//	collision with boss ship algo ship = player's ship, bs = boss

#define check_bs_flag boss[i].flag == 1 && ship.flag == 0
#define check_bs_ship_x ship.x >= boss[i].x && ship.x <= boss[i].x + 114 || ship.x + ship.w >= boss[i].x && ship.x + ship.w <= boss[i].x + 114 && boss[i].x <= 980
#define check_bs_ship_y ship.y >= boss[i].y && ship.y <= boss[i].y + 152 || ship.y + ship.h >= boss[i].y && ship.y + ship.h <= boss[i].y + 152

// collision with bullet and enemyship

#define check_en_bullet_flag bullet[i].flag == 1 && enemy[c].flag == 1 && ship.flag == 0
#define check_en_bullet_x bullet[i].x + 25 >= enemy[c].x && bullet[i].x + 25 <= enemy[c].x + 59 && enemy[c].x <= 980
#define check_en_bullet_y bullet2[i].y <= enemy[c].y + 35 && bullet2[i].y >= enemy[c].y || bullet[i].y + 7 <= enemy[c].y + 35 && bullet[i].y + 7 >= enemy[c].y

// collision with bullet and bossships

#define check_bs_bullet_flag boss[c].flag == 1 && bullet[i].flag == 1 && ship.flag == 0
#define check_bs_bullet_x bullet[i].x + 25 > boss[c].x && bullet[i].x + 25 < boss[c].x + 114 && boss[c].x <= 980
#define check_bs_bullet_y bullet2[i].y <= boss[c].y + 152 && bullet2[i].y >= boss[c].y || bullet[i].y + 7 <= boss[c].y + 152 && bullet[i].y + 7 >= boss[c].y

#define check_star_flag star.flag == 1 && ship.flag == 0 // every flag checking will include ship.flag
#define check_star_ship_x ship.x >= istar.x && ship.x <= istar.x + 54 || ship.x + ship.w >= istar.x && ship.x + ship.w <= istar.x + 54 && istar.x <= 980
#define check_star_ship_y ship.y >= istar.y && ship.y <= istar.y + 54 || ship.y + ship.h >= istar.y && ship.y + ship.h <= istar.y + 54