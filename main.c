#include <stdio.h>
#include <math.h>
#include "create_file.h"
#include "draw.h"

int DrawTutorial(char map[X_PIXEL][Y_PIXEL]){
    int n = 0;
    printf("give a variable n\n");
    scanf("%d", &n);
    printf("%d", n);
    n = n-1;
    int temp1 = X_PIXEL/2;
    int temp2 = Y_PIXEL/2;
    double temp3 = (double)Y_PIXEL/n;
    printf("temp3: %f\n", temp3);
    for(int i = 0; i <= n; i++){
        DrawLine(0,temp2,temp2,temp3*i, map);
        DrawLine(temp1,temp3*i,Y_PIXEL,temp2, map);
        printf("i: %d\n", i);
    }
}

int AskNumberInput(){
    int number = 0;
    printf("give a variable n\n");
    scanf("%d", &number);
    printf("%d\n", number);
    number = number-1;
    return number;
}

void DrawLinesOnCircle(int xc, int yc, int radius, int n, char map [X_PIXEL][Y_PIXEL]) {
    double angleIncrement = 2 * M_PI / n;
    double angle = 0.0;

    for (int i = 0; i < n; i++) {
        // Calculate the coordinates of the point on the circumference
        int x = xc + (int)(radius * cos(angle));
        int y = yc + (int)(radius * sin(angle));

        // Print the coordinates of the point
        //printf("Point %d: (%d, %d)\n", i + 1, x, y);
        if (1000 >= x && 0 <= x && 1000 >= y && 0 <= y){
            DrawLine(0, Y_PIXEL, x, y, map);
            DrawLine(x,y,X_PIXEL,0, map);
        }
        // Increment the angle for the next division
        angle += angleIncrement;
    }
}

int DrawOneQuaterCircle(char map[X_PIXEL][Y_PIXEL]){
    int number = (AskNumberInput()*4)+8;
    CircleBresenham(0, Y_PIXEL-1, X_PIXEL-1, map);
    DrawLinesOnCircle(0, Y_PIXEL-1, X_PIXEL-1, number, map);
}

void DrawBorder(char map[X_PIXEL][Y_PIXEL]){
    DrawLine(0,0,X_PIXEL-1,0, map);
    DrawLine(X_PIXEL-1,0,X_PIXEL-1,Y_PIXEL-1, map);
    DrawLine(X_PIXEL-1,Y_PIXEL-1,0,Y_PIXEL-1,map);
    DrawLine(0,Y_PIXEL-1,0,0,map);
}

int main() {
    char map [X_PIXEL][Y_PIXEL] = {0};
    //DrawTutorial(map);
    DrawBorder(map);
    DrawOneQuaterCircle(map);
    //DrawLine(0,0,X_PIXEL,Y_PIXEL, map);
    /*
    for(int i = 0; i<X_PIXEL-1; i++){
        for(int ii = 0; ii<Y_PIXEL-1; ii++)
            printf("%c", map[i][ii]);
    }
    */
    create_ppm(map);
    return 0;
}
