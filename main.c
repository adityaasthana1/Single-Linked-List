#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

struct node
{
    int data ;
    struct node *link;
};

struct node *addatbeg(struct node *start);
struct node *addatend(struct node *start);
struct node *addatpos(struct node *start);
void display(struct node *start);
int count(struct node *start);
struct node *delete_node(struct node *start);
struct node *reverse_list(struct node *start);
void search_node(struct node *start);
void SetColor(int ForgC);

int main()
{
    struct node *start = NULL ;

    while(1)
    {
        SetColor(11);
        printf("1.Add at beg.\n2.Add at end.\n3.add at a position\n4.Display List\n5.count\n6.Delete node.\n7.Reverse List.\n8.Search node\n\nEnter choice :  ");
        int i,a ;
//    textcolor(26);
        SetColor(12);

        scanf("%d",&i );
        switch(i)
        {
        case 1 :
            start = addatbeg(start);
            break ;
        case 2 :
            start = addatend(start);
            break;
        case 3:
            start = addatpos(start);
            break ;
        case 4:
            display(start);
            break;
        case 5:
            a = count(start);
            printf("\nThere are %d nodes.\n",a);
            break;
        case 6:
            start = delete_node(start);
            break;
        case 7 :
            start = reverse_list(start);
            break;
        case 8:
            search_node(start);
            break;
        default:
            printf("\nEnter a valid option.\n");
            break;
        }
    }
    return 0 ;
}

struct node *addatbeg(struct node *start)
{
//struct node *p = start;
    if(start == NULL)
        printf("\nList is Empty.\nAdding data in an empty list...\n");

    int data ;
    printf("\nInput data : ");
    scanf("%d", &data);
    struct node *temp ;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data ;
    temp->link = start ;
    start = temp ;
    printf("\nNode successfully added.\n");
    return start;
}

struct node *addatend(struct node *start )
{
    int a ;
    if(start == NULL)
    {
        printf("\nEmpty List\n");
        printf("Do you want to add in beginning? 1/0 \n(1 = Yes \n0 = No.)\n");
        scanf("%d",&a);
        if(a==1)
        {
            start = addatbeg(start);
            return start ;
        }
        else
            return start;
    }

    struct node *p = start ;
    int data ;
    printf("\nInput data : ");
    scanf("%d", &data);
    struct node *temp ;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data ;
    while(p->link!=NULL)
        p = p->link;
    temp->link = p->link;
    p->link = temp ;
    printf("\nNode successfully added.\n");
    return start ;
}

struct node *addatpos(struct node *start)
{
    if(start == NULL)
    {
        printf("\nEmpty List.\n");
        printf("\nYou can add data at first place..\n");
    }
    struct node *p = start ;
    int data, position ;
    printf("\nInput data and position. : ");
    scanf("%d %d", &data,&position);
    if(position==1)
    {
        start = addatbeg(start);
        return start;
    }
    if(position > count(start))
    {
        printf("\nOUT OF BOUND\n");
        return start;
    }
    for(int i = 1; i < position ; i++)
        p = p->link ;
    struct node *temp ;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data ;
    temp->link = p->link;
    p->link = temp;
    printf("\nSuccessfully added node at %d position\n", position);
    return start ;
}

void display(struct node *p)
{
//   struct node *p = start ;
    if(p == NULL )
    {
        printf("\nEmpty List.\n");
        return ;
    }
    printf("\n");
    while(p!=NULL)
    {
        if(p->link==NULL)
        {
            printf(" %d\n",p->data);
            return ;
        }
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("\n\n");
}

int count(struct node *start)
{
    struct node *p = start ;
    int count = 0 ;
    if(p==NULL)
        printf("\nEmpty List\n\n");
    else
    {
        while(p!=NULL)
        {
            count++ ;
            p = p->link;
        }
    }
    return count ;
}

struct node *delete_node(struct node *start)
{
    if(start==NULL)
    {
        printf("\nEmpty list\n\n");
        return 0;
    }
    struct node *p = start ;
    struct node *temp = NULL ;
    int option,data ;
    int position ;
    printf("\n1.Delete at end\n2.Delete at beginning\n3.Delete at position\n4.Delete by data.\n\nEnter Choice : ");
    scanf("%d", &option);
    switch(option)
    {
    case 1:
        if(start == NULL )
        {
            printf("\nEmpty List\n");
            return start ;
        }
        if(p->link == NULL)
        {
            start = NULL ;
            return start ;
        }
        while(p->link->link!=NULL)
            p=p->link ;
        temp = p->link ;
        p->link = NULL ;
        free(temp);
        printf("\nNode Successfully deleted.\n");
        return start;
        break;

    case 2:
        if(start == NULL )
        {
            printf("\nEmpty List.\n");
            return start;
        }
        if(start->link == NULL)
        {
            temp = start ;
            start = NULL;
            free(temp);
            printf("\nSuccessfully Deleted.\n");
            return start;
        }
        start = start->link;
        printf("\nNode Successfully Deleted.\n");
        return start;
        break;

    case 3:
        printf("\nEnter the position");
        scanf("%d",&position);
        if(position > count(start))
        {
            printf("\nOut of bound.\n");
            return start ;
        }
        for(int i = 0; i < position-2 ; i++ )
            p = p->link;
        temp = p->link->link;
        p = temp ;
        free(temp);
        return start;
        break;

    case 4:
        printf("Value of the element to be deleted :  ");
        scanf("%d",&data);
        if(start==NULL)
        {
            printf("\nEmpty List.\n");
            return start ;
        }
        if(start->data==data)
        {
            temp = start;
            start = start->link ;
            free(temp);
            printf("\nDeleted Successfully.\n");
            return start;
        }
        while(p->link!=NULL)
        {
            if(p->data==data && p->link==NULL)
        {
            temp = start;
            start = NULL;
            free(temp);
            return start;
        }
            if(p->link->data == data )
            {
                temp = p->link ;
                p->link = p->link->link;
                printf("\nSuccessfully Deleted.\n");
                free(temp);
                return start;
            }
            printf("\nElement not present in the list.\n");
            return start ;
        }

    default:
        printf("\nInvalid Input\n");
        return start;
        break;
    }
}

struct node *reverse_list(struct node *start)
{
    struct node *prev, *next, *current ;
    current = start ;
    prev = NULL ;
    while(current!=NULL)
    {
        next = current->link ;
        current->link = prev;
        prev = current ;
        current = next ;

    }
    start = prev ;
    printf("\nSuccessfully Reversed.\n\n");
    return start ;
}

void search_node(struct node *start)
{
    if(start == NULL)
    {
        printf("\nEmpty List\n");
        return ;
    }
    int data, position = 0;
    struct node *temp = start;
    printf("\nInput search element\n");
    scanf("%d",&data);
    while(temp->link!=NULL)
    {
        temp = temp->link;
        position++;
        if(temp->data==data)
        {
            printf("\nThe element is present at the position %d \n\n",position+1);
            return ;
            break;
        }
    }
    printf("\nNot present in the list.\n");
}

void SetColor(int ForgC)
{
    WORD wColor;
    //This handle is needed to get the current background attribute

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    //csbi is used for wAttributes word

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //To mask out all but the background attribute, and to add the color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

