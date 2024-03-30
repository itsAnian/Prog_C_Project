#include <stdio.h>
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

int main() {
    char map [X_PIXEL][Y_PIXEL];
    DrawTutorial(map);
    //DrawLine(0,0,X_PIXEL,Y_PIXEL, map);
    /*
    for(int i = 0; i<200; i++){
        for(int ii = 0; ii<200; ii++)
            printf("%c", map[i][ii]);
    }
     */
    create_ppm(map);
    return 0;
}
