#include<conio.h>
#include<stdio.h>
int a[10][10];
void prims(int n){
    int i, j;
    int mincost=0, min, u, v, visited[10], ne=0;
    for(int i=1; i<=n; i++){
        visited[i]=0;
    }
    visited[1]=1;
    while(ne<n-1){
        min=999;
        for(i=1; i<=n; i++){
            if(visited[i] == 1){
                for(j=1; j<=n; j++){
                    if(a[i][j] < min){
                        min = a[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        if(visited[u] == 0 || visited[v] == 0){
            printf("From vertex  %d to %d cost=%d\n",u,v,min);
            ne++;
            mincost += min;
            visited[v] =1;
        }
        a[v][u] = a[u][v] = 999;
       }
printf("The Mincost is %d\n",mincost);
}
int main()
{
	int i,j,n;
	printf("Enter the no of nodes\n");
	scanf("%d",&n);
	printf("Enter matrix\n");

	for(i=1;i<=n;i++)
	 {
		  for(j=1;j<=n;j++)
		  {
			 scanf("%d",&a[i][j]);
		  }
	 }
	 prims(n);

         return 0;
}
