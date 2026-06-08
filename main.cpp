#include "GOL.h"
#include <ncurses.h>
#include <string>

std::string CurrentGameSaveFile = "./game_saves/defaultPastState.txt";

//WARNING, DO NOT PUT 0 OR NEGATIVE NUMBERS
#define GAME_SPEED 2

int main(int argc, char *argv[])
{
	GOLncursesInitialSetup();
	GOLboard *board = GOLboardNew((vec2){COLS, LINES});
	int sx = 50;
	int sy = 20;

	//Patrón hecho con ChatGPT para probar la función de GOLboardSet
	GOLboardSet(board, GOL_ARR, 
		// Left Square (Stabilizer)
		sx + 0, sy + 4,  sx + 0, sy + 5,
		sx + 1, sy + 4,  sx + 1, sy + 5,

		// Left "Bell" of the gun
		sx + 10, sy + 4, sx + 10, sy + 5, sx + 10, sy + 6,
		sx + 11, sy + 3, sx + 11, sy + 7,
		sx + 12, sy + 2, sx + 12, sy + 8,
		sx + 13, sy + 2, sx + 13, sy + 8,
		sx + 14, sy + 5,
		sx + 15, sy + 3, sx + 15, sy + 7,
		sx + 16, sy + 4, sx + 16, sy + 5, sx + 16, sy + 6,
		sx + 17, sy + 5,

		// Right "Bell" of the gun
		sx + 20, sy + 2, sx + 20, sy + 3, sx + 20, sy + 4,
		sx + 21, sy + 2, sx + 21, sy + 3, sx + 21, sy + 4,
		sx + 22, sy + 1, sx + 22, sy + 5,
		sx + 24, sy + 0, sx + 24, sy + 1,
		sx + 24, sy + 5, sx + 24, sy + 6,

		// Right Square (Stabilizer)
		sx + 34, sy + 2, sx + 34, sy + 3,
		sx + 35, sy + 2, sx + 35, sy + 3,
		GOL_END
	);

	while(1){
		static char ch;
		ch = getch();
		if(ch == 27 || ch == 'q') break;
		if(ch == 's') GOLsaveState(board);
	    	GOLboardPrint(board);
	    	GOLsetNexGen(board);
	    	napms(100 / GAME_SPEED);
	}
	endwin();
}
