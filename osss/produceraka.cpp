#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 5, x = 0;
void producer() {
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\nProducer produces item %d", x);
    ++mutex;
}

void consumer() {
    --mutex;
    --full;
    ++empty;
    printf("\nConsumer consumes item %d", x);
    x--;
    ++mutex;
}

int main() {
    int n;
    while (1) {
        printf("\n1. Press 1 for Producer"
               "\n2. Press 2 for Consumer"
               "\n3. Press 3 for Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &n);
          switch (n) {
            case 1:
                 if ((mutex == 1) && (empty != 0)) {
                    producer();
                }
                else {
                    printf("Buffer is full!");
                }
                break;
            case 2:
                 if ((mutex == 1) && (full != 0)) {
                    consumer();
                }
                 else {
                    printf("Buffer is empty!");
                }
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.");
        }
    }
    return 0;
}




void p(){

}
 
// int mutex = 1;
// int full = 0 ;
//  int empty = 5;

// int x = 0;
// void p(){
//     mutex--;
//     full++;
//     x++;
//     empty--;
//     printf("producer produced :: ");
//     mutex++;
// }
// void c(){
//     mutex--;
//     full--;
//     x--;
//     empty++;
//     printf("comsumer  comsumedd  :: ");
//     mutex++;
// }