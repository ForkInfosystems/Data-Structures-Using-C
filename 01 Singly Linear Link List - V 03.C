#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
            int  Data;
            struct Node *Next;
};

void  Insert_First( struct Node  **First  ,  int  No )
{
            struct Node *NewN = NULL;                                                                      // Creating  Pointer for New Node

            NewN = (struct Node*)malloc(sizeof(struct Node));                          // Allocation Dynamic Memory for New Node in Data Section (Heap) by malloc

            NewN ->Data = No;
            NewN ->Next = NULL;                                                                             //  Setting Values to New Node

            if( NULL == *First )                                                 // Only Once means for inserting very 1st element in LL
            {
                        *First  =  NewN;
                        printf("\n\n Inside if block of insert first");
            }
            else                                                                                // Works for every next element i.e. from 2nd elements onwards
            {
                        NewN -> Next = *First;
                        *First = NewN;
            }

            printf("\n %d Element Inserted  at First Position Successfully", No);

            return;
}

void  Insert_Last( struct Node  **First  ,  int  No )
{
            struct Node *NewN = NULL;                                                                      // Creating  Pointer for New Node

            NewN = (struct Node*)malloc(sizeof(struct Node));                          // Allocation Dynamic Memory for New Node in Data Section (Heap) by malloc

            NewN ->Data = No;
            NewN ->Next = NULL;                                                                             //  Setting Values to New Node

            if( NULL == *First )                                                 // Only Once means for inserting very 1st element in LL
            {
                        *First  =  NewN;
                        printf("\n\n Inside if block of insert Last");
            }
            else                                                                                // Works for every next element i.e. from 2nd elements onwards
            {
                        struct Node *Temp = *First;

                        while(Temp -> Next != NULL)
                        {
                                    Temp = Temp -> Next;
                        }

                        Temp -> Next  = NewN;
            }

            printf("\n %d Element Inserted at Last Position Successfully", No);

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
                            }

                            printf("\n\n Deleted Last Element in LL is = %d.", Temp->Next->Data);

                            free(Temp->Next);

                            Temp->Next = NULL;
                }

                return;
}

int  Count_LL_Nodes(struct  Node  *First)
{
                int  Cnt = 0;

                if( First  !=  NULL)
                {
                            while( First != NULL)
                            {
                                        Cnt++;
                                        First = First -> Next;
                            }
                }

                return Cnt;
}

void  Insert_At_Position(struct Node **First, int Pos, int  Val)
{
                int Ele_Cnt = Count_LL_Nodes(*First);

                if(Pos <= 0)
                {
                            printf("\n Invalid Position To Insert!!!");
                }
                else  if(Pos == 1)
                {
                            Insert_First(First, Val);
                }
                else  if(Pos >= Ele_Cnt + 1)
                {
                            if(Pos == Ele_Cnt + 1)
                            {
                                        Insert_Last(First, Val);
                            }
                            else
                            {
                                        printf("\n Position You Wish is Not Valid Do You Want To Insert Element at Position %d ?? (Y/ N)", Ele_Cnt + 1);

                                        char ch = getchar();

                                        fflush(stdin);

                                        if(ch == 'y' || ch == 'Y')
                                        {
                                                    Insert_Last(First, Val);
                                        }
                                        else
                                        {
                                                    printf("\n Ok Then Your Element is Trashed Not Inserted in Current LL.");
                                        }
                            }
                }
                else
                {
                            printf("\n\n **Code Not Written Yet!!! Working!!!**\n");
                            printf("\n **Please Try Later To Insert Element = %d**\n", Val);
                }

                return;
}

int main()
{
                struct Node *Head = NULL;

        /*
                Insert_First(&Head, 10);
                Insert_Last(&Head, 20);

                Insert_First(&Head, 30);
                Insert_Last(&Head, 40);

                Insert_First(&Head, 50);
                Insert_Last(&Head, 60);
                */

                Insert_At_Position(&Head, 0 , 55);
                Insert_At_Position(&Head, 1 , 15);

                Insert_At_Position(&Head, 2 , 41);

                Insert_At_Position(&Head, 5 , 101);

                Insert_At_Position(&Head, 1 , 21);

                Insert_At_Position(&Head, 12 , 404);

                Insert_At_Position(&Head, 3, 884);

                Display_LL(Head);
                getch();

                /*Delete_First(&Head);

                Display_LL(Head);
                getch();

                Delete_Last(&Head);

                Display_LL(Head);
                getch();
                system("cls");
                Display_LL(Head);

                getch();
                */

                return 0;
}
