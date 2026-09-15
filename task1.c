#include <stdio.h>

int main() {
    int category, destination;
    int age, baggage, allowance;
    int documents;
    int remainder;
    int priority;

    printf("Enter Passenger Category:\n");
    printf("1. Adult\n");
    printf("2. Student\n");
    printf("3. Senior Citizen\n");
    printf("Enter choice: ");
    scanf("%d", &category);

    printf("\nEnter Destination Type:\n");
    printf("1. Domestic\n");
    printf("2. International\n");
    printf("Enter choice: ");
    scanf("%d", &destination);

    printf("\nEnter passenger age: ");
    scanf("%d", &age);

    printf("Enter actual baggage weight (kg): ");
    scanf("%d", &baggage);

    switch (category) {

        case 1:
            printf("\nPassenger Category: Adult\n");

            switch (destination) {
                case 1:
                    allowance = 20;
                    printf("Destination: Domestic\n");
                    break;

                case 2:
                    allowance = 30;
                    printf("Destination: International\n");
                    break;

                default:
                    printf("Invalid destination!\n");
                    return 0;
            }
            break;

        case 2:
            printf("\nPassenger Category: Student\n");

            switch (destination) {
                case 1:
                    allowance = 25;
                    printf("Destination: Domestic\n");
                    break;

                case 2:
                    allowance = 35;
                    printf("Destination: International\n");
                    break;

                default:
                    printf("Invalid destination!\n");
                    return 0;
            }
            break;

        case 3:
            printf("\nPassenger Category: Senior Citizen\n");

            switch (destination) {
                case 1:
                    allowance = 30;
                    printf("Destination: Domestic\n");
                    break;

                case 2:
                    allowance = 40;
                    printf("Destination: International\n");
                    break;

                default:
                    printf("Invalid destination!\n");
                    return 0;
            }
            break;

        default:
            printf("Invalid passenger category!\n");
            return 0;
    }

    printf("Permitted Baggage Allowance: %d kg\n", allowance);
    printf("Actual Baggage Weight: %d kg\n", baggage);

    printf("\nAre travel documents valid?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter choice: ");
    scanf("%d", &documents);

    remainder = age % 5;

    printf("\nVerification Category: ");

    switch (remainder) {
        case 0:
            printf("Category A\n");
            break;

        case 1:
            printf("Category B\n");
            break;

        case 2:
            printf("Category C\n");
            break;

        case 3:
            printf("Category D\n");
            break;

        case 4:
            printf("Category E\n");
            break;
    }

    priority = (category == 3) ||
               (category == 2 && destination == 2);

    printf("Priority Assistance: %s\n",
           priority ? "Available" : "Not Available");

    printf("\n--- Boarding Decision ---\n");

    if (documents != 1) {
        printf("Document Status: Invalid\n");
        printf("Final Decision: DENIED BOARDING\n");
    }
    else if (baggage <= allowance && documents == 1) {
        printf("Document Status: Valid\n");
        printf("Final Decision: NORMAL BOARDING\n");
    }
    else if (baggage > allowance && documents == 1) {
        printf("Document Status: Valid\n");
        printf("Final Decision: ENHANCED BAGGAGE SCREENING\n");
    }
    else {
        printf("Final Decision: DENIED BOARDING\n");
    }

    return 0;
}