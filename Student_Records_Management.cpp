#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
struct sem1
{
 int rollno;
 char name[50];
 int eng_marks,alg_marks,bsm_marks,hb_marks,c_marks;
 float gpa;
 char grade;
 int std;
}sem1;
 FILE *fptr;
void write_student_sem1()
   {
    fptr=fopen("sem1.dat","ab");
    printf("\nPlease Enter The New Details of student \n");
    printf("\nEnter The roll number of student: ");
    scanf("%d",&sem1.rollno);
    fflush(stdin);
    printf("\n\nEnter The Name of student: ");
    gets(sem1.name);
    printf("\nEnter The marks in Technical English out of 100 : ");
    scanf("%d",&sem1.eng_marks);
    printf("\nEnter The marks in Algebra and calculus out of 100 : ");
    scanf("%d",&sem1.alg_marks);
    printf("\nEnter The marks in Basic Statistical Methods out of 100 : ");
    scanf("%d",&sem1.bsm_marks);
    printf("\nEnter The marks in Human Behaviour out of 100 : ");
    scanf("%d",&sem1.hb_marks);
    printf("\nEnter The marks in C Programming out of 100 : ");
    scanf("%d",&sem1.c_marks);
    sem1.gpa=(sem1.eng_marks+sem1.alg_marks+sem1.bsm_marks+sem1.hb_marks+sem1.c_marks)/50.0;
    if(sem1.gpa>=8.5)
       sem1.grade='A';
    else if(sem1.gpa>=7.5 &&sem1.gpa<8.5)
      sem1.grade='B';
    else if(sem1.gpa>=6 &&sem1.gpa<7.5)
      sem1.grade='C';
    else if(sem1.gpa>=5 &&sem1.gpa<6)
      sem1.grade='D';
    else
     sem1.grade='E';
    fwrite(&sem1,sizeof(sem1),1,fptr);
    fclose(fptr);
    printf("\n\nStudent Record Has Been Created ");
    getch();
}



void display_all_sem1()
{
    system("cls");
    printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");
    fptr=fopen("sem1.dat","rb");
    while((fread(&sem1,sizeof(sem1),1,fptr))>0)
    {
      printf("\nRoll Number of Student : %d",sem1.rollno);
      printf("\nName of student : %s",sem1.name);
      printf("\nMarks in Technical English : %d",sem1.eng_marks);
      printf("\nMarks in Algebra and Calculus : %d",sem1.alg_marks);
      printf("\nMarks in Basic Statistical Methods : %d",sem1.bsm_marks);
      printf("\nMarks in Human Behaviour : %d",sem1.hb_marks);
      printf("\nMarks in C Programming : %d",sem1.c_marks);
      printf("\nCGPA of student is  : %.2f",sem1.gpa);
      printf("\nGrade of student is : %c",sem1.grade);
      printf("\n\n====================================\n");
      getch();
    }
    fclose(fptr);
    getch();
}

void display_sp_sem1(int n)
{
    int flag=0;
    fptr=fopen("sem1.dat","rb");
    while((fread(&sem1,sizeof(sem1),1,fptr))>0)
    {
     if(sem1.rollno==n)
        {
         system("cls");
            printf("\nRoll number of student : %d",sem1.rollno);
            printf("\nName of student : %s",sem1.name);
            printf("\nMarks in Technical English : %d",sem1.eng_marks);
            printf("\nMarks in Algebra and Calculus : %d",sem1.alg_marks);
            printf("\nMarks in Basic Statistical Methods : %d",sem1.bsm_marks);
            printf("\nMarks in Human Behaviour : %d",sem1.hb_marks);
            printf("\nMarks in C Programming : %d",sem1.c_marks);
            printf("\nCGPA of student is  : %.2f",sem1.gpa);
            printf("\nGrade of student is : %c",sem1.grade);
         flag=1;
        }
    }
    fclose(fptr);
if(flag==0)
 printf("\n\nRecord does not exist");
    getch();
}

