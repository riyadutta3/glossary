//GLOSSARY-MINI PROJECT//
//HEADER FILES USED IN THE PROJECT//
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include<dos.h>
#define max 5
//---------------------------------//

char pasword[4];
FILE *fp, *fp1; //fp is pointer to dictionary file and fp1 is pointer to temporary file used for updation and deletion of a word.
int n; //Use to add new number in the dictionary.
int x;  //To traverse all the words of the dictionary.
int found;    //To check whether the word is present in dictionary or not.

char queue[max][80];
int front=-1;
int rear=-1;


//Structure dictionary to store the word and it's meaning
typedef struct dictionary
{
    char word[30];
    char mean[200];
}dict;

//Array of structure
dict a[100];

//Functions used in the project.
void set_pos();
int menu();
int search(char *);
void update(char *);
void add(char *);
void display();
void del(char *);
void search_letter(char );
void did_you_mean(char *);
void recent_searches();
void delay(int);

int main()
{
    system("color F1");
    char password[4],ch;
    COORD c;
    c.X = 0;
    c.Y = 10;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c); //Placing the cursor to the center of the screen using x and y co-ordinates.
    printf("~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~\n");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t C GLOSSARY\n");
    printf("\n\n~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~\n");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t Mini Project\n");
    printf("\t\t\t\t\t\t\t\t\t\t     By: Riya And Navneet\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t MCA 2-Semester\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t Submitted to: Prof.M. Syamala Devi\n\n");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Password: ");
    for(int i=0;i<4;i++)
    {
        ch = getch();
        password[i] = ch;
        ch = '*' ;
        printf("%c",ch);
    }
    if(password[0]=='p'&&password[1]=='a'&&password[2]=='s'&&password[3]=='s')
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tAccess Granted!!");
    }
    else
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t\t\tAccess Aborted!!");
        exit(0);
    }
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\tPress Enter To Continue...");
    getch();
    printf("\n\n\t\t\t\t\t\t\t\t\t\tLoading");

  for(int process=0;process<3;process++)
  {
    sleep(1);  //To delay the program execution by 1 second
    printf(".");

  }
  menu();
  return 0;
}


