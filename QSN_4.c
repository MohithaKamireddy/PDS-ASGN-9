#include<stdio.h>
struct address{
  char street[100];
  char city[50];
  long long int zipcode;
};
struct person{
  char name[100];
  struct address add;
};
void scandetails(struct person *ptr);
void printdetails(struct person *ptr);
int main(){
    struct person per;
    struct person *ptr=&per;
    scandetails(ptr);
    printdetails(ptr);
    return 0;
}
void scandetails(struct person *ptr){
    printf("Enter the name of the person : ");
    gets(ptr->name);
     printf("Enter the street of the person : ");
     gets(ptr->add.street);
    printf("Enter the city of the person : ");
    gets(ptr->add.city);
    printf("Enter the zip code of the person : ");
    scanf("%lld", &ptr->add.zipcode);
    getchar();
}
void printdetails(struct person *ptr){
    printf("The name of the person is : ");
    puts(ptr->name);
    printf("The street of the person is : ");
    puts(ptr->add.street);
    printf("The city of the person is : ");
    puts(ptr->add.city);
    printf("The zipcode of the person is : %lld",ptr->add.zipcode);

}