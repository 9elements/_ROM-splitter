#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

//program to create ROM$N Methods in asl which each
//return 4KB chunks of a file vbios.rom.
//
//_ROM can call the first method, each method here
//can then decide if the offset falls into range,
//otherwise call the next method

int main(){

	const int chunk = 4096; //what the nvidia reads

	FILE* f = fopen("vbios.rom", "r");

	FILE* ftemplate = fopen("template.txt", "r");

	//read our template
	char* template = malloc(800);
	fread(template, 1, 800, ftemplate);
	fclose(ftemplate);

	uint8_t* buffer = malloc(chunk);

	int read;
	int i = 0;
	while(read = fread(buffer, 1, chunk, f) > 0){

		//create our file with the method
		char fname[100];
		sprintf(fname, "out/my-ssdt%02d.asl", i);
		FILE* fout = fopen(fname, "w");

		printf("-acpitable file=acpitables/manual/out/my-ssdt%02d.aml \\\n", i);

		const int size = chunk*5+1;
		char* datastr = malloc(size);
		memset(datastr, (int)' ', size);
		for(int i=0; i < chunk; i++){
			sprintf(datastr+i*5, "0x%02x,", buffer[i]);
		}

		int next = (i==41)?99:i+1;

		fprintf(fout, template, next, i, (i+1)*chunk, next, chunk, datastr);

		free(datastr);
		fclose(fout);
		i++;
	}

	fclose(f);

	return 0;
}
