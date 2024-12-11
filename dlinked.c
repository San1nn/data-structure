#include <stdio.h>
#include <stdlib.h>

//node definition
struct node{
int data;
struct node *left, *right;
};
struct node* insert(struct node*,int);
struct node* delete(struct node*,int);
struct node* search(struct node*,int);
void display(struct node*);

void main()
{
        struct node *start=(struct node*)0;
        int op,data;
        
        do{
                printf("\n -doubly linked list operations-\n");
                printf("1.insert\n2.delete\n3.search\n4.display\n5.exit\n");
                printf("\n--------------------\n\nyour choice:");
                scanf("%d",&op);
                
                switch(op)
                {
                case 1:
                printf("enter data:");
                scanf("%d",&data);
                start=insert(start,data);
                break;
                
                case 2:
                printf("enter data to be deleted:");
                scanf("%d",&data);
                start=delete(start,data);
                break;
                
                case 3:
                printf("enter the data to search:");
                scanf("%d",&data);
                if (search(start,data))
                printf("item found\n");
                else
                printf("item not found");
                break;
                
                case 4:
                display(start);
                break;
                
                case 5:
                exit(0);
                
                default:
                printf("enter a valid choice\n");
                break;
                }
         }
         while(1);
}

//insert 
struct node*insert(struct node* s,int item)
{
        struct node*t=(struct node*)malloc(sizeof(struct node));
        t->data=item;
        t->right=s;
        t->left= (struct node*)0;
        if(s!= (struct node*)0)
        {
                s->left=t;
        }
        return t;
}
//delete
struct node* delete(struct node* s, int data)
{
        struct node *t= search(s,data);
        if(t!=(struct node*)0)
        {
                printf("%d is deleted\n",t->data);
                if (t->left ==(struct node*)0 && t->right == (struct node*)0)
                {
                        s=(struct node*)0;
                }
                
                else if (t->left ==(struct node*)0)
                {
                        s=t->right;
                        if(s !=(struct node*)0)
                        {
                                s->left=(struct node*)0;
                        }
                }
        
         else if (t->right ==(struct node*)0)
         { //deleting the last node 
                t->left->right=(struct node*)0;
         }
         else //deleting the node in the middle 
         {
                t->left->right = t->right;
                t->right->left =t->left;
         }
         free(t);
}
else
{
        printf("item not found\n");
}
return s;
}

//search
struct node* search(struct node* s,int item){
struct node *t = s;

while (t !=(struct node*)0 && t->data != item)
        t=t->right;
return t;
}

//display 
void display(struct node* s)
{
        if (s==(struct node*)0)
        {
                printf("list is empty\n");
                return;
        }
        while (s !=(struct node*)0)
        {
                printf("%d\t",s->data);
                s= s->right;
        }
        printf("\n");
}

                      
