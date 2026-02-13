#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeFile();
void readFile();
void appendFile();
void countFile();

int main() {
    int choice;

    while(1) {
        printf("\n==== FILE HANDLING MENU ====\n");
        printf("1. Write to File\n");
        printf("2. Read from File\n");
        printf("3. Append to File\n");
        printf("4. Count Characters, Words, Lines\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();   // clear buffer

        switch(choice) {
            case 1: writeFile(); break;
            case 2: readFile(); break;
            case 3: appendFile(); break;
            case 4: countFile(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Function to write into file
void writeFile() {
    FILE *fp;
    char data[200];

    fp = fopen("data.txt", "w");
    if(fp == NULL) {
        printf("File cannot be opened!\n");
        return;
    }

    printf("Enter text to write in file:\n");
    fgets(data, sizeof(data), stdin);

    fputs(data, fp);
    fclose(fp);

    printf("Data written successfully!\n");
}

// Function to read file
void readFile() {
    FILE *fp;
    char ch;

    fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("File does not exist!\n");
        return;
    }

    printf("\nFile Content:\n");
    while((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);
}

// Function to append data
void appendFile() {
    FILE *fp;
    char data[200];

    fp = fopen("data.txt", "a");
    if(fp == NULL) {
        printf("File cannot be opened!\n");
        return;
    }

    printf("Enter text to append:\n");
    fgets(data, sizeof(data), stdin);

    fputs(data, fp);
    fclose(fp);

    printf("Data appended successfully!\n");
}

// Function to count characters, words, lines
void countFile() {
    FILE *fp;
    char ch;
    int characters = 0, words = 0, lines = 0;

    fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("File does not exist!\n");
        return;
    }

    while((ch = fgetc(fp)) != EOF) {
        characters++;

        if(ch == '\n')
            lines++;

        if(ch == ' ' || ch == '\n')
            words++;
    }

    fclose(fp);

    printf("\nCharacters: %d\n", characters);
    printf("Words: %d\n", words + 1);
    printf("Lines: %d\n", lines + 1);
}
