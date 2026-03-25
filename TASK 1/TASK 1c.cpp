#include <stdio.h>

int product_of_array(int arr[], int n)
{
    int product = 1;
    int i;

    for (i = 0; i < n; i++)
    {
        product = product * arr[i];
    }
    return product;
}

int main()
{
    int n;
    int arr[100];   // maximum size
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Product of array elements = %d\n", product_of_array(arr, n));

    return 0;
}

