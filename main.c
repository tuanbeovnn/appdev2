#include <stdlib.h>		// for random numbers
#include <time.h>		// for randomization (using system time)
#include "screen.h"
#include <stdio.h>
#include "sound.h"

int main(){
	FILE *f;
	short sd[80000];
	for(;;){
	system(RCMD);
	f=fopen("test.wav", "r");
	if(f == NULL){
		printf("Cannot open the file\n");
		return 1;
	}

	clearScreen();
	setColors(RED, bg(YELLOW));
	struct WAVHDR hdr;
	fread(&hdr, sizeof(hdr), 1, f);		// read WAV header
	fread(&sd, sizeof(sd), 1, f);
	fclose(f);
	displayWAVHDR(hdr);

	// display WAVHDR();
	}
	resetColors();
	getchar();
}
