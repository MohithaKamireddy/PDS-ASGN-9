#include<stdio.h>
struct date{
    int day;
    int month;
    int year;
    };
    void scandetails(struct date dates[],int n);
    int comparedates(struct date dates[]);
int main(){
    struct date dates[2];
    int n = 2;
    scandetails(dates,n);
    printf("The result is : %d",comparedates(dates));
    return 0;
}
void scandetails(struct date dates[],int n){
    for(int i = 0 ; i < n ; i++){
    printf("Enter the day of the 1st date : ");
    scanf("%d", &dates[i].day);
    printf("Enter the month of the first date : ");
    scanf("%d", &dates[i].month);
    printf("Enter the year of the first month : ");
    scanf("%d", &dates[i].year);
    }
}
int comparedates(struct date dates[]){
    
        if(dates[0].year>dates[1].year){
            return 1;
        }
        else if(dates[0].year<dates[1].year){
            return -1;
        }
        else if(dates[0].month>dates[1].month){
            return 1;
        }
        else if(dates[0].month<dates[1].month){
            return -1;
        }
        else if(dates[0].day>dates[1].day){
            return 1;
        }
        else if(dates[0].day<dates[1].day){
            return -1;
        }
        else{
            return 0;
        }
    } 

