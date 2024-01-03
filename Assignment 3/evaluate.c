// CS2211a 2023
// Assignment #3
// Salim Terzout Yettou
// 251214366
// sterzout
// October 20, 2023
#include <stdio.h>
#include <stdlib.h>
char get_op(void) {
    char operationType;
    while(1){
        operationType = getchar();
        if (operationType == ' '){
            continue;
        }
        if (operationType == '-' || operationType == '+' || operationType == '\n'|| operationType == '*'){
            return operationType;
        }
        else if (operationType != '+' && operationType != '-' && operationType != '\n'){
            printf("The following input is wrong: %c\n", operationType);

        }
    }
//    get operation checks for each case, skips spaces, returns +,- and \n as instructed
// if neither it notifies user
}

float get_num(void) {
    float input = 0;
    if (scanf("%f", &input) != 1){
        printf("Invalid entry. Not a float number\n");
        return 0;
    }
    return input;
    // if scanned input is float return input if float is not true then send error message
}
float sub_sim_exp(float sub_exp) {
    char operation = get_op();
    if (operation == '\n') {
        return sub_exp;
// once we reach a new line we return our sub_exp input
    }
    if (operation == '-') {
        float total_exp = sub_exp - get_num();
        return sub_sim_exp(total_exp);
// once we reach a minus we make a new float and call the recursive function with that variable that used subtraction
    } else if (operation == '+') {
        float total_exp2 = sub_exp + get_num();
        return sub_sim_exp(total_exp2);
// once we reach a minus we make a new float and call the recursive function with that variable that used addition

    }
    else if (operation == '*') {
        float total_exp3 = sub_exp * get_num();
        return sub_sim_exp(total_exp3);
    }

}
float sim_exp(void) {
    float num = get_num();
    return sub_sim_exp(num);
// function is given to us

}
int main() {
    while (1) {
        printf("Please enter a simple arithmetic expression: ");
        float total;
        total = sim_exp();
        printf("The total of the arithmetic expression is: %.2f\n", total);
        printf("Do you want to continue? (Y/N): ");
        char yesOrNo = 'Y';
        scanf(" %c", &yesOrNo);
// ask user to enter arithmetic expression once he enters we call sim_exp which returns our recursive method on the
//arithmetic input of the user
        while (yesOrNo == 'y' || yesOrNo == 'Y') {
            printf("Please enter a simple arithmetic expression: ");
            float total;
            total = sim_exp();
            printf("The total of the arithmetic expression is: %.2f\n", total);
            printf("Do you want to continue? (Y/N): ");
            char yesOrNo = 'Y';
            scanf(" %c", &yesOrNo);
            if (yesOrNo == 'n' || yesOrNo == 'N') {
                exit(EXIT_FAILURE);
            }
// loop until either user types 'Y', 'y' for yes and 'N' or 'n' for no. if no then we use the exit(EXIT_FAILURE) as instructed
        }

        while (yesOrNo != 'y' && yesOrNo != 'Y') {
            printf("Do you want to continue? (Y/N): ");
            scanf(" %c", &yesOrNo);
            if (yesOrNo == 'n' || yesOrNo == 'N') {
                exit(EXIT_FAILURE);
            }

        }
//same loop as before but condition is for if the user says 'y' or 'Y' the first time.
    }
    return 0;
}