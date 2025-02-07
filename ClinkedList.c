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
int nodeCounter = 0;

// Insertion choice screen & function.
void insertion();
void atBeginning();
void atEnd();
void atASpecificPosition();

// Deletion choice screen & function.
void deletion();
void firstNode();
void lastNode();
void specificNode();

void search();

void sort();
struct node * mergeSort(struct node * );
struct node * split(struct node * );
struct node * merge(struct node * , struct node * );

void update();
int verification(int , int );

void reverse();

void welcomeScreen();       // Introduction to main page & choice screen.
void screenCleaner();       // Clear the console & input buffer.

void printL();
void tryAgain(int );

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
    printf("> 3. Search.\n");
    printf("> 4. Sort.\n");
    printf("> 5. Upadate.\n");
    printf("> 6. Reverse.\n");
    printf("> 7. Removing duplicates.\n");
    printf("> 8. Exit the program.\n\n");

    printf("*NOTE: Before choosing options like deletion, search,\n"
           "reverse,. must insert enough elements.\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            search();
            break;
        case 4:
            sort();
            break;
        case 5:
            update();
            break;
        case 6:
            reverse();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Error! choose from the given options.\n");
            printf("Press any key to exit...");
            getch();
            goto label1;
    }
}

// Traverse through and print the list.
void printL() {
    struct node *p = NULL;
    p = headN;
    
    if(headN == NULL) {
        printf("Alert: the list is empty!\n");
        return;
    }

    printf("\nThe List: ");
    do {
        printf("| %d |", p->data);
        p = p->linkN;
    } while(p != headN);
    printf("\n");
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

            tail = headN;
            headN->linkN = headN;

            nodeCounter++;
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
            printL();
            tryAgain(1);
            break;
        case 2:
            atEnd();
            printL();
            tryAgain(1);
            break;
        case 3:
            atASpecificPosition();
            printL();
            tryAgain(1);
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

// Insert a node at the end of the list.
void atEnd() {
    struct node *newNode = malloc(sizeof(struct node));
    if (!newNode) {
        printf("\nError: Memory allocation failed!.\n");
        exit(1);
    }

    printf("\nnewNode->data: ");
    scanf("%d", &(newNode->data));

    newNode->linkN = headN;
    tail->linkN = newNode;
    tail= newNode;
    
    nodeCounter++;
}

// Insert a node at a specific position. (specified by it's serial no.)
void atASpecificPosition() {
    int index;

    struct node *newNode = malloc(sizeof(struct node));
    if (!newNode) {
        printf("\nError: Memory allocation failed!.\n");
        exit(1);
    } else {
        printf("\nnewNode->data: ");
        scanf("%d", &(newNode->data));
        newNode->linkN = NULL;
        printf("serial: ");
        scanf("%d", &index);

        struct node *p = headN;

        // The serial number should be between the list, or at the end.
        if(index > nodeCounter + 1 || index < 1) {
            printf("\nError: Enter a valid serial number.");
            printf("\nPress any key to continue...");
            getch();
            insertion();
        } else if(index == 1) {
            newNode->linkN = headN;
            headN = newNode;
            tail->linkN = headN;

        } else if(index == nodeCounter + 1) {
            newNode->linkN = headN;
            tail->linkN = newNode;
            tail= newNode;

        } else {
            for(int i = 1; i < index - 1; i++) {
                p = p->linkN;
            }
            newNode->linkN = p->linkN;
            p->linkN = newNode;
        }
    }

    nodeCounter++;
}

// Deletion function and it's operations.
void deletion() {
    screenCleaner();

    if(headN == NULL) {
        printf("\nAlert: The list is empty.\n");
        printf("Press any key to continue...");
        getch();
        welcomeScreen();
    }

    int choice2;

label3:
    screenCleaner();
    printf("-- Deletion.\n\n");
    printf("Options: \n");
    printf("> 1. First node.\n");
    printf("> 2. Last node.\n");
    printf("> 3. A specific node.\n");
    printf("> 4. Exit from this section.\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice2);

    switch(choice2) {
        case 1:
            firstNode();
            printL();
            tryAgain(2);
            break;
        case 2: 
            lastNode();
            printL();
            tryAgain(2);
            break;
        case 3:
            specificNode();
            printL();
            tryAgain(2);
            break;
        case 4:
            welcomeScreen();
            break;
        default:
            printf("\nError! choose from the given options.");
            printf("\nPress any key to continue...");
            getch();
            goto label3;
    }

}

// Deletes the first node from the list.
void firstNode() {
    if(nodeCounter == 1) {
        headN->linkN = NULL;
        
        free(headN);
        headN = NULL;
        tail = NULL;

    } else {
        struct node *p = headN;
        headN = headN->linkN;
        tail->linkN = headN;
        
        free(p);
        p = NULL;
    }

    nodeCounter--;
}

// Deletes the last node from the list.
void lastNode() {
    if(headN == tail) {
        free(headN);
        headN = NULL;
        tail = NULL;

    } else {
        struct node *p1 = headN;
        struct node *p2 = NULL;

        for(int i = 1; i < nodeCounter; i++) {
            p2 = p1;
            p1 = p1->linkN;
        }
        tail = p2;
        tail->linkN = headN;

        free(p1);
        p1 = NULL;
    }

    nodeCounter--;
}

// Deletes a specific node, specified by it's serial number.
void specificNode() {
    int index;
    struct node *p1 = headN;
    struct node *p2 = NULL;

    printf("\nserial no.: ");
    scanf("%d", &index);

    if(index >= nodeCounter + 1 || index < 1) {
        printf("\nError: Enter a valid serial number.");
        printf("\nPress any key to continue...");
        getch();
        deletion();
    } 
    // Case 1: Deleting the only node in the list.
    else if(index == 1 && nodeCounter == 1) {
        free(headN);
        headN = NULL;
        tail = NULL;
    } 
    // Case 2: Deleting the first node in a multi-node list
    else if(index == 1) {
        headN = headN->linkN;
        
        free(p1);
        p1 = NULL;

    } 
    // Case 3: Deleting the last node
    else if(index == nodeCounter) {
        for(int i = 1; i < index; i++) {
            p2 = p1;
            p1 = p1->linkN;
        }
        p2->linkN = headN;

        free(p1);
        p1 = NULL;

    } 
    // Case 4: Deleting a node in the middle
    else {
        for(int i = 1; i < index; i++) {
            p2 = p1;
            p1 = p1->linkN;
        }
        p2->linkN = p1->linkN;

        free(p1);
        p1 = NULL;
    }

    nodeCounter--;
}

// Search a specific node, taking reference it's data & returns it's serial number.
void search(){
    screenCleaner();

    int target, i, flag = 0, choice;

    if(headN == NULL) {
        printf("\nError: The list is empty.\n");
        printf("Press any key to continue...");
        getch();
        welcomeScreen();
    }

    printL();

    printf("\nelement: ");
    scanf("%d", &target);

    struct node *p = headN;

    do {
        if(target == p->data) {
            flag++;
            printf("\nserial no.: %d", i);
        }
        p = p->linkN;
    } while(p != headN);

    if(flag == 0) {
        printf("\nelement not found!");
    }

    printf("\n\n> 1. Continue to search elements.\n");
    printf("> 2. Exit from this section.\n");
    printf("\nyour choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            search();
            break;
        case 2:
            welcomeScreen();
            break;
        default:
            printf("\nError: Choose from the given options.");
            printf("\nPress any key to continue...");
            getch();
            welcomeScreen();
    }
}

int verification(int index, int data) {
    int verify = 0;
    struct node *p = headN;

    if(index >= nodeCounter + 1 || index < 1) {
        return 4;       // error code: 4
    } else {
        for(int i = 1; i <= index; i++) {
            if(p->data == data) {
                verify++;
                break;
            }
            p = p->linkN;
        }
    }

    if(verify == 0) {
        return 5;       // error code: 5
    } else {
        return 1;
    }
}

// Sort the list using merge sort algorithm. (Backtracking!)
void sort() {
    screenCleaner();

    struct node *p = NULL;

    printL();

    if(headN == NULL || headN->linkN == headN) {
        printf("\nError: The list is empty or it has only one node!\n");
        printf("Press any key to continue...");
        getch();
        welcomeScreen();
    }

    // Breaking the circularity.
    tail->linkN = NULL;
    tail = NULL;

    headN = mergeSort(headN);

    // Re establishing the connection to maintain circularity.
    p = headN;
    while(p->linkN != NULL) {
        p = p->linkN;
    }
    tail = p;
    tail->linkN = headN;

    printL();

    printf("\nPress any key to continue...");
    getch();
    welcomeScreen();
}

struct node * mergeSort(struct node *headN) {

    if (headN == NULL || headN->linkN == NULL) {
        return headN;
    }

    struct node *second = split(headN);

    headN = mergeSort(headN);
    second = mergeSort(second);

    return merge(headN, second);
}

struct node * split(struct node *headN) {

    struct node *fast = headN->linkN;
    struct node *slow = headN;

    while (fast != NULL && fast->linkN != NULL) {
        fast = fast->linkN->linkN;
        slow = slow->linkN;
    }

    struct node *temp = slow->linkN;
    slow->linkN = NULL;
    return temp;
}

struct node * merge(struct node * first, struct node * second) {

    if(first == NULL) return second;
    if(second == NULL) return first;

    if(first->data < second->data) {
        first->linkN = merge(first->linkN, second);
        return first;
    } else {
        second->linkN = merge(first, second->linkN);
        return second;
    }
}

// Update nodes with new data.
void update() {
    screenCleaner();

    int serial, data, uData, choice, errorCode;

    printf("Which node do you want to update?");
    printL();

    printf("\nserial no.: ");
    scanf("%d", &serial);
    printf("node's data: ");
    scanf("%d", &data);

    errorCode = verification(serial, data);
    if(errorCode == 4) {
        printf("\nError: Enter a valid serial number.");
        printf("\nPress any key to continue...");
        getch();
        update();
    } else if(errorCode == 5) {
        printf("\nError: The element is not present at the\n"
               "specified serial number. ");
        printf("\nPress any key to continue...");
        getch();
        update();
    }

    printf("\nnew->data: ");
    scanf("%d", &uData);

    struct node *p = headN;

    for(int i = 1; i < serial; i++) {
        p = p->linkN;
    }

    p->data = uData;

    printL();

    printf("\n> 1. Continue to update more elements.\n");
    printf("> 2. Exit from this section.\n");
    printf("\nyour choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            update();
            break;
        case 2:
            welcomeScreen();
            break;
        default:
            printf("\nError: Choose from the given options.");
            printf("\nPress any key to continue...");
            getch();
            welcomeScreen();
    }
}

// Reverse the list.
void reverse() {
    screenCleaner();

    int choice;

    if(headN == NULL || headN->linkN == NULL) {
        printf("\nError: The list is empty or it has only one node!\n");
        printf("Press any key to continue...");
        getch();
        welcomeScreen();
        return;
    }

    printL();

    struct node *prev = tail;
    struct node *current = headN;
    struct node *next = NULL;
    struct node *start = headN;

    do {
        next = current->linkN;      // Store next node
        current->linkN = prev;      // Reverse the link
        prev = current;             // Move prev to current
        current = next;             // Move current to next
    } while (current != start);     // Traverse until full circle

    tail = headN;   
    headN = prev;   

    printL();

    printf("\n> 1. Reverse one more time OR.\n");
    printf("> 2. Exit from this section.\n");
    printf("\nyour choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            reverse();
            break;
        case 2:
            welcomeScreen();
            break;
        default:
            printf("\nError: Choose from the given options.");
            printf("\nPress any key to continue...");
            getch();
            welcomeScreen();
    }
}

// Try again program.
void tryAgain(int choice) {
    char ch;

    printf("\nDo you want to try again[y/N]: ");
    scanf(" %c", &ch);

    switch(ch) {
        case 'y':
        case 'Y':
            if(choice == 1) {
                insertion();
            } else {
                deletion();
            }
            break;
        case 'n':
        case 'N':
            welcomeScreen();
            break;
        default:
            printf("\nError: invalid input. \n");
            printf("Press any key to continue... \n");
            getch();
            welcomeScreen();
    }
}

// Screen cleaner function.
void screenCleaner() {
    system("cls");
    fflush(stdin);
}