void modify_student_sem1()
{
    int no,found=0;
    system("cls");
    printf("\n\n\tTo Modify ");
    printf("\n\n\tPlease Enter The roll number of student:");
    scanf("%d",&no);
    fptr=fopen("sem1.dat","rb+");
    while((fread(&sem1,sizeof(sem1),1,fptr))>0 && found==0)
    {
    if(sem1.rollno==no)
           {
            printf("\nRoll number of student : %d",sem1.rollno);
            printf("\nName of student : %s",sem1.name);
            printf("\nMarks in Technical English : %d",sem1.eng_marks);
            printf("\nMarks in Algebra and Calculus : %d",sem1.alg_marks);
            printf("\nMarks in Basic Statistical Methods : %d",sem1.bsm_marks);
            printf("\nMarks in Human Behaviour : %d",sem1.hb_marks);
            printf("\nMarks in C Programming : %d",sem1.c_marks);
            printf("\nCGPA of student is  : %.2f",sem1.gpa);
            printf("\nGrade of student is : %c",sem1.grade);
            printf("\nPlease Enter The New Details of student \n");
            printf("\nEnter The roll number of student: ");
            scanf("%d",&sem1.rollno);
            fflush(stdin);
            printf("\n\nEnter The Name of student :");
            gets(sem1.name);
            printf("\nEnter The marks in Technical English out of 100 : ");
            scanf("%d",&sem1.eng_marks);
            printf("\nEnter The marks in Algebra and Calculus out of 100 : ");
            scanf("%d",&sem1.alg_marks);
            printf("\nEnter The marks in Basic Statistical Methods out of 100 : ");
            scanf("%d",&sem1.bsm_marks);
            printf("\nEnter The marks in Human Behaviour out of 100 : ");
            scanf("%d",&sem1.hb_marks);
            printf("\nEnter The marks in C Programming out of 100 : ");
            scanf("%d",&sem1.c_marks);
            sem1.gpa=(sem1.eng_marks+sem1.alg_marks+sem1.bsm_marks+sem1.hb_marks+sem1.c_marks)/50.0;
    	if(sem1.gpa>=8.5)
       		sem1.grade='A';
    	else if(sem1.gpa>=7.5 &&sem1.gpa<8.5)
      		sem1.grade='B';
    	else if(sem1.gpa>=6 &&sem1.gpa<7.5)
      		sem1.grade='C';
    	else if(sem1.gpa>=5 &&sem1.gpa<6)
      		sem1.grade='D';
    	else
     		sem1.grade='E';
            fseek(fptr,-(long)sizeof(sem1),1);
            fwrite(&sem1,sizeof(sem1),1,fptr);
            printf("\n\n\t Record Updated");
            found=1;
           }
         }
    fclose(fptr);
    if(found==0)
    printf("\n\n Record Not Found ");
    getch();
}
void delete_student_sem1()
   {
    int no;
    FILE *fptr2;
    system("cls");
    printf("\n\n\n\tDelete Record");
    printf("\n\nPlease Enter The roll number of student You Want To Delete:");
    scanf("%d",&no);
    fptr=fopen("sem1.dat","rb");
    fptr2=fopen("Temp.dat","wb");
    rewind(fptr);
    while((fread(&sem1,sizeof(sem1),1,fptr))>0)
    {
       if(sem1.rollno!=no)
       {
      fwrite(&sem1,sizeof(sem1),1,fptr2);
       }
    }
    fclose(fptr2);
    fclose(fptr);
    remove("sem1.dat");
    rename("Temp.dat","sem1.dat");
    printf("\n\n\tRecord Deleted ..");
    getch();
}



void class_result_sem1()
{
    system("cls");
    fptr=fopen("sem1.dat","rb");
    if(fptr==NULL)
    {
       printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File");
       printf("\n\n\n Program is closing ....");
       getch();
       exit(0);
     }

     printf("\n\n\t\tALL STUDENTS RESULT \n\n");
      printf("=======================================================================\n");
      printf("R.No.   Name               E     A    BSM     HB    C     Avg    Grade\n");
      printf("=======================================================================\n");

      while((fread(&sem1,sizeof(sem1),1,fptr))>0)
     {
       printf("%-6d %-10s   %-3d   %-3d   %-3d   %-3d   %-3d   %-3.2f    %-1c\n",sem1.rollno,sem1.name,sem1.eng_marks,sem1.alg_marks,sem1.bsm_marks,sem1.hb_marks,sem1.c_marks,sem1.gpa,sem1.grade);
     }
     fclose(fptr);
     getch();
}



