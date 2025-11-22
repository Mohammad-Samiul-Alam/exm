#include<stdio.h>
int main() {
    int n,f,i,j, pos, min;
    int pages[30], frames[10], times[10];
    int pages_fault = 0, count = 0;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    printf("Enter the page numbers: ");
    for(i=0;i<n;i++) {
        scanf("%d", &pages[i]);
    }
    for(i=0;i<f;i++) {
        frames[i] = -1;
        times[i] = 0;
    }
    printf("\nPage\tFrames\n");
    for(i=0;i<n;i++) {
        int avail = 0;
        for(j=0;j<f;j++) {
            if(frames[j] == pages[i]) {
                avail = 1;
                times[j] = ++count;
                break;
            }
        }
        if(avail == 0) {
            pos = 0;
            min = times[0];
            for(j=1;j<f;j++) {
                if(times[j] < min) {
                    min = times[j];
                    pos = j;
                }
            }
            frames[pos] = pages[i];
            times[pos] = ++count;
            pages_fault++;
        }
        printf("%d\t", pages[i]);
        for(j=0;j<f;j++) {
            if(frames[j] != -1) {
                printf("%d ", frames[j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\nPages faults : %d", pages_fault);
    return 0;
}