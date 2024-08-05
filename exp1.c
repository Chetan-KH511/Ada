#include <stdio.h>;
int cost[10][10];
void krush(int n)
{
    int parent[10], i, j, ne = 0, min, mincost = 0, a, b, u, v;
    for (i = 1; i <= n; i++)
    {
        parent[i] = 0;
    }
    while (ne != n - 1)
    {
        min = 999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    u = i;
                    b = j;
                    v = j;
                }
            }
        }
        while (parent[u] != 0)
            u = parent[u];
        while (parent[v] != 0)
            v = parent[v];
        if (u != v)
        {
            printf("\nVertex(%d-->%d)=%d", a, b, min);
            ne++;
            parent[v] = u;
            mincost = mincost + min;
        }

        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nCost of Spanning Tree is = %d\n", mincost);
}
int main()
{
    int i, j, n;
    printf("Enter the no of nodes\n");
    scanf("%d", &n);
    printf("Enter the matrix\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    krush(n);
    return 0;
}