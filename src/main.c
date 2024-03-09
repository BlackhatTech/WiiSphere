#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "colors.h"
#include "banner_and_help.h"
#include "rom_commands.h"

#define BUFFER 1024

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("%s: [ ROM ]\n", argv[0]);
		return 0;
	}
	char* rom = argv[1];
	banner();
	while (true) {
		char buffer[BUFFER];
		printf(" WiiSphere > ");
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strcspn(buffer, "\n")] = '\0';

		if (strcmp(buffer, "clear") == 0) {
			banner();
		} else if (strcmp(buffer, "help") == 0) {
			help();
		} else if (strcmp(buffer, "exit") == 0) {
			printf("\n Thanks for using WiiSphere <3\n");
			exit(EXIT_SUCCESS);
		} else if (strcmp(buffer, "extract-rom") == 0) {
			char output_dir[BUFFER];
			printf(" Enter output directory > ");
			fgets(output_dir, sizeof(output_dir), stdin);
			output_dir[strcspn(output_dir, "\n")] = '\0';
			extract_rom(rom, output_dir);
		} else if (strcmp(buffer, "modify-rom") == 0) {
			modify_rom(rom);
		} else if (strcmp(buffer, "dump-rom") == 0) {
			dump_rom(rom);
		} else if (strcmp(buffer, "compress-rom") == 0) {
			compress_rom(rom, "");
		}

	}

	return 0;
}