void result_sem1()
{	
	int ans,rno;
	char ch;
	system("cls");
	printf("\n\n\nRESULT MENU");
	printf("\n\n\n1. Class Result\n\n2. Student Report Card\n\n3. Back to Main Menu");
    printf("\n\n\nEnter Choice (1-3): ");
    scanf("%d",&ans);
    switch(ans)
    {
     case 1 : class_result_sem1();break;
     case 2 : {
        do{
        char ans;
        system("cls");
        printf("\n\nEnter Roll Number Of Student : ");
        scanf("%d",&rno);
        display_sp_sem1(rno);
        printf("\n\nDo you want to See More Result (y/n)?");
        scanf("%c",&ans);
        }while(ans=='y'||ans=='Y');
        break;
           }
     case 3: break;
     default:  printf("\a");
    }
 }
void entry_menu_sem1()
{
    char ch2;
   system("cls");
  printf("\n\n\n\tENTRY MENU");
  printf("\n\n\t1.CREATE STUDENT RECORD");
  printf("\n\n\t2.DISPLAY ALL STUDENTS RECORDS");
  printf("\n\n\t3.SEARCH STUDENT RECORD ");
  printf("\n\n\t4.MODIFY STUDENT RECORD");
  printf("\n\n\t5.DELETE STUDENT RECORD");
  printf("\n\n\t6.BACK TO MAIN MENU");
  printf("\n\n\tPlease Enter Your Choice (1-6) ");
  ch2=getche();
  switch(ch2)
  {
    case '1': system("cls");
          write_student_sem1();
          break;
    case '2': display_all_sem1();break;
    case '3':  {
           int num;
           system("cls");
           printf("\n\n\tPlease Enter The roll number:");
           scanf("%d",&num);
           display_sp_sem1(num);
           }
           break;
      case '4': modify_student_sem1();break;
      case '5': delete_student_sem1();break;
      case '6': break;
      default:printf("\a");entry_menu_sem1();
   }
}

void first_sem( )
{
	char ch;
  	do
    {
      system("cls");
      printf("\n\n\n\tSEMESTER 1 MARKS-DCS");
      printf("\n\n\t01. RESULT MENU");
      printf("\n\n\t02. ENTRY/EDIT MENU");
      printf("\n\n\t03. MAIN MENU");
      printf("\n\n\tPlease Select Your Option (1-3) ");
      ch=getche();
      switch(ch)
      {
         case '1': system("cls");
               result_sem1();
               break;
          case '2': entry_menu_sem1();
            	break;
          case '3':break;
          default :printf("\a");
    }
    }while(ch!='3');
}

struct sem2
{
 int rollno;
 char name[50];
 int lang_marks,prob_marks,pom_marks,wt_marks,ds_marks;
 float gpa;
 char grade;
 int std;
}sem2;
 FILE *fptr3;
void write_student_sem2()
   {
    fptr=fopen("sem2.dat","ab");
    printf("\nPlease Enter The New Details of student \n");
    printf("\nEnter The roll number of student: ");
    scanf("%d",&sem2.rollno);
    fflush(stdin);
    printf("\n\nEnter The Name of student: ");
    gets(sem2.name);
    printf("\nEnter The marks in Language Elective out of 100 : ");
    scanf("%d",&sem2.lang_marks);
    printf("\nEnter The marks in Probability and Applications out of 100 : ");
    scanf("%d",&sem2.prob_marks);
    printf("\nEnter The marks in Principles of Management out of 100 : ");
    scanf("%d",&sem2.pom_marks);
    printf("\nEnter The marks in Web Technology out of 100 : ");
    scanf("%d",&sem2.wt_marks);
    printf("\nEnter The marks in Data Structures and Algorithms out of 100 : ");
    scanf("%d",&sem2.ds_marks);
    sem2.gpa=(sem2.lang_marks+sem2.prob_marks+sem2.pom_marks+sem2.wt_marks+sem2.ds_marks)/50.0;
    if(sem2.gpa>=8.5)
       sem2.grade='A';
    else if(sem2.gpa>=7.5 &&sem2.gpa<8.5)
      sem2.grade='B';
    else if(sem2.gpa>=6 &&sem2.gpa<7.5)
      sem2.grade='C';
    else if(sem2.gpa>=5 &&sem2.gpa<6)
      sem2.grade='D';
    else
     sem2.grade='E';
    fwrite(&sem2,sizeof(sem2),1,fptr);
    fclose(fptr3);
    printf("\n\nStudent Record Has Been Created ");
    getch();
}



