#include<stdio.h>
#include<stdlib.h>
int main() {
    int n,i,head,totalMovement = 0;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int request[n];
    printf("Enter the disk request sequence: ");
    for(i=0;i<n;i++){
        scanf("%d", &request[i]);
    }
    printf("Enter the head position: ");
    scanf("%d", &head);
    printf("Sequence of movement: \n");
    for(i=0;i<n;i++) {
        printf("%d -> %d\n", head, request[i]);
        totalMovement += abs(request[i] - head);
        head = request[i];
    }
    printf("\nTotal head movement = %d\n", totalMovement);
    printf("Average head movement = %.2f\n", (float)totalMovement);
    return 0;
}