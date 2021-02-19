#include <stdio.h>
int main()
{
int a,b,c,d,e,f,min1,min2,min;
printf("ENTER NUMBER a,b,c,d,e,f respectivily:");
scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
min1=(a<c)?(a<b)?a:b:(b<c)?b:c;
min2=(min1<e)?(min1<d)?min1:d:(d<e)?d:e;
min=(min2<f)?min2:f;
printf("min number=%i\n",min);
return 0;
}