void display_all_sem2()
{
    system("cls");
    printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");
    fptr3=fopen("sem2.dat","rb");
    while((fread(&sem2,sizeof(sem2),1,fptr3))>0)
    {
      printf("\nRoll Number of Student : %d",sem2.rollno);
      printf("\nName of student : %s",sem2.name);
      printf("\nMarks in Language Elective : %d",sem2.lang_marks);
      printf("\nMarks in Probability and Applications : %d",sem2.prob_marks);
      printf("\nMarks in Principles of Management : %d",sem2.pom_marks);
      printf("\nMarks in Web Technology : %d",sem2.wt_marks);
      printf("\nMarks in Data Structures and Algorithms : %d",sem2.ds_marks);
      printf("\nCGPA of student is  : %.2f",sem2.gpa);
      printf("\nGrade of student is : %c",sem2.grade);
      printf("\n\n====================================\n");
      getch();
    }
    fclose(fptr3);
    getch();
}



void display_sp_sem2(int n)
{
    int flag=0;
    fptr3=fopen("sem2.dat","rb");
    while((fread(&sem2,sizeof(sem2),1,fptr3))>0)
    {
     if(sem2.rollno==n)
        {
         system("cls");
            printf("\nRoll Number of Student : %d",sem2.rollno);
      		printf("\nName of student : %s",sem2.name);
      		printf("\nMarks in Language Elective : %d",sem2.lang_marks);
      		printf("\nMarks in Probability and Applications : %d",sem2.prob_marks);
      		printf("\nMarks in Principles of Management : %d",sem2.pom_marks);
      		printf("\nMarks in Web Technology : %d",sem2.wt_marks);
      		printf("\nMarks in Data Structures and Algorithms : %d",sem2.ds_marks);
      		printf("\nCGPA of student is  : %.2f",sem2.gpa);
      		printf("\nGrade of student is : %c",sem2.grade);
         flag=1;
        }
    }
    fclose(fptr3);
if(flag==0)
 printf("\n\nRecord does not exist");
    getch();
}

void modify_student_sem2()
{
    int no,found=0;
    system("cls");
    printf("\n\n\tTo Modify ");
    printf("\n\n\tPlease Enter The roll number of student:");
    scanf("%d",&no);
    fptr3=fopen("sem2.dat","rb+");
    while((fread(&sem2,sizeof(sem2),1,fptr3))>0 && found==0)
    {
    if(sem2.rollno==no)
           {
            printf("\nRoll Number of Student : %d",sem2.rollno);
      		printf("\nName of student : %s",sem2.name);
      		printf("\nMarks in Language Elective : %d",sem2.lang_marks);
      		printf("\nMarks in Probability and Applications : %d",sem2.prob_marks);
      		printf("\nMarks in Principles of Management : %d",sem2.pom_marks);
      		printf("\nMarks in Web Technology : %d",sem2.wt_marks);
      		printf("\nMarks in Data Structures and Algorithms : %d",sem2.ds_marks);
      		printf("\nCGPA of student is  : %.2f",sem2.gpa);
      		printf("\nGrade of student is : %c",sem2.grade);
            printf("\nPlease Enter The New Details of student \n");
            printf("\nEnter The roll number of student: ");
            scanf("%d",&sem2.rollno);
            fflush(stdin);
            printf("\n\nEnter The Name of student :");
            gets(sem2.name);
            printf("\nEnter The marks in Language Elective out of 100 : ");
    		scanf("%d",&sem2.lang_marks);
    		printf("\nEnter The marks in Probability and Applications out of 100 : ");
    		scanf("%d",&sem2.prob_marks);
    		printf("\nEnter The marks in Principles of Management out of 100 : ");
    		scanf("%d",&sem2.pom_marks);
    		printf("\nEnter The marks in Web Technology out of 100 : ");
    		scanf("%d",&sem2.wt_marks);
    		printf("\nEnter The marks in Data Structures and Algorithms out of 100 : ");
    		scanf("%d",&sem2.ds_marks);
            sem2.gpa=(sem2.lang_marks+sem2.prob_marks+sem2.pom_marks+sem2.wt_marks+sem2.ds_marks)/50.0;
    	if(sem2.gpa>=8.5)
       		sem2.grade='A';
    	else if(sem2.gpa>=7.5 &&sem2.gpa<8.5)
      		sem2.grade='B';
    	else if(sem2.gpa>=6 &&sem2.gpa<7.5)
      		sem2.grade='C';
    	else if(sem2.gpa>=5 &&sem2.gpa<6)
      		sem2.grade='D';
    	else
     		sem2.grade='E';
            fseek(fptr3,-(long)sizeof(sem2),1);
            fwrite(&sem2,sizeof(sem2),1,fptr3);
            printf("\n\n\t Record Updated");
            found=1;
           }
         }
    fclose(fptr3);
    if(found==0)
    printf("\n\n Record Not Found ");
    getch();
}
void delete_student_sem2()
   {
    int no;
    FILE *fptr2;
    system("cls");
    printf("\n\n\n\tDelete Record");
    printf("\n\nPlease Enter The roll number of student You Want To Delete:");
    scanf("%d",&no);
    fptr3=fopen("sem2.dat","rb");
    fptr2=fopen("Temp2.dat","wb");
    rewind(fptr);
    while((fread(&sem2,sizeof(sem2),1,fptr3))>0)
    {
       if(sem2.rollno!=no)
       {
      fwrite(&sem2,sizeof(sem2),1,fptr2);
       }
    }
    fclose(fptr2);
    fclose(fptr3);
    remove("sem2.dat");
    rename("Temp2.dat","sem2.dat");
    printf("\n\n\tRecord Deleted ..");
    getch();
}



