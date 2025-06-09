#include <stdio.h>
#include <string.h>
#include <conio.h> // Add this include for Windows

#define MAX_USERS 10 // Maximum number of users that can be registered
#define CREDENTIAL_LENGTH 30 // Maximum length for username and password

typedef struct  // Structure to hold user credentials
{
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];
} User ;

User user[MAX_USERS];  // Array to hold registered users
int user_count = 0;    // Counter for the number of registered users

void register_user();  // Function to register a new user
int login_user();      // Function to log in an existing user
void input_credentials(char *username, char *password); // Function to input credentials
void input_username(char *username); // Function to input username
void input_password(char *password); // Function to input password

int main()
{
    while(1)
    {
        int option;
        printf("\nWelcome to User Management System\n");
        printf("1. Register");
        printf("\n2. Login");
        printf("\n3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        getchar(); // Consume the newline character left by scanf
        
        switch(option)
        {
            case 1:  // Register a new user
            {
                register_user();
                break;
            }
            case 2:  // Login an existing user
            {
                int user_index = login_user();
                if (user_index >= 0)
                {
                    printf("Login successful! Welcome, %s\n", user[user_index].username);
                }
                else
                {
                    printf("Login failed! Invalid username or password.\n");
                }
                break;
            }
            case 3:  // Exit the program
            {
                printf("\nExiting...\n");
                printf("Developed by: Kamran Rizvi\n");
                return 0;
            }
            default:  // Handle invalid option
            {
                printf("Invalid option! Please try again.\n");
                break;
            }
        }
    }
    return 0;
}

void register_user()  // Function to register a new user
{
    if(user_count >= MAX_USERS)  // Check if user limit has been reached
    {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }
    printf("\nRegister a new user");
    input_credentials(user[user_count].username, user[user_count].password); // Function to input credentials

    printf("Registration successful!\n");
    user_count++;  // Increment the user count
}

int login_user()  // Function to log in an existing user
{
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];
    printf("\nLogin to your account");
    input_credentials(username, password); // Function to input credentials

    for(int i = 0; i < user_count; i++)
    {
        if(strcmp(user[i].username, username) == 0 && strcmp(user[i].password, password) == 0)  // Checking if credentials match
        {
            return i; // Return index of the logged-in user
        }
    }
    return -1; // Return -1 if login fails
}

void input_credentials(char *username, char *password)
{
    input_username(username); // Function to input username
    input_password(password); // Function to input password
}

void input_username(char *username)  // Function to input username
{
    printf("\nEnter username: ");
    fgets(username, CREDENTIAL_LENGTH, stdin);
    username[strcspn(username, "\n")] = 0; // Remove newline character
}

void input_password(char *password)  // Function to input password with masking
{
    printf("Enter password: ");
    int i = 0;
    char ch;
    while ((ch = getch()) != '\r' && i < CREDENTIAL_LENGTH - 1) // '\r' is Enter key
    {
        if (ch == '\b')  // Handle backspace
        {
            if (i > 0) 
            {
                i--;
                printf("\b \b");
            }
        } 
        else 
        {
            password[i++] = ch;
            printf("*"); // Mask the character
        }
    }
    password[i] = '\0';
    printf("\n");
}