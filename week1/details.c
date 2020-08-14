#include<stdio.h>
#include<stdlib.h>
struct student
{
	char roll[12];
	char name[15];
	int m1,m2,m3;
	char grade;
};
int main()
{
	struct student s;
    float avg;
	scanf("%s%s%d%d%d",&s.roll,&s.name,&s.m1,&s.m2,&s.m3);
	printf("rollno=%s\n",s.roll);
	printf("name=%s\n",s.name);
	printf("avg=%f\n",(s.m1+s.m2+s.m3)/3.0);
	if(avg>=20)
		s.grade = 'A';
	else 
		s.grade = 'B';
printf("grade=%c\n",s.grade);
}
