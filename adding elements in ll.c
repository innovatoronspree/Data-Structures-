#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insertfirst(struct node **header, int d)
{
    struct node *t= (struct node*)malloc(sizeof(struct node));
    if(*header==NULL)
    {
        t->data=d;
        t->next=NULL;
    }
    else
    {
        t->data=d;
        t->next= *header;
    }
    *header=t;
}
void printlistreverse( struct node *header)
{
       if(header == NULL)
            return;
        
        printlistreverse(header->next);
        printf("%d  ", header->data);
}
int main()
           {
               struct node *head= NULL;
               int i,c;
               printf("Enter a negative element to end list \n");
               printf("Enter the element: \n");
              
               for(i=0; ;i++)
               {
                scanf("%d", &c);
                   if(c<0)
                   
                       break;
                   
                   else
                   {
                       insertfirst(&head,c);
                   }
               }
               printlistreverse(head);
               return 0;
           }
           
                     
               
               

