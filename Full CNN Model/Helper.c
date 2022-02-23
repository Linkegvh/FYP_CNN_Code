#include <stdio.h>

int main(){
    int input[16][32][4];

    printf("Enter data:\n");

    for (int i = 0; i < 16; i ++){
        for (int j = 0; j < 32; j ++){
            for (int t = 0; t < 4; t++){
                scanf("%d", &input[i][j][t]);
            }
        }
    }

    printf("Here are the data:\n");

    // Initialise Write to a text file
    FILE *out_file = fopen("Result_add.txt", "w");
    if (out_file == NULL){
        printf("Error!!!\n");
        return 0;
    }

    for (int i = 0; i < 16; i ++){
        for (int j = 0; j < 32; j ++){
            for (int t = 0; t < 4; t++){
                fprintf(out_file, "array[%d][%d][%d] = %d;\n", i, j, t, input[i][j][t]);
            }
        }
    }

}