#ifndef ROM_COMMANDS_H_
#define ROM_COMMANDS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1024

int patch_wiimmfi(char* rom) {
	char command[BUFFER];
	snprintf(command, sizeof(command), "wit copy %s wiimmfi-%s --wiimmfi", rom, rom);
	system(command);
	printf("Game successfully patched with wiimmfi. File 'wiimmfi-%s' created.", rom);
	return 0;
}

int extract_rom(char* rom, char* output_dir) {
	char command[BUFFER];
	snprintf(command, sizeof(command), "wit extract %s %s", rom, output_dir);
	system(command);
	return 0;
}

int rebuild_rom(char* folder, char* output, char* format) {
	char command[BUFFER];
	snprintf(command, sizeof(command), "wit copy %s %s --%s", folder, output, format);
	return 0;
}

int modify_rom(char* rom) {
	printf("COMING SOON\n");
	return 0;
}

int dump_rom(char* rom) {
	char command[BUFFER];
	snprintf(command, sizeof(command), "wit dump %s", rom);
	system(command);
	return 0;
}

#endif
