#include <stdio.h>
#include <stdlib.h>

int cScan(int requests[], int n, int head, int disk_size) {
    int total_seek = 0, i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (requests[i] > requests[j]) {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    int pos = 0;
    while (pos < n && requests[pos] < head) {
        pos++;
    }

    for (i = pos; i < n; i++) {
        total_seek += abs(requests[i] - head);
        head = requests[i];
    }

    total_seek += abs(disk_size - 1 - head);
    total_seek += disk_size - 1;
    head = 0;

    for (i = 0; i < pos; i++) {
        total_seek += abs(requests[i] - head);
        head = requests[i];
    }

    return total_seek;
}

int main() {
    int n, i, head;
    int disk_size = 200;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the disk requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial position of the head: ");
    scanf("%d", &head);
    int total_seek = cScan(requests, n, head, disk_size);
    printf("Total seek movement: %d\n", total_seek);
    return 0;
}
