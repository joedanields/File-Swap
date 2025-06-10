#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

int main() {
    FILE *file1, *file2;
    char *content1, *content2;
    char *filename1 = "file1.txt";
    char *filename2 = "file2.txt";
    long size1, size2;
    
    // Open first file for reading
    file1 = fopen(filename1, "r");
    if (file1 == NULL) {
        printf("Error: Cannot open file '%s'\n", filename1);
        return 1;
    }
    
    // Get size of first file
    fseek(file1, 0, SEEK_END);
    size1 = ftell(file1);
    fseek(file1, 0, SEEK_SET);
    
    // Allocate memory and read first file content
    content1 = (char*)malloc(size1 + 1);
    if (content1 == NULL) {
        printf("Error: Memory allocation failed\n");
        fclose(file1);
        return 1;
    }
    
    fread(content1, 1, size1, file1);
    content1[size1] = '\0';
    fclose(file1);
    
    // Open second file for reading
    file2 = fopen(filename2, "r");
    if (file2 == NULL) {
        printf("Error: Cannot open file '%s'\n", filename2);
        free(content1);
        return 1;
    }
    
    // Get size of second file
    fseek(file2, 0, SEEK_END);
    size2 = ftell(file2);
    fseek(file2, 0, SEEK_SET);
    
    // Allocate memory and read second file content
    content2 = (char*)malloc(size2 + 1);
    if (content2 == NULL) {
        printf("Error: Memory allocation failed\n");
        fclose(file2);
        free(content1);
        return 1;
    }
    
    fread(content2, 1, size2, file2);
    content2[size2] = '\0';
    fclose(file2);
    
    // Write content1 to file2
    file2 = fopen(filename2, "w");
    if (file2 == NULL) {
        printf("Error: Cannot write to file '%s'\n", filename2);
        free(content1);
        free(content2);
        return 1;
    }
    
    fwrite(content1, 1, size1, file2);
    fclose(file2);
    
    // Write content2 to file1
    file1 = fopen(filename1, "w");
    if (file1 == NULL) {
        printf("Error: Cannot write to file '%s'\n", filename1);
        free(content1);
        free(content2);
        return 1;
    }
    
    fwrite(content2, 1, size2, file1);
    fclose(file1);
    
    // Clean up memory
    free(content1);
    free(content2);
    
    printf("Swapping contents of '%s' and '%s'...\n", filename1, filename2);
    
    printf("Files swapped successfully!\n");
    
    return 0;
}