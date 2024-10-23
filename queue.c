#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int que[SIZE];
int front=-1, rear=-1;
void main()
{
        void insertq(int);
        int deleteq();
        int searchq(int);
        int data,opt;
        do
        {
                printf("\n 1.insert    \n");
                printf("\n 2.delete    \n");
                printf("\n 3.search    \n");
                printf("\n 4.exit    \n");
                printf("\n your option is:    \n");
                scanf("%d",&opt);
                switch(opt)
                {
                        case 1:printf("data:");
                        scanf("%d",&data);
                        insertq(data);
                        break;
                        
                        case 2:data=deleteq();
                        printf("\ndeleted item=%d\n",data);
                        break;
                        
                        case 3:printf("\nitem to search:\n");
                        scanf("%d",&data);
                        if(searchq(data))
                        printf("found \n");
                        else
                        printf("not found \n");
                        break;
                        
                        case 4:exit(0);
                }}
                while(1);
                }
                void insertq(int item)
                {
                if(rear==SIZE-1)
                printf("queue is full\n");
                else
                que[++rear]=item;
                }
                
                int deleteq()
                {
                if(front==rear)
                {
                printf("queue is empty\n");
                exit(0);
                }
                else
                front++;
                
                return que[front];
                
                }
                
                int searchq(int item)
                {
                if (front==rear)
                        return 0;
                int temp=front+1;
                while(temp!=rear && que[temp]!=item)
                ++temp;
                if(que[temp]==item)
                return 1;
                return 0;
                }
