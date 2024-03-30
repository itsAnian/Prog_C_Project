#include "draw.h"
#include <stdio.h>
#include <math.h>
#include "create_file.h"

void SetPixel(int x, int y, char map[X_PIXEL][Y_PIXEL]){
    map[y][x] = '+';
}

// function for line generation
void DrawLine(int x1, int y1, int x2, int y2,char map[X_PIXEL][Y_PIXEL]) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while (1) {
        // Draw the current point (x1, y1)
        SetPixel(x1,y1,map);
        //printf("(%d, %d)\n", x1, y1);
        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

// Function to draw a circle with adjustable color
void DrawCircle(int xc, int yc, int x, int y, char map[X_PIXEL][Y_PIXEL]) {
    SetPixel(xc + x, yc + y, map);
    SetPixel(xc - x, yc + y, map);
    SetPixel(xc + x, yc - y, map);
    SetPixel(xc - x, yc - y, map);
    SetPixel(xc + y, yc + x, map);
    SetPixel(xc - y, yc + x, map);
    SetPixel(xc + y, yc - x, map);
    SetPixel(xc - y, yc - x, map);
}

// Function for circle-generation using Bresenham's algorithm
void CircleBresenham(int xc, int yc, int r, char map[X_PIXEL][Y_PIXEL]) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    DrawCircle(xc, yc, x, y, map);
    while (y >= x) {
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else
            d = d + 4 * x + 6;
        DrawCircle(xc, yc, x, y, map);
    }
}

