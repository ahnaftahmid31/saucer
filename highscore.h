#include"variables.h"
#include<stdio.h>

FILE *fp;
int d, e;
char *highscore_file = "highscore.txt";
void high_score(){
	fp = fopen(highscore_file, "r");
	for (i = 0; i < 5; i++){
		fscanf(fp, "%d", &ara[i]);
	}
	for (d = 0; d < 4; d++){ for (e = d + 1; e < 5; e++){ if (ara[d]>ara[e]){ int te = ara[d]; ara[d] = ara[e]; ara[e] = te; } } }
	if (score > ara[0]){
		ara[0] = score;
	}
	for (d = 0; d < 4; d++){ for (e = d + 1; e < 5; e++){ if (ara[d]>ara[e]){ int te = ara[d]; ara[d] = ara[e]; ara[e] = te; } } }
	fclose(fp);
	fp = fopen(highscore_file, "w");
	for (i = 1; i <= 4; i++){
		fprintf(fp, "%d\n", ara[i]);
	}
}