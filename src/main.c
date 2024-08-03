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
	
	char output_dir[BUFFER];
	char output_file[BUFFER];
	char output_format[BUFFER];
	char output_full[BUFFER];
	char extracted_folder[BUFFER];

	while (true) {
		char buffer[BUFFER];
		printf(" WiiSphere > ");
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strcspn(buffer, "\n")] = '\0';

		if (strcmp(buffer, "clear") == 0) {
			banner();
		} 
		else if (strcmp(buffer, "help") == 0) {
			help();
		} 
		else if (strcmp(buffer, "exit") == 0) {
			printf("\n Thanks for using WiiSphere <3\n");
			exit(EXIT_SUCCESS);
		} 
		else if (strcmp(buffer, "extract-rom") == 0) {
			printf(" Enter output directory > ");
			fgets(output_dir, sizeof(output_dir), stdin);
			output_dir[strcspn(output_dir, "\n")] = '\0';
			extract_rom(rom, output_dir);
		} 
		else if (strcmp(buffer, "modify-rom") == 0) {
			modify_rom(rom);
		} 
		else if (strcmp(buffer, "dump-rom") == 0) {
			dump_rom(rom);
		}
		else if (strcmp(buffer, "rebuild-rom") == 0) {
			printf(" Enter the extracted folder's name: ");
			fgets(extracted_folder, sizeof(extracted_folder), stdin);
			extracted_folder[strcspn(extracted_folder, "\n")] = '\0';
			
			printf(" Enter output file name (without file extension, for example: mariokart): ");
			fgets(output_file, sizeof(output_file), stdin);
			output_file[strcspn(output_file, "\n")] = '\0';
			
			printf(" Enter file extension supported by wit (for example: .iso or .wbfs): ");
			fgets(output_format, sizeof(output_format), stdin);
			output_format[strcspn(output_format, "\n")] = '\0';
			
			snprintf(output_full, sizeof(output_full), "%s.%s", output_file, output_format);
			rebuild_rom(extracted_folder, output_full, output_format);
		}
		else if (strcmp(buffer, "patch-wiimmfi" == 0)) {
			patch_wiimmfi(rom);
		}

	}

	return 0;
}
