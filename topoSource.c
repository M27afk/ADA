#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,k,n,cnt=0;
	printf("\nEnter no of nodes:\n");
	scanf("%d",&n);
	int a[20][20];int id[20]={0},f[20]={0};
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&a[i][j]);
	
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	id[i]+=a[j][i];
	
	while(cnt!=n)
	{
		for(i=0;i<n;i++)
		{
			if(id[i]==0 && f[i]==0)
			{
				printf("%c->",i+65);
				f[i]=1;	
				for(j=0;j<n;j++)
				{

					if(a[i][j]==1)
					{
						a[i][j]=0;
						id[j]--;
					}
					
				}
				cnt++;
			}
		}
	}
	
	return 0;
}
