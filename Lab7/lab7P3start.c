/* Lab 7 P3: starter code to complete*/
#include <stdio.h>
#include <string.h>

int main()
{
    char input[256];
    int letterCount[26] = {0}; // Array to store the count of each letter initialized to zeros

    printf("Enter text strings (press Enter on an empty line to exit):\n");

    while (1)
    {
        fgets(input, sizeof(input), stdin); // get the input from the user via keyboard

        // Check for an empty line to exit the loop
        if (strlen(input) == 1 && input[0] == '\n')
        {
            break;
        }
        // Your Code should be implemented here
        // Iterate through the characters in the input
        // Check if the character is a letter (A-Z or a-z)
        // Increment the corresponding count in the array
    }
    // More of your code here to
    // Display the letter counts

    return 0;
}