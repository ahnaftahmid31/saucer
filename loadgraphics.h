#include"variables.h"

// loading initial values
#define loadthemall loadgfx(); firstpage.flag = 1; games.start = 0; games.over = 0; highscore.flag = 0; somoy = 0; iSetTimer(tym, collision_render); iSetTimer(tym, collision); iSetTimer(tym, guli); iSetTimer(30, enemymove); iSetTimer(tym, game); iSetTimer(1, somoycount)

//for copying image links
void loadgfx(){
	strcpy_s(iship.link, "gfx//ship.bmp");
	strcpy_s(istar.link, "gfx//star.bmp");
	for (i = 1; i <= 12; i++){
		strcpy_s(ismallex[i].link, "gfx//small explosion 0x.bmp");
		if (i <= 9)
			ismallex[i].link[22] = '0' + i;
		else
		{
			ismallex[i].link[21] = '1';
			ismallex[i].link[22] = '0' + i - 10;
		}
	}
	strcpy_s(ibullet.link, "gfx//bullet1.bmp");
	strcpy_s(isaucer.link, "gfx//saucer.bmp");
	strcpy_s(igover.link, "gfx//gameover.bmp");
	strcpy_s(iboss[1].link, "gfx//target3.bmp");
	for (i = 1; i <= 12; i++){
		strcpy_s(ienex[i].link, "gfx//explosion0xr.bmp");
		if (i <= 9)
			ienex[i].link[15] = '0' + i;
		else
		{
			ienex[i].link[14] = '1';
			ienex[i].link[15] = '0' + i - 10;
		}
	}
	for (i = 1; i <= 12; i++){
		strcpy_s(ibigex[i].link, "gfx//big explosion 0x.bmp");
		if (i <= 9)
			ibigex[i].link[20] = '0' + i;
		else
		{
			ibigex[i].link[19] = '1';
			ibigex[i].link[20] = '0' + i - 10;
		}
	}

}