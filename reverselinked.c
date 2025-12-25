#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct node {
    int data;
    struct node *next;
};

// Function prototype
struct node *create(int value);

// Function to insert a node at the beginning of the list
struct node *insert_beg(struct node *head, int value)
{
    struct node *newnode;
    newnode = create(value);

    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
    return head;
}

// Function to create a new node
struct node *create(int value)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL) {
        printf(" Memory allocation failed\n");
        exit(0);
    }

    temp->data = value;
    temp->next = NULL;
    return temp;
}

// Function to print the linked list
void display(struct node *head)
{
    struct node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
struct node *reverse_list(struct node *head)
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to sort the linked list using bubble sort
struct node *sort_list(struct node *head)
{
    int swap;
    struct node *ptr1;
    struct node *lptr = NULL;

    if (head == NULL)
        return NULL;

    do {
        swap = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swap = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swap);

    return head;
}

// Function to concatenate two linked lists
struct node* concat_lists(struct node *head1, struct node *head2)
{
    struct node *current;

    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    current = head1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head2;
    return head1;
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int m, n, val, i;

    printf(" Enter no. of nodes in the lists\n");
    scanf("%d %d", &m, &n);

    // Create first list
    printf(" enter the values\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &val);
        head1 = insert_beg(head1, val);
    }

    printf(" List 1 is: ");
    display(head1);

    // Create second list
    printf(" enter the values\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        head2 = insert_beg(head2, val);
    }

    printf("List 2 is: ");
    display(head2);

    // Reverse List 1
    head1 = reverse_list(head1);
    printf("Reversed List 1 is: ");
    display(head1);

    // Sort List 2
    head2 = sort_list(head2);
    printf("Sorted List 2 is: ");
    display(head2);

    // Concatenate List 1 and List 2
    struct node *concat_head = concat_lists(head1, head2);
    printf("Concatenated List is: ");
    display(concat_head);

    return 0;
}
