#include<stdio.h>
#include<stdlib.h>
struct node
{
    int v;
    struct node *next;
};
struct queue
{
    struct queue *front;
    struct queue *rear;
    struct queue *next;
    int data;
};
struct node *createnode(int d)
{
    struct node *temp= (struct node *)malloc(sizeof(struct node ));
    temp->v=d;
    temp->next=NULL;
    return temp;
}
int isempty(struct queue *front)
{
    if(front==NULL)
        return 1;
    else
        return 0;
}
void enqueue(struct queue **front, struct queue **rear, int d)
{
    if(*front==NULL)
    {
        struct queue *temp= (struct queue *)malloc(sizeof(struct queue));
        temp->data=d;
        temp->next=NULL;
        *front= temp;
        *rear= temp;
    }
    else
    {
        struct queue *temp= (struct queue *)malloc(sizeof(struct queue));
        temp->data=d;
        temp->next=NULL;
        (*rear)->next= temp;
        *rear= temp;
        
    }
}
int dequeue(struct queue **front, struct queue **rear)
{
    struct queue *temp=NULL;
    if(*front == NULL)
    {
        printf(" \n No node is present..");
        return -1;
    }
    else
    {
        temp= *front;
        *front =temp->next;
        int v= temp->data;
        free(temp);
        return v;
    }
}
void creategraph(struct node *adjlist[], int n)
{
    struct node *newnode;
    int reply;
    int i,j;
    printf("\n If link is present enter 1: ");
    printf("\n If link is absent enter 0:  " );
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)
            {
                continue;
            }
            else
            {
                printf("\n Is there any link between %d and %d: ", i,j);
                scanf("%d", &reply);
                if(reply==1)
                {
                    newnode= createnode(j);
                    if(adjlist[i]==NULL)
                    {
                        adjlist[i]= newnode;
                    }
                    else
                    {
                        struct node *current= adjlist[i];
                        while(current->next!=NULL)
                        {
                            current= current->next;
                        }
                        current->next= newnode;
                    }
                }
            }
        }
    }
}
void BFS(struct node *adjlist[], int n, int svertex)
{
    int visited[50];
    int i,j;
    for(i=0;i<=n;i++)
    {
        visited[i]=0;
    }
    visited[svertex]=1;
    printf("%d->", svertex);
    
    for(j=1;j<=n;j++)
    {
        struct node *current= adjlist[j];
        while(current!=NULL )
        {
            if(visited[current->v]==0)
            {
                int data= current->v;
                visited[data]= 1;
                printf("%d-> ", current->v);
                current=current->next;
            }
            else
            {
                current= current->next;
            }
        }
    }
}
int main()
{
    struct node *adjlist[50];
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    creategraph(adjlist,n);
    BFS(adjlist,n,1);
    

}
                    
                    
        
    
    

    
