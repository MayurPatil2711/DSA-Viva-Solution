#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void printlist(struct node * head){
    struct node * temp2=head;
    while (temp2!=NULL)
    {
        printf("%d\n",temp2->data);
        temp2=temp2->next;
    }
}
int main(){
    int size;
    scanf("%d", &size);
    struct node * head, *current, *temp;
    for (int i = 0; i < size; i++)
    {
        current= (struct node *)(malloc(sizeof(struct node)));
        scanf("%d",&current->data);
        if (i==0)
        {
            head=temp=current;
        }
        else{
            temp->next=current;
            temp=current;
        }
    }
    current = temp = NULL;

    struct node *current2=head,*prev=NULL,*next=NULL;
    //printf("this is done\n");
    int count = 0;
    while (count<size)
    {
        //printf("executing\n");
        next=current2->next;
        current2->next=prev;
        prev=current2;
        current2=next;
        //printf("done\n");
        //printf("\n");
        count++;
    }
    head=prev;
    ///printf("this is done\n");
    printlist(head);
    return 0;
}