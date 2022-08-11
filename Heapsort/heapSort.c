#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int count=0;
void heapify(int *a,int n, int i)
{
	count++;
	int largest=i;
	int lc=2*i+1;
	int rc=2*i+2;
	if(a[lc] > a[largest] && lc<n)
	largest=lc;
	if(a[rc] > a[largest] && rc<n)
	largest=rc;
	
	if(largest!=i)
	{
		int temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		heapify(a,n,largest);
	}
}
void heapsort(int a[],int n)
{
	int i;
	for(i=n/2 -1;i>=0;i--)
	{
		heapify(a,n,i);
	}
	for(i=n-1;i>=0;i--)
	{
		count++;
		int temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		heapify(a,i,0);
	}

}
int main()
{
	int *a,n,i;
	FILE *f1,*f2,*f3,*ba,*aa,*wa;
	system("rm -f heap_*.txt");
	f1=fopen("heap_best.txt","a");
		f2=fopen("heap_avg.txt","a");
			f3=fopen("heap_wst.txt","a");

						srand(time(0));
	for(n=10;n<=100;n+=10)
	{	
		a=(int *)malloc(n*sizeof(int));
		
		
		for(i=0;i<n;i++)//best case
		a[i]=1;
		
		count=0;
		heapsort(a,n);
		fprintf(f1,"%d\t%d\n",n,count);

		
		for(i=0;i<n;i++)//avg case
		a[i]=rand()%2;
    
		count=0;
		heapsort(a,n);
		fprintf(f2,"%d\t%d\n",n,count);
		
		
		
		for(i=0;i<n;i++)//worst case
		a[i]=n-i-1;
		
		count=0;
		heapsort(a,n);
		fprintf(f3,"%d\t%d\n",n,count);


	}
	fclose(f1);	fclose(f2);	fclose(f3);	return 0;
}