int menu()
{
    while(1)
    {
    char choice;
    system("cls");
    COORD c;
    c.X = 0;
    c.Y = 10;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf("~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~\n");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tMAIN MENU\n");
    printf("\n\n~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~\n");
    printf("\t\t\t\t\t\t\t 1. Search Word\n\n");
    delay(250);
    printf("\t\t\t\t\t\t\t 2. Add Word\n\n");
    delay(250);
    printf("\t\t\t\t\t\t\t 3. Display List\n\n");
    delay(250);
    printf("\t\t\t\t\t\t\t 4. Update Word\n\n");
    delay(250);
    printf("\t\t\t\t\t\t\t 5. Delete Word\n\n");
    delay(250);
    printf("\t\t\t\t\t\t\t 6. To Print Words Staring From A Particular Alphabet\n\n");
    delay(250);
    printf("\t\t\t\t\t\t\t 7. Recently Searched Words\n\n");
    delay(250);
    printf("\t\t\t\t\t\t\t 8. Exit\n\n");
    delay(250);
    fflush(stdin);
    printf("\t\t\t\t\t\t\tEnter Your Choice: ");
    scanf("%c",&choice);
    getchar();
    switch(choice)
    {
        case '1': {

                    set_pos();
                    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf("\n\t\t\t\t\t\t\t\t\t\t\tSEARCH WORD\n\n");
                    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                    char search_word[20];
                    fflush(stdin);
                    printf("\n\n\t\t\t\t\t\t    Enter the word you want to search: ");
                    gets(search_word);
                    int len = sizeof(search_word)/sizeof(search_word[0]);
                    for(int i=0;i<len;i++)
                    {
                        search_word[i]=tolower(search_word[i]);
                    }
                    int found = search(search_word);
                    if(rear == max-1)
                    {
                        for (int i = 0; i < rear ; i++)
                            strcpy(queue[i],queue[i+1]);
                        rear = rear - 1;
                    }
                    if(front==-1)
                        front=0;
                    rear = rear + 1;
                    strcpy(queue[rear],search_word);
                    if(found==0)
                    {
                        did_you_mean(search_word);
                    }
                     printf("\n\n\t\t\t\t\t\t\tPress any key to go to main menu.");
                    getchar();
                }
                break;
        case '2': {
                    char word[20];
                    int invalid=0;
                    char ch;
                    set_pos();
                    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf("\n\t\t\t\t\t\t\t\t\t\tADD WORD\n\n");
                    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf("\n\n\t\t\t\t\t\tEnter the word: ");
                    gets(word);
                    int len = sizeof(word)/sizeof(word[0]);
                    for(int i=0;i<len;i++)
                    {
                        word[i]=tolower(word[i]);
                    }
                    for(int i=0;i<len;i++)
                    {
                        if(isdigit(word[i]))
                        {
                             printf("\n\n\t\t\t\t\t\t\tInvalid Word!!!");
                            invalid=1;
                            break;
                        }

                    }
                    if(invalid==0)
                    {
                        int found = search(word);
                        if(found==0)
                        {
                            add(word);
                            printf("\n\n\t\t\t\t\tWord Added Successfully!!");
                        }
                        else
                        {
                            printf("\n\n\t\t\t\t\t\tWord Already Exists, Do You Want to Modify it?(Enter y/n)");
                            scanf("%c",&ch);
                            if(ch=='y' || ch=='Y')
                            {
                                update(word);
                                printf("\n\n\t\t\t\t\t\tWord Got Updated Successfully!!!");
                            }
                        }
                    }

                    printf("\n\n\t\t\t\t\t\t\tPress any key to go to main menu.");
                    getchar();
                }
                break;
        case '3': {
                    set_pos();
                    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf("\n\t\t\t\t\t\t\t\t\t\tWORD-MEANING\n\n");
                    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                    display();
                    printf("\n\n\t\t\t\t\t\t\tPress any key to go to main menu.");
                    getchar();
                }
                break;
        case '4':{
                    char word[20];
                    set_pos();
                    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf("\n\t\t\t\t\t\t\t\t\t\tUPDATE WORD\n\n");
                    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf("\n\t\t\t\t\t\t  Enter the word you want to update: ");
                    gets(word);
                    int len = sizeof(word)/sizeof(word[0]);
                    for(int i=0;i<len;i++)
                    {
                        word[i]=tolower(word[i]);
                    }
                    int found = search(word);
                    if(found==1)
                    {
                        update(word);
                        printf("\n\n\t\t\t\t\t\tWord Got Updated Successfully!!!");
                    }
                    else
                    {
                        printf("\n\t\t\t\t\t\tWord Not Found!!!");
                    }
                    printf("\n\n\t\t\t\t\t\t\tPress any key to go to main menu.");
                    getchar();
               }
                break;
        case '5': {
                char word[20];
                set_pos();
                printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("\n\t\t\t\t\t\t\t\t\t\tDELETE WORD\n\n");
                printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("\t\t\t\t\tEnter the word you want to delete: ");
                gets(word);
                int len = sizeof(word)/sizeof(word[0]);
                for(int i=0;i<len;i++)
                {
                    word[i]=tolower(word[i]);
                }

                del(word);
                printf("\n\n\t\t\t\t\tPress any key to go to main menu.");
                getchar();
                }
                break;
        case '6': {
                    char ch;
                    set_pos();
                    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf("\t\t\t\t\t\t\t\t\t\tSEARCH WORD WITH FIRST LETTER\n");
                    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf("\n\t\t\t\t\t\tEnter the alphabet: ");
                    scanf("%c",&ch);
                    ch=tolower(ch);
                    printf("\n");
                    getchar();
                    search_letter(ch);
                    printf("\n\n\t\t\t\t\t\t\tPress any key to go to main menu.");
                    getchar();
                }

                break;
        case '7': {
                    set_pos();
                    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf("\t\t\t\t\t\t\t\t\t\tRECENTLY SEARCHED WORDS\n");
                    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                    recent_searches();
                    printf("\n\n\t\t\t\t\t\t\tPress any key to go to main menu.");
                    getchar();
                }
                break;
        case '8': {
                    set_pos();
                    printf("\t\t\t\t\t\t\tHAVE A NICE DAY!!\n\n\n\n\n\n");
                    exit(0);
                }
        default: printf("\t\t\t\t\tInvalid choice");
                sleep(1);
                break;

    }
    }

}

