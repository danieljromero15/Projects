#include <stdio.h>

unsigned long multiplyIntArray(int *ArrayToMultiply, int sizeOfArray) {
    int n = sizeOfArray / 4;
    unsigned long product = 1;

    if (n == 0) {
        // printf("Array is empty!");
        product = 0;
    } else {
        for (int i = 0; i < n; i++) {
            product *= (*ArrayToMultiply + i);
            // printf("%d ", (*ArrayToMultiply + i));
        }
    }
    printf("\nThe product of the array is %lu\n", product);

    return product;
}

int arrayShift(int *ArrayToShift, int sizeOfArray) {
    for (int i = 0; i < sizeOfArray / 4; i++) {
        ArrayToShift[i] += 2;
    }
}

double nilakantha(int accuracy) {
    double PICalc = 3;
    int array[] = {2, 3, 4};

    for (int i = 0; i < accuracy; i++) {
        switch (i % 2) {
            case 0:  // even
                PICalc += ((float) 4.0 / (float) multiplyIntArray(array, sizeof(array)));
                break;
            case 1:  // odd
                PICalc -= ((float) 4 / (float) multiplyIntArray(array, sizeof(array)));
                break;
            default:
                printf("Error");
                exit(22);
                break;
        }
        printf("Before: %d %d %d\t%d", array[0], array[1], array[2], i);
        arrayShift(array, sizeof(array));
        // printf("\tAfter: %d %d %d\n", array[0], array[1], array[2]);
    }

    // const double PI = 3;

    return PICalc;
}

int main() {  // How the fuck did I mess up the int main so much i literally
              // know this shit wtf
    // im so tired
    //printf("\e[1;1H\e[2J"); // clears screen
    printf("\n");

    int inputNum;

    // scanf("Number of digits (max x): %d", &inputNum);

    // printf("\n%d\n\n", sizeof(array));
    // multiplyIntArray(array, sizeof(array));

    printf("%.20f", nilakantha(813));

    int array[] = {1626, 1627, 1628};
    printf("\n\n%lu\n\n", multiplyIntArray(array, sizeof(array)));

    printf("\n\n");
    return 0;
}