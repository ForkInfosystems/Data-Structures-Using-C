struct Node{
            int  Data;
            struct Node *Next;
};
void  Insert_First( struct Node  **First  ,  int  No );
void  Insert_Last( struct Node  **First  ,  int  No );
void  Display_LL(struct  Node  *First);
int  Count_LL_Nodes(struct  Node  *First);

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

