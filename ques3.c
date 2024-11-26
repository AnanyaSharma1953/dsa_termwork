#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char name[100];  // Changed from String to char array to store name
    int rollNo;
    struct node* next;
} L;

void insert(L**, L**);
void display(L*);
void deleteDuplicates(L**);
void main()
{
    int ch;
    L *f = NULL, *r = NULL;  // f is the front, r is the rear
    do
    {
        printf("\n1. Insert\n2. Delete duplicates\n3. Display\n4. Exit\nEnter Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(&r, &f);
            break;
        case 2:
            deleteDuplicates(&f);
            break;
        case 3:
            display(f);
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (ch != 4);  // Exit when the user chooses 4
}

void display(L* head) {
    L* temp = head;
    if (!temp) {
        printf("The list is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("Name: %s, Roll No: %d\n", temp->name, temp->rollNo);
        temp = temp->next;
    }
}

// Function to delete duplicate nodes based on name
void deleteDuplicates(L** head) {
    L* current = *head;
    L* prev = NULL;
    L* temp = NULL;
    L* duplicate = NULL;

    while (current != NULL && current->next != NULL) {
        prev = current;
        temp = current->next;
        while (temp != NULL) {
            if (strcmp(current->name, temp->name) == 0) {
                // Duplicate found, delete it
                duplicate = temp;
                prev->next = temp->next;  // Skip the duplicate
                free(duplicate);
                temp = prev->next;  // Continue checking for further duplicates
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

void insert(L** r1, L** f1)
{
    L* p = NULL;
    int x;
    p = (L*)malloc(sizeof(L));  // Allocate memory for a new node
    
    printf("Enter roll no.: ");
    scanf("%d", &x);
    
    // Input name using an array of characters
    printf("Enter name: ");
    // Using scanf with a width specifier to avoid buffer overflow
    scanf("%99s", p->name);  // Limits the input to 99 characters (1 less than array size for '\0')

    p->rollNo = x;
    p->next = NULL;

    // If the list is empty, both front and rear are the same node
    if (*r1 == NULL) {
        *r1 = p;
    } else {
        // Insert at the end of the list
        (*r1)->next = p;
        *r1 = p;
    }

    // If the list is empty, set the front pointer to the new node
    if (*f1 == NULL) {
        *f1 = *r1;
    }
}