void class_result_sem2()
{
    system("cls");
    fptr3=fopen("sem2.dat","rb");
    if(fptr3==NULL)
    {
       printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File");
       printf("\n\n\n Program is closing ....");
       getch();
       exit(0);
     }

     printf("\n\n\t\tALL STUDENTS RESULT \n\n");
      printf("=======================================================================\n");
      printf("R.No.   Name               L     P    POM     WT    DS     GPA    Grade\n");
      printf("=======================================================================\n");

      while((fread(&sem2,sizeof(sem2),1,fptr3))>0)
     {
       printf("%-6d %-10s   %-3d   %-3d   %-3d    %-3d   %-3d    %-3.2f    %-1c\n",sem2.rollno,sem2.name,sem2.lang_marks,sem2.prob_marks,sem2.pom_marks,sem2.wt_marks,sem2.ds_marks,sem2.gpa,sem2.grade);
     }
     fclose(fptr3);
     getch();
}



void result_sem2()
{	
	int ans,rno;
	char ch;
	system("cls");
	printf("\n\n\nRESULT MENU");
	printf("\n\n\n1. Class Result\n\n2. Student Report Card\n\n3. Back to Main Menu");
    printf("\n\n\nEnter Choice (1/2)? ");
    scanf("%d",&ans);
    switch(ans)
    {
     case 1 : class_result_sem2();break;
     case 2 : {
        do{
        char ans;
        system("cls");
        printf("\n\nEnter Roll Number Of Student : ");
        scanf("%d",&rno);
        display_sp_sem2(rno);
        printf("\n\nDo you want to See More Result (y/n)?");
        scanf("%c",&ans);
        }while(ans=='y'||ans=='Y');
        break;
           }
     case 3: break;
     default:  printf("\a");
    }
 }
void entry_menu_sem2()
{
    char ch2;
   system("cls");
  printf("\n\n\n\tENTRY MENU");
  printf("\n\n\t1.CREATE STUDENT RECORD");
  printf("\n\n\t2.DISPLAY ALL STUDENTS RECORDS");
  printf("\n\n\t3.SEARCH STUDENT RECORD ");
  printf("\n\n\t4.MODIFY STUDENT RECORD");
  printf("\n\n\t5.DELETE STUDENT RECORD");
  printf("\n\n\t6.BACK TO MAIN MENU");
  printf("\n\n\tPlease Enter Your Choice (1-6) ");
  ch2=getche();
  switch(ch2)
  {
    case '1': system("cls");
          write_student_sem2();
          break;
    case '2': display_all_sem2();break;
    case '3':  {
           int num;
           system("cls");
           printf("\n\n\tPlease Enter The roll number:");
           scanf("%d",&num);
           display_sp_sem2(num);
           }
           break;
      case '4': modify_student_sem2();break;
      case '5': delete_student_sem2();break;
      case '6': break;
      default:printf("\a");entry_menu_sem2();
   }
}

