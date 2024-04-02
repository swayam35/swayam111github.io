#include<stdio.h>
#include<stdlib.h>

int main() {
    int a[2][2], i, j;
    
    // Input
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("Enter number at position (%d, %d): ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    
    // Output
    printf("\nMatrix:\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("\t%d", a[i][j]);
        }
        printf("\n");
    }
    
    getchar(); // To wait for a character input before exiting
    return 0;
}
