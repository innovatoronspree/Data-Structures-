/* creating a linked list and printing its content in reverse */
#include<stdlib.h>
#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
void fun1(struct node* head);
int main()
{
    struct node* head= NULL;
    struct node* second=NULL;
    struct node* third= NULL;
    head= (struct node*)malloc(sizeof(struct node));
    second= (struct node*)malloc(sizeof(struct node));
    third= (struct node*)malloc(sizeof(struct node));
    head->data=1;
    head->next=second;
    second->data=2;
    second->next= third;
    third->data= 3;
    third->next=NULL;
    printf(" the data in the link list: \n");
    fun1(head);
    return 0;
    }
void fun1(struct node* head)
{
   if(head==NULL)
       return;
    fun1(head->next);
    printf("%d \n", head->data);
}
    
