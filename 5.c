#include <stdio.h>
#include <conio.h>
void main()
{
    int adj[10][10], n, i, j, w, indeg[10], flag[10], count;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    for (i = 0; i < n; i++)
        indeg[i] = 0, flag[i] = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            indeg[i] += adj[j][i];
    count = 0;
    printf("Topological ordering is \n");
    while (count < n)
    {
        for (i = 0; i < n; i++)
            if (indeg[i] == 0 && flag[i] == 0)
            {
                printf("%d\t", i + 1);
                flag[i] = 1;
                count++;
                for (w = 0; w < n; w++)
                    if (adj[i][w] == 1)
                        indeg[w]--;
            }
    }
    getch();
}
