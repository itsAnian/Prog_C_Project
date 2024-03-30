#ifndef TINF23_PROG1_5019343_DRAW_H
#define TINF23_PROG1_5019343_DRAW_H
#include "create_file.h"

void SetPixel(int x, int y, char map[X_PIXEL][Y_PIXEL]);
void DrawLine(int x1, int y1, int x2, int y2,char map[X_PIXEL][Y_PIXEL]);
void DrawCircle(int xc, int yc, int x, int y, char map[X_PIXEL][Y_PIXEL]);
void CircleBresenham(int xc, int yc, int r, char map[X_PIXEL][Y_PIXEL]);

#endif //TINF23_PROG1_5019343_DRAW_H
