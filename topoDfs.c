#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int top=-1;
void dfs(int g[][MAX],int n,int v[],int st[],int s)
{
	v[s]=1;
	for(int i=0;i<n;i++)
	{
		if(g[s][i]==1 && !v[i])
		dfs(g,n,v,st,i);
	}
	st[++top]=s;
	return;
}

void sort(int g[][MAX],int n,int v[],int st[],int s)
{
	for(int i=0;i<n;i++)
	{
		if(!v[i])
		dfs(g,n,v,st,i);
	}
	return;
}

int main()
{
	int n,i,j;
	printf("\nEnter no of nodes in the graph:");
	scanf("%d",&n);
	int g[MAX][MAX],v[MAX],st[MAX],s;
	printf("\nEnter adj matrix:");
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&g[i][j]);
	for(i=0;i<n;i++)
	{
		v[i]=0;
		
	}
	sort(g,n,v,st,0);
	for(i=n-1;i>=0;i--)
	printf("%c-",st[i]+65);
	return 0;
}
