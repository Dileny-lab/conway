#include "GOL.h"
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cstdarg>
#include <cstdio>

struct GOLboard{
	int width = 10;
	int height = 10;
	int *cell = nullptr;
};


GOLboard*GOLboardNew(struct vec2 v)
{
	GOLboard *b = (GOLboard *) calloc(1, sizeof(GOLboard));
	assert(b);

	b->width = v.x;
	b->height = v.y;
	b->cell = (int *) calloc(v.x * v.y, sizeof(int));
	assert(b->cell);

	return b;
}

void GOLboardDel(GOLboard *b)
{
	free(b->cell);
	free(b);
}

void GOLboardSet(GOLboard *b, enum GOLsetType t, ...)
{
	va_list ap;
	va_start(ap, t);
	struct vec2 v = {0, 0};
	if(t == GOL_ARR){
		while (true){
			v.x = va_arg(ap, int);
			if(v.x == GOL_END){
				break;
			}
			v.y = va_arg(ap, int);
			GOLsetCellAlive(b, v);
		}
	} else if(t == GOL_FILE){
		char *fileName = va_arg(ap, char *);
		FILE *f = fopen(fileName,"r");
		if(f == nullptr){
			fprintf(stderr, "Could not open %s\n", fileName);
		}
		assert(f);
		int x_off = va_arg(ap, int);
		int y_off = va_arg(ap, int);
		v.x += x_off;
		v.y += y_off;
		int ch;
		while((ch = fgetc(f)) != EOF){
			if(ch == '\n'){
				v.y++;
				v.x = x_off;
				continue;
			}

			v.x++;
			if(ch == '#' || ch == 'X' || ch == 'o'){
				GOLsetCellAlive(b, v);
				continue;
			}
		}
		fclose(f);
	}
	va_end(ap);
}

#define GOLboardXY(b, x, y) ((b)->cell[(y) * (b)->width + (x)])


int GOLisCellAlive(const GOLboard *b, struct vec2 v)
{
	int wrappedX = (v.x + b->width) % b->width;
	int wrappedY = (v.y + b->height) % b->height;
	return GOLboardXY(b, wrappedX, wrappedY) == GOL_ALIVE;
}

void GOLsetCellAlive(const GOLboard *b, struct vec2 v)
{
	GOLboardXY(b, v.x, v.y) = GOL_ALIVE;
}

bool GOLwillCellSurvive(const GOLboard *b, struct vec2 v)
{
	int cellStatus = GOLisCellAlive(b, v);
	int totalCells = 0;
	totalCells += GOLisCellAlive(b, (struct vec2){v.x - 1, v.y + 1});
	totalCells += GOLisCellAlive(b, (struct vec2){v.x, v.y + 1});
	totalCells += GOLisCellAlive(b, (struct vec2){v.x + 1, v.y + 1});
	totalCells += GOLisCellAlive(b, (struct vec2){v.x - 1, v.y});
	totalCells += GOLisCellAlive(b, (struct vec2){v.x + 1, v.y});
	totalCells += GOLisCellAlive(b, (struct vec2){v.x - 1, v.y - 1});
	totalCells += GOLisCellAlive(b, (struct vec2){v.x, v.y - 1});
	totalCells += GOLisCellAlive(b, (struct vec2){v.x + 1, v.y - 1});

	if(cellStatus == GOL_ALIVE){
		return (totalCells == 2 || totalCells == 3);
	}
	if(cellStatus == GOL_DEAD)
		return totalCells == 3;

	return false;
}