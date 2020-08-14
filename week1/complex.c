#include<stdio.h>
#include<stdlib.h>
typedef struct complex
{
	int real,imag;
}complex;
complex add(struct complex c1,struct complex c2)
{
	complex c3;
	c3.real=c1.real+c2.real;
	c3.imag=c1.imag+c2.imag;
	return c3;
}
complex sub(struct complex c1,struct complex c2)
{
	complex c4;
	c4.real=c1.real-c2.real;
	c4.imag=c1.imag-c2.imag;
	return c4;
}
complex mul(struct complex c1,struct complex c2)
{
	complex c5;
	c5.real= (c1.real*c2.real) - (c1.imag*c2.imag);
	c5.imag= (c1.real*c2.imag) + (c2.real*c1.imag);
	return c5;
}
int main()
{
	struct complex c1,c2,c3,c4,c5;
	scanf("%d%d",&c1.real,&c1.imag);	
	scanf("%d%d",&c2.real,&c2.imag);
	c3=add(c1,c2);
	c4=sub(c1,c2);
	c5=mul(c1,c2);
	printf("%d+i%d\n",c3.real,c3.imag);
	printf("%d+i%d\n",c4.real,c4.imag);
	printf("%d+i%d",c5.real,c5.imag);
	return 0;
}
	
