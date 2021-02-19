#include<stdio.h>
int main(){
int num,a,b,c,d,e,f,sq;
printf("enter four digit number");
scanf("%d",&num);
a=num%10;
b=(num/10)%10;
c=(num/100)%10;
d=(num/1000)%10;
e=(c*10+b);
f= (d*10+a);
sq=e*e;
(f==sq)? printf("y"):printf("n");
return 0;
}