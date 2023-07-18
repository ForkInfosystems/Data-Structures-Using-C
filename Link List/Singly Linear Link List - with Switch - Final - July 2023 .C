#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int LL_Ele_Cnt = 0;

struct Node
{
        int  Data;
        struct Node *Next;
};

void  Insert_First( struct Node  **First  ,  int  No )
{
        struct Node *NewN = NULL;                                                  // Creating  Pointer for New Node

        NewN = (struct Node*)malloc(sizeof(struct Node));                          // Allocation Dynamic Memory for New Node in Data Section (Heap) by malloc

        NewN ->Data = No;
        NewN ->Next = NULL;                                                        //  Setting Values to New Node

        if( NULL == *First )                                                       // Only Once means for inserting very 1st element in LL
        {
            *First  =  NewN;
        }
        else                                                                       // Works for every next element i.e. from 2nd elements onwards
        {
            NewN -> Next = *First;
            *First = NewN;
        }

        printf("\n %d Element Inserted  at First Position Successfully", No);

        LL_Ele_Cnt++;
        return;
}

void  Insert_Last( struct Node  **First  ,  int  No )
{
        struct Node *NewN = NULL;                                                  // Creating  Pointer for New Node

        NewN = (struct Node*)malloc(sizeof(struct Node));                          // Allocation Dynamic Memory for New Node in Data Section (Heap) by malloc

        NewN ->Data = No;
        NewN ->Next = NULL;                                                        //  Setting Values to New Node

        if( NULL == *First )                                                       // Only Once means for inserting very 1st element in LL
        {
            *First  =  NewN;
        }
        else                                                                       // Works for every next element i.e. from 2nd elements onwards
        {
            struct Node *Temp = *First;

            while(Temp -> Next != NULL)
            {
                    Temp = Temp -> Next;
            }

            Temp -> Next  = NewN;
        }

        printf("\n %d Element Inserted at Last Position Successfully", No);

        LL_Ele_Cnt++;
        return;
}

void  Display_LL(struct  Node  *First)
{
        if( NULL == First )
        {
            printf("\n Given Link List is Already Empty!!!");
        }
        else
        {
            printf("\n Elements in Given Link List are => \n\t");

            while( First != NULL)
            {
                printf("  | %d |  ->", First -> Data);
                First = First -> Next;
            }
        }
        printf(" NULL ");
        return;
}

void  Delete_First(struct  Node **First)
{
        if(NULL  == *First)
        {
            printf("\n Link List Already Empty , Can't Delete any Element!!!");
        }
        else
        {
            struct Node *Temp = *First;

            *First = Temp -> Next;

            printf("\n\n Deleted First Element in LL is = %d.", Temp->Data);

            free(Temp);

            LL_Ele_Cnt--;
        }

        return;
}

void  Delete_Last(struct Node  **First)
{
        if(NULL  == *First)
        {
            printf("\n Link List Already Empty , Can't Delete any Element!!!");
        }
        else
        {
            struct Node *Temp = *First;

            if(Temp -> Next != NULL)
            {
                    while(Temp -> Next -> Next != NULL)
                    {
                                Temp = Temp -> Next;
                    }

                    printf("\n\n Deleted Last Element in LL is = %d.", Temp->Next->Data);
                    free(Temp->Next);

                    Temp->Next = NULL;
            }
            else
            {
                    printf("\n\n Deleted Last Element in LL is = %d.", Temp->Data);

                    free(Temp);
                    *First = NULL;
            }
            LL_Ele_Cnt--;
        }

        return;
}

void Insert_At_Position(struct Node **First, int No, int Pos)
{
        if( ( Pos <= 0 ) || (Pos > LL_Ele_Cnt + 1))
        {
            printf("\n\n Invalid Position Enter valid Position Value!!!");
        }
        else if(Pos == 1)
        {
            Insert_First(First, No);
        }
        else if(Pos == LL_Ele_Cnt+1)
        {
            Insert_Last(First, No);
        }
        else
        {
            struct Node *NewN = (struct Node*)malloc(sizeof(struct Node));
            NewN ->Data = No;
            NewN ->Next = NULL;

            struct Node *Temp = *First;

            while(Pos > 2)
            {
                Temp = Temp -> Next;
                Pos--;
            }

            NewN -> Next = Temp -> Next;
            Temp -> Next = NewN;

            LL_Ele_Cnt++;
        }

        return;
}

