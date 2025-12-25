

#include <stdio.h>
#include <stdlib.h>  

#define MAX 50

int queue_array[MAX];
int rear = -1;
int front = -1;


void insert();
void delete();
void display();

int main()
{
    int choice;
    
    while (1)
    {
        printf("\n===== LINEAR QUEUE MENU =====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void insert()
{
    int add_item;
    
    if (rear == MAX - 1)
    {
        printf("Queue Overflow! Cannot insert.\n");
    }
    else
    {
        if (front == -1)  // If queue is initially empty
            front = 0;
        
        printf("Enter the element to insert: ");
        scanf("%d", &add_item);
        
        rear = rear + 1;
        queue_array[rear] = add_item;
        printf("Element %d inserted successfully.\n", add_item);
    }
}

void delete()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    else
    {
        printf("Deleted Element: %d\n", queue_array[front]);
        front = front + 1;
        
     
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

void display()
{
    int i;
    
    if (front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements: ");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}
