#include<stdio.h>
#include<stdlib.h>

void printList();
void insertAtStart();
void deleteAtStart();

void insertAtEnd();
void deleteAtEnd();

void insertAtPosition();
void deleteAtPosition();

void show();

int count=0;
struct List 
{
        int data;
        struct List *next;
        struct List *prev;
};

typedef struct List Node;

Node *start = NULL;

Node *createNode();

int main()
{
        int choice;
        while(1)
        {
             printList();
             scanf("%d",&choice);
             if(choice==8){break;}
             
             switch(choice)
             {
                case 1: insertAtStart(); break;
                case 2: insertAtEnd(); break;
                case 3: insertAtPosition(); break;
                case 4: deleteAtStart(); break;
                case 5: deleteAtEnd(); break;
                case 6: deleteAtPosition(); break;
                case 7: show(); break;     
                default: printf("\nWrong Choice\n");
                                                                                           
             }
                        
        }
        printf("\n*** Thanks ***\n");        
}

Node *createNode()
{
        int num;
        Node *newNode = (Node *)malloc(sizeof(Node));
        if(newNode==NULL){
                printf("\nNew Block Not Created !\n");
                return 0;
        }        
        printf("\nEnter Number : ");
        scanf("%d",&num); 
        newNode->data = num;
        return newNode;
}

void insertAtStart()
{       
        Node *newNode= createNode();
        newNode->prev = NULL;        
        newNode->next = start;
        if(start!=NULL)
        { start->prev = newNode; }
        start = newNode;
        count++;
}

void insertAtEnd()
{
        if(start==NULL){insertAtStart(); return;}
        
        int num;        
        Node *newNode= createNode();
        newNode->next=NULL;         
     
          Node *temp = start;
          while(temp->next!=NULL)
          {
                temp = temp->next;
          }      
          temp->next = newNode; 
          newNode->prev = temp;
          count++;
}

void insertAtPosition()
{
        int pos,num,x;
        printf("\nEnter Position : ");
        scanf("%d",&pos);
        
        if(pos<1 || pos>count+1)
        {
                printf("\nWrong Position !\n");
        }else
        {
                if(pos==1)
                {  insertAtStart(); }else{
                        if(pos==count+1){
                                insertAtEnd();
                        }else{
                                Node *newNode= createNode();
                                                                
                                Node *temp = start;
                                x=1;
                                while(x<pos-1)
                                {
                                        temp= temp->next;
                                        x++;
                                }
                                
                                temp->next->prev = newNode;
                                newNode->next = temp->next;
                                newNode->prev = temp;
                                temp->next = newNode;
                                count++;
                        }
                }
        }
}



void deleteAtStart()
{
       if(start==NULL){
                printf("\nList is Empty\n");
                return;            
        }
        Node *temp = start;
        start = start->next;
        if(start != NULL)
        	start->prev = NULL;
        free(temp);
        printf("\nElement Deleted.\n");
        count--;
}


void deleteAtEnd()
{
       if(start->next==NULL){deleteAtStart(); return;}
       if(start==NULL){
                printf("\nList is Empty\n");
                return;            
        }
        Node *temp = start;
        while(temp->next->next!=NULL)
        {
                temp = temp->next;
        }
        
        free(temp->next);        
        temp->next = NULL;        
        printf("\nElement Deleted.\n");
        count--;
}

void deleteAtPosition()
{
        int pos,x;
        printf("\nEnter Position : ");
        scanf("%d",&pos);
        
        if(pos<1 || pos>count)
        {
                printf("\nWrong Position !\n");
        }else{
                 if(pos==1)
                {  deleteAtStart(); }else{
                        if(pos==count){
                                deleteAtEnd();
                        }else{
                                Node *temp = start;
                                x=1;
                                while(x<pos)
                                {
                                        temp = temp->next;
                                        x++;
                                }                                
                                Node *t = temp;

                                temp->prev->next = temp->next;
                                temp->next->prev = temp->prev;
                                
                                free(t);
                                 printf("\nElement Deleted.\n");
                                count--;
                        }
                }
        }
}



void show()
{
        if(start==NULL){
                printf("\nList is Empty\n");
                return;            
        }
        printf("\nList : ");
        Node *temp = start;
        do
        {
                printf("%d ",temp->data);
                temp = temp->next;
        }while(temp!=NULL);
        printf("\n");
}

void printList()
{
        printf("\n1. Insert At Start");
        printf("\n2. Insert At End");        
        printf("\n3. Insert At Specific Position");        
        printf("\n4. Delete At Start");
        printf("\n5. Delete At End");        
        printf("\n6. Delete At Specific Position");        
        printf("\n7. Show");        
        printf("\n8. Exit");        
        printf("\n>>>> ");        
}

