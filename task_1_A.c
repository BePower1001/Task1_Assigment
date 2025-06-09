//
// Created by adria on 07/04/2025.
//
#include <stdio.h> //Standard input-output header

int main(void) { //Main function
    float Groceries = 123.56, Rent = 1280, Utilities = 456.88, total_w_expences; // Assigned values to variables
    total_w_expences = Groceries + Utilities + Rent; // Sum of total expences
    printf("Totall weekly expence is: %.2f\n", total_w_expences); // User output from variable (total_w_expence)
    return 0; //No argument returned to main function
}