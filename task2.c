#include <stdio.h>

int main() {
    int department;
    int age, heartRate, consciousness, severity;
    float temperature;
    int departmentPriority = 0;
    int critical;
    int senior;
    int temperatureAlert;
    int caseCategory;

    printf("Hospital Emergency Triage System\n");

    printf("\nSelect Emergency Department:\n");
    printf("1. General Emergency\n");
    printf("2. Cardiology\n");
    printf("3. Neurology\n");
    printf("4. Trauma\n");
    printf("Enter choice: ");
    scanf("%d", &department);

    printf("\nEnter patient age: ");
    scanf("%d", &age);

    printf("Enter heart rate (BPM): ");
    scanf("%d", &heartRate);

    printf("Enter body temperature (C): ");
    scanf("%f", &temperature);

    printf("Level of consciousness:\n");
    printf("1. Conscious\n");
    printf("2. Unconscious\n");
    printf("Enter choice: ");
    scanf("%d", &consciousness);

    printf("Enter severity level (1-5): ");
    scanf("%d", &severity);

    switch (department) {

        case 1:
            printf("\nDepartment: General Emergency\n");

            switch (severity) {
                case 4:
                case 5:
                    departmentPriority = 1;
                    break;

                default:
                    departmentPriority = 0;
            }
            break;

        case 2:
            printf("\nDepartment: Cardiology\n");

            switch (heartRate) {
                case 0:
                    departmentPriority = 1;
                    break;

                default:
                    departmentPriority =
                        (heartRate < 50 || heartRate > 120);
            }
            break;

        case 3:
            printf("\nDepartment: Neurology\n");

            switch (consciousness) {
                case 2:
                    departmentPriority = 1;
                    break;

                default:
                    departmentPriority = 0;
            }
            break;

        case 4:
            printf("\nDepartment: Trauma\n");

            switch (severity) {
                case 4:
                case 5:
                    departmentPriority = 1;
                    break;

                default:
                    departmentPriority = 0;
            }
            break;

        default:
            printf("Invalid department!\n");
            return 0;
    }

    critical = (heartRate < 50 || heartRate > 120)
               && consciousness == 2;

    senior = age >= 65;

    temperatureAlert = temperature < 36 || temperature > 38;

    caseCategory = (age + heartRate) % 4;

    printf("\n--- Patient Classification ---\n");

    printf("Age: %d\n", age);
    printf("Heart Rate: %d BPM\n", heartRate);
    printf("Temperature: %.1f C\n", temperature);

    printf("Department-Specific Priority: %s\n",
           departmentPriority ? "Yes" : "No");

    printf("Critical Condition: %s\n",
           critical ? "Yes" : "No");

    printf("Senior Priority: %s\n",
           senior ? "Yes" : "No");

    printf("Temperature Alert: %s\n",
           temperatureAlert ? "Yes" : "No");

    switch (caseCategory) {
        case 0:
            printf("Case Category: A\n");
            break;

        case 1:
            printf("Case Category: B\n");
            break;

        case 2:
            printf("Case Category: C\n");
            break;

        case 3:
            printf("Case Category: D\n");
            break;
    }

    printf("\n--- Final Triage Decision ---\n");

    if (critical) {
        printf("Immediate Medical Attention Required\n");
    }
    else if (departmentPriority || senior || temperatureAlert) {
        printf("Priority Level: Further Assessment Required\n");
    }
    else {
        printf("Routine Medical Assessment\n");
    }

    return 0;
}