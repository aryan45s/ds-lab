#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;

// Function prototypes
int count();
struct node *create(int value);
void insert_begin(int value);
void insert_end(int value);
void insert_pos(int value, int pos);
void display();

// Count number of nodes in the list
int count()
{
    struct node *temp;
    int i = 0;
    
    if (head == NULL)
        return 0;
    
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}

// Create a new node
struct node *create(int value)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    
    if (temp == NULL)  // Fixed: was === (triple equals)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    
    temp->data = value;
    temp->next = NULL;
    return temp;
}

// Insert at beginning
void insert_begin(int value)
{
    struct node *newnode;
    newnode = create(value);
    
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    printf("Inserted %d at beginning\n", value);
}

// Insert at end
void insert_end(int value)
{
    struct node *newnode, *temp;
    newnode = create(value);
    
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Inserted %d at end\n", value);
}

// Insert at specific position
void insert_pos(int value, int pos)
{
    struct node *newnode, *temp, *prev;
    int i, total_nodes;
    
    total_nodes = count();
    
    if (pos < 1)
    {
        printf("Invalid position! Position starts from 1.\n");
        return;
    }
    else if (pos == 1)
    {
        insert_begin(value);
        return;
    }
    else if (pos > total_nodes + 1)
    {
        printf("Insertion is not possible at position %d. ", pos);
        printf("List has only %d nodes. You can insert at position %d.\n", 
               total_nodes, total_nodes + 1);
        return;
    }
    else
    {
        newnode = create(value);
        prev = NULL;
        temp = head;
        
        for (i = 1; i < pos && temp != NULL; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        
        // Insert between prev and temp
        prev->next = newnode;
        newnode->next = temp;
        
        printf("Inserted %d at position %d\n", value, pos);
    }
}

// Display the list
void display()
{
    struct node *temp;
    
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        printf("Linked List: ");
        while (temp != NULL)
        {
            printf("%d", temp->data);
            if (temp->next != NULL)
                printf(" -> ");
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()  // Changed from void main() to int main()
{
    int ch, pos, value;
    
    do
    {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1: 
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_begin(value);
                break;
                
            case 2: 
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_end(value);
                break;
                
            case 3: 
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insert_pos(value, pos);
                break;
                
            case 4: 
                display();
                break;
                
            case 5: 
                printf("Exiting program...\n");
                break;
                
            default: 
                printf("Invalid choice! Try again.\n");
        }
    } while(ch != 5);
    
    // Free allocated memory before exiting
    struct node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}