void second_sem()
{
	char ch;
  	do
    {
      system("cls");
      printf("\n\n\n\tSEMESTER 2 MARKS-DCS");
      printf("\n\n\t01. RESULT MENU");
      printf("\n\n\t02. ENTRY/EDIT MENU");
      printf("\n\n\t03. MAIN MENU");
      printf("\n\n\tPlease Select Your Option (1-3) ");
      ch=getche();
      switch(ch)
      {
         case '1': system("cls");
               result_sem2();
               break;
          case '2': entry_menu_sem2();
            	break;
          case '3':break;
          default :printf("\a");
    }
    }while(ch!='3');
}

struct details
{
 int rollno;
 char name[50],mail[50],blood[5],mobl[15],dob[12];
 int std;
}det;
FILE *fptr4;

void write_details()
   {
    fptr4=fopen("details.dat","ab");
    printf("\nPlease Enter The Details of student \n");
    printf("\nEnter The roll number of student: ");
    scanf("%d",&det.rollno);
    fflush(stdin);
    printf("\n\nEnter The Name of student: ");
    gets(det.name);
    printf("\n\nEnter The D.O.B of student: ");
    gets(det.dob);
    printf("\n\nEnter The Blood group of student: ");
    gets(det.blood);
    printf("\n\nEnter The Email ID of student: ");
    gets(det.mail);
    printf("\n\nEnter the parent's mobile number: ");
    gets(det.mobl);
    fwrite(&det,sizeof(det),1,fptr4);
    fclose(fptr4);
    printf("\n\nStudent Details has been created ");
    getch();
}


void modify_details()
{
    int no,found=0;
    system("cls");
    printf("\n\n\tTo Modify the student details ");
    printf("\n\n\tPlease Enter The roll number of student:");
    scanf("%d",&no);
    fptr4=fopen("details.dat","rb+");
    while((fread(&det,sizeof(det),1,fptr4))>0 && found==0)
    {
    if(det.rollno==no)
           {
            printf("\nRoll number of student : %d",det.rollno);
            printf("\nName of student : %s",det.name);
            printf("\nDate of Birth : %s",det.dob);
            printf("\nBlood group of student : %s",det.blood);
            printf("\nEmail ID of student : %s",det.mail);
            printf("\nParent's mobile number : %s",det.mobl);
            printf("\nPlease Enter The New Details of student \n");
            printf("\nEnter The roll number of student: ");
    		scanf("%d",&det.rollno);
    		printf("\n\nEnter The Name of student: ");
    		gets(det.name);
    		printf("\n\nEnter The D.O.B of student: ");
    		gets(det.dob);
    		printf("\n\nEnter The Blood group of student: ");
    		gets(det.blood);
    		printf("\n\nEnter The Email ID of student: ");
    		gets(det.mail);
    		printf("\n\nEnter the parent's mobile number: ");
    		gets(det.mobl);
            fseek(fptr4,-(long)sizeof(det),1);
            fwrite(&det,sizeof(det),1,fptr4);
            printf("\n\n\t Details Modified..");
            found=1;
           }
         }
    fclose(fptr4);
    if(found==0)
    printf("\n\n Record Not Found ");
    getch();
}

void search_details(int n)
{
    int flag=0;
    fptr4=fopen("details.dat","rb");
    while((fread(&det,sizeof(det),1,fptr4))>0)
    {
     if(det.rollno==n)
        {
         system("cls");
            printf("\nRoll number of student : %d",det.rollno);
            printf("\nName of student : %s",det.name);
            printf("\nDate of Birth : %s",det.dob);
            printf("\nBlood group of student : %s",det.blood);
            printf("\nEmail ID of student : %s",det.mail);
            printf("\nParent's mobile number : %s",det.mobl);
         flag=1;
        }
    }
    fclose(fptr4);
if(flag==0)
 printf("\n\nRecord does not exist");
    getch();
}

