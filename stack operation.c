#include<stdio.h>
#include<stdlib.h>  // for exit()

#define SIZE 10

void push(int);
void pop();
void display();
void peek();

int stack[SIZE], top = -1;

int main()
{
    int value, choice;
    while(1){
        printf("\n\n***** MENU ****\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                printf("Enter the value to be insert: ");
                scanf("%d",&value);
                push(value);
                break;
            case 2: 
                pop();
                break;
            case 3: 
                display();
                break;
            case 4:
                peek();
                break;
            case 5: 
                exit(0);
            default: 
                printf("\nWrong selection!!! Try again!!!");
        }
    }
    return 0;
}

void push(int value){
    if(top == SIZE-1)
        printf("\nStack is Full!!! Insertion is not possible!!!");
    else{
        top++;
        stack[top] = value;
        printf("\nInsertion success!!!");
    }
}

void pop(){
    if(top == -1)
        printf("\nStack is Empty!!! Deletion is not possible!!!");
    else{
        printf("\nDeleted : %d", stack[top]);
        top--;
    }
}

void display(){
    if(top == -1)
        printf("\nStack is Empty!!!!");
    else{
        int i;
        printf("\nStack elements are:\n");
        for(i=top; i>=0; i--)
            printf("%d\n",stack[i]);
    }
}

// Function to peek at the top element of the stack without removing it
void peek()
{
    if(top >= 0)
    {
        int ele = stack[top];
        printf("Peeked: %d\n", ele);
    }
    else
        printf("Stack is empty. Cannot peek.\n");
}
