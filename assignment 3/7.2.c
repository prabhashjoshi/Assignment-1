#include<stdio.h>
int main()
{
int years=18;
int months=6;
int days=27;
int totaldays;
totaldays=((years*365)+months*31+days);
float totalmonths;
totalmonths=(years*12)+months+(days/(float)31);
float totalyears;
totalyears=years+(months/(float)31)+(days/(float)365);
printf("my age in toataldays %d\n",totaldays);
printf("my age in totalmonths %f\n",totalmonths);
printf(" my age in totalyears %f\n",totalyears);
return 0;
}