// beecrowd 2234 - Hot Dogs

#include <stdio.h>

int main() {
    float total_hotdogs, total_participants, average_hotdogs;  // Declare variables for total hotdogs, total participants, and the average

    scanf("%f %f", &total_hotdogs, &total_participants);  // Read the values for total hotdogs and participants

    average_hotdogs = total_hotdogs / total_participants;  // Calculate the average number of hotdogs per participant

    printf("%.2f", average_hotdogs);  // Print the average with 2 decimal places
    printf("\n");  // Print a newline at the end

    return 0;  // End the program
}
