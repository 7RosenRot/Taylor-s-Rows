#include "func.h"

int main(void) {
    printf("Select function to study:\n");
    printf("1. sin(x)\n");
    printf("2. cos(x)\n");
    printf("3. eˣ\n");
    printf("4. Check all\n");
    printf("Your choice: ");
    int choice;
    scanf("%i", &choice);
    
    printf("Select the number of row members: ");
    int quantity;
    scanf("%i", &quantity);

    printf("Select row step: ");
    double step;
    scanf("%lf", &step);

    printf("\n");
    HUD(quantity, step, choice);
}