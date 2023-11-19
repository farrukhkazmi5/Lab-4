#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//QUESTION1
struct Contact {
    char name[50];
    char email[50];
    char phoneNumber[15];
};

void displayMenu() {
    printf("\n** ADDRESS BOOK **\n");
    printf("1. Add new contact\n");
    printf("2. Delete contact\n");
    printf("3. Display contacts\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void addContact(struct Contact** addressBook, int* numContacts) {
    // Increase the size of the address book using realloc
    *numContacts += 1;
    *addressBook = (struct Contact*)realloc(*addressBook, (*numContacts) * sizeof(struct Contact));

    if (*addressBook == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    struct Contact newContact;

    printf("Enter name: ");
    scanf("%s", newContact.name);

    printf("Enter email: ");
    scanf("%s", newContact.email);

    printf("Enter phone number: ");
    scanf("%s", newContact.phoneNumber);

    // Add the new contact to the address book
    (*addressBook)[*numContacts - 1] = newContact;

    printf("Contact added successfully!\n");
}

void deleteContact(struct Contact** addressBook, int* numContacts) {
    if (*numContacts == 0) {
        printf("Address book is empty\n");
        return;
    }

    char deleteName[50];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", deleteName);

    int foundIndex = -1;

    // Find the index of the contact to delete
    for (int i = 0; i < *numContacts; ++i) {
        if (strcmp((*addressBook)[i].name, deleteName) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        // Shift elements to fill the gap left by the deleted contact
        for (int i = foundIndex; i < *numContacts - 1; ++i) {
            (*addressBook)[i] = (*addressBook)[i + 1];
        }

        // Decrease the size of the address book using realloc
        *numContacts -= 1;
        *addressBook = (struct Contact*)realloc(*addressBook, (*numContacts) * sizeof(struct Contact));

        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found\n");
    }
}

void displayContacts(struct Contact* addressBook, int numContacts) {
    if (numContacts == 0) {
        printf("Address book is empty\n");
        return;
    }

    printf("\n** CONTACTS **\n");
    for (int i = 0; i < numContacts; ++i) {
        printf("Name: %s\n", addressBook[i].name);
        printf("Email: %s\n", addressBook[i].email);
        printf("Phone Number: %s\n", addressBook[i].phoneNumber);
        printf("---------------------\n");
    }
}

int main() {
    struct Contact* addressBook = NULL;
    int numContacts = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(&addressBook, &numContacts);
                break;
            case 2:
                deleteContact(&addressBook, &numContacts);
                break;
            case 3:
                displayContacts(addressBook, numContacts);
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    // Free the allocated memory before exiting the program
    free(addressBook);

    return 0;
}


//QUESTION 2

struct node {
    int data;
    struct node*next;
};
struct node* createnode(int data) {
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if (newnode==NULL) {
        printf("memory not allocated");
        return NULL;
    }else {
        newnode->next=NULL;
        newnode->data=data;
        return newnode;
    }
}
struct node* addnode(struct node*head,int data){
    struct node *newnode=createnode(data);
    if (head==NULL) {
        head=newnode;
        return head;
    }else {
        struct node*current=head;
        while (current->next!=NULL) {
            current=current->next;
        }
        current->next=newnode;
        return head;
    }
}
struct node* mergedlist(struct node*list1,struct node*list2) {
    struct node*head=NULL;
    while (list1!=NULL && list2!=NULL && list1->data<=list2->data) {
        head=addnode(head,list1->data);
        list1=list1->next;
    }while (list1!=NULL && list2!=NULL && list1->data>=list2->data) {
        head=addnode(head,list2->data);
        list2=list2->next;
    }while (list1!=NULL && list2!=NULL){
        if (list1->data<list2->data) {
        head=addnode(head,list1->data);
        list1=list1->next;
        }else {
        head=addnode(head,list2->data);
        list2=list2->next;
        }
    }
    return head;
}
void freeList(struct node* head) {
struct node* current = head;
while (current != NULL) {
struct node* temp = current;
current = current->next;
free(temp);
}
}
void printList(struct node* head) {
struct node* current = head;
while (current != NULL) {
printf("%d -> ", current->data);
current = current->next;
}
printf("NULL\n");
}

int main() {
    struct node* head1=createnode(1);
    struct node* head2=createnode(1);
    addnode(head1,2);
    addnode(head2,2);
    addnode(head1,3);
    addnode(head2,3);
    addnode(head1,4);
    addnode(head2,4);
    printList(head1);
    printList(head2);
    struct node* x=mergedlist(head1,head2);
    printList(x);
    return;
}

//question 3

struct node {
    int data;
    struct node*next;
};
struct node* createnode(int data) {
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if (newnode==NULL) {
        printf("memory not allocated");
        return NULL;
    }else {
        newnode->next=NULL;
        newnode->data=data;
        return newnode;
    }
}
struct node* addnode(struct node*head,int data){
    struct node *newnode=createnode(data);
    if (head==NULL) {
        head=newnode;

    }else {
        struct node*current=head;
        while (current->next!=NULL) {
            current=current->next;
        }
        current->next=newnode;

    }
     return head;
}
void array(struct node*head) {
    int arr[100],i=0;
//    ptra=(struct node*)malloc(sizeof(struct node));
//    ptra=&a;
    if (head==NULL || head->next==NULL) {
            printf("no array");

    }  struct node* current=head;
    while (current!=NULL) {
        arr[i]=current->data;
        i++;
        current=current->next;
    } printf("Array: ");
    for (int j = 0; j < i; j++) {
    printf("%d ", arr[j]);
    }
    printf("\n");

}
int main() {
    struct node* head1=createnode(1);
    struct node* head2=createnode(1);
    addnode(head1,2);
    addnode(head2,2);
    addnode(head1,3);
    addnode(head2,3);
    addnode(head1,4);
    addnode(head2,4);

    array(head1);
    return 0;
}



//question 4

struct node {
    int data;
    struct node*next;
};
struct node* createnode(int data) {
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if (newnode==NULL) {
        printf("memory not allocated");
        return NULL;
    }else {
        newnode->next=NULL;
        newnode->data=data;
        return newnode;
    }
}
struct node* addnode(struct node*head,int data){
    struct node *newnode=createnode(data);
    if (head==NULL) {
        head=newnode;

    }else {
        struct node*current=head;
        while (current->next!=NULL) {
            current=current->next;
        }
        current->next=newnode;

    }
     return head;
}
void removeodd(struct node*head) {
     struct node*newnode;
     struct node* current=head;
     if (head==NULL) {
            return;
     }
     while (current!=NULL && current->next!=NULL){
     newnode=current->next;
     current->next=newnode->next;
     free(newnode);
     current=current->next;
     }
     return;
}
void printList(struct node* head) {
struct node* current = head;
while (current != NULL) {
printf("%d -> ", current->data);
current = current->next;
}
printf("NULL\n");
}

int main() {
    struct node* head1=createnode(1);
    struct node* head2=createnode(1);
    addnode(head1,2);
    addnode(head2,2);
    addnode(head1,3);
    addnode(head2,3);
    addnode(head1,4);
    addnode(head2,4);
    removeodd(head1);
    printList(head1);

    return 0;
}




