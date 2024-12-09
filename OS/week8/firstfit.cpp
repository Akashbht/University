#include <stdio.h>
void firstFit(int blockSize[], int m, int p_size[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= p_size[i]) {
                allocation[i] = j;
                blockSize[j] = -1; 
                break;
            }
        }
    }
    printf("\nprocess no.\tprocess size\tblock \n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, p_size[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("not allocated \n");
    }
}
int main() {
    int m, n;
    printf("enter the no. of memory blocks :  ");
    scanf("%d", &m);
    int blockSize[m];
    printf("enter the size \n");
    for (int i = 0; i < m; i++) {
        printf("block  %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }
    printf("enter the no of proccesses : ");
    scanf("%d", &n);
    int p_size[n];
    printf("enter the size :\n");
    for (int i = 0; i < n; i++) {
        printf("p %d: ", i + 1);
        scanf("%d", &p_size[i]);
    }
    firstFit(blockSize, m, p_size, n);
    return 0;
}
