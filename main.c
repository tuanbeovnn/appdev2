#include <stdlib.h>
#include <signal.h>		// for random numbers
#include <time.h>		// for randomization (using system time)
#include "screen.h"
#include <stdio.h>
#include "sound.h"
#include "comm.h"

int main(int argc, char **argv){
	if(argc == 2){
		int ch;
		printf("How many channels? (1:mono, 2:stereo)");
		scanf("%d", &ch);
		float duration;
		printf("how long is the test tone (1-10 sec) ");
		scanf("%f", &duration);
		testTone(ch, atoi( argv[1]), duration);
		return 0;
	}
	FILE *f;	
	short sd[RATE]; // for all samples in 1 sec
	while(1){
		int ret = system(CMD);
		if(ret == SIGINT) break;
		f=fopen("test.wav", "r"); // open the  file for read only
		if(f == NULL){
			printf("Cannot open the file\n");
			return 1;
		}

		clearScreen();
		setColors(GREEN, bg(BLUE));
		struct WAVHDR hdr; // instance of wav header
		fread(&hdr, sizeof(hdr), 1, f);		// read WAV header
		fread(&sd, sizeof(sd), 1, f); // show wav header information
		fclose(f); // close the open file
		sendDATA(sd);
		displayWAVHDR(hdr);

	// display WAVHDR();
		displayWAVDATA(sd);
	}
	resetColors();
	
}
