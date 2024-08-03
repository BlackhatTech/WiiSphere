#ifndef BANNER_H_
#define BANNER_H_

void banner(void) {
	system("clear");
        printf("  _      ___ _   ____     __              \n");
        printf(" | | /| / (_|_) / __/__  / /  ___ _______ \n");
        printf(" | |/ |/ / / / _\\ \\/ _ \\/ _ \\/ -_) __/ -_) \n");
        printf(" |__/|__/_/_/ /___/ .__/_//_/\\__/_/  \\__/ \n");
        printf("                 /_/ Using Wiimms ISO Tools\n\n");
        printf(" %s%sNintendo%s%s Wii & Gamecube ROM modding toolkit.\n", BOLD, ANSI_COLOR_RED, ANSI_COLOR_RESET, BOLD_RESET);
	printf("    by $pectr4\n\n");
}

void help(void) {
	printf("\n");
	printf(" BASIC COMMANDS:\n\n");

	printf("    COMMAND                DESCRIPTION \n");
	printf("    =======                =========== \n");
	printf("    help                   Shows this message.\n");
	printf("    clear                  Clears the console.\n");
	printf("    exit                   Exits WiiSphere.\n");
	printf("\n");

	printf(" MODDING COMMANDS:\n\n");
	printf("    COMMAND                DESCRIPTION \n");
	printf("    =======                =========== \n");
	printf("    dump-rom               Dump ROM data.\n");
	printf("    modify-rom             Opens a dialogue to modify ROM data.\n");
	printf("    extract-rom            Extracts the ROM (like models, audio tracks, etc...)\n");
	printf("    rebuild-rom            Rebuilds the ROM from the extracted folder.\n");
	printf("    patch-wiimmfi          Patch ROM with external wiimmfi online services.\n");
	printf("\n");
}

#endif
