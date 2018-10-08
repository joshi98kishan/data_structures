#include<stdio.h>
#define SIZE 5

void insert();
void delete();
void traverse();

int arr[SIZE];
int front=-1;
int rear = -1;

int main()
{
        int choice;
        while(1)
        {
        printf("\n1. Insert");
        printf("\n2. Delete");        
        printf("\n3. Traverse");        
        printf("\n4. Size Count");
        printf("\n5. Exit");
        printf("\n>>>> ");         
                scanf("%d",&choice);               
                if(choice==5)  {break;}             
                switch(choice)
                {
                        case 1: insert(); break;
                        case 2: delete(); break;
                        case 3: traverse(); break;
                        case 4: break;
                        default: printf("\nWrong Option choose !\n");
                }
        }
        printf("\n**** Thanks ****\n");
}
void insert()
{
        int num;
        if( (rear+1)%SIZE==front)
        {
                printf("\nQueue is Full.\n");
        }else{
                printf("Enter Number : ");        
                scanf("%d",&num);
                
                if(front==-1){front++;}
                rear = (rear+1)%SIZE;
                arr[rear]= num;
                printf("\n\tElement is inserted !\n");
        }
}

void delete()
{
        if(front==-1){
                printf("\nQueue is Empty .\n");
        }else{
         printf("\ndelete element is  : %d\n",arr[front]);
         if(front==rear){
                front=rear=-1;
         }else
         {
                 front = (front+1)%SIZE;
         }
        }
}

void traverse()
{
        int x,y;
        if(front==-1){
                printf("\nQueue is Empty .\n");
        }else{
                printf("\nQueue : ");
                x = front;
                do
                {                       
                        printf("%d ",arr[x]);
                        x = (x+1)%SIZE;
                }while(x != (rear+1)%SIZE);
        }
        printf("\n");
}





