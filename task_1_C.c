//
// Created by adria on 07/04/2025.
//
#include <stdio.h> //Standard input-output header
//#include <conio.h> //Console input.output functions header

int main(void) { //Main function
    char flag;
    do {
    float Groceries1, Rent1, Utilities1, total_w_expenses1, weekly_budget; // Declared variables
        float Groceries2, Rent2, Utilities2, total_w_expenses2; // Declared variables
    printf("Set your budget limit:\n"); // User set up budget
    scanf("%f", &weekly_budget); // Assigning budget value to the variable
        printf("\e[38;5;75mWEEK 1\n \e[38;5;75m____________________________________________\e[0m\n");
    printf("Enter Groceries expences:  \n"); //User groceries expences
    scanf("%f", &Groceries1); // Assigning budget value to the variable
    if (Groceries1 < 0) { // Negative numbers prevention
        printf("Groceries expences must be positive value\n");
    }
        printf("\e[38;5;75mWEEK 1\n ____________________________________________\e[0m\n");
    printf("Enter Rent expences:  \n");
    scanf("%f", &Rent1);
    if (Rent1 < 0) { //Negative numbers prevention
        printf("Groceries expences must be positive value\n");
    }
        printf("\e[38;5;75mWEEK 1\n ____________________________________________\e[0m\n");
    printf("Enter Utilities expences:  \n");
    scanf("%f", &Utilities1);
    if (Utilities1 < 0) { // Negative numbers prevention
        printf("Groceries expences must be positive value\n");
    }
        printf("\e[38;5;158mWEEK 2\n ____________________________________________\e[0m\n");
 printf("Enter Groceries expences: \n"); //User groceries expences
        scanf("%f", &Groceries2); // Assigning budget value to the variable
        if (Groceries2 < 0) { // Negative numbers prevention
            printf("Groceries expences must be positive value\n");
        }
        printf("\e[38;5;158mWEEK 2\n ____________________________________________\e[0m\n");
    printf("Enter Rent expences:  \n");
        scanf("%f", &Rent2);
        if (Rent2 < 0) { //Negative numbers prevention
            printf("Groceries expences must be positive value\n");
        }
        printf("\e[38;5;158mWEEK 2 \n ____________________________________________\e[0m\n");
    printf("Enter Utilities expences:  \n");
        scanf("%f", &Utilities2);
        if (Utilities2 < 0) { // Negative numbers prevention
            printf("Groceries expences must be positive value\n");
        }
    total_w_expenses1 = Groceries1 + Utilities1 + Rent1; // Sum of total expenses
        total_w_expenses2 = Groceries2 + Utilities2 + Rent2;
    if (total_w_expenses1 < weekly_budget) {
        printf("\e[0;32mYou are within budget in WEEK 1\e[0m [%.2f] - \e[38;5;214mYour total in WEEK 1 is:\e[0m %.2f\n\n",weekly_budget, total_w_expenses1);
    }
        if (total_w_expenses2 < weekly_budget) {
            printf("\e[0;32mYou are within budget in WEEK 2\e[0m [%.2f] - \e[38;5;214mYour total in WEEK 2 is:\e[0m %.2f\n\n",weekly_budget, total_w_expenses2);
        } else {
            printf ("\e[1;31mYOU EXCEED YOUR WEEK 2 BUDGET!\e[0m - [%.2f] \nYour total in WEEK 2 is: %.2f\n\n", weekly_budget, total_w_expenses2);
        }

    // User output from variable (total_w_expense) in 2 decimal numbers
    if (total_w_expenses2 > total_w_expenses1) {
        printf("\e[1;31mSPENDING INCREASED!!! :( \e[0m \n\n");
    }   else if (total_w_expenses1 > total_w_expenses2) {
        printf("\e[0;32mSPENDING DECREASED :) \e[0m\n\n");
    }   else {
        printf ("SPENDING REMAIN THIS SAME\n\n");
    }
        printf("Do you want to run this program again? (Yes/No)\n");
        scanf(" %c", &flag); // Added a space before %c to consume any leftover newline
    } while (flag == 'Y' || flag == 'y'); // Loop will continue if the user enters Yes or y

    return 0;
}
