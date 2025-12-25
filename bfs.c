#include<stdio.h>

// Function prototype
void bfs(int v);

int a[10][10], vis[10], n;

int main()  // Changed from void main() to int main()
{
    int i, j, src;
    
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
    
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    
    printf("Nodes reachable from source vertex %d: ", src);
    bfs(src);
    
    printf("\n");
    return 0;
}

void bfs(int v)
{
    int q[10], f = 1, r = 1, u, i;
    
    q[r] = v;     // Enqueue source vertex
    vis[v] = 1;   // Mark as visited
    
    while(f <= r)  // While queue is not empty
    {
        u = q[f];  // Dequeue
        printf("%d ", u);
        
        // Explore neighbors of u (not v!)
        for(i = 1; i <= n; i++)
        {
            if(a[u][i] == 1 && vis[i] == 0)  // Fixed: check adjacency with u
            {
                vis[i] = 1;     // Mark neighbor as visited
                r = r + 1;      // Increase rear
                q[r] = i;       // Enqueue neighbor
            }
        }
        f = f + 1;  // Move front pointer
    }
}