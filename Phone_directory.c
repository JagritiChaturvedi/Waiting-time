#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Contact {
    char name[50];
    char phone[15];
    struct Contact* prev;
    struct Contact* next;
} C;

C* create(char* name, char* phone) {   //contact 1 will be created
    C* new = (C*)malloc(sizeof(C));
    strcpy(new->name, name);
    strcpy(new->phone, phone);
    new->prev = NULL;
    new->next = NULL;
    return new;
}

void add(C** head, char* name, char* phone) { // to add contacts
    C* new = create(name, phone);
    if (*head == NULL) {
        *head = new;
    } else {
        C* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
        new->prev = temp;
    }
}
void del(C** head, char* name) {      // delete any contact by name
    C* temp = *head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                *head = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
            printf("Contact deleted: %s\n", name);
            return;
        }
        temp = temp->next;
    }
    printf("Contact not found: %s\n", name);
}

void display(C* head) {               //to diplay the current contacts available in the directory
    C* temp = head;
    if (temp == NULL) {
        printf("No contacts in the directory.\n");
    } else {
        while (temp != NULL) {
            printf("Name: %s, Phone: %s\n", temp->name, temp->phone);
            temp = temp->next;
        }
    }
}


int main() {
    C* head = NULL;
    int choice;
    char name[50];
    char phone[10];
     printf("\n------------  PHONE DIRECTORY APPLICATION  ----------\n");
       

    while (1) {
         printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number : ");
                scanf("%s", phone);
                add(&head, name, phone);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter name to delete: ");
                scanf("%s", name);
                del(&head, name);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

              return 0;
}