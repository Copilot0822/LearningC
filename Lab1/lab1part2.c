#include <stdio.h>
#include <math.h>
int main() {
    float originalBill;
    printf("Enter the original bill amount:");
    scanf("%f", &originalBill);
    printf("\nEnter the tip percentage: ");
    int tipper;
    scanf("%d", &tipper);
    int people;
    printf("\nEnter the number of people splitting the bill: ");
    scanf("%d", &people);
    double totalBill = originalBill*(((float)tipper/100)+1);
    printf("The total bill including tip is: %.2lf", totalBill);
    printf("\nEach person should pay: %.2lf", totalBill/people);
    return 0;
}