void Delete_At_Position(struct Node **First,int Pos)
{
        if( ( Pos <= 0 ) || (Pos > LL_Ele_Cnt))
        {
            printf("\n\n Invalid Position Enter valid Position Value!!!");
        }
        else if(Pos == 1)
        {
            Delete_First(First);
        }
        else if(Pos == LL_Ele_Cnt)
        {
            Delete_Last(First);
        }
        else
        {
            struct Node *Temp1 = *First, *Temp2 = *First;

            while(Pos > 2)
            {
                        Temp1 = Temp1 -> Next;
                        Temp2 = Temp2 -> Next;
                        Pos--;
            }

            Temp2 = Temp2 -> Next;

            printf("\n\n Deleted Element in LL is = %d.", Temp2->Data);

            Temp1 -> Next = Temp2 -> Next;

            free(Temp2);
        }

        return;
}

int main()
{
                int Num = 0, Loc = 0;
                char ch = '0';

                struct Node *Head = NULL;

            Up:
                printf("\n\n ******************** WELCOME FORK Link List App ******************** \n ");

                printf("\n Choices => ");
                printf("\n\t 1. Insert First \n\t 2. Insert Last \n\t 3. Insert At Position \n\t 4. Delete First \n\t 5. Delete Last \n\t 6. Delete At Position \n\t 7. Display Link List \n\t 8. Exit \n");

                printf("\n ******************************************************************** \n");
                printf("\n Enter Choice => ");
                ch = getche();

                switch(ch)
                {
                         case '1':
                                    printf("\n Enter Value To Insert at 1st Position in Link List = ");
                                    scanf("%d",&Num);

                                    Insert_First(&Head, Num);
                                    getch();

                                    fflush(stdin);
                                    system("cls");
                                    goto Up;

                        case '2':
                                    printf("\n Enter Value To Insert at Last Position in Link List = ");
                                    scanf("%d",&Num);

                                    Insert_Last(&Head, Num);
                                    getch();

                                    fflush(stdin);
                                    system("cls");
                                    goto Up;

                        case '3':
                                    printf("\n Enter Location To Insert Your Value in Link List Between ( 1 To %d) = ", LL_Ele_Cnt+1);
                                    scanf("%d",&Loc);
                                    printf("\n Enter Value To Insert at %d Position in Link List = ", Loc);
                                    scanf("%d",&Num);

                                    Insert_At_Position(&Head, Num, Loc);
                                    getch();

                                    fflush(stdin);
                                    system("cls");
                                    goto Up;

                        case '4':
                                    Delete_First(&Head);
                                    getch();

                                    fflush(stdin);
                                    system("cls");
                                    goto Up;

                        case '5':
                                    Delete_Last(&Head);
                                    getch();

                                    fflush(stdin);
                                    system("cls");
                                    goto Up;

                        case '6':
                                    printf("\n Enter Location Which Element in Link List to be Deleted Between ( 1 To %d) = ", LL_Ele_Cnt);
                                    scanf("%d",&Loc);

                                    Delete_At_Position(&Head, Loc);
                                    getch();

                                    fflush(stdin);
                                    system("cls");
                                    goto Up;

                        case '7':
                                    Display_LL(Head);
                                    getch();

                                    fflush(stdin);
                                    system("cls");
                                    goto Up;

                        case '8':
                                    printf("\n\n Are You Sure Do You Want Exit(Yes/No) : ");
                                    ch = getchar();

                                    if(ch == 'Y' || ch == 'y')
                                    {
                                        break;
                                    }

                                    fflush(stdin);
                                    system("cls");
                                    goto Up;

                        default :
                                    printf("\n\n Invalid Choice, Select Correct Option... \n Press Any Key To Continue ");

                                    getch();
                                    fflush(stdin);
                                    system("cls");
                                    goto Up;
                }

                printf("\n\n Thanks For Interacting With Our Link List App");

                getch();
                return 0;
}
