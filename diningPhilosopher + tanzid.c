#include <stdio.h>

int main() {
    int totalPhilosopher, i, hungryCount;
    int philosopher[20], hungryPosition[20], status[20]; 
    // 1 = Thinking, 2 = Hungry, 3 = Waiting

    printf("\n\n\t\tDINING PHILOSOPHER PROBLEM\n");

    // Total philosophers
    printf("\nEnter total number of Philosophers: ");
    scanf("%d", &totalPhilosopher);

    // Initialize
    for (i = 0; i < totalPhilosopher; i++) {
        philosopher[i] = i + 1;
        status[i] = 1;   // Initially Thinking
    }

    // Input hungry philosophers
    printf("\nHow many Hungry Philosophers: ");
    scanf("%d", &hungryCount);

    // Deadlock check
    if (hungryCount == totalPhilosopher) {
        printf("\nAll philosophers are hungry -> DEADLOCK OCCURS!\n");
        return 0;
    }

    // Taking hungry positions
    for (i = 0; i < hungryCount; i++) {
        int pos;
        do {
            printf("\nEnter Philosopher Position (1 to %d): ", totalPhilosopher);
            scanf("%d", &pos);

            if (pos < 1 || pos > totalPhilosopher)
                printf("Invalid Position! Try again.\n");

        } while (pos < 1 || pos > totalPhilosopher);

        hungryPosition[i] = pos;
        status[pos - 1] = 2;  // Set Hungry
    }

    // Display Status
    printf("\n\n\tPhilosopher\tStatus\n");
    printf("__________________________________\n");

    for (i = 0; i < totalPhilosopher; i++) {
        printf("%d\t\t", philosopher[i]);

        if (status[i] == 1)
            printf("Thinking\n");
        else if (status[i] == 2)
            printf("Hungry\n");
        else if (status[i] == 3)
            printf("Waiting\n");
    }

    // Safe Sequence (Max 2 Eating)
    printf("\n\nSafe Sequence: (Max 2 Philosophers Eating at a time)\n");

    int eatingCount = 0;

    for (i = 0; i < totalPhilosopher; i++) {
        if (status[i] == 2 && eatingCount < 2) {
            printf("Philosopher %d is EATING\n", philosopher[i]);
            eatingCount++;
        }
        else if (status[i] == 2) {
            status[i] = 3;
            printf("Philosopher %d is WAITING\n", philosopher[i]);
        }
    }

    printf("\nExecution Completed.\n\n");

    return 0;
}
