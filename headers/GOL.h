#ifndef GOL_H
#define GOL_H

#define GOL_ALIVE	1
#define GOL_DEAD	0

struct GOLboard;

struct vec2{
	int x;
	int y;
};

/*-----------------Board management-----------------*/

//Board constructor
GOLboard*	GOLboardNew	(vec2 v);

//Board destructor
void		GOLboardDel	(GOLboard *b);

constexpr int GOL_ARR = 0;
constexpr int GOL_FILE = 1;

#define GOL_END -1

//Sets a board's initial cell status given either an array
//of vectors or a file
void		GOLboardSet	(GOLboard *b, int t, ...);

//Empties the given board
void		GOLemptyBoard	(GOLboard *b);



/*-----------------Cell management------------------*/

//Checks if a cell at (x,y) is alive
int		GOLisCellAlive		(const GOLboard *b, vec2 v);

//Sets a new live cell at (x,y) on the given board
void		GOLsetCellAlive		(const GOLboard *b, vec2 v);

//Determines if the cell on (x, y) will survive until next generation
bool		GOLwillCellSurvive	(const GOLboard *b, vec2 v);

//Advances to the next generation
void		GOLsetNexGen		(GOLboard *b);



/*--------------NCURSES management------------------*/

//Initial ncurses setup for correct visualization
void		GOLncursesInitialSetup();

//Cleans up ncurses
void		GOLncursesEnd();

//Prints the board
void		GOLboardPrint	(const GOLboard *b);



/*-----------------file management------------------*/
void		GOLgetDefaultSave(void);

//Saves the game's current state
void		GOLsaveState	(GOLboard *b);
#endif
