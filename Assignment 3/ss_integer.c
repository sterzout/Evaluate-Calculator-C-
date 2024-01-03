// CS2211a 2023
// Assignment #3
// Salim Terzout Yettou
// 251214366
// sterzout
// October 20, 2023
#include <stdio.h>
#include <stdlib.h>
const char segments[10][3][3] = {
        { {' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'} },
        { {' ', ' ', ' '}, {' ', '|', ' '}, {' ', '|', ' ' } },
        { {' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' ' } },
        { {' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'} },
        { {' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'} },
        { {' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'} },
        { {' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'} },
        { {' ', '_', ' '}, {' ', '|', ' '}, {' ', ' ', '|'} },
        { {' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'} },
        { {' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'} }
};

int printBoard(int value){
    int minus = 0;
    if (value < 0 == 1) {
        minus = 1;
        // if the inputted number is negative
    }

    int size = 0;
    value = abs(value);
    int tempVal = value;
    while (tempVal != 0) {
        tempVal = tempVal / 10;
        size++;
    }
    //retrieve size by dividing by 10 each time and increasing size by one for each division
    int number[size];
    //make an array of that size
    for (int i = size - 1; i >= 0; i--) {
        if (value >= 1) {
            int modular = value % 10;
            value = value / 10;
            number[i] = modular;
//  take the number and put in a sorted array
        }
    }
    char top[size][3];
    char middle[size][3];
    char bottom[size][3];
//    make 3 arrays by length of the number and by 3 since there are 3 one for top layer, one for middle layer, one for bottom layer

    for (int i = 0; i < size; i++) {
        for (int k = 0; k < 3; k++) {
            top[i][k] = segments[number[i]][0][k];
//  add all the first (index 0) arrays in each number for the top of the entire number
        }
    }

    for (int i = 0; i < size; i++) {
        for (int k = 0; k < 3; k++) {
            middle[i][k] = segments[number[i]][1][k];
//  add all the second (index 1) arrays in each number for the middle of the entire number
        }
    }
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < 3; k++) {
            bottom[i][k] = segments[number[i]][2][k];
//  add all the third (index 2) arrays in each number for the bottom of the entire number
        }
    }
    printf(" ");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c", top[i][j]);
        }
//        for loop to print top
    }
    printf("\n");
    if (minus==1){
        printf("-");
    }else if (minus == 0) {
        printf(" ");
//        if the number is negative then add the space to the middle array since it puts the '-' in the right place
//        else leave it since it just needs a space since its not negative its positive
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c", middle[i][j]);
//        for loop to print middle
        }
    }
    printf("\n");
    printf(" ");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c", bottom[i][j]);
//        for loop to print bottom
        }
    }
    printf("\n");

}

int main() {
    int value;
    printf("Please enter an integer value: ");
    scanf("%d", &value);
//    scan the value for input
    printBoard(value);
    //call our printboard method to print the inputted value
}