#include<stdio.h>

float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
int modulus(int num1, int num2);
int power(int base, int exp);

int main()
{
    do
    {
        printf("\n========================================");
        printf("\nWelcome to Simple Calculator\n");
        printf("Choose one of the following options:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Power\n");
        printf("7. Exit\n");

        int choice;
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 7)
        {
            fprintf(stderr, "Invalid choice! Please select a number between 1 and 7.\n");
            continue; // Skip to the next iteration of the loop
        }

        // Declare variables for user input
        float a, b;
        int num1,num2;
        // Process the user's choice
        switch(choice)
        {
            case 1:   // Addition operation
                printf("Enter first number: ");
                scanf("%f", &a);
                printf("Enter second number: ");
                scanf("%f", &b);
                printf("Result: %f\n", add(a, b));
                break;
            case 2:   // Subtraction operation
                printf("Enter first number: ");
                scanf("%f", &a);
                printf("Enter second number: ");
                scanf("%f", &b);
                printf("Result: %f\n", subtract(a, b));
                break;
            case 3:   // Multiplication operation
                printf("Enter first number: ");
                scanf("%f", &a);
                printf("Enter second number: ");
                scanf("%f", &b);
                printf("Result: %f\n", multiply(a, b));
                break;
            case 4:   // Division operation
                printf("Enter first number: ");
                scanf("%f", &a);
                printf("Enter second number: ");
                scanf("%f", &b);
                if (b != 0) 
                {
                    printf("Result: %f\n", divide(a, b));
                } 
                else 
                {
                    fprintf(stderr, "Error: Division by zero is not allowed.\n");
                }
                break;
            case 5:    // Modulus operation
                printf("Enter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                if (num2 != 0) 
                {
                    printf("Result: %d\n", modulus(num1, num2));
                }
                else 
                {
                    fprintf(stderr, "Error: Modulus by zero is not allowed.\n");
                }
                break;
            case 6:    // Power operation
                printf("Enter base number: ");
                scanf("%d", &num1);
                printf("Enter exponent number: ");
                scanf("%d", &num2);
                if (num2 < 0) 
                {
                    fprintf(stderr, "Error: Negative exponent is not supported.\n");
                } 
                else 
                {
                    printf("Result: %d\n", power(num1, num2));
                }
                break;
            case 7:
                printf("\nExiting the calculator. Goodbye!\n");
                printf("Developed by: Kamran Rizvi\n");
                return 0; // Exit the program
        }
    } while (1);
}

float add(float a, float b)
{
    return a + b;
}

float subtract(float a, float b)
{
    return a - b;
}

float multiply(float a, float b)
{
    return a * b;
}

float divide(float a, float b)
{
    return a / b;
}

int modulus(int num1, int num2)
{
    return num1 % num2;
}

int power(int base, int exp)
{
    int result = 1;
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }
    return result;
}