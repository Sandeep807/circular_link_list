#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *root;

void append();
void addBegin();
void display();
int length();
void deleteBegin();
void deleteEnd();
void search();
int main()
{
    int choice;
    while (1)
    {
        printf("1.Append\n");
        printf("2.Add begin\n");
        printf("3.Display\n");
        printf("4.Length\n");
        printf("5.Delete begin\n");
        printf("6.Delete end\n");
        printf("7.Search\n");
        printf("8.Exit\n");
        printf("Enter you choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            append();
            break;
        case 2:
            addBegin();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("%d\n",length());
            break;
        case 5:
            deleteBegin();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            search();
            break;
        case 8:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}

void append()
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: \n");
    scanf("%d", &temp->data);
    if (root == NULL)
    {
        root = temp;
        temp->link = root;
    }
    else
    {
        p = root;
        while (p->link != root)
        {
            p = p->link;
        }
        p->link = temp;
        temp->link = root;
    }
}

void addBegin()
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: \n");
    scanf("%d", &temp->data);
    if (root == NULL)
    {
        root = temp;
        temp->link = root;
    }
    else
    {
        p = root;
        while (p->link != root)
        {
            p = p->link;
        }
        p->link = temp;
        temp->link = root;
        root = temp;
    }
}


void display()
{
    struct node *p = root;
    if (root==NULL)
    {
        printf("Not data available\n");
    }
    else
    {
         do
        {
            printf("%d-->\n", p->data);
            p = p->link;
        }
        while (p!= root);
    }
    
   
}


int length()
{
    int count=0;
    struct node *p=root;
    if (root==NULL)
    {
        return count;
    }
    else
    {
        do
        {
            count++;
            p = p->link;
        }
        while (p!= root);
        return count;
    }
    
}



void deleteBegin()
{
    struct node *p = root;
    if (root == NULL)
    {
        printf("Data not available\n");
    }
    else
    {
        while (p->link!=root)
        {
            p = p->link;
        }
        p->link = root->link;
        free(root);
        root=p->link;
        printf("Deleted successfully\n");
        
    }   
}

void deleteEnd()
{
    struct node *p = root,*q;
    if (root == NULL)
    {
        printf("List is empty\n");
    }
    else if (root->link==root)
    {
        root=NULL;
        free(root);
        printf("Node deleted\n");
    }
    
    else
    {
        while (p->link!=root)
        {
            q=p;
            p=p->link;
        }
        q->link=p->link;
        free(p);
        printf("Deleted successfully\n");   
    }
    
    
}

void search()
{
    int n,flag=0;
    struct node *p=root;
    if (root==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Enter data: ");
        scanf("%d",&n);
        do
        {
            if (p->data==n)
            {
                flag=1;
                break;
            }
            p=p->link;
            
        } while (p!=root);

        if (flag !=0)
        {
            printf("Data found\n");
        }
        else
        {
            printf("Data not found\n");
        }
         
    }
       
}
