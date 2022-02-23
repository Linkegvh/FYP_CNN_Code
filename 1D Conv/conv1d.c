#include <stdio.h>

int MAC(int [], int []);

int main (){
    int data_set_cnt = 512;
    int number_of_feature = 6;
    int number_of_filters = 8;

    int data_RAM[512];
    // int weights_RAM[8][6];

    int correct_result[8][512];
    int calculated_result[8][512];
    int data[5];
    int weights[6];
    int intermediate_result[6];

    printf("Enter data:\n");
    for (int i = 0; i < data_set_cnt; i ++){
        scanf("%d", &data_RAM[i]);
    }

    int weights_RAM_layer_1 [8][6] = {
        {22, -31, -1, 36, 62, 47},
        {20, 20, -10, 13, -72, 70},
        {80, 79, 43, 38, 41, -63},
        {45, 12, -21, -31, 40, 82},
        {22,	-5,	-40,	-16,	-15,	97},
        {13,	-82,	89,	-2,	-15,	14},
        {-14,	114,	65,	-17,	-86,	-74},
        {6,	-72,	-44,	2,	27,	32}
    };

    int weights_RAM_layer_2 [16][4] = {
        
    }


    // printf("Enter weights:\n");
    // for (int i = 0; i < number_of_filters; i ++){
    //     for (int j = 0; j < number_of_feature; j ++){
    //         scanf("%d", &weights_RAM[i][j]);
    //     }
    // }

    // printf("Enter Correct result:\n");
    // for (int i = 0; i < number_of_filters; i ++){
    //     printf("Layer: %d\n", i);
    //     for (int j = 0; j < data_set_cnt; j ++){
    //         scanf("%d", &correct_result[i][j]);
    //     }
    // }

    /************** Actual Calculation **************/
    printf("Start Calculation\n");

    for (int i = 0; i < number_of_filters; i ++){
        for (int j = 0; j < data_set_cnt; j ++){

            // Read in 5 data point
            data[0] = (j - 2 < 0) ? 0 : data_RAM[j - 2];
            data[1] = (j - 1 < 0) ? 0 : data_RAM[j - 1];
            data[2] = data_RAM[j];
            data[3] = (j + 1 >= 512) ? 0 : data_RAM[j + 1];
            data[4] = (j + 2 >= 512) ? 0 : data_RAM[j + 2];

            // Read in 6 weights
            weights[0] = weights_RAM[i][0];
            weights[1] = weights_RAM[i][1];
            weights[2] = weights_RAM[i][2];
            weights[3] = weights_RAM[i][3];
            weights[4] = weights_RAM[i][4];
            weights[5] = weights_RAM[i][5];

            // Calculate & save to RAM
            calculated_result[i][j] = MAC(data, weights);
        }
    }

    // Write to a text file
    FILE *out_file = fopen("CONV1D_Result.txt", "w");
    if (out_file == NULL){
        printf("Error!!!\n");
        return 0;
    }

    // Compare data to check for correctness
    for (int i = 0; i < number_of_filters; i ++){
        for (int j = 0; j < data_set_cnt; j ++){
            fprintf(out_file, "Filter: %d\t", i);
            fprintf(out_file, "Location: %d\t", j);
            fprintf(out_file, "Calculated Result: %d\t", calculated_result[i][j]);
            if (calculated_result[i][j] != correct_result[i][j]){
                fprintf(out_file, "Correct Result: %d", correct_result[i][j]);
            }
            fprintf(out_file, "\n");
        }
    }

    return 0;
}

int MAC(int data[5], int weights[6]){
    int intermediate_result [6];
    int final_result;
    
    // Multiply
    intermediate_result[0] = 256 * weights[0];
    intermediate_result[1] = data[0] * weights[1];
    intermediate_result[2] = data[1] * weights[2];
    intermediate_result[3] = data[2] * weights[3];
    intermediate_result[4] = data[3] * weights[4];
    intermediate_result[5] = data[4] * weights[5];

    // Accumulate
    final_result = intermediate_result[0] + intermediate_result[1] + intermediate_result[2] + intermediate_result[3] + intermediate_result[4] + intermediate_result[5];

    return final_result / 256;
}