// #include <stdio.h>
// int main()
// {
//     int n, m, i, j, k;
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);
//     printf("Enter the number of resources: ");
//     scanf("%d", &m);
//     int resou[m],avail[m], max[n][m], alloc[n][m], need[n][m];
//     printf("Enter the resource vector: ");
//     for (i = 0; i < m; i++) {
//         scanf("%d", &resou[i]);
//     }
//     printf("Enter the maximum resources for each process: \n");
//     for (i = 0; i < n; i++) {
//         for (j = 0; j < m; j++) {
//             scanf("%d", &max[i][j]);
//         }
//     }
//     printf("Enter the allocated resources for each process: \n");
//     for (i = 0; i < n; i++) {
//         for (j = 0; j < m; j++) {
//             scanf("%d", &alloc[i][j]);
//         }
//     }
//     for (i = 0; i < m; i++) {
//         int sum=0;
//         for(j = 0; j < n; j++){
//             sum+=alloc[j][i];
//         }
//         avail[i] =resou[i]-sum;
        
//         }
//     int f[n], ans[n], ind = 0;
//     for (k = 0; k < n; k++) {
//         f[k] = 0;
//     }
//     for (i = 0; i < n; i++) {
//         for (j = 0; j < m; j++)
//             need[i][j] = max[i][j] - alloc[i][j];
//     }
//     int y = 0;
//     for (k = 0; k < 5; k++) {
//         for (i = 0; i < n; i++) {
//             if (f[i] == 0) {

//                 int flag = 0;
//                 for (j = 0; j < m; j++) {
//                     if (need[i][j] > avail[j]){
//                         flag = 1;
//                          break;
//                     }
//                 }
//                 if (flag == 0) {
//                     ans[ind++] = i;
//                     for (y = 0; y < m; y++)
//                         avail[y] += alloc[i][y];
//                     f[i] = 1;
//                 }
//             }
//         }
//     }
//       int flag = 1;
//       for(int i=0;i<n;i++)
//     {
//       if(f[i]==0)
//       {
//         flag=0;
//          printf("The following system is not safe");
//         break;
//       }
//     }
//       if(flag==1)
//     {
//       printf("Following is the SAFE Sequence\n");
//       for (i = 0; i < n - 1; i++)
//         printf(" P%d ->", ans[i]);
//       printf(" P%d", ans[n - 1]);
//     }
//     return (0);
// }




#include <stdio.h>
int main(){
    int n, m;
    printf("Enter no of process : ");
    scanf("%d", &n);
    printf("Enter no of resources : ");
    scanf("%d", &m);
    int alloc[n][m], max[n][m], rem[n][m], avail[m];
    printf("Enter maximum requirement : ");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter allocated matrix : ");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Resource Vector : ");
    for (int i = 0; i < m; i++){
        scanf("%d", &avail[i]);
    }
    int s;
    for (int i = 0; i < m; i++){
        s = 0;
        for (int j = 0; j < n; j++){
            s += alloc[j][i];
        }
        avail[i] -= s;
    }
    int done[n], ans[n], ind = 0;
    for (int k = 0; k < n; k++){
        done[k] = 0;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            rem[i][j] = max[i][j] - alloc[i][j];
    }
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
             int flag = 0;
            if (done[i] == 0){
               
                for (int j = 0; j < m; j++){
                    //printf("need for :%d %d\n",i+1,rem[i][j]);
                    //printf("avail : %d\n",avail[j]);
                    if (rem[i][j] > avail[j]){
                       // printf(" not allocated \n");
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0){
                    //printf("ans[%d] to %d\n",ind,i);
                    ans[ind++] = i;
                    for (int y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    done[i] = 1;
                }
            }
        }
    }
    int flag = 1;
    for (int i = 0; i < n; i++){
        if (done[i] == 0){
            flag = 0;
            printf("The following system is not safe");
            break;
        }
    }
    if (flag == 1){
        printf("Request can be fulfilled\n");
        printf("Following is the SAFE Sequence\n");
        for (int i = 0; i < n - 1; i++)
            printf(" P%d ->", ans[i]);
        printf(" P%d", ans[n - 1]);
    }
    return 0;
}
