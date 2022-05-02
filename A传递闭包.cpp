#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int N;
	cin>>N;//输入N阶矩阵 
	
	int a[N][N];
	int b[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>a[i][j];//输入矩阵M 
		}
	}	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			b[i][j]=a[i][j];//置新矩阵A 
		}
	}
 
	//warshall算法 
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(b[j][i]==1)
			{
				for(int k=0;k<N;k++)
				{
					if(b[j][k]==0&&b[i][k]==0)
					{
						b[j][k]=0;
					}
					else	b[j][k]=1;
				}
				
			}
			
		}
		
	} 
	
	
	
	//打印传递闭包的矩阵 
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%d ",b[i][j]);
			if((j+1)%N==0)	cout<<endl;
		}
	}
		
	
	
	
	return 0;
} 
