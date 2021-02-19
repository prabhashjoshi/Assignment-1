#include<stdio.h>
#include<conio.h>
void main()
{
    int num,rev,unit,tens,hundreds,thousands;
    clrscr();
    printf("enter the 4 digit no.");
    scanf("%d",&num);
    unit=num%10;
    tens=(num/10)%10;
    hundreds=(num/100)%10;
    thousands=(num/1000);
    rev=((unit*1000)+(tens*100)*(hundreds*10)+thousands);
    printf("reverse of %d=%d",num,rev);
    (num==rev)?printf("true"):printf("false");
}

}