void set_pos()
{
    system("cls");
    COORD c;
    c.X = 0;
    c.Y = 10;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


int search(char * search_word)
{
    int x = 0;
    int found = 0;
    fp = fopen("dictionary.txt","r");
    if(fp==NULL)
    {
        printf("Cannot open the file");
    }
    else
    {
        while(fscanf(fp,"%d",a[x].word) != EOF)
        {
            fscanf(fp,"%s\t%[^\n]s\n", a[x].word, a[x].mean);
            if(strcmp(a[x].word,search_word)==0)
            {
                 printf("\n\t\t\t\t\t%-20s -> \t%s\n ",a[x].word, a[x].mean);
                 found = 1;
            }
            x++;
        }
    }
    fclose(fp);
    return found;
}

void did_you_mean(char * word)
{
    int x=0,i, found=0;
    fp = fopen("dictionary.txt","r");
    if(fp==NULL)
    {
        printf("Cannot open the file");
    }
    else
    {
        while(fscanf(fp,"%d",a[x].word) != EOF)
        {
            int count=0, c1[123]={0}, c2[123]={0};
            fscanf(fp,"%s\t%[^\n]s\n", a[x].word, a[x].mean);
            for(i=0;word[i]!='\0';i++)
                c1[word[i]]++;
            for(i=0;a[x].word[i]!='\0';i++)
                c2[a[x].word[i]]++;
            for(i=0;i<123;i++)
            {
                if(c1[i]!=0 && c2[i]!=0)
                {
                count++;
                }
            }
            if(count>=4)
            {
                if(found==0)
                {
                    printf("\n\n\t\t\t\t\t\tDid you mean?\n");
                }
                 found=1;
                 printf("\n\t\t\t\t\t%-20s -> \t%s\n ",a[x].word, a[x].mean);
            }
            }
            x++;
    }
    if(found==0)
    {
        printf("\n\n\t\t\t\t\t\t\tWord Not Found!!!");
    }
    fclose(fp);
}

void update(char * word)
{
    char update_mean[200] ;
    int x = 0;
    int found = 0;
    fflush(stdin);
    fp = fopen("dictionary.txt","r");
    fp1= fopen("temp.txt","w");
    while(fscanf(fp,"%d",a[x].word) != EOF)
        {
            fscanf(fp,"%s\t%[^\n]s\n", &a[x].word, &a[x].mean);
            if(strcmp(a[x].word,word)==0)
            {
                found=1;
                printf("\n\n\t\t\t\t\t\tEnter the updated meaning: ");
                gets(update_mean);
                strcpy(a[x].mean,update_mean);
            }
            fprintf(fp1,"%s\t%s\n", a[x].word, a[x].mean);
            x++;
        }
    fclose(fp);
    fclose(fp1);
    fp = fopen("dictionary.txt","w");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%d",a[x].word) != EOF)
    {
        fscanf(fp1,"%s\t%[^\n]s\n", &a[x].word, &a[x].mean);
        fprintf(fp,"%s\t%s\n", a[x].word, a[x].mean);
    }
    fclose(fp);
    fclose(fp1);
}

void add(char * word)
{
    int x = 0;
    char mean[100];
    fflush(stdin);
    fp = fopen("dictionary.txt","a+");  //Opening the file
    if(fp==NULL)
    {
        printf("Cannot open the file");
    }
    else
    {
        fseek(fp,0,SEEK_END);
        printf("\n\t\t\t\t\t\tEnter meaning: ");
        gets(mean);
        fprintf(fp,"%s\t%s\n",word,mean);
    }
    fclose(fp);  //Closing the file
}

void display()
{
    fp = fopen("dictionary.txt","r");
    if(fp==NULL)
    {
        printf("Cannot open the file.");
    }
    else
    {
    dict temp;
    int no_of_words=0;
    int x = 0;
    fflush(stdin);
     while(fscanf(fp,"%d",a[x].word)!= EOF)
    {
        fscanf(fp,"%s\t%[^\n]s\n", &a[x].word, &a[x].mean);/* [^\n] allows scanf() to take multi-word input until enter isn't pressed.*/
        no_of_words++;
        x++;
    }
    fclose(fp);
    for(int i=0;i<no_of_words;i++)
    {
        for(int j=i+1;j<no_of_words;j++)
        {
            if(strcmp(a[i].word,a[j].word)>0)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    fp = fopen("dictionary.txt","w");
    for(int i=0;i<no_of_words;i++)
    {
            if(i%15==0 && i!=0)
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tPress any key to continue!");
                getchar();
                system("cls");
                COORD c;
                c.X = 1;
                c.Y = 10;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
            }
            fprintf(fp,"%s\t%s\n",a[i].word,a[i].mean);
            printf("\t\t\t%-20s ->\t%s\n\n",a[i].word,a[i].mean);
    }
    fclose(fp);
    }
}



void del(char * word)
{
    int x=0;
    found=0;
    fp = fopen("dictionary.txt","r");
    fp1 = fopen("temp.txt","w");
    while((fscanf(fp,"%s\t%[^\n]s\n", &a[x].word, &a[x].mean)!=EOF))
		{
		    if(strcmp(a[x].word, word)==0)
		    {
		        found=1;
		    }

			if(strcmp(a[x].word, word)!=0)  //all the words from dict except the one which is being entered by the user for deletion, are copied on temp.text
                fprintf(fp1,"%s\t%s\n", a[x].word, a[x].mean);
                x++;
		}

    fclose(fp);
    fclose(fp1);
    if(found==0)
    {
        printf("\n\t\t\t\t\tWord not Found!!!");
    }
    else
    {
        fp = fopen("dictionary.txt","w");
        fp1 = fopen("temp.txt","r");
        x = 0;
        while(fscanf(fp1,"%d",a[x].word) != EOF)
        {
            fscanf(fp1,"%s\t%[^\n]s\n", &a[x].word, &a[x].mean);
            fprintf(fp,"%s\t%s\n", a[x].word, a[x].mean);
            x++;
        }
        fclose(fp);
        fclose(fp1);
        printf("\n\t\t\t\t\t WORD DELETED SUCCESSFULLY!!!");
    }
}

void search_letter(char ch)
{
    found=0;
    while(found==0)
    {
    int x=0, i=0;
    fflush(stdin);
    fp = fopen("dictionary.txt","r");
        while((fscanf(fp,"%s\t%[^\n]s\n", &a[x].word, &a[x].mean)!=EOF))
		{
		    if(a[x].word[i]==ch)
            {
                 printf("\t\t%-20s -> \t%s\n ",a[x].word, a[x].mean);
                 found=1;
            }
            x++;
		}
        if(found==0)
        {
            printf("\t\t\t\t\t\tEnter valid alphabet");
            found=1;
        }
    fclose(fp);
    }
}

void recent_searches()
{
    printf("\n\n");
    if(rear == front && rear!=0)
    {
        printf("\t\t\t\t\t\t\tNo Recent Searches!!!");
    }
    else
    {
        for(int i = front; i <= rear; i++)
        {
            printf("\t\t\t\t\t\t\%s \n", queue[i]);
        }
    }
}

void delay(int number_of_seconds)
{
    int milli_seconds=number_of_seconds;
    clock_t start_time=clock();
    while(clock()<start_time+milli_seconds)
    {
        ;
    }

}
