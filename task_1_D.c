//
// Created by adria on 12/04/2025.
//
#include <stdio.h> //Standard input output header
#include <string.h> //String handling

#define MAX_CATEGORIES 100 //Derective for number of expenses
#define NAME_LEN 50 //Max lengh of category names

int main(void) {
    int num_categories;//Number of user categories
    char flag;//Rerun control flag

    do { //rerun loop
        char category_name[MAX_CATEGORIES][NAME_LEN]; //arrays for category names and expanses for 2 weeks
        float week1_expense[MAX_CATEGORIES];
        float week2_expense[MAX_CATEGORIES];
        float weekly_budget;//User defined budget limit
        float total_week1 = 0.0, total_week2 = 0.0;//Tosal expenses for week 1 and week 2
        printf("Set your weekly budget limit: "); //Prompts for user
        scanf("%f", &weekly_budget);
        printf("Enter the number of expense categories: ");
        scanf("%d", &num_categories);
        for (int i = 0; i < num_categories; i++) { //week 1 expenses with validation for negative numbers
            printf("Enter name of category #%d: ", i + 1);
            scanf("%s", category_name[i]);
        }
        printf("\e[38;5;75mWEEK 1\n ____________________________________________\e[0m\n");
        for (int i = 0; i < num_categories; i++) {
            float expense;
            do {
                printf("Enter expense for %s: ", category_name[i]);
                scanf("%f", &expense);
                if (expense < 0)
                    printf("Expense must be a positive value. Try again.\n");
            } while (expense < 0);
            week1_expense[i] = expense; //valid expense week 1
            total_week1 += expense;//Adding tottal to week 1
        }
        printf("\e[38;5;158mWEEK 2\n ____________________________________________\e[0m\n");
        for (int i = 0; i < num_categories; i++) {
            float expense;
            do { //do-while loop
                printf("Enter expense for %s: ", category_name[i]);
                scanf("%f", &expense);
                if (expense < 0) //loop until the value is negative
                    printf("Expense must be a positive value. Try again...\n");
            } while (expense < 0);
            week2_expense[i] = expense;//valid expenses
            total_week2 += expense;//Adding to week 2 total
        }
        printf("\n\e[1;34m--- EXPENSE SUMMARY ---\e[0m\n");//expense summary message
        for (int i = 0; i < num_categories; i++) {
            float percent_w1 = (week1_expense[i] / total_week1) * 100;
            float percent_w2 = (week2_expense[i] / total_week2) * 100;
            printf("%s:\n", category_name[i]);
            printf("  Week 1 = %.2f (%.2f%% of Week 1 in total)\n", week1_expense[i], percent_w1);
            printf("  Week 2 = %.2f (%.2f%% of Week 2 in total)\n", week2_expense[i], percent_w2);
            if (week2_expense[i] > week1_expense[i]) //comparing expenses between weeks
                printf("  \e[1;31mINCREASED\e[0m\n");
            else if (week2_expense[i] < week1_expense[i])
                printf("  \e[0;32mDECREASED\e[0m\n");
            else
                printf("\e[0;32  NO CHANGE\e[0m\n");
        }
        printf("\n\e[1;33m--- WEEKLY TOTALS ---\e[0m\n");//Displying total expenses for both weeks
        printf("Total Week 1 Expenses: %.2f\n", total_week1);
        printf("Total Week 2 Expenses: %.2f\n", total_week2);
        printf("\n\e[1;36m--- BUDGET STATUS ---\e[0m\n");
        if (total_week1 <= weekly_budget) //busget status display
            printf("WEEK 1: \e[0;32mWithin Budget\e[0m\n");
        else
            printf("WEEK 1: \e[1;31mExceeded Budget\e[0m\n");
        if (total_week2 <= weekly_budget)
            printf("WEEK 2: \e[0;32mWithin Budget\e[0m\n");
        else
            printf("WEEK 2: \e[1;31mExceeded Budget\e[0m\n");
        if (total_week2 > total_week1)
            printf("\n\e[1;31mSPENDING INCREASED\e[0m\n");
        else if (total_week2 < total_week1)
            printf("\n\e[0;32mSPENDING DECREASED\e[0m\n");
        else
            printf("\nSPENDING REMAINED THE SAME\n");
        printf("\nDo you want to run the program again? (Y/N): "); //Rerun program message
        scanf(" %c", &flag);
    } while (flag == 'Y' || flag == 'y');

    return 0;//program term
}
