#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int N;
	cin>>N;//����N�׾��� 
	
	int a[N][N];
	int b[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>a[i][j];//�������M 
		}
	}	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			b[i][j]=a[i][j];//���¾���A 
		}
	}
 
	//warshall�㷨 
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
	
	
	
	//��ӡ���ݱհ��ľ��� 
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
