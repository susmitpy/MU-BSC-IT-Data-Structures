#include <stdio.h>

void TOH(char from,char to,char other,int n){
    if (n==1) {
        printf("Move disc 1 from %c to %c\n",from,to);
    }
    if (n>1) {
        TOH(from,other,to,n-1);
        printf("Move disc %d from %c to %c \n",n,from,to);
        TOH(other,to,from,n-1);
    }
    
}

int main(){
    int num;
    printf("Enter no. of disc: ");
    scanf("%d",&num);
    printf("TOH for %d no. of discs\n",num);
    TOH('A','B','C',num);
    return 0;
}
