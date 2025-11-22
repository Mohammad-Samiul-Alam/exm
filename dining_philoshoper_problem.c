#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5 // Number of philosophers

// Mutex for each fork
pthread_mutex_t forks[N];

// Philosopher function
void* philosopher(void* num) {
    int id = *(int*)num;

    while(1) {
        printf("Philosopher %d is thinking.\n", id);
        sleep(1); // Thinking

        // Pick up forks
        if (id % 2 == 0) {
            pthread_mutex_lock(&forks[id]);           // Pick left fork
            pthread_mutex_lock(&forks[(id + 1) % N]); // Pick right fork
        } else {
            pthread_mutex_lock(&forks[(id + 1) % N]); // Pick right fork
            pthread_mutex_lock(&forks[id]);           // Pick left fork
        }

        // Eating
        printf("Philosopher %d is eating.\n", id);
        sleep(2);

        // Put down forks
        pthread_mutex_unlock(&forks[id]);
        pthread_mutex_unlock(&forks[(id + 1) % N]);

        printf("Philosopher %d finished eating and goes back to thinking.\n", id);
        sleep(1);
    }
}

int main() {
    pthread_t philosophers[N];
    int ids[N];

    // Initialize mutexes
    for(int i = 0; i < N; i++) {
        pthread_mutex_init(&forks[i], NULL);
        ids[i] = i;
    }

    // Create philosopher threads
    for(int i = 0; i < N; i++) {
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    // Join threads (infinite loop, so it won't actually finish)
    for(int i = 0; i < N; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy mutexes
    for(int i = 0; i < N; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
