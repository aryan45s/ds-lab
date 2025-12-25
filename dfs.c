#include<stdio.h>

// Function prototype
void dfs(int v);

int n, i, j;
int a[10][10], vis[10], count = 0;

int main()  // Changed from void main() to int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0;  // Initialize all vertices as unvisited
    }
    
    printf("DFS Traversal: ");
    
    // Start DFS from first vertex
    if(n > 0)
        dfs(1);
    else
        printf("No vertices to traverse!");
    
    printf("\n");
    
    // Check if all vertices were visited
    count = 0;
    for(i = 1; i <= n; i++)
    {
        if(vis[i] == 1)
        {
            count++;
        }
    }
    
    // Determine connectivity
    if(count == n)
        printf("Graph is connected\n");
    else
        printf("Graph is not connected\n");
    
    return 0;
}

// DFS function
void dfs(int v)
{
    vis[v] = 1;
    printf("%d ", v);
    
    for(j = 1; j <= n; j++)
    {
        if(a[v][j] == 1 && vis[j] == 0)
        {
            dfs(j);
        }
    }
}