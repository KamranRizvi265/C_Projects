#include<stdio.h>
#include<time.h>
#include<unistd.h> // For sleep function
#include<stdlib.h> // For system function

void get_time(char *buffer, int format); // Function prototype to get the current time
void get_date(char *buffer); // Function prototype to get the current date
void clear_screen(); // Function prototype to clear the console screen

int main()
{
    char time_string[50]; // Buffer to hold the formatted time string
    char date_string[100]; // Buffer to hold the formatted date string
    int format; // Variable to hold the user's choice for time format
    printf("\nChoose the time format:");
    printf("\n1. 24-hour format");
    printf("\n2. 12-hour format (default)\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &format); // Read the user's choice for time format

    while(1)
    {
        get_time(time_string, format); // Call the function to get the current time
        get_date(date_string); // Call the function to get the current date
        clear_screen(); // Clear the console screen
        printf("\nTime: %s\n", time_string); // Print the formatted time
        printf("Date: %s\n", date_string); // Print the formatted date
        sleep(1); // Sleep for 1 second before updating the time and date
    }
    return 0;
}

void get_time(char *buffer, int format)
{
    time_t raw_time;         // Variable to hold the raw time
    struct tm *current_time; // Pointer to hold the broken-down time structure

    time(&raw_time); // Get the current time in seconds since the epoch
    current_time = localtime(&raw_time); // Convert raw time to local time
    if (format == 1)
    {
        strftime(buffer, 50, "%H:%M:%S", current_time); // Format the time into a string
    }
    else
    {
        strftime(buffer, 50, "%I:%M:%S %p", current_time); // Format the time into a string
    }
}

void get_date(char *buffer)
{
    time_t raw_time;         // Variable to hold the raw time
    struct tm *current_time; // Pointer to hold the broken-down time structure

    time(&raw_time); // Get the current time in seconds since the epoch
    current_time = localtime(&raw_time); // Convert raw time to local time

    strftime(buffer, 50, "%A %d %b %Y", current_time); // Format the date into a string
}

void clear_screen()
{
    #ifdef _WIN32
        system("cls"); // Clear the console screen on Windows
    #else
        system("clear"); // Clear the console screen on Unix/Linux/MAC
    #endif
}