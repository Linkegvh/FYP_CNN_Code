#include <stdio.h>

int main(){
    int input[17];

    printf("Enter data:\n");

    // for (int i = 0; i < 16; i ++){
    //     for (int j = 0; j < 32; j ++){
    //         for (int t = 0; t < 4; t++){
    //             scanf("%d", &input[i][j][t]);
    //         }
    //     }
    // }

    // for (int i = 0; i < 16; i ++){
    //     for (int j = 0; j < 33; j ++){
    //         scanf("%d", &input[i][j]);
    //     }
    // }
    for (int i = 0; i < 17; i ++){
        scanf("%d", &input[i]);
    }

    printf("Here are the data:\n");

    // Initialise Write to a text file
    FILE *out_file = fopen("Result_add.txt", "w");
    if (out_file == NULL){
        printf("Error!!!\n");
        return 0;
    }

    // for (int i = 0; i < 16; i ++){
    //     for (int j = 0; j < 32; j ++){
    //         for (int t = 0; t < 4; t++){
    //             fprintf(out_file, "array[%d][%d][%d] = %d;\n", i, j, t, input[i][j][t]);
    //         }
    //     }
    // }
    // for (int i = 0; i < 16; i ++){
    //     for (int j = 0; j < 32; j ++){
    //         fprintf(out_file, "array[%d][%d] = %d;\n", i, j, input[i][j]);
    //     }
    // }

    for (int i = 0; i < 17; i ++){
        fprintf(out_file, "array[%d] = %d;\n", i, input[i]);
    }
    

}