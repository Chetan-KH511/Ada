#include<stdio.h>
#include<conio.h>
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
void main()
{
	int n,i,j,capacity;
	int weight[20],value[20];
	int V[20][20],w;
	printf("Enter the number of items: \n");
	scanf("%d",&n);
	printf("__________________\n");
	printf("\nWEIGHTS VALUES\n");
	printf("\n__________________\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&weight[i]);
		scanf("%d",&value[i]);
	}
	
	printf("Enter the capacity of kanpsack \n");
	scanf("%d",&capacity);
	
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=capacity;j++)
		{
			if(i==0 || j==0)
			{
				V[i][j]=0;
			}
			else if(j-weight[i]>=0)
			{
				V[i][j]=max(V[i-1][j],V[i-1][j-weight[i]]+value[i]);
			}
			else
			{
				V[i][j]=V[i-1][j];
			}
			printf("%d\t",V[i][j]);
		}
		printf("\n");
	}
	
	w=capacity;
	printf("The items in the knapsack are \n");
	for(i=n;i>0;i--)
	{
		if(V[i][w]==V[i-1][w])
			continue;
		else
		{
			printf("%d\t",weight[i]);
			w=w-weight[i];
		}
	}
	printf("\n Total profit= %d",V[n][capacity]);
	getch();
}	