#include"variables.h"

#define set_level1_phase1 phase = 1; enemy[1].flag = 1; enemy[1].x = 1000; enemy[1].y = 320; en.no = 1; dir = 1  // dir = direction , dir = 1 meaning enemies attack from right and vise versa
#define set_level1_phase2 phase = 2; bonus = 0; en.no = 7; enemy[2].y = 100; dir = 1; for (i = 2; i <= 7; i++){ enemy[i].flag = 1; enemy[i].x = 1000; if (i >= 3)  enemy[i].y = enemy[i - 1].y + 80;}
#define set_level1_phase3 phase = 3; en.no = 7; enemy[1].y = 100; dir = -1; for (i = 1; i <= 7; i++){ enemy[i].flag = 1; enemy[i].x = -50; if (i >= 2) enemy[i].y = enemy[i - 1].y + 80;}
#define set_level1_phase4 phase = 4; dir = -1; en.no = 2; enemy[1].flag = 1; enemy[2].flag = 1; enemy[1].x = -50; enemy[1].y = 160; enemy[2].x = -50; enemy[2].y = 480
#define set_level1_phase5 phase = 4; if (gametime == 2000 + shit && en.no < 10){ en.no++; enemy[dhat].flag = 1; enemy[dhat].x = 1000; enemy[dhat].y = 320; dir = 1; shit += 20; dhat++; }
#define set_level1_phase6 phase = 6; boss[1].flag = 1; bs.come = 1; bs.no = 1; boss[1].x = 1000; boss[1].y = 320; boss[1].lives = 200; bosstime = 0



#define set_level2_phase1 
#define set_level2_phase2
#define set_level2_phase3
#define set_level2_phase4
#define set_level2_phase5
#define set_level2_phase6



#define set_level3_phase1 
#define set_level3_phase2
#define set_level3_phase3
#define set_level3_phase4
#define set_level3_phase5
#define set_level3_phase6