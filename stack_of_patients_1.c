#include<stdio.h>
#define SIZE 3

void push();
void pop();
void traverse();


int top=-1;

struct Patient
{
	char name[50];
	int ward;
};
typedef struct Patient Patient;

Patient pat[SIZE];

int main()
{
        int choice;
        while(1)
        {
        printf("\n1. PUSH");
        printf("\n2. POP");        
        printf("\n3. Traverse");        
        printf("\n4. Size Count");
        printf("\n5. Exit");
        printf("\n>>>> ");         
                scanf(" %d",&choice);               
                if(choice==5)  {break;}             
                switch(choice)
                {
                        case 1: push(); break;
                        case 2: pop(); break;
                        case 3: traverse(); break;
                        case 4: printf("\nSize: %d\n",top+1);break;
                        default: printf("\nWrong Option choose !\n");
                }
        }
        printf("\n**** Thanks ****\n");
}
void push()
{
        int num;
        if(top==SIZE-1)
        {
                printf("\nNo Wards Available!!\n");
        }else{	
        		top++;
        		printf("\n\tPATIENT NO. : %d\n",top+1);
                printf("\n\tEnter Patient Name : ");  scanf(" %[^\n]c",pat[top].name);  
                printf("\n\tEnter Ward No. : "); scanf("%d",&pat[top].ward);
              
                printf("\n\tDetails Entered !\n");
        }
}

void pop()
{
        if(top==-1){
                printf("\nNo Patient!!\n");
        }else{
                printf("\nPatient Details Deleted : %d\n",top+1);
                top--;
        }
}

void traverse()
{
        int x;
        if(top==-1){
                printf("\nNo Patient!!\n");
        }else{
                printf("\nALL PATIENT DETAILS : \n");
                for(x=0; x<=top; x++){
                        printf("\n\tPatient No. : %d",x+1);
                        printf("\n\t\tPatient Name : %s",pat[x].name);
                        printf("\n\t\tWard No. : %d",pat[x].ward);
                        printf("\n");
                }
        }
        printf("\n");
}


