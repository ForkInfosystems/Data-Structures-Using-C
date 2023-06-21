#include<stdio.h>
#include<conio.h>

struct Node
{
            int  Data;
            struct Node *Next;
};

int main()
{
            struct Node *Head = NULL;

            struct  Node Obj1;
            Obj1.Data = 21;
            Obj1.Next = NULL;

            Head = Obj1;

            struct  Node Obj2;
            Obj2.Data = 21;
            Obj2.Next = NULL;

            Obj1.Next = Obj2;

            struct  Node Obj3;
            Obj3.Data = 75;
            Obj3.Next = NULL;

            Obj2.Next = Obj3;

            struct  Node Obj4;
            Obj4.Data = 51;
            Obj4.Next = NULL;

            Obj4.Next = Obj3;
            Obj2.Next = Obj4;

            getch();
            return 0;
}
