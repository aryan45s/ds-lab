#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;


int isFull();
int isEmpty();
void enQueue(int element);
int deQueue();
void display();

int main()
{
    int option, val;
    
    do
    {
        printf("\n===== CIRCULAR QUEUE MENU =====\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the queue\n");
        printf("4. EXIT\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                printf("Enter the number to be inserted: ");
                scanf("%d", &val);
                enQueue(val);
                break;
                
            case 2:
                val = deQueue();
                if (val != -1)
                    printf("The number deleted is: %d\n", val);
                break;
                
            case 3:
                display();
                break;
                
            case 4:
                exit(0);
                
            default:
                printf("Invalid option! Try again.\n");
        }
    } while(option != 4);
    
    return 0;
}


int isFull()
{
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
        return 1;
    return 0;
}


int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}


void enQueue(int element)
{
    if (isFull())
    {
        printf("Queue is full! Cannot insert %d.\n", element);
    }
    else
    {
        if (front == -1)  // First element
            front = 0;
        
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("Inserted: %d\n", element);
    }
}


int deQueue()
{
    int element;
    
    if (isEmpty())
    {
        printf("Queue is empty! Cannot delete.\n");
        return -1;
    }
    else
    {
        element = items[front];
        
        if (front == rear)  // Only one element
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
        
        printf("Deleted: %d\n", element);
        return element;
    }
}


void display()
{
    int i;
    
    if (isEmpty())
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements: ");
        
        if (rear >= front)
        {
            for (i = front; i <= rear; i++)
                printf("%d ", items[i]);
        }
        else
        {
            for (i = front; i < SIZE; i++)
                printf("%d ", items[i]);
            for (i = 0; i <= rear; i++)
                printf("%d ", items[i]);
        }
        printf("\n");
    }
}
