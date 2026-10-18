//+Time taken to executesolve the tower of hanoi. Is it linear or exponential.
#include <iostream>
using namespace std;

const int MAX_DISKS = 100;

class Stack
{
private:
    int items[MAX_DISKS];
    int top;

public:
    Stack() : top(-1) {}

    bool isEmpty() const
    {
        return top == -1;
    }

    bool push(int disk)
    {
        if (top == MAX_DISKS - 1)
        {
            return false;
        }

        items[++top] = disk;
        return true;
    }

    bool pop(int &disk)
    {
        if (isEmpty())
        {
            return false;
        }

        disk = items[top--];
        return true;
    }

    void traverse() const
    {
        if (isEmpty())
        {
            cout << "empty";
            return;
        }

        for (int index = top; index >= 0; --index)
        {
            cout << items[index] << ' ';
        }
    }
};

class TowerOfHanoi
{
private:
    Stack towers[3];
    int numberOfDisks;

    int towerIndex(char towerName) const
    {
        if (towerName == 'X')
        {
            return 0;
        }
        if (towerName == 'Y')
        {
            return 1;
        }
        return 2;
    }

    void moveDisk(char from, char to)
    {
        int disk;
        Stack &source = towers[towerIndex(from)];
        Stack &destination = towers[towerIndex(to)];

        source.pop(disk);
        destination.push(disk);

        cout << "Move disk " << disk << " from tower " << from
             << " to tower " << to << '\n';
    }

    void solve(int disks, char from, char to, char auxiliary)
    {
        if (disks == 0)
        {
            return;
        }

        solve(disks - 1, from, auxiliary, to);
        moveDisk(from, to);
        solve(disks - 1, auxiliary, to, from);
    }

public:
    explicit TowerOfHanoi(int disks) : numberOfDisks(disks) {}

    void setup()
    {
        for (int disk = numberOfDisks; disk >= 1; --disk)
        {
            towers[0].push(disk);
        }
    }

    void traverse() const
    {
        cout << "\nTower X (top to bottom): ";
        towers[0].traverse();
        cout << "\nTower Y (top to bottom): ";
        towers[1].traverse();
        cout << "\nTower Z (top to bottom): ";
        towers[2].traverse();
        cout << '\n';
    }

    void solve()
    {
        solve(numberOfDisks, 'X', 'Z', 'Y');
    }
};

int main()
{
    int numberOfDisks;

    cout << "Enter the number of disks you want to move from X to Z (1-" << MAX_DISKS << "): ";
    cin >> numberOfDisks;

    if (!cin || numberOfDisks < 1 || numberOfDisks > MAX_DISKS)
    {
        cout << "Invalid number of disks.\n";
        return 1;
    }

    TowerOfHanoi game(numberOfDisks);
    game.setup();

    cout << "\nInitial stacks:";
    game.traverse();

    cout << "\nMoves:\n";
    game.solve();

    cout << "\nFinal stacks:";
    game.traverse();
    return 0;
}