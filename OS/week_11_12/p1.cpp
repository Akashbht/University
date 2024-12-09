#include<stdio.h>
#include<stdlib.h>

int main() {
    int total_head_movement = 0, initial_pos, n;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    int request_queue[100];
    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &request_queue[i]);
    }
    initial_pos = request_queue[0];
    for (int i = 1; i < n; i++) {
        total_head_movement += abs(initial_pos - request_queue[i]);
        initial_pos = request_queue[i];
    }
    printf("Total seek movement = %d\n", total_head_movement);
    return 0;
}
