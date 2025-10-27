#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
float plus(float A, float B) {//plus function
    return A + B;
}

float minus(float A, float B) {//minus function
    return A - B;
}

float times(float A, float B) {//times function
    return A * B;
}

float division(float A, float B) {//division function
    if (B == 0) {
        printf("Error: division by zero!\n");
        return A; //keep the previous value
    }
    return A / B;
}

int main() {
    char select;//select as type char variable
    float TOTAL = 0, number;//TOTAL and Number variables
    int start = 0; //control if it's the first operator

    printf("=== Ismael's Calculator ===\n\n");

    while (1) { //while be 1, it will repeat, of course, it means that repeation will always be true until type up S option from "Scanf"
        if (!start) {
            printf("Type First number: "); 
            scanf("%f", &TOTAL);
            start = 1; // mark that the total started
        }

        printf("\nOperators (+, -, *, /, R to reset, Q to quit): ");
        scanf(" %c", &select); //space ignores previous ENTERs

        if (select == 'Q' || select == 'q') {
        	printf("\nTotal Results: %.2f\n", TOTAL);
            printf("\nQuitting...\n");
            return 0;
            break;
        }

        if (select == 'R' || select == 'r') {
            printf("\nTotal Result: %.2f\n", TOTAL);
            TOTAL = 0;
            start = 0;
            printf("Total reset!\n\n");
            system("pause");//
            system("cls");//it will clear the terminal
            continue;
        }

        printf("type the next number: ");
        scanf("%f", &number);

        switch (select) {
            case '+':
                TOTAL = plus(TOTAL, number);
                break;
            case '-':
                TOTAL = minus(TOTAL, number);
                break;
            case '*':
                TOTAL = times(TOTAL, number);
                break;
            case '/':
                TOTAL = division(TOTAL, number);
                break;
            default:
                printf("Invalid Operator!\n");
                continue;
        }
        printf("Current Total: %.2f\n", TOTAL);
    }
    return 0;
}

