#include<stdio.h>
int main(){
int a,b,c,d,e,f,g,h,i;
scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
g = (a<b)?((a<c)? a:c) : ((b<c)? b:c);
h= (e<d)? ((e<f)? e:f) : ((d<f)? d:f);
i= (g<h)? g:h;

printf("%d this is smallest ",i);
return 0;

}