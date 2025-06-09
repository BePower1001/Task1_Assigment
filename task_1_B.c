//
// Created by adria on 07/04/2025.
//
#include <stdio.h> //Standard input-output header
//#include <conio.h> //Console input.output functions header

int main(void) { //Main function
    float Groceries, Rent, Utilities, total_w_expenses, weekly_budget; // Declared variables
    printf("Set your budget limit: ", weekly_budget); //User set up budget
    scanf("%f", &weekly_budget); //Assigning budget value to the variable
    printf("Enter Groceries expences:  \n"); //User groceries expences
    scanf("%f", &Groceries); //Assigning budget value to the variable
    if (Groceries < 0) { //negative numbers prevention
        printf("Groceries expences must be positive value\n");
    }
    printf("Enter Rent expences:  \n");
    scanf("%f", &Rent); //getting user input into Rent
    if (Rent < 0) { //negative numbers prevention
        printf("Rent expences must be positive value\n");
    }
    printf("Enter Utilities expences:  \n");
    scanf("%f", &Utilities); //getting user input into Utilities
    if (Utilities < 0) { //negative numbers prevention
        printf("Groceries expences must be positive value\n");
    }
    total_w_expenses = Groceries + Utilities + Rent; // Sum of total expenses
    if (total_w_expenses < weekly_budget) {
        printf("\e[0;32mYou are within budget\e[0m [%.2f] - \e[38;5;214mYour total expences is:\e[0m %.2f\n",weekly_budget, total_w_expenses);
    }
    else printf ("\e[1;31m YOU EXCEED YOUR BUDGET!!!\e[0m - [%.2f] \n Your total expences is: %.2f", weekly_budget, total_w_expenses);
    // User output from variable (total_w_expense) in 2 decimal numbers
    return 0; //No argument returned to main function
}
