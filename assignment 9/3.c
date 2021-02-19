#include<stdio.h>
int main()
{
 int num,m,n;
 
 printf ("Enter range (m, n ) : ") ;
 scanf ("%d %d", &m, &n);
 if(m<n)
 {
 for (num = m; num <= n; num++) 
   printf("%d\n ",num);
 }
 else
    while(m>=n)
    {
        printf("%d\n", m);
        m--;
    }
return 0;
}