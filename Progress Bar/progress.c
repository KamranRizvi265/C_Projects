#include<stdio.h>
#include<stdlib.h> // For system function
#include<unistd.h> // For sleep function
#include<time.h> // For time function

typedef struct
{
    int id;
    int progress;
    int step;   
}Task;

const int BAR_LENGTH = 50; // Length of the progress bar
const int MAX_TASKS = 5; // Maximum number of tasks

void print_progress_bars(Task task);  // Function prototype to print progress bars
void clear_screen(); // Function prototype to clear the console screen

int main()
{
    Task task[MAX_TASKS]; // Array to hold tasks
    srand(time(NULL)); // Seed the random number generator
    for(int i = 0; i< MAX_TASKS; i++)
    {
        task[i].id = i + 1; // Assign task ID starting from 1
        task[i].progress = 0; // Initialize progress to 0
        task[i].step = rand() % 10 + 1; // Random step size between 1 and 10
    }

    int tasks_incomplete = 1;
    while(tasks_incomplete)
    {
        clear_screen(); // Clear the console screen
        tasks_incomplete = 0;
        for(int i = 0; i < MAX_TASKS; i++)
        {
            task[i].progress += task[i].step; // Increment progress by step size
            if(task[i].progress < 100)
            {
                tasks_incomplete = 1; // If any task is not complete, set flag to 1
            }
            print_progress_bars(task[i]); // Print the progress bar for each task
        }
        sleep(1); // Sleep for 1 second
    }
    printf("All tasks completed!\n");

    return 0;
}

void print_progress_bars(Task task)
{
    int bars_to_show = (task.progress * BAR_LENGTH) / 100; // Calculate how many bars to show based on progress
    printf("\nTask %d: [", task.id);
    for(int i = 0; i < BAR_LENGTH; i++)  // Loop through the length of the bar
    {
        if(i < bars_to_show)
        {
            printf("="); // Print filled part of the bar
        }
        else
        {
            printf(" "); // Print empty part of the bar
        }
    }
    if(task.progress < 0)
    {
        task.progress = 0; // Ensure progress is not negative
    }
    else if (task.progress > 100)
    {
        task.progress = 100; // Ensure progress does not exceed 100
    }
    printf("] %d%%\n", task.progress);
}

void clear_screen()
{
    #ifdef _WIN32
        system("cls"); // Clear the console screen on Windows
    #else
        system("clear"); // Clear the console screen on Unix/Linux/MAC
    #endif
}