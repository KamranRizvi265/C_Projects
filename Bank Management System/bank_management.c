#include<stdio.h>
#include<string.h>

const char *ACCOUNT_FILE = "account.dat";  // File to store account information

typedef struct  // Structure to hold bank account information
{
    char name[50];
    int number;;
    float balance;
} Bank;

Bank bank_write;    // Structure for writing account information
Bank bank_read;     // Structure for reading account information
Bank bank_deposit;  // Structure for depositing money
Bank bank_withdraw; // Structure for withdrawing money


void create_account();  // Function to create a new bank account
void deposit_money();   // Function to deposit money into an account
void withdraw_money();  // Function to withdraw money from an account
void check_balance();   // Function to check the balance of an account

int main()
{
    while(1)
    {
        printf("\n*** Bank Management System ***\n");
        printf("1. Create Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Check Balance");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);
        getchar();

        switch (choice)  // Switch case to handle user choices
        {
            case 1:  // Create a new account
                create_account();
                break;

            case 2:  // Deposit money into an existing account
                deposit_money();
                break;

            case 3:  // Withdraw money from an existing account
                withdraw_money();
                break;

            case 4:  // Check the balance of an existing account
                check_balance();
                break;
            
            case 5:  // Exit the program
                printf("\nExiting the Bank Management System. Thank you!\n");
                printf("Developed by: Kamran Rizvi\n");
                return 0;
            
            default:  // Handle invalid choices
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}

void create_account()   // Function to create a new bank account
{
    FILE *file;
    file = fopen(ACCOUNT_FILE, "ab+"); // Open file in append mode to add new account
    if (file == NULL)                  // Check if the file opened successfully
    {
        printf("Error opening file!\n");
        return;
    }

    printf("\nCreating Account...\n");
    printf("Enter your name: ");
    fgets(bank_write.name, sizeof(bank_write.name), stdin);  // Read name input from user
    bank_write.name[strcspn(bank_write.name, "\n")] = 0;     // Remove newline character from name input

    printf("Enter your account number: ");
    scanf("%d", &bank_write.number);
    getchar();
    bank_write.balance = 0.0;  // Initialize balance to 0.0

    if (strlen(bank_write.name) == 0)  // Validate name input
    {
        printf("Invalid name! Please enter a valid name.\n");
        fclose(file);
        file = NULL;
        return;
    }

    if (bank_write.number <= 0)  // Validate account number
    {
        printf("Invalid account number! Please enter a positive value.\n");
        fclose(file);
        file = NULL;
        return;
    }

    fwrite(&bank_write, sizeof(bank_write), 1, file);  // Write account information to file
    fclose(file);
    file = NULL;

    printf("Account created successfully!\n");
}

void deposit_money()   // Function to deposit money into an existing account
{
    FILE *file;
    file = fopen(ACCOUNT_FILE, "rb+");  // Open file in read/write mode to update account information
    if (file == NULL)   
    {
        printf("Error opening file!\n");
        return;
    }

    int account_number;
    float money;

    printf("\nDepositing Money...\n");
    printf("Enter account number: ");
    scanf("%d", &account_number);

    printf("Enter amount to deposit: ");
    scanf("%f", &money);
    if (money <= 0)
    {
        printf("Invalid amount! Please enter a positive value.\n");
        fclose(file);
        file = NULL;
        return;
    }

    while( fread(&bank_deposit, sizeof(bank_deposit), 1, file) )  // Read each account from the file
    {
        if (bank_deposit.number == account_number)  // Check if account number matches
        {
            bank_deposit.balance += money;
            fseek(file, -sizeof(bank_deposit), SEEK_CUR);  // Move the file pointer back to the current account
            fwrite(&bank_deposit, sizeof(bank_deposit), 1, file);  // Write updated account information back to file
            fclose(file);
            file = NULL;
            printf("Rs %.2f deposited successfully!\n", money);
            return;
        }
    }
    printf("Account not found!\n");
    fclose(file);
    file = NULL;
}

void withdraw_money()   // Function to withdraw money from an existing account
{
    FILE *file;
    file = fopen(ACCOUNT_FILE, "rb+");  // Open file in read/write mode to update account information
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    int account_number;
    float money;

    printf("\nWithdrawing Money...\n");
    printf("Enter account number: ");
    scanf("%d", &account_number);

    printf("Enter amount to withdraw: ");
    scanf("%f", &money);
    if (money <= 0)  // Validate the withdrawal amount
    {
        printf("Invalid amount! Please enter a positive value.\n");
        fclose(file);
        file = NULL;
        return;
    }

    while( fread(&bank_withdraw, sizeof(bank_withdraw), 1, file) )  // Read each account from the file
    {
        if (bank_withdraw.number == account_number && bank_withdraw.balance >= money)  // Check if account number matches and sufficient balance exists
        {
            bank_withdraw.balance -= money;
            fseek(file, -sizeof(bank_withdraw), SEEK_CUR);  // Move the file pointer back to the current account
            fwrite(&bank_withdraw, sizeof(bank_withdraw), 1, file);  // Write updated account information back to file
            fclose(file);
            file = NULL;
            printf("Rs %.2f withdrawn successfully!\n", money);
            return;
        }
        else if (bank_withdraw.number == account_number && bank_withdraw.balance < money)  // Check if account number matches but insufficient balance exists
        {
            printf("Insufficient balance!\n");
            fclose(file);
            file = NULL;
            return;
        }
    }
    printf("Account not found!\n");
    fclose(file);
    file = NULL;
}

void check_balance()  // Function to check the balance of an existing account
{
    int account_number;
    printf("\nChecking Balance...\n");
    printf("Enter account number: ");
    scanf("%d", &account_number);
    getchar();  // Clear the input buffer

    FILE *file;
    file = fopen(ACCOUNT_FILE, "rb");  // Open file in read mode to check account balance
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    while ( fread(&bank_read, sizeof(bank_read), 1, file) )   // Read each account from the file
    {
        if (bank_read.number == account_number)  // Check if account number matches
        {
            printf("Account Holder: %s\n", bank_read.name);
            printf("Account Number: %d\n", bank_read.number);
            printf("Current Balance: Rs %.2f\n", bank_read.balance);
            fclose(file);
            file = NULL;
            return;
        }
    }
    printf("Account not found!\n");
    fclose(file);
    file = NULL;
}