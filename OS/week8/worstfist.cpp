#include<stdio.h>
#include<math.h>
int main() {
    int nb, np;
    printf("Enter the number of processes\n");
    scanf("%d", &np);
    printf("Enter the number of blocks\n");
    scanf("%d", &nb);

    int b[nb], p[np];
    printf("Enter the size of processes\n");
    for(int i = 0; i < np; i++) {
        printf("Size of p%d: ", (i+1));
        scanf("%d", &p[i]);
    }

    printf("Enter the size of blocks\n");
    for(int i = 0; i < nb; i++) {
        printf("Size of b%d: ", (i+1));
        scanf("%d", &b[i]);
    }

    int b1[nb];  
    for(int i = 0; i < nb; i++) {
        b1[i] = 0; 
    }

    int p1[np];  
    for(int i = 0; i < np; i++) {
        p1[i] = 0; 
    }

   
    for(int i = 0; i < np; i++) {
        int lowest = -1; 
        int bestBlock = -1;
        
        for(int j = 0; j < nb; j++) {
            if(b1[j] == 0 && b[j] >= p[i]) {  
                int temp = b[j] - p[i];
                if(temp >lowest) {
                    lowest = temp;
                    bestBlock = j;
                }
            }
        }

        
        if(bestBlock != -1) {
            p1[i] = bestBlock + 1;  
            b1[bestBlock] = 1; 
    }
    }

   
    for(int i = 0; i < np; i++) {
        if(p1[i] != 0) {
            printf("p%d(%d) -> b%d\n", (i+1), p[i], p1[i]);
        } else {
            printf("No allocation for p%d\n", (i+1));
        }
    }

    return 0;
}