void delete_details()
   {
    int no;
    FILE *fptr5;
    system("cls");
    printf("\n\n\n\tTo delete details");
    printf("\n\nPlease Enter The roll number of student:");
    scanf("%d",&no);
    fptr4=fopen("details.dat","rb");
    fptr5=fopen("tempr.dat","wb");
    rewind(fptr4);
    while((fread(&det,sizeof(det),1,fptr4))>0)
    {
       if(det.rollno!=no)
       {
      fwrite(&det,sizeof(det),1,fptr5);
       }
    }
    fclose(fptr5);
    fclose(fptr4);
    remove("details.dat");
    rename("tempr.dat","details.dat");
    printf("\n\n\tRecord Deleted ..");
    getch();
}

void all_details()
{
    system("cls");
    printf("\n\n\n\t\tDISPLAY ALL DETAILS !!!\n\n");
    fptr4=fopen("details.dat","rb");
    while((fread(&det,sizeof(det),1,fptr4))>0)
    {	
    	printf("\nRoll number of student : %d",det.rollno);
    	printf("\nName of student : %s",det.name);
    	printf("\nDate of Birth : %s",det.dob);
        printf("\nBlood group of student : %s",det.blood);
        printf("\nEmail ID of student : %s",det.mail);
        printf("\nParent's mobile number : %s",det.mobl);
    	printf("\n\n====================================\n");
      	getch();
    }
    fclose(fptr4);
    getch();
}

void edit_details()
{
	char ch;
  	do
    {
      system("cls");
      printf("\n\n\n\tEDIT STUDENT DETAILS");
      printf("\n\n\t1. ENTER STUDENT DETAILS");
      printf("\n\n\t2. MODIFY STUDENT DETAILS");
      printf("\n\n\t3. DISPLAY ALL DETAILS");
      printf("\n\n\t4. SEARCH STUDENT DETAILS");
      printf("\n\n\t5. DELETE STUDENT DETAILS");
      printf("\n\n\t6. MAIN MENU");
      printf("\n\n\tPlease Select Your Option (1-6):");
      ch=getche();
      switch(ch)
      {
        case '1': system("cls");
               write_details();
               break;
        case '2': modify_details();
            	break;
        case '3': all_details();
            	break;
        case '4':  {
           int num;
           system("cls");
           printf("\n\n\tPlease Enter The roll number:");
           scanf("%d",&num);
           search_details(num);
           }
           break;
        case '5': delete_details();break;
        case '6':break;
        default :printf("\a");
    }
    }while(ch!='6');
}

void view_details()
{	
	int ans,rno;
	char ch;
	system("cls");
	printf("\n\n\nRESULT MENU");
	printf("\n\n\n1. Individual details\n\n2. Back to Main Menu");
    printf("\n\n\nEnter Choice (1/2): ");
    scanf("%d",&ans);
    switch(ans)
    {
     case 1 : {
        do{
        char ans;
        system("cls");
        printf("\n\nEnter Roll Number Of Student : ");
        scanf("%d",&rno);
        search_details(rno);
        printf("\n\nDo you want to See More Result (y/n)?");
        scanf("%c",&ans);
        }while(ans=='y'||ans=='Y');
        break;
           }
     case 2: break;
     default:  printf("\a");
    }
 }
 
void student_details()
{
	char ch;
	do{
	system("cls");
	printf("\n\n\nSTUDENT PERSONAL DETAILS");
	printf("\n\n\n1. View details\n\n2. Enter/Edit menu\n\n3. Back to Main Menu");
    printf("\n\n\nEnter Choice (1-3): ");
    scanf("%d",&ch);
    switch(ch){
    	case 1:view_details();
            break;
        case 2: edit_details();
            break;
        case 3:break;
        default :printf("\a");
    }
    }while(ch!='2');
}

 


void final()
{
  char ch;
  do
    {
      system("cls");
      printf("\n\tM.Sc-DCS STUDENT RECORD MANAGEMENT SYSTEM");
      printf("\n\n\n\tMAIN MENU");
      printf("\n\n\t01. SEMESTER-1 MARKS");
      printf("\n\n\t02. SEMESTER-2 MARKS");
      printf("\n\n\t03. STUDENT DETAILS");
      printf("\n\n\t04. EXIT");
      printf("\n\n\tPlease Select Your Option (1-4) ");
      ch=getche();
      switch(ch)
      {
         case '1': system("cls");
               first_sem();
               break;
          case '2': second_sem();
                break;
          case '3':student_details();
          		break;
          case '4':exit(0);
          default :printf("\a");
    }
    }while(ch!='3');
}

int main()
{
	final();
	return 0;
}
