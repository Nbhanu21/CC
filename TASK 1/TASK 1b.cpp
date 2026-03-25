#include<stdio.h>
int isugly(int n)
{
	if(n<=0)
	return 0 ;
	while (n%2==0)
	n=n/2;
	while(n%3==0)
	n=n/3;
	while(n%5==0)
	n=n/5;
	return (n==1);
}
int main ()
{
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	if (isugly(n))
	printf("%d is an ugly number/n",n);
	else
	printf("%d is not an ugly number/n",n);
	return 0;
}
