
#include"variables.h"


// ahnaf's codes

#define en_shift_y for (i = 1; i <= 100; i++) enemy[i].shift.y = 6 // sets all enemy shifting to 6;
#define set_all_bullet_flag_0 for (i = 1; i <= bull.no; i++) bullet[i].flag = 0 // sets all bullet flag to zero
#define set_all_bullet_ini_pos for (i = 1; i < bull.no; i++) { bullet[i].x = ship.x + ship.w / 2; bullet[i].y = ship.y + 2 * ship.h / 4; bullet2[i].x = bullet[i].x; bullet2[i].y = ship.y + ship.h / 4;} // sets all bullet's position to playership's position
#define set_selected_bullet_ini_pos(a) bullet[a].flag = 1; bullet[a].x = ship.x + ship.w; bullet[a].y = ship.y + 2 * ship.h / 4; bullet2[a].x = ship.x + ship.w;  bullet2[a].y = ship.y + ship.h / 4

#define bullet_shift_x bullet[i].x += bull.shift.x; bullet2[i].x += bull.shift.x // bullet shifting along x-axis.

 //due to easy understanding of enemy shifting and their moves we choose not to use macro for enemy shifiting 