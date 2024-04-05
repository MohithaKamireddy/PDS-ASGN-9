#include <stdio.h>
#include <string.h>
#include <math.h>

struct student
{
    char name[50];
    int roll;
    float p;
};
int n = 0;

void insert(struct student st[]);
void sortName(struct student st[]);
void findOne(struct student st[]);
void specs(struct student st[], float arr[5]);
void delete(struct student st[]);
void print(struct student st[]);

int main()
{
    struct student s[100];
    int ch;
    float arr[5];
    printf("1. Insert record\n2. Sort database according to name\n3. Find a name starting with given string\n4. Analysis of perecntage of students\n5. Delete record\n6. Exit");
    while (1)
    {
        printf("\n\nEnter choice: ");
        scanf("%d", &ch);
        if (ch == 6)
        {
            break;
        }
        switch (ch)
        {
        case 1:
            insert(s);
            break;
        case 2:
            sortName(s);
            printf("\nDatabase is sorted according to names");
            break;
        case 3:
            findOne(s);
            break;
        case 4:
            specs(s, arr);
            printf("\nNumber of records in database: %.0f", arr[0]);
            printf("\nHighest percentage: %.2f", arr[1]);
            printf("\nLowest percentage: %.2f", arr[2]);
            printf("\nMean: %.2f", arr[3]);
            printf("\nStandard deviation: %.2f", arr[4]);
            break;
        case 5:
            delete (s);
            break;
        }
    }
    printf("\n\nRecords in database:\n\n");
    print(s);
    return 0;
}

void insert(struct student st[])
{
    int r, t;
    printf("\nEnter details of student:\n");
    printf("Roll no.: ");
    scanf("%d", &r);
    for (t = 0; t < n; t++)
    {
        if (r < st[t].roll)
        {
            break;
        }
    }
    if (t < n)
    {
        for (int h = n; h > t; h--)
        {
            st[h] = st[h - 1];
        }
    }
    st[t].roll = r;
    printf("Name: ");
    scanf(" %[^\n]", st[t].name);
    printf("Percentage: ");
    scanf("%f", &st[t].p);
    printf("\nRecord inserted");
    n++;
}

void sortName(struct student st[])
{
    char temp[50];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(st[j].name, st[j + 1].name) > 0)
            {
                strcpy(temp, st[j].name);
                strcpy(st[j].name, st[j + 1].name);
                strcpy(st[j + 1].name, temp);
            }
        }
    }
}

void findOne(struct student st[])
{
    int j;
    char a[50];
    printf("Enter the string: ");
    scanf(" %[^\n]", a);
    for (int i = 0; i < n; i++)
    {
        for (j = 0; a[j] != '\0'; j++)
        {
            if (a[j] != st[i].name[j])
            {
                break;
            }
        }
        if (a[j] == '\0')
        {
            printf("Name starting with %s is %s", a, st[i].name);
            return;
        }
    }
    printf("No name found starting with %s", a);
    return;
}

void specs(struct student st[], float arr[5])
{
    arr[0] = n;
    arr[1] = arr[2] = st[0].p;
    arr[3] = arr[4] = 0;
    for (int i = 0; i < n; i++)
    {
        if (st[i].p > arr[1])
        {
            arr[1] = st[i].p;
        }
        if (st[i].p < arr[2])
        {
            arr[2] = st[i].p;
        }
        arr[3] += st[i].p;
    }
    arr[3] /= n;
    for (int i = 0; i < n; i++)
    {
        arr[4] += pow(st[i].p - arr[3], 2);
    }
    arr[4] = pow(arr[4], 0.5);
}

void delete(struct student st[])
{
    int r, h;
    printf("\nEnter the roll no. of student: ");
    scanf("%d", &r);
    for (h = 0; h < n; h++)
    {
        if (st[h].roll == r)
            break;
    }
    if (h == n)
    {
        printf("\nRecored cannot be deleted\nStudent not found");
    }
    else if (h == n - 1)
    {
        printf("\nRecord deleted");
        n--;
    }
    else
    {
        for (int k = h; k < n - 1; k++)
        {
            st[k] = st[k + 1];
        }
        printf("\nRecord deleted");
        n--;
    }
}

void print(struct student st[])
{
    for (int i = 0; i < n; i++)
    {
        printf("\nStudent %d", i + 1);
        printf("\nRoll no.: %d, Name: %s, Percentage: %.2f", st[i].roll, st[i].name, st[i].p);
    }
}