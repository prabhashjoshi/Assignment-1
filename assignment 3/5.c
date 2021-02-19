#include<stdio.h>  
 int main()    
{    
int a=2, b=9;      
printf("Before a=%d b=%d",a,b);      
a=a+b;    
b=a-b;    
a=a-b;    
printf("\nAfter a=%d b=%d",a,b);    
return 0;  
}