#include <stdio.h>
int main(){
	char* pc;
	short* ps;
	int* pi;
	long* pl;
	long long* pll;
	float* pf;
	double* pd;
	
	//现将整形类型转化对应的指针类型在赋值
	pc = (char*)100;
	ps = (short*)100;
	pi = (int*)100;
	pl = (long*)100;
	pll = (long long*)100;
	pf = (float*)100;
	pd = (double*)100;
	
	pc = pc + 1; 
	ps = ps + 1;
	pi = pi + 1;
	pl = pl + 1;
	pll = pll + 1;
	pf = pf + 1;
	pd = pd + 1;
	
	printf("pc=%u\n",pc);
	printf("ps=%u\n",ps);
	printf("pi=%u\n",pi);
	printf("pl=%u\n",pl);
	printf("pll=%u\n",pll);
	printf("pf=%u\n",pf);
	printf("pd=%u\n",pd);
} 
