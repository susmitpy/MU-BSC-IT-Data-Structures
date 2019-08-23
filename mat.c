#include <stdio.h>

struct Matrix
{
  int r;
  int c;
  int m[10][10];
};

struct Matrix getMatrix()
{
  struct Matrix m;
  int i,j;
  printf("Dimensions: ");
  scanf("%d %d",&m.r,&m.c);
  printf("Elements:\n");
  for(i=0;i<m.r;i++)
  {
    for(j=0;j<m.c;j++)
    {
      scanf("%d",&m.m[i][j]);
    }
  }
  return m;
}

void displayMatrix(struct Matrix m)
{
  int i,j;
  for(i=0;i<m.r;i++)
  {
    for(j=0;j<m.c;j++)
    {
      printf("%d ",m.m[i][j]);
    }
    printf("\n");
  }
}

struct Matrix addMatrices(struct Matrix a, struct Matrix b)
{
  struct Matrix c;
  int i,j;
  c.r = a.r;
  c.c = b.c;
  for(i=0;i<a.r;i++)
  {
    for(j=0;j<a.c;j++)
    {
      c.m[i][j] = a.m[i][j] + b.m[i][j];
    }
  }
  return c;
}

struct Matrix mulMatrices(struct Matrix a, struct Matrix b)
{
  struct Matrix m;
  int i,j,k;
  m.r = a.r;
  m.c = b.c;
  for(i=0;i<m.r;i++)
  {
    for(j=0;j<m.c;j++)
    {
      m.m[i][j]=0;
      for(k=0;k<m.c;k++)
      {
        m.m[i][j] += a.m[i][k] * b.m[k][j];
      }
    }
  }
  return m;
}

struct Matrix tranMatrix(struct Matrix m)
{
  struct Matrix t;
  int i,j;
  t.r = m.c;
  t.c = m.r;
  for(i=0;i<t.r;i++)
  {
    for(j=0;j<t.c;j++)
    {
      t.m[i][j] = m.m[j][i];
    }
  }
  return t;
}

struct Matrix options(struct Matrix a, struct Matrix b){
	char c;
	printf("Op: ");
	scanf(" %c",&c);
	switch(c){
		case 'a':
			return addMatrices(a,b);
		case 'm':
			return mulMatrices(a,b);
		case 't':
			return tranMatrix(a);
		default:
			printf("Invalid Op\n");
	}
}



int main()
{
 struct Matrix a,b,ans;
 printf("Mat 1\n");
 a = getMatrix();
 printf("Mat 2\n");
 b = getMatrix();
 ans = options(a,b);
 // printf("\nAddition\n");
 // c = addMatrices(a,b);
 // displayMatrix(c);
 // printf("\nMultiplication\n");
 // d = mulMatrices(a,b);
 // displayMatrix(d);
 // printf("\nTranspose of first matrix: \n");
 // e = tranMatrix(a);
 displayMatrix(ans);
 return 0;
}
