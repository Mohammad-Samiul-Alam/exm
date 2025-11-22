#include <stdio.h>

int main() {
    int n, start, length, i;
    printf("Enter total blocks on disk: ");
    scanf("%d", &n);

    int disk[n];
    for(i = 0; i < n; i++) disk[i] = 0;

    printf("Enter starting block of file: ");
    scanf("%d", &start);
    printf("Enter length of file: ");
    scanf("%d", &length);

    for(i = start; i < start + length; i++) {
        if(i < n) disk[i] = 1;
        else {
            printf("Disk overflow!\n");
            break;
        }
    }

    printf("Disk allocation: ");
    for(i = 0; i < n; i++) printf("%d ", disk[i]);
    printf("\n");
    return 0;
}
