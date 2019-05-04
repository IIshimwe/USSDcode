#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct mtnservice
{
    char fname[50];
    char lname[50];
    int age;
    char phone[20];
    int balance;

}mt,chec,by,gh;
void registerr()
{
    FILE *d;
    d=fopen("create.txt","a+");
    invalid_phone:
    printf("\n\t welcome to mtn services");
    printf("\n\t -----------------------\n");
    printf("\n Enter customer's number: ");
    scanf("%s",&chec.phone);
    while(!feof(d))
    {
        fscanf(d,"\n %s %s %d %s %d",&mt.fname,&mt.lname,&mt.age,&mt.phone,&mt.balance);
        if(strcmp(chec.phone,mt.phone)==0)
        {
            printf("\n this number is already taken\n");
            goto invalid_phone;
        }
    }
    strcpy(mt.phone,chec.phone);
    printf("\n First name: ");
    scanf("%s",&mt.fname);
    printf("\n Last name: ");
    scanf("%s",&mt.lname);
    printf("\n Age: ");
    scanf("%d",&mt.age);
    printf("\n Opening balance: ");
    scanf("%d",&mt.balance);
    fprintf(d,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,mt.balance);
    fclose(d);
}
void buypack()
{
    char code[20];
    int choice;
    int nice;
    int paid;
    FILE *d;
    //FILE *f;
    FILE *newc;
    d=fopen("create.txt","r");
    //f=fopen("yoloo.txt","a+");
    newc=fopen("new.txt","w");
    printf("\n\t Welcome to Yolo pack");
    printf("\n\t --------------------");
    printf("\n Enter the customer's phone number: ");
    scanf("%s",&by.phone);

     while(!feof(d))
    {
         fscanf(d,"\n %s %s %d %s %d",&mt.fname,&mt.lname,&mt.age,&mt.phone,&mt.balance);
         if(strcmp(by.phone,mt.phone)==0)
         {
             system("cls");
             printf("\n Enter yolo code: ");
             scanf("%s",&code);
             system("cls");
             printf("\n\t USSD code \n");
             delay(5);
             if(strcmp(code,"*154#")==0)
             {
                 if(mt.age<=25)
                 {
                     system("cls");
                     printf("\n[1]Guhamagara\n[2]interneti\n[3]Ayo usigaranye\n\n");
                     scanf("%d",&choice);
                     if(choice==1)
                     {
                         system("cls");
                         guhamagara();
                     }
                     else if(choice==2)
                     {
                         system("cls");
                         internet();
                     }
                     else if(choice==3)
                     {
                         system("cls");
                         balance();
                     }
                 }
                 else
                 {
                      fprintf(newc,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,mt.balance);
                      printf("\n\t!!You are not allowed to use yolo pack!!\n\n");
                 }

             }
             else
             {
              fprintf(newc,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,mt.balance);
              printf("\n\t!!Invalid MMI code!!\n\n");
             }
         }
         else
         {
            fprintf(newc,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,mt.balance);
            printf("\n !!!This number is not registered in mtn services!!!\n\n");
         }
    }
     fclose(d);
     fclose(newc);
     remove("create.txt");
     rename("new.txt","create.txt");

}
void guhamagara()
{
    int nice;
    int paid;
    FILE *d;
    FILE *f;
    FILE *newc;
    d=fopen("create.txt","r");
    f=fopen("yoloo.txt","a+");
    newc=fopen("new.txt","w");
     while(!feof(d))
    {
         fscanf(d,"\n %s %s %d %s %d",&mt.fname,&mt.lname,&mt.age,&mt.phone,&mt.balance);

            printf("\n[1]100Rwf = 1020sec + 30Sms/24hours\n[2]EXTRA YOLO 100Rwf = 1800sec + 30Sms/Umunsi wose ureste hagati ya 18h na 22h\n[3]500Rwf=4800secs+25Sms/Icyumweru\n\n");
            scanf("%d",&nice);
            if(nice==1)
            {
                if(mt.balance>=100)
                {
                    system("cls");
                printf("\n Uguze pack ku 100Rwf=1020secs+30Sms/24hrs\n\n");
                by.balance=mt.balance-100;
                paid=100;
                fprintf(newc,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,by.balance);
                fprintf(f,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,paid);
                }
                else
                {
                    fprintf(newc,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,mt.balance);
                    system("cls");
                    printf("\n Ayo mufitemo nahagije\n\n");
                }
            }
            else if(nice==2)
            {
                 if(mt.balance>=100)
                 {
                     system("cls");
                 printf("\n Uguze EXTRA yolo 100Rwf=1800sec+30Sms/ikora umunsi wose ureste hagati ya 18h na 22h\n\n");
                 by.balance=mt.balance-100;
                 paid=100;
                 fprintf(newc,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,by.balance);
                 fprintf(f,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,paid);
                 }
                 else
                 {
                   fprintf(newc,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,mt.balance);
                    system("cls");
                   printf("\n Ayo mufitemo nahagije\n\n");
                 }
            }
            else if(nice==3)
            {
                  if(mt.balance>=500)
                  {
                      system("cls");
                  printf("\n uguze pack ya 500Rwf=4800secs+25Sms/imamara icyumweru\n\n");
                  by.balance=mt.balance-500;
                  paid=500;
                  fprintf(newc,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,by.balance);
                  fprintf(f,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,paid);
                  }
                  else
                  {
                      fprintf(newc,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,mt.balance);
                      system("cls");
                      printf("\n Ayo mufitemo nahagije\n\n");
                  }
            }
            else
            {
                fprintf(newc,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,mt.balance);
                system("cls");
                printf("\n!!Invalid input\n");
            }

     }
     fclose(d);
     fclose(newc);
     fclose(f);
     remove("create.txt");
     rename("new.txt","create.txt");

}
void internet()
{
    int nice;
    int paid;
    FILE *d;
    FILE *f;
    FILE *newc;
    d=fopen("create.txt","r");
    f=fopen("yoloo.txt","a+");
    newc=fopen("new.txt","w");
     while(!feof(d))
    {
        fscanf(d,"\n %s %s %d %s %d",&mt.fname,&mt.lname,&mt.age,&mt.phone,&mt.balance);
        printf("[1] 100Rwf= (100MB+30sms) /24hrs\n[2]500Rwf= (500MB)IMARA ICYUMWERU\n[3] 1000Rwf= (800MB+30sms) IMARA UKWEZI\n");
        scanf("%d",&nice);
        if (nice==1)
        {
           if(mt.balance>=100)
           {
           system("cls");
           printf("\nuguze pack 100Rwf iguha 100MB+30sms\n izarangira nyuma ya masaha 24\n\n");
           by.balance=mt.balance-100;
           paid=100;
           fprintf(newc,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,by.balance);
           fprintf(f,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,paid);
           }
           else
           {
              fprintf(newc,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,mt.balance);
              system("cls");
              printf("\n Ayo mufitemo nahagije\n\n");
           }
        }
        else if(nice==2)
        {
            if(mt.balance>=500)
            {
                system("cls");
            printf("\n uguze pack 500Rwf iguha 500MB+30sms\n imara icyumweru\n\n");
            by.balance=mt.balance-500;
            paid=500;
            fprintf(newc,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,by.balance);
            fprintf(f,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,paid);
            }
            else
            {
                fprintf(newc,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,mt.balance);
                system("cls");
                printf("\n Ayo mufitemo nahagije\n\n");
            }
        }
        else if(nice==3)
        {
           if(mt.balance>=1000)
           {
               system("cls");
            printf("\n uguze pack 1000Rwf iguha 800MB+30sms imara ukwezi\n\n");
            by.balance=mt.balance-1000;
            paid=1000;
            fprintf(newc,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,by.balance);
            fprintf(f,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,paid);
           }
           else
           {
               fprintf(newc,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,mt.balance);
                system("cls");
                printf("\n Ayo mufitemo nahagije\n\n");
           }
        }
        else
        {
            fprintf(newc,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,mt.balance);
            system("cls");
            printf("\n!!Invalid input\n");
        }
    }
     fclose(d);
     fclose(newc);
     fclose(f);
     remove("create.txt");
     rename("new.txt","create.txt");
}
void balance()
{
    FILE *d;
   // FILE *f;
    FILE *newc;
    d=fopen("create.txt","r");
   // f=fopen("yoloo.txt","a+");
    newc=fopen("new.txt","w");
     while(!feof(d))
    {
        fscanf(d,"\n %s %s %d %s %d",&mt.fname,&mt.lname,&mt.age,&mt.phone,&mt.balance);
         fprintf(newc,"\n %s %s %d %s %d",mt.fname,mt.lname,mt.age,mt.phone,mt.balance);
        system("cls");
        printf("\n ayo usigaranye urayabona mu butumwa bugufi \n");
        delay(5);
        system("cls");
        printf("\n PACK YAWE YARANGIYE GURA INDI!\n YOU HAVE NO ACTIVE YOLO PACK PLEASE DIAL *154# TO BUY ANOTHER ONE\n\n");

    }
     fclose(d);
     fclose(newc);
     remove("create.txt");
     rename("new.txt","create.txt");
}

void delay(int sec)
{
    unsigned long int count=333333333;
    int i,k;
    for(i=0;i<sec;i++)
        for(k=0;k<count;k++);

}
void main()
{
    registerr();
}
