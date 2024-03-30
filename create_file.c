#include "create_file.h"
#include <stdio.h>
#include <stdlib.h>
#define MYFILENAME "image.ppm" // Ihr Filename


int create_ppm(char map[X_PIXEL][Y_PIXEL]){
    FILE *p_file = fopen(MYFILENAME,"w");
    if (NULL != p_file)
    {
        fprintf (p_file, "P3\n %d %d\n 255\n", X_PIXEL, Y_PIXEL);
        for (int i = 0; i < Y_PIXEL; i++) {
            for (int ii = 0; ii < X_PIXEL; ii++) {
                if (map[i][ii] == '+') {
                    //sprintf(x, "%d %d %d ", rand(), rand(), rand());
                    fprintf(p_file, "255 255 255 ");
                } else {
                    fprintf(p_file, "  0   0   0   ");
                }
            }
        }
        fclose (p_file);
    }
    return 0;
}
