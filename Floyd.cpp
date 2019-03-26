//用Microsoft Visual C++6.0编程Floyd.cpp如下：
//Floyd.cpp
#include <stdio.h>
#include <stdio.h>
#include "math.h"
#define N 6
#define inf 999
int main()
{
	FILE *fp;
	int i,j,k;
	int r[N][N]={0};
	double d[N][N]={
                    0,1,inf,inf,inf,2,
                    1,0,4,inf,inf,4,
					inf,4,0,2,inf,1,
					inf,inf,2,0,3,3,
					inf,inf,inf,3,0,5,
					2,4,1,3,5,0,
				 };
	double a;
	fp=fopen("D:\Foldy-1.txt","w");
    for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			r[i][j]=j;
		}

	for(k=0;k<N;k++)
	{
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
			{
				a=d[i][k]+d[k][j];
				if(d[i][j]>a)
					{
						d[i][j]=a;
			            r[i][j]=k;
					}
			}
	}
	fprintf(fp,"\n D=\n");
	for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
				fprintf(fp,"%5.2f",d[i][j]);
			fprintf(fp,"\n");
		}
	fprintf(fp,"\n R=\n");
    for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
				fprintf(fp,"%5d",r[i][j]+1);
			fprintf(fp,"\n");
		}
	fclose(fp);
	return 0;
}
