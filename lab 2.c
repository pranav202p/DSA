#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for gym member
struct GymMember {
    int id;
    char name[50];
    char membershipType[20];
    struct GymMember* next;
    struct GymMember* prev;
};

// Function to create a new gym member node
struct GymMember* createMember(int id, const char* name, const char* membershipType) {
    struct GymMember* newMember = (struct GymMember*)malloc(sizeof(struct GymMember));
    if (newMember == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newMember->id = id;
    strcpy(newMember->name, name);
    strcpy(newMember->membershipType, membershipType);
    newMember->next = NULL;
    newMember->prev = NULL;
    return newMember;
}

// Function to insert a member at the beginning of the singly linked list
void insertAtBeginningSingly(struct GymMember** head, int id, const char* name, const char* membershipType) {
    struct GymMember* newMember = createMember(id, name, membershipType);
    newMember->next = *head;
    *head = newMember;
}

// Function to insert a member at the end of the singly linked list
void insertAtEndSingly(struct GymMember** head, int id, const char* name, const char* membershipType) {
    struct GymMember* newMember = createMember(id, name, membershipType);
    if (*head == NULL) {
        *head = newMember;
        return;
    }
    struct GymMember* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newMember;
}

// Function to insert a member at a specific position in the singly linked list
void insertAtPositionSingly(struct GymMember** head, int id, const char* name, const char* membershipType, int position) {
    struct GymMember* newMember = createMember(id, name, membershipType);
    if (position == 0) {
        newMember->next = *head;
        *head = newMember;
        return;
    }
    struct GymMember* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    newMember->next = temp->next;
    temp->next = newMember;
}

// Function to delete a member with a given ID from the singly linked list
void deleteMemberSingly(struct GymMember** head, int id) {
    struct GymMember* temp = *head;
    struct GymMember* prev = NULL;

    if (temp != NULL && temp->id == id) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Member not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to search for a member with a given ID in the singly linked list
struct GymMember* searchMemberSingly(struct GymMember* head, int id) {
    struct GymMember* temp = head;
    while (temp != NULL && temp->id != id) {
        temp = temp->next;
    }
    return temp;
}

// Function to display all members in the singly linked list
void displayListSingly(struct GymMember* head) {
    struct GymMember* temp = head;
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Membership Type: %s\n", temp->id, temp->name, temp->membershipType);
        temp = temp->next;
    }
}

// Function to free memory allocated for the singly linked list
void freeListSingly(struct GymMember** head) {
    struct GymMember* current = *head;
    struct GymMember* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

// Function to insert a member at the beginning of the doubly linked list
void insertAtBeginningDoubly(struct GymMember** head, int id, const char* name, const char* membershipType) {
    struct GymMember* newMember = createMember(id, name, membershipType);
    newMember->next = *head;
    newMember->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = newMember;
    }

    *head = newMember;
}

// Function to insert a member at the end of the doubly linked list
void insertAtEndDoubly(struct GymMember** head, int id, const char* name, const char* membershipType) {
    struct GymMember* newMember = createMember(id, name, membershipType);
    if (*head == NULL) {
        *head = newMember;
        return;
    }
    struct GymMember* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newMember;
    newMember->prev = temp;
}

// Function to insert a member at a specific position in the doubly linked list
void insertAtPositionDoubly(struct GymMember** head, int id, const char* name, const char* membershipType, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }

    if (position == 0 || *head == NULL) {
        insertAtBeginningDoubly(head, id, name, membershipType);
        return;
    }

    struct GymMember* newMember = createMember(id, name, membershipType);
    struct GymMember* temp = *head;

    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    newMember->next = temp->next;
    newMember->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newMember;
    }

    temp->next = newMember;
}

