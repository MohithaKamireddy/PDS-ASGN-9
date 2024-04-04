#include<stdio.h>
struct student{
    char firstname[50];
    char lastname[50];
    int rollno;
    char department[50];
    char coursecode[20];
    int threetestmarks[3];
};
void scandetails(struct student student[],int n);
void printdetails(struct student student[],int n);
float average(struct student student[],int i);
char passorfail(struct student student[],int i);
int main(){
    int n;
    float q;
    printf("Enter the no of students : ");
    scanf("%d",&n);
    getchar();
    struct student student[n];
    scandetails(student,n);
    for(int i = 0 ; i < n ; i++){
      q=average(student,i);
      printf("The average of the marks of student-%d is : %f\n", (i+1),q);
    }
    for(int i = 0 ; i < n ; i++){
    char ch = passorfail(student,i);
    if(ch=='P'){
      printf("TRUE");
    }
    else if(ch == 'F'){
      printf("False");
    }
    }
  
return 0;
    


}
void scandetails(struct student student[],int n){
  for(int i = 0 ; i< n ; i++){
    printf("Enter the first name of the student - %d : ", (i+1));
    gets(student[i].firstname);
    printf("Enter the last name of the student-%d: ", (i+1));
    gets(student[i].lastname);
    printf("Enter the roll no of the student-%d : ", (i+1));
    scanf("%d", &student[i].rollno);
    getchar();
    printf("Enter the department of the student-%d: ", (i+1));
    gets(student[i].department);
    printf("Enter the course code of the student-%d : ", (i+1));
    gets(student[0].coursecode);
    printf("Enter the marks of the three subjects of student -%d : ", (i+1));
    scanf("%d %d %d", &student[i].threetestmarks[0],&student[i].threetestmarks[1],&student[i].threetestmarks[2]);
    getchar();

  }
  void printdetails(struct student student[],int n){
   for(int i = 0 ; i < n ; i++){
    printf("The first name of the student - %d is : ", (i+1));
    puts(student[i].firstname);
    printf("\n");
    printf("The last name of the student-%d is : ",(i+1));
    puts(student[i].lastname);
    printf("\n");
    printf("The roll no of the student-%d is : %d\n", (i+1),student[i].rollno);
    

   }

  
  }
  
}
float average(struct student student[],int i){
  float p;
  p=(((float)student[i].threetestmarks[0]+(float)student[i].threetestmarks[1]+(float)student[i].threetestmarks[2])/3);
  
  return p;
 
}
char passorfail(struct student student[],int i){
  
  if(student[i].threetestmarks[0]>=35 &&student[i].threetestmarks[1]>=35 && student[i].threetestmarks[2]>=35){
    return 'P';
      
  }
  else{
    return 'F';
  }
}