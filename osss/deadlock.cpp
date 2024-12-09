#include <stdio.h>
int main(){
    int n, m;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);
    
    int alloc[n][m], max[n][m], rem[n][m], total[m];
    
    // Input maximum requirement matrix
    printf("Enter maximum requirement (each process on a new line):\n");
    for (int i = 0; i < n; i++){
        printf("Process P%d: ", i);
        for (int j = 0; j < m; j++){
            scanf("%d", &max[i][j]);
        }
    }
    
    // Input allocation matrix
    printf("Enter allocated matrix (each process on a new line):\n");
    for (int i = 0; i < n; i++){
        printf("Process P%d: ", i);
        for (int j = 0; j < m; j++){
            scanf("%d", &alloc[i][j]);
        }
    }
    
    // Input total resources
    printf("Enter total resources vector: ");
    for (int i = 0; i < m; i++){
        scanf("%d", &total[i]);
    }
    
    // Calculate available resources: avail = total - sum(alloc)
    int avail[m];
    for (int i = 0; i < m; i++){
        int sum_alloc = 0;
        for (int j = 0; j < n; j++){
            sum_alloc += alloc[j][i];
        }
        avail[i] = total[i] - sum_alloc;
    }
    
    // Calculate remaining (need) matrix
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            rem[i][j] = max[i][j] - alloc[i][j];
        }
    }
    
    // Initialize process completion status
    int done[n];
    for (int i = 0; i < n; i++){
        done[i] = 0;
    }
    
    // Deadlock detection algorithm
    int progress;
    do {
        progress = 0;
        for (int i = 0; i < n; i++){
            if (done[i] == 0) {  // If process i is not completed
                int canProceed = 1;
                
                // Check if all resource needs can be satisfied
                for (int j = 0; j < m; j++) {
                    if (rem[i][j] > avail[j]) {
                        canProceed = 0;
                        break;
                    }
                }
                
                // If process i can proceed
                if (canProceed) {
                    // Mark process as done
                    done[i] = 1;
                    progress = 1;
                    
                    // Release allocated resources
                    for (int j = 0; j < m; j++) {
                        avail[j] += alloc[i][j];
                    }
                }
            }
        }
    } while (progress);
    int deadlock = 0;
    printf("Deadlocked processes: ");
    for (int i = 0; i < n; i++){
        if (done[i] == 0) {
            printf("P%d ", i);
            deadlock = 1;
        }
    }
    
    if (!deadlock) {
        printf("\nNo deadlock detected.\n");
    } else {
        printf("\nDeadlock detected!\n");
    }
    
    return 0;
}
