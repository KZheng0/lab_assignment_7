#include <stdio.h>
#include <stdlib.h>

//Bubble sorting function
//Counts total # of swaps
int bubbleSort(int array[], int n){
    int i, j, tmp, count1 = 0;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (array[j] > array[j+1]){
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
                count1++;
            }
        }
    }
    return count1;
}

//Counts # of swaps for each number using bubble sort
int * bubbleCount(int array[], int n, int sortedArray[]){
    int *freq = (int*) calloc(9, sizeof(int));
    int i, j, k, tmp;
    for (i = 0; i < n; i++){
        freq[i] = 0;
    }
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (array[j] > array[j+1]){
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
                for(k = 0; k < n; k++){
                    if (array[j] == sortedArray[k]){
                        freq[k]++;
                    }
                    if(array[j+1] == sortedArray[k]){
                        freq[k]++;
                    }
                }
            }
        }
    }
    return freq;
}
//Selection sorting function
//Counts total # of swaps
int selectSort(int array[], int n){
    int i, j, min, tmp, count2 = 0;
    for (i = 0; i < n-1; i++){
        min = i;
        for (j = i+1; j < n; j++){
            if (array[j] < array[min]){
                min = j;
            }
        }
        if (array[i] != array[min]){
            tmp = array[i];
            array[i] = array[min];
            array[min] = tmp;
            count2++;
        }
    }
    return count2;
}
//Counts # of swap for each number using selection sort
int * selectCount(int array[], int n, int sortedArray[]){
    int *count = (int*) calloc(9, sizeof(int));
    int i, j, k, min, tmp;
    for (i = 0; i < n-1; i++){
        min = i;
        for (j = i+1; j < n; j++){
            if (array[j] < array[min]){
                min = j;
            }
        }
        if (array[i] != array[min]){
            tmp = array[i];
            array[i] = array[min];
            array[min] = tmp;
            for (k = 0; k < n; k++){
                if (array[i] == sortedArray[k]){
                        count[k]++;
                    }
                    if(array[min] == sortedArray[k]){
                        count[k]++;
                    }
            }
        }
    }
    return count;
}

int main(){
    int total1, total2, total3, total4;
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int array11[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array22[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = 9;

    int *freq1;
    int *freq2;
    int *freq3;
    int *freq4;
    
    //Total # of swaps using bubble sort
    total1 = bubbleSort(array1, n);
    total2 = bubbleSort(array2, n);
    
    //Number of swaps for each number using bubble sort
    freq1 = bubbleCount(array11, n, array1);
    freq2 = bubbleCount(array22, n, array2);
    
    //Prints the swaps for array 1 using bubble sort
    printf("array1 bubble sort: \n");
    for (int i = 0; i < n; i++){
        printf("%d: %d\n", array1[i], freq1[i]);
    }
    printf("%d\n", total1);
    
    //Prints the swaps for array 2 using bubble sort
    printf("\narray2 bubble sort: \n");
    for (int i = 0; i < n; i++){
        printf("%d: %d\n", array2[i], freq2[i]);
    }
    printf("%d\n", total2);

    int array3[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array4[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int array33[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array44[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    
    //Total # of swaps using selection sort
    total3 = selectSort(array3, n);
    total4 = selectSort(array4, n);

    //Number of swaps for each number using selection sort
    freq3 = selectCount(array33, n, array3);
    freq4 = selectCount(array44, n, array4);

    //Prints the swaps for array 1 using selection sort
    printf("\narray1 selection sort: \n");
    for (int i = 0; i < n; i++){
        printf("%d: %d\n", array1[i], freq3[i]);
    }
    printf("%d\n", total3);

    //Prints the swaps for array 2 using selection sort
    printf("\narray1 selection sort: \n");
    for (int i = 0; i < n; i++){
        printf("%d: %d\n", array2[i], freq4[i]);
    }
    printf("%d\n", total4);
    
    //Free memory
    free(freq1);
    free(freq2);
    free(freq3);
    free(freq4);

    return 0;
}