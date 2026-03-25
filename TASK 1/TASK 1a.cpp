#include<stdio.h>
int integersquareroot(int x)
{
	int count = 0;
	int odd = 1;
	while(x>=odd) 
	{
		x=x-odd;
		odd=odd+2;
		count++;
	}
	return count ;
}
int main ()
{
	int x ;
	printf("Enter a non-negative number: ");
	scanf("%d",&x);
	printf("squareroot(rounded down)=%d\n", integersquareroot(x));
	return 0;
}
