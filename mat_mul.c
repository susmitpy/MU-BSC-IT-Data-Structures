#include <stdio.h>

int main()
{
 int a[10][10], b[10][10], c[10][10];
 int r1, c1, r2, c2;
 int i, j, k;
 printf("Mat 1 dimen: ");
 scanf("%d %d", &r1,&c1);
 printf("Mat 2 dimen: ");
 scanf("%d %d", &r2,&c2);
 printf("Mat 1 elements: \n");
 for (i=0;i<r1;i++){
  for (j=0;j<c1;j++){
   scanf("%d", &a[i][j]);
  }
 }
 printf("Mat 2 elements: \n");
 for (i=0;i<r2;i++){
  for (j=0;j<c2;j++){
   scanf("%d", &b[i][j]);
  }
 }
 for (i=0;i<r1;i++){
  for (j=0;j<c2;j++){
   c[i][j] = 0;
   for (k=0;k<r2;k++){
    c[i][j] += a[i][k] * b[k][j];
   }
   printf("%d ", c[i][j]);
  }
  printf("\n");
 }
 return 0;
}