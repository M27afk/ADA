#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,j,k,cnt=0;
	FILE *f;
	system("rm file.txt");
	f=fopen("file.txt","a");
	for(n=3;n<=10;n++){
	
		cnt=0;
		//printf("\nEnter no of nodes in the graph");
		//scanf("%d",&n);
		int w[n][n];
		//printf("\nEnter adjacency matrix:");
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		w[i][j]=rand()%2;

		//scanf("%d",&w[i][j]);
		
		for(k=0;k<n;k++)
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			cnt++;
			w[i][j]=(w[i][j] || (w[k][j] && w[i][k]));
		}
		
		printf("\n");
		for(i=0;i<n;i++)
		{for(j=0;j<n;j++)
		{printf("%d ",w[i][j]);
		}
		printf("\n");
		}
		fprintf(f,"\n%d\t%d",n,cnt);
	}
	fclose(f);
	return 0;
}
