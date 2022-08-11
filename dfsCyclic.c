#include<stdio.h>
#include<stdlib.h>
int isCyclic=0,count=0;
int isCycle(int g[][20],int n,int s,int v[],int dv[])
{
	v[s]=1;
	dv[s]=1;
	for(int i=0;i<n;i++)
	{
	
		if(!v[i])
		{
			if(isCycle(g,n,i,v,dv))
			return 1;
		}
		else if(dv[i])
		return 1;
	}
	dv[s]=0;
	return 0;
	
}
void dfs(int g[][20],int n,int s,int v[])
{
	printf(" %c ->",s+65);
	v[s]=1;
	count++;
	for(int i=0;i<n;i++)
	{
	
		if(g[s][i]==1 && !v[i])
		{
			dfs(g,n,i,v);
			
		}
	}
	return;
	
}
int main()
{
	int g[20][20],v[20],dv[20],n;
	printf("\nEnter the num of nodes:");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	scanf("%d",&g[i][j]);
	
	for(int i=0;i<n;i++) {v[i]=0;dv[i]=0;}
	
	if(isCycle(g,n,0,v,dv))
	printf("\nAcylic\n"); 
	else
	printf("\nCyclic\n");
	
	for(int i=0;i<n;i++) {v[i]=0;}
	dfs(g,n,0,v);
	
	if(count==n)
	printf("\nGraph is connected:");
	else
	{
		while(count!=n){
		printf("\nGraph is disconnected at:");
		for(int i=0;i<n;i++)
		if(v[i]==0)
		dfs(g,n,i,v);
		}
	}

	return 0;
}
