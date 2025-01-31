// Implementing Circular Linked List - abstract data type.

#include <stdio.h>      // for: input & output.
#include <conio.h>      // for: getch();
#include <stdlib.h>     // for: exit(), system();

// Structure that contains a data variable & two pointers variables of it's own type. (NODE)
struct node {
    int data;
    struct node *linkN;
};

/* head node (short for headN) globally declared to reduce the number of parametes, 
++accessibility across program. */
struct node *headN = NULL;
struct node *tail = NULL;
int nodeCounter = 1;

// Insertion choice screen & function.
void insertion();
void atBeginning();

void welcomeScreen();       // Introduction to main page & choice screen.
void screenCleaner();       // Clear the console & input buffer.

// Driver code.
void main () {
    welcomeScreen();
}

// Welcomescreen.
void welcomeScreen() {
    screenCleaner();

    int choice;

label1:
    screenCleaner();
    printf("-- Impelementing & demonstrating operations on Circular Linked List.\n\n");

    printf("*Read the options carefully and choose.\n");
    printf("> 1. Insertion.\n");
    printf("> 2. Deletion.\n");
    printf("> 3. Update.\n");
    printf("> 4. Search.\n");
    printf("> 5. Sort.\n");
    printf("> 6. Reverse.\n");
    printf("> 7. Exit the program.\n\n");

    printf("*NOTE: Before choosing options like deletion, search,\n"
           "reverse,. must insert enough elements.\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            insertion();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Error! choose from the given options.\n");
            printf("Press any key to exit...");
            getch();
            goto label1;
    }
}

void insertion() {
    screenCleaner();
    if(headN == NULL) {
        headN = malloc(sizeof(struct node));
        if(!(headN)) {
            printf("\nError: Memory allocation failed!\n");
            exit(1);
        } else {
            printf("Important: Before inserting further nodes,\n"
                   "in the list must create the head NODE!\n");
            printf("\nheadN->data: ");
            scanf("%d", &(headN->data));

            headN->linkN = NULL;
            tail = headN;
        }
    }
    
    int choice1;

label2:
    screenCleaner();
    printf("-- Insertion.\n\n");
    printf("Options: \n");
    printf("> 1. At the beginning.\n");
    printf("> 2. At the end.\n");
    printf("> 3. At a specific position.\n");
    printf("> 4. Exit from this section.\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice1);

    switch(choice1) {
        case 1:
            atBeginning();
            break;
        case 4:
            welcomeScreen();
            break;
        default:
            printf("\nError! choose from the given options.");
            printf("\nPress any key to continue...");
            getch();
            goto label2;
    }

}

// Insert a node at the beginning of the list.
void atBeginning() {
    struct node *newNode = malloc(sizeof(struct node));
    if (!newNode) {
        printf("\nError: Memory allocation failed!.\n");
        exit(1);
    }

    printf("\nnewNode->data: ");
    scanf("%d", &(newNode->data));

    newNode->linkN = headN;
    headN = newNode;
    tail->linkN = headN;

    nodeCounter++;
}

// Screen cleaner function.
void screenCleaner() {
    system("cls");
    fflush(stdin);
}