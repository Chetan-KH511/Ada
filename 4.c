#include<stdio.h>
int cost[10][10],n,dist[10];
int minm(int m, int n)
{
	return(( m < n) ? m: n);
}

void dijkstra(int source)
{
	int s[10]={0}; int min, w=0;
	
	for(int i=0;i<n;i++) 
		dist[i]=cost[source][i];
	
	//Initialize dist from source to source as 0 
	dist[source] = 0;
	
	//mark source vertex as visited
	s[source] = 1;
	
	for(int i=0; i < n-1; i++)
	{
		//Find the nearest neighbour vertex 
		min = 999;
		for(int j = 0; j < n; j++)
		{
			if ((s[j] == 0 ) && (min > dist[j]))
			{
				min = dist[j];	 w = j;
			}
		}
		
		s[w]=1;
		//Update the shortest path of neighbour of w 
		for(int v=0;v<n;v++)
		{
			if(s[v]==0 && cost[w][v]!=999)
			{
				dist[v]= minm(dist[v],dist[w]+cost[w][v]);
			}	
		}
	}
}

int main()
{
	int source;

	printf("Enter the no.of vertices: "); 
	scanf("%d",&n);

	printf("Enter the cost matrix\n"); 
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) 
			scanf("%d",&cost[i][j]);
		
	printf("Enter the source vertex: "); 
	scanf("%d",&source); 
	
	dijkstra(source);
	
	printf("the shortest distance is... \n"); 
	
	for(int i=0; i<n; i++)
		printf("Cost from %d to %d is %d\n",source,i,dist[i]);
}
