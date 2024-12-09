#include <stdio.h>
#include <string.h>
int main() {
    FILE *file1, *file2;
    char line1[100], line2[100];
    file1 = fopen("my_details.txt", "w");
    fprintf(file1, "Rohan\nRam\nKishan\n");
    fclose(file1);
    file2 = fopen("friends_details.txt", "w");
    fprintf(file2, "Ram\nShyaan\nKishan\n");
    fclose(file2);
    file1 = fopen("my_details.txt", "r");
    file2 = fopen("friends_details.txt", "r");
    if (file1 == NULL || file2 == NULL) {
        printf("Error opening files.\n");
        return 1;
    }
    while (fgets(line1, sizeof(line1), file1)) {
        fseek(file2, 0, SEEK_SET);
        while (fgets(line2, sizeof(line2), file2)) {
            if (strcmp(line1, line2) == 0) {
                printf("Matching line: %s", line1);
                break;
            }
        }
    }
    fclose(file1);
    fclose(file2);
    return 0;
}
