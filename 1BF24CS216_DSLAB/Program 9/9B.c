#include<stdio.h>
int graph[20][20], visited[20], n;
void dfs(int v)
{
    visited[v] = 1;
    printf("%d ", v);
    for(int i = 0; i < n; i++)
    {
        if(graph[v][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}
void main()
{
    int connected = 1;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    for(int i = 0; i < n; i++)
        visited[i] = 0;
        printf("DFS Traversal starting from vertex 0:\n");
    dfs(0);
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            connected = 0;
            break;
        }
    }
    if(connected)
        printf("The graph is connected.\n");
    else
        printf("The graph is not connected.\n");
}