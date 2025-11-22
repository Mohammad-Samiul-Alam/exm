#include<stdio.h>
int main() {
    int n,f,i,j;
    int pages[30],frames[10];
    int k=0, page_fault = 0;
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
    }
    printf("\nPage\tFrames\n");
    for(i=0;i<n;i++) {
        int avail = 0;
        for(j=0; j<f; j++) {
            if(frames[j] == pages[i]) {
                avail = 1;
                break;
            }
        }
        if(avail == 0) {
            frames[k] = pages[i];
            k = (k+1) % f; //move to next circularly
            page_fault++;
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
    printf("\nTotal page faults: %d\n", page_fault);
    return 0;
}