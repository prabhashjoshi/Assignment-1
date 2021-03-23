#include <stdio.h>

int main()
{
    
    float i=1 , n;
    float sum=0;
    printf("Enter the value of n:");
    scanf("%f",&n);
    for(i=1;i<=n;i++)
    {
       sum=sum+(((4*i)-3)/((4*i)-1));            
       
    }
    
    printf("Sum = %f",sum);
    return 0;
}