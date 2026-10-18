#include <iostream>
#include <cstdlib>
using namespace std;

#define MAXSIZE 100

class STACK_ARRAY
{
    int stack[MAXSIZE];
    int Top;

public:
    STACK_ARRAY()
    {
        Top = -1;
    }

    void push();
    void pop();
    void traverse();
};

// PUSH operation
void STACK_ARRAY::push()
{
    int item;

    if (Top == MAXSIZE - 1)
    {
        cout << "\nThe Stack Is Full";
    }
    else
    {
        cout << "\nEnter The Element To Be Inserted = ";
        cin >> item;

        stack[++Top] = item;
    }
}

// POP operation
void STACK_ARRAY::pop()
{
    int item;

    if (Top == -1)
    {
        cout << "\nThe Stack Is Empty";
    }
    else
    {
        item = stack[Top--];

        cout << "\nThe Deleted Element Is = " << item;
    }
}

// TRAVERSE operation
void STACK_ARRAY::traverse()
{
    int i;

    if (Top == -1)
    {
        cout << "\nThe Stack Is Empty";
    }
    else
    {
        cout << "\n\nThe Element(s) In The Stack(s) is/are...";

        for (i = Top; i >= 0; i--)
        {
            cout << "\n " << stack[i];
        }
    }
}

int main()
{
    int choice;
    char ch;

    STACK_ARRAY ps;

    do
    {
        system("cls");

        cout << "\n1. PUSH";
        cout << "\n2. POP";
        cout << "\n3. TRAVERSE";
        cout << "\n4. EXIT";

        cout << "\nEnter Your Choice = ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                ps.push();
                break;

            case 2:
                ps.pop();
                break;

            case 3:
                ps.traverse();
                break;

            case 4:
                exit(0);

            default:
                cout << "\nWrong Choice";
        }

        cout << "\n\nDo you want to continue (Y/y) = ";
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');

    return 0;
}