// Function to delete a member with a given ID from the doubly linked list
void deleteMemberDoubly(struct GymMember** head, int id) {
    struct GymMember* temp = *head;

    while (temp != NULL && temp->id != id) {
        temp = temp->
    next;
    }

    if (temp == NULL) {
        printf("Member not found\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

// Function to search for a member with a given ID in the doubly linked list
struct GymMember* searchMemberDoubly(struct GymMember* head, int id) {
    struct GymMember* temp = head;
    while (temp != NULL && temp->id != id) {
        temp = temp->next;
    }
    return temp;
}

// Function to display all members in the doubly linked list
void displayListDoubly(struct GymMember* head) {
    struct GymMember* temp = head;
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Membership Type: %s\n", temp->id, temp->name, temp->membershipType);
        temp = temp->next;
    }
}

// Function to free memory allocated for the doubly linked list
void freeListDoubly(struct GymMember** head) {
    struct GymMember* current = *head;
    struct GymMember* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

// Function to insert a member at the beginning of the circular linked list
void insertAtBeginningCircular(struct GymMember** head, int id, const char* name, const char* membershipType) {
    struct GymMember* newMember = createMember(id, name, membershipType);
    if (*head == NULL) {
        *head = newMember;
        newMember->next = *head;
    } else {
        struct GymMember* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newMember->next = *head;
        temp->next = newMember;
        *head = newMember;
    }
}

// Function to insert a member at the end of the circular linked list
void insertAtEndCircular(struct GymMember** head, int id, const char* name, const char* membershipType) {
    struct GymMember* newMember = createMember(id, name, membershipType);
    if (*head == NULL) {
        *head = newMember;
        newMember->next = *head;
    } else {
        struct GymMember* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newMember;
        newMember->next = *head;
    }
}

// Function to insert a member at a specific position in the circular linked list
void insertAtPositionCircular(struct GymMember** head, int id, const char* name, const char* membershipType, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }

    if (position == 0 || *head == NULL) {
        insertAtBeginningCircular(head, id, name, membershipType);
        return;
    }

    struct GymMember* newMember = createMember(id, name, membershipType);
    struct GymMember* temp = *head;

    for (int i = 0; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }

    newMember->next = temp->next;
    temp->next = newMember;
}

// Function to delete a member with a given ID from the circular linked list
void deleteMemberCircular(struct GymMember** head, int id) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct GymMember* temp = *head;
    struct GymMember* prev = NULL;

    while (temp->next != *head && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->id != id) {
        printf("Member not found\n");
        return;
    }

    if (prev == NULL) {
        // If the member to be deleted is the first node
        if (temp->next == *head) {
            *head = NULL;
        } else {
            *head = temp->next;
            prev = temp;
            while (prev->next != temp) {
                prev = prev->next;
            }
            prev->next = *head;
        }
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

// Function to search for a member with a given ID in the circular linked list
struct GymMember* searchMemberCircular(struct GymMember* head, int id) {
    struct GymMember* temp = head;
    do {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    } while (temp != head);

    return NULL;
}

// Function to display all members in the circular linked list
void displayListCircular(struct GymMember* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct GymMember* temp = head;
    do {
        printf("ID: %d, Name: %s, Membership Type: %s\n", temp->id, temp->name, temp->membershipType);
        temp = temp->next;
    } while (temp != head);
}

// Function to free memory allocated for the circular linked list
void freeListCircular(struct GymMember** head) {
    if (*head == NULL) {
        return;
    }

    struct GymMember* current = *head;
    struct GymMember* next;

    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != *head);

    *head = NULL;
}

int main() {
    struct GymMember* singlyLinkedList = NULL;
    struct GymMember* doublyLinkedList = NULL;
    struct GymMember* circularLinkedList = NULL;

    int choice, id, position;
    char name[50], membershipType[20];

    do {
        printf("\nMenu:\n");
        printf("1. Singly Linked List - Add member at the beginning\n");
        printf("2. Singly Linked List - Add member at the end\n");
        printf("3. Singly Linked List - Add member at a specific position\n");
        printf("4. Singly Linked List - Delete a member\n");
        printf("5. Singly Linked List - Search for a member\n");
        printf("6. Singly Linked List - Display members\n");
        printf("7. Doubly Linked List - Add member at the beginning\n");
        printf("8. Doubly Linked List - Add member at the end\n");
        printf("9. Doubly Linked List - Add member at a specific position\n");
                        printf("10. Doubly Linked List - Delete a member\n");
                printf("11. Doubly Linked List - Search for a member\n");
                printf("12. Doubly Linked List - Display members\n");
                printf("13. Circular Linked List - Add member at the beginning\n");
                printf("14. Circular Linked List - Add member at the end\n");
                printf("15. Circular Linked List - Add member at a specific position\n");
                printf("16. Circular Linked List - Delete a member\n");
                printf("17. Circular Linked List - Search for a member\n");
                printf("18. Circular Linked List - Display members\n");
                printf("0. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        // Singly Linked List - Add member at the beginning
                        printf("Enter member ID: ");
                        scanf("%d", &id);
                        printf("Enter member name: ");
                        scanf("%s", name);
                        printf("Enter membership type: ");
                        scanf("%s", membershipType);
                        insertAtBeginningSingly(&singlyLinkedList, id, name, membershipType);
                        break;

                    case 2:
                        // Singly Linked List - Add member at the end
                        printf("Enter member ID: ");
                        scanf("%d", &id);
                        printf("Enter member name: ");
                        scanf("%s", name);
                        printf("Enter membership type: ");
                        scanf("%s", membershipType);
                        insertAtEndSingly(&singlyLinkedList, id, name, membershipType);
                        break;

                    case 3:
                        // Singly Linked List - Add member at a specific position
                        printf("Enter member ID: ");
                        scanf("%d", &id);
                        printf("Enter member name: ");
                        scanf("%s", name);
                        printf("Enter membership type: ");
                        scanf("%s", membershipType);
                        printf("Enter position: ");
                        scanf("%d", &position);
                        insertAtPositionSingly(&singlyLinkedList, id, name, membershipType, position);
                        break;

                    case 4:
                        // Singly Linked List - Delete a member
                        printf("Enter member ID to delete: ");
                        scanf("%d", &id);
                        deleteMemberSingly(&singlyLinkedList, id);
                        break;

                    case 5:
                        // Singly Linked List - Search for a member
                        printf("Enter member ID to search: ");
                        scanf("%d", &id);
                        if (searchMemberSingly(singlyLinkedList, id) != NULL) {
                            printf("Member with ID %d found\n", id);
                        } else {
                            printf("Member with ID %d not found\n", id);
                        }
                        break;

                    case 6:
                        // Singly Linked List - Display members
                        displayListSingly(singlyLinkedList);
                        break;

                    case 7:
                        // Doubly Linked List - Add member at the beginning
                        printf("Enter member ID: ");
                        scanf("%d", &id);
                        printf("Enter member name: ");
                        scanf("%s", name);
                        printf("Enter membership type: ");
                        scanf("%s", membershipType);
                        insertAtBeginningDoubly(&doublyLinkedList, id, name, membershipType);
                        break;

                    case 8:
                        // Doubly Linked List - Add member at the end
                        printf("Enter member ID: ");
                        scanf("%d", &id);
                        printf("Enter member name: ");
                        scanf("%s", name);
                        printf("Enter membership type: ");
                        scanf("%s", membershipType);
                        insertAtEndDoubly(&doublyLinkedList, id, name, membershipType);
                        break;

                    case 9:
                        // Doubly Linked List - Add member at a specific position
                        printf("Enter member ID: ");
                        scanf("%d", &id);
                        printf("Enter member name: ");
                        scanf("%s", name);
                        printf("Enter membership type: ");
                        scanf("%s", membershipType);
                        printf("Enter position: ");
                        scanf("%d", &position);
                        insertAtPositionDoubly(&doublyLinkedList, id, name, membershipType, position);
                        break;
                    
                    case 10:
                        // Doubly Linked List - Delete a member
                        printf("Enter member ID to delete: ");
                        scanf("%d", &id);
                        deleteMemberDoubly(&doublyLinkedList, id);
                        break;

                    case 11:
                        // Doubly Linked List - Search for a member
                        printf("Enter member ID to search: ");
                        scanf("%d", &id);
                        if (searchMemberDoubly(doublyLinkedList, id) != NULL) {
                            printf("Member with ID %d found\n", id);
                        } else {
                            printf("Member with ID %d not found\n", id);
                        }
                        break;

                    case 12:
                        // Doubly Linked List - Display members
                        displayListDoubly(doublyLinkedList);
                        break;

                    case 13:
                        // Circular Linked List - Add member at the beginning
                        printf("Enter member ID: ");
                        scanf("%d", &id);
                        printf("Enter member name: ");
                        scanf("%s", name);
                        printf("Enter membership type: ");
                        scanf("%s", membershipType);
                        insertAtBeginningCircular(&circularLinkedList, id, name, membershipType);
                        break;

                    case 14:
                        // Circular Linked List - Add member at the end
                        printf("Enter member ID: ");
                        scanf("%d", &id);
                        printf("Enter member name: ");
                        scanf("%s", name);
                        printf("Enter membership type: ");
                        scanf("%s", membershipType);
                        insertAtEndCircular(&circularLinkedList, id, name, membershipType);
                        break;

                    case 15:
                        // Circular Linked List - Add member at a specific position
                        printf("Enter member ID: ");
                        scanf("%d", &id);
                        printf("Enter member name: ");
                        scanf("%s", name);
                        printf("Enter membership type: ");
                        scanf("%s", membershipType);
                        printf("Enter position: ");
                        scanf("%d", &position);
                        insertAtPositionCircular(&circularLinkedList, id, name, membershipType, position);
                        break;

                    case 16:
                        // Circular Linked List - Delete a member
                        printf("Enter member ID to delete: ");
                        scanf("%d", &id);
                        deleteMemberCircular(&circularLinkedList, id);
                        break;

                    case 17:
                        // Circular Linked List - Search for a member
                        printf("Enter member ID to search: ");
                        scanf("%d", &id);
                        if (searchMemberCircular(circularLinkedList, id) != NULL) {
                            printf("Member with ID %d found\n", id);
                        } else {
                            printf("Member with ID %d not found\n", id);
                        }
                        break;

                    case 18:
                        // Circular Linked List - Display members
                        displayListCircular(circularLinkedList);
                        break;

                    case 0:
                        printf("Exiting...\n");
                        break;

  
                        default:
                            printf("Invalid choice\n");
                }
            } while (choice != 0);

            // Free memory
            freeListSingly(&singlyLinkedList);
            freeListDoubly(&doublyLinkedList);
            freeListCircular(&circularLinkedList);

            return 0;
        }
