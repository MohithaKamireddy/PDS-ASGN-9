#include<stdio.h>
struct company{
    char name[100];
    char address[100];
    long long int phone;
    int members;
    
};
int main(){
    struct company c1;
    printf("Enter the name of the company : ");
    gets(c1.name);
    printf("Enter the Address of the company : ");
    gets(c1.address);
    printf("Enter the Phone of the company : ");
    scanf("%lld", &c1.phone);
    printf("Enter the no of Employees in the company : ");
    scanf("%d", &c1.members);
    printf("The name of the company is : ");
    puts(c1.name);
    printf("The Phone number of the company is :%lld\n", c1.phone);
    printf("The no of employees in the company is : %d\n", c1.members);

    return 0;



}