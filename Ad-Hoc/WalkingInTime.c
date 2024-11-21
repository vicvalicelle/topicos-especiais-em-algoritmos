// beecrowd 2235 - Walking in Time

#include <stdio.h>

int main() {
    int credit1, credit2, credit3;  // Declare variables for the three credits
    scanf("%d %d %d", &credit1, &credit2, &credit3);  // Read the values of the credits

    // Check if it's possible to return to the present by using the credits
    if (credit1 == credit2 || credit1 == credit3 || credit2 == credit3 || 
        credit1 + credit2 == credit3 || credit1 + credit3 == credit2 || 
        credit2 + credit3 == credit1) {
        printf("S\n");  // If it's possible to return to the present, print "S"
    } else {
        printf("N\n");  // Otherwise, print "N"
    }

    return 0;  // End the program
}
