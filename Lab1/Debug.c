#include <stdio.h>

int main(void) {
    const double poundPerKg = 2.20462;
    const double OuncesPerPound = 16.0;
    double weight;
    printf("Please enter a weight in kilograms: ");
    scanf("%lf", &weight);
    double weightInPounds = weight * poundPerKg;

    // Truncate fractional part to get the whole number of pounds
    int pounds = weightInPounds;
    weightInPounds = weightInPounds - pounds;

    // Convert remaining pounds to ounces
    double totalOunces = weightInPounds * OuncesPerPound;

    // Truncate fractional part to get whole ounces
    int ounces = totalOunces;
    totalOunces = totalOunces - ounces;

    printf("%d pounds, %d ounces, %.3f ounces remainder\n", pounds, ounces, totalOunces);
    return 0;

    





}
