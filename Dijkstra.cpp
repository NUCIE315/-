//用Microsoft Visual C++6.0编程Dijkstra.cpp如下：
//Dijkstra.cpp
#include <stdio.h>
#include "math.h"
#define inf 999
#define N 8
int main()
{
	int i,j,k;
	double r,l[N];
	int u,t[N],flag;
	int s[N];
	double w[N][N]={ 0,1,2,inf,7,inf,4,8,
					1,0,2,3,inf,inf,inf,7,
					2,2,0,1,5,inf,inf,inf,
					inf,3,1,0,3,6,inf,inf,
					7,inf,5,3,0,4,3,inf,
					inf,inf,inf,6,4,0,6,4,
					4,inf,inf,inf,3,6,0,2,
					8,7,inf,inf,inf,4,2,0
				  };
	FILE *fp;
	fp=fopen("D:\dijstra-1.txt","w");
	for(i=0;i<N;i++)
		{
			l[i]=w[0][i];
			t[i]=0;
			s[i]=i;
		}
	u=0;
p:  for(i=0;i<N;i++)
		{
			if(s[i]>0)
			{
			r=l[u]+w[u][s[i]];
			if(l[s[i]]>r)
				{
					l[s[i]]=r;
					t[s[i]]=u;
				}
			}
		}
	r=inf;
	for(i=0;i<N;i++)
		{   if(s[i]>0)
			{
			if(l[s[i]]<r)
				{
					r=l[s[i]];
					u=s[i];
					k=i;
				}
			}
		}
	s[k]=0;
	flag=0;
	for(i=0;i<N;i++)
		if(s[i]>0)
			flag=1;
	if(1==flag)
		goto p;
	else
		printf("Finished!\n");
	fprintf(fp,"W=\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			{
				fprintf(fp,"%6.0f",w[i][j]);
			}
		fprintf(fp,"\n");
	}
	fprintf(fp,"l=\n");
	for(i=0;i<N;i++)
		fprintf(fp,"%6.0f",l[i]);
	fprintf(fp,"\n");
	fprintf(fp,"t=\n");
    for(i=0;i<N;i++)
		fprintf(fp,"%6d",t[i]);
	fprintf(fp,"\n");
	fclose(fp);
	return 0;
}

