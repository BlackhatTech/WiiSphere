#ifndef ROM_COMMANDS_H_
#define ROM_COMMANDS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1024

int extract_rom(char* rom, char* output_dir) {
	char* command[BUFFER];
	strcpy(command, "wit extract ");
	strcat(command, rom);
	strcat(command, " ");
	strcat(command, output_dir);
	system(command);
	return 0;
}

int compress_rom(char* rom, char* output_dir) {
	printf("COMING SOON\n");
	return 0;
}

int modify_rom(char* rom) {
	printf("COMING SOON\n");
	return 0;
}

int dump_rom(char* rom) {
	char* command[BUFFER];
	strcpy(command, "wit dump ");
	strcat(command, rom);
	system(command);
	return 0;
}

#endif
