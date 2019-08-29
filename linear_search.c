#include <stdio.h>

int main ()
{
    int a[] = {10, 23, 40, 1, 2, 0, 14, 13, 50, 9};
    int item, i,flag=0, n = 10;
    printf("Enter Item which is to be searched\n");
    scanf("%d",&item);
    for (i = 0; i< n; i++)
    {
	if(a[i] == item){
	    flag=1;
	    break;
	}
    }
    if (flag==1)
	printf("Item found at location %d\n",i+1);
    else
	printf("Item not found\n");
    return 0;
}
