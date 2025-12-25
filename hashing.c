#include<stdio.h>
#include<stdlib.h>

int key[20], n, m;
int *ht;
int count = 0;

// Function prototypes
void insert(int key_val);
void display();

int main()
{
    int i;
    
    printf("Enter the number of employee records (N): ");
    scanf("%d", &n);
    
    printf("Enter the size of hash table (m): ");
    scanf("%d", &m);
    
  
    ht = (int *)malloc(m * sizeof(int));
    if (ht == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
   
    for(i = 0; i < m; i++)
        ht[i] = -1;  
    
    printf("Enter the four-digit key values (K) for N Employee Records:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &key[i]);
    }
    
    // Insert keys into hash table
    for(i = 0; i < n; i++)
    {
        if(count == m)
        {
            printf("\nHash table is full. Cannot insert record %d (key: %d)\n", i+1, key[i]);
            break;
        }
        insert(key[i]);
    }
    
   
    display();
    
   
    free(ht);
    
    return 0;
}

void insert(int key_val)
{
    int index = key_val % m;
    int original_index = index;
    
    
    while(ht[index] != -1)
    {
        index = (index + 1) % m;
        
       
        if(index == original_index)
        {
            printf("Hash table is full. Cannot insert key %d\n", key_val);
            return;
        }
    }
    
    ht[index] = key_val;
    count++;
}

void display()
{
    int i;
    
    if(count == 0)
    {
        printf("\nHash Table is empty\n");
        return;
    }
    
    printf("\nHash Table contents:\n");
    printf("Index\tValue\n");
    printf("-----\t-----\n");
    for(i = 0; i < m; i++)
    {
        printf("T[%d]\t%d\n", i, ht[i]);  
    }
    
    printf("\nTotal records inserted: %d", count);
    printf("\nHash table size: %d", m);
    
  
    int empty_count = 0;
    for(i = 0; i < m; i++)
    {
        if(ht[i] == -1)
            empty_count++;
    }
    printf("\nEmpty slots (with -1): %d", empty_count);
}
