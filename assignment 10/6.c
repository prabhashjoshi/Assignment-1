#include<stdio.h>

int main(void){
    printf("Mon\tTue\tWed\tThur\tFri\tSat\tSun\n");
    printf("1\t2\t3\t4\t5\t6\t7\n");
    int day;
    printf("Enter the day according to the above format:- " );
    scanf("%d",&day);
    printf("\n");
    
    printf("Mon\tTue\tWed\tThur\tFri\tSat\tSun\n");
    //int i=1;
    int counter=1,j;
    j=day;
    if((day>=1)&&(day<=7))
        while(j>1){
            printf("\t");
            j--;
            
            }
            //day=day-1;
        while(counter>0&&counter<=31){
                //day=day-1;
                if(day%8==0){
                    printf("\n");
                    day=1;
                }
                
                    
                else{
                    printf("%d\t",counter);
                    counter++;
                    //i++;
                    day++;
                }   
            
        }
    return 0;
}