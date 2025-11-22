#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

sem_t mutex;
sem_t S[N];
int state[N];

void test(int i) {
    if(state[i] == HUNGRY && state[(i+4)%N] != EATING && state[(i+1)%N] != EATING) {
        state[i] = EATING;
        sem_post(&S[i]);
    }
}

void take_forks(int i) {
    sem_wait(&mutex);
    state[i] = HUNGRY;
    test(i);
    sem_post(&mutex);
    sem_wait(&S[i]);
}

void put_forks(int i) {
    sem_wait(&mutex);
    state[i] = THINKING;
    test((i+4)%N);
    test((i+1)%N);
    sem_post(&mutex);
}

void *philosopher(void *num) {
    int i = *(int*)num;
    while(1) {
        printf("Philosopher %d is thinking\n", i);
        sleep(1);
        take_forks(i);
        printf("Philosopher %d is eating\n", i);
        sleep(2);
        put_forks(i);
    }
}

int main() {
    int i;
    pthread_t thread_id[N];
    sem_init(&mutex, 0, 1);
    for(i = 0; i < N; i++)
        sem_init(&S[i], 0, 0);

    int phil[N];
    for(i = 0; i < N; i++) {
        phil[i] = i;
        pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
    }

    for(i = 0; i < N; i++)
        pthread_join(thread_id[i], NULL);

    return 0;
}
