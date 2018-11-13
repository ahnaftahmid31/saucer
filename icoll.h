#define icoll_en(m) ien[m].t = 48; ien[m].no = 1; ien[m].x = enemy[m].x; ien[m].y = enemy[m].y - 20
#define icoll_ship ship.flag = 48; iship.no = 1; iship.x = ship.x; iship.y = ship.y; // iship.no hoilo koto number ismallex[i] image ta show korbe, shuru hobe iship.no = 1 dia
#define icoll_render_ship(m) if (ship.flag > 0){ ship.flag--; if (ship.flag % m == 0) iship.no++;  if (ship.flag == 0) { iship.no = 1;} }
#define icoll_render_en(m) for (i = 1; i <= 10; i++){ if (ien[i].t > 0){ ien[i].t--; if (ien[i].t % m == 0) ien[i].no++; if (ien[i].t == 0) ien[i].no = 1;} }
#define icoll_render_boss if(bosstime > 0){ bosstime--; if(bosstime % 4 == 0) iboss[1].no++; if(bosstime == 0) iboss[1].no = 1;}