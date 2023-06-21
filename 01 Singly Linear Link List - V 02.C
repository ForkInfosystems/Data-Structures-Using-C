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

int main()
{
                struct Node *Head = NULL;

                Display_LL(Head);

                getch();

                Insert_First(&Head, 10);
                Insert_Last(&Head, 20);

                Insert_First(&Head, 30);
                Insert_Last(&Head, 40);

                Insert_First(&Head, 50);
                Insert_Last(&Head, 60);

                system("cls");
                Display_LL(Head);
                getch();

                Delete_First(&Head);

                Display_LL(Head);
                getch();

                Delete_Last(&Head);

                Display_LL(Head);
                getch();
                system("cls");
                Display_LL(Head);

                getch();
                return 0;
}
