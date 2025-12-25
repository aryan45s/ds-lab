#include <stdio.h>
#include <stdlib.h>

// Structure for a node in DLL
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

// Global head pointer
struct node *head = NULL;

// Function prototypes
struct node *create(int data);
struct node *insert_end(int data);
void insert_left(int new_data, int key_value);
void delete_spec(int key_value);
void search(int key);
void display();

// Create a new node
struct node *create(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

// Insert a node at the end of the doubly linked list
struct node *insert_end(int data)
{
    struct node *newnode = create(data);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        // Link the new node to the last node
        current->next = newnode;
        newnode->prev = current;
    }
    printf("Inserted %d at end\n", data);
    return head;
}

// Insert a new node to the left of a given node
void insert_left(int new_data, int key_value)
{
    struct node *newnode = create(new_data);
    
    if (head == NULL)
    {
        printf("List is empty. Inserting as first node.\n");
        head = newnode;
        return;
    }
    
    struct node *current = head;
    while (current != NULL && current->data != key_value)
    {
        current = current->next;
    }
    
    if (current == NULL)
    {
        printf("Target node with value %d not found. Node not inserted.\n", key_value);
        free(newnode); // Free memory if not inserted
        return;
    }
    
    // Insert before the target node
    newnode->next = current;
    newnode->prev = current->prev;
    
    if (current->prev != NULL)
    {
        current->prev->next = newnode;
    }
    else
    {
        head = newnode; // If inserting before head, update head
    }
    current->prev = newnode;
    
    printf("Inserted %d to the left of %d\n", new_data, key_value);
}

// Delete a specific node by value
void delete_spec(int key_value)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    
    struct node *current = head;
    
    // Find the node to delete
    while (current != NULL && current->data != key_value)
    {
        current = current->next;
    }
    
    if (current == NULL)
    {
        printf("Node with value %d not found. Cannot delete.\n", key_value);
        return;
    }
    
    // Adjust links
    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }
    else
    {
        // Deleting the head node
        head = current->next;
    }
    
    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }
    
    printf("Deleted node with value %d\n", key_value);
    free(current);
}

// Search for a node by value
void search(int key)
{
    struct node *current = head;
    int pos = 1;
    
    if (head == NULL)
    {
        printf("List is empty. Element not found.\n");
        return;
    }
    
    // Traverse DLL
    while (current != NULL && current->data != key)
    {
        pos++;
        current = current->next;
    }
    
    // If key is not present in the list
    if (current == NULL)
    {
        printf("Element %d not found\n", key);
    }
    else
    {
        printf("Element %d found at position %d\n", key, pos);
    }
}

// Display the contents of the list
void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    
    struct node *current = head;
    printf("Doubly Linked List: NULL <-> ");
    while (current != NULL)
    {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()  // Changed from void main() to int main()
{
    int ch, value, key;
    
    do
    {
        printf("\n===== DOUBLY LINKED LIST MENU =====\n");
        printf("1. Insert at end\n");
        printf("2. Insert to left of a node\n");
        printf("3. Delete specific value\n");
        printf("4. Search for a value\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1: 
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insert_end(value);
                break;
                
            case 2: 
                printf("Enter the new value: ");
                scanf("%d", &value);
                printf("Enter the key value (insert to left of this): ");
                scanf("%d", &key);
                insert_left(value, key);
                break;
                
            case 3: 
                printf("Enter the value of node to be deleted: ");
                scanf("%d", &key);
                delete_spec(key);
                break;
                
            case 4: 
                printf("Enter the value to search: ");
                scanf("%d", &key);
                search(key);
                break;
                
            case 5: 
                display();
                break;
                
            case 6: 
                printf("Exiting program...\n");
                break;
                
            default: 
                printf("Invalid choice! Try again.\n");
        }
    } while(ch != 6);
    
    // Free allocated memory before exiting
    struct node *current = head;
    struct node *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    
    return 0;
}