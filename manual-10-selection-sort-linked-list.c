#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node* next;
} *head=NULL;


void insert(int value)
{
    struct Node *newNode;
    newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data=value;

    if(head == NULL)
    {
        newNode->next=NULL;
        head=newNode;
    }
    else
    {
        newNode->next=head;
        head=newNode;
    }
}

void printList()
{
    if(head == NULL)
    {
        printf("\n List is empty !!");
    }
    else
    {
        struct Node *temp=head;

        while(temp->next != NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
    }
}

void swap(struct Node *a, struct Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void selection_sort(int n)
{
    int i,j;

    struct Node *temp;
    struct Node *temp2=head;

    for (i = 0; i <n; i++)
    {
        temp=temp2;

        while(temp->next != NULL)
        {

            if (temp->next->data < temp2->data)
            {
                swap(temp->next,temp2);
            }
            temp=temp->next;

        }

        temp2=temp2->next;
    }

}



int main()
{
    int n,data,i;
    printf("Enter the list size: ");
    scanf("%d",&n);

    for (i=0; i<n; i++)
    {
        scanf("%d",&data);
        insert(data);
    }


    printf("Unsorted list: ");
    printList();

    selection_sort(n);

    printf("\n\nSorted list: ");
    printList();

    return 0;
}



