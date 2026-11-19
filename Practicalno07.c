/*Name:Somning mali
Roll no:C02078
Title : Social Network Connectivity Using Graph Traversal*/

#include <stdio.h>
#define MAX 100
int adj[MAX][MAX], n;
void addConnection(int u, int v)
{
    if (u < 0 || u >= n || v < 0 || v >= n || u == v)
    {
        printf("Invalid user IDs!\n");
        return;
    }
    if (adj[u][v])
    {
        printf("Connection already exists.\n");
        return;
    }
    adj[u][v] = adj[v][u] = 1;
    printf("Connection added successfully.\n");
}
void displayGraph()
{
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}
void BFS(int start)
{
    int visited[MAX] = {0}, q[MAX];
    int front = 0, rear = 0, i, v;
    if (start < 0 || start >= n)
    {
        printf("Invalid starting ID!\n");
        return;
    }
    q[rear++] = start;
    visited[start] = 1;
    printf("BFS: ");
    while (front < rear)
    {
        v = q[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++)
            if (adj[v][i] && !visited[i])
            {
                visited[i] = 1;
                q[rear++] = i;
            }
    }
    printf("\n");
}
void DFSUtil(int v, int visited[])
{
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for (i = 0; i < n; i++)
        if (adj[v][i] && !visited[i])
            DFSUtil(i, visited);
}
void DFS(int start)
{
    int visited[MAX] = {0};
    if (start < 0 || start >= n)
    {
        printf("Invalid starting ID!\n");
        return;
    }
    printf("DFS: ");
    DFSUtil(start, visited);
    printf("\n");
}
int main()
{
    int choice, u, v, start;

    printf("Enter number of users (1-%d): ", MAX);
    scanf("%d", &n);
    if (n < 1 || n > MAX)
    {
        printf("Invalid number!\n");
        return 1;
    }
    do
    {
        printf("\n1. Add Connection\n2. Display Matrix\n");
        printf("3. BFS\n4. DFS\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter two user IDs: ");
                scanf("%d%d", &u, &v);
                addConnection(u, v);
                break;
            case 2:
                displayGraph();
                break;
            case 3:
                printf("Starting ID: ");
                scanf("%d", &start);
                BFS(start);
                break;
            case 4:
                printf("Starting ID: ");
                scanf("%d", &start);
                DFS(start);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}

/*output :

student@TCOERCL-VI-01:~$ cc Socialnetwork78.c
student@TCOERCL-VI-01:~$ ./a.out
Enter number of users (1-100): 4

1. Add Connection
2. Display Matrix
3. BFS
4. DFS
5. Exit
Choice: 1
Enter two user IDs: 1 
2
Connection added successfully.

1. Add Connection
2. Display Matrix
3. BFS
4. DFS
5. Exit
Choice: 2

Adjacency Matrix:
0 0 0 0 
0 0 1 0 
0 1 0 0 
0 0 0 0 

1. Add Connection
2. Display Matrix
3. BFS
4. DFS
5. Exit
Choice: 3
Starting ID: 1
BFS: 1 2 

1. Add Connection
2. Display Matrix
3. BFS
4. DFS
5. Exit
Choice: 4
Starting ID: 1
DFS: 1 2 

1. Add Connection
2. Display Matrix
3. BFS
4. DFS
5. Exit
Choice: 5
Exiting program.
student@TCOERCL-VI-01:~$ 
*/
