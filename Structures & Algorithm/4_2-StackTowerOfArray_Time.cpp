//Added Time taken to fully execute and solve the tower of hanoi
//After doing tests and calculations - it shows that the time taken to solve the tower of hanoi increases exponentially with the amount of disks added, not Linear. 
//This is also proven with the algorithm of the tower of hanoi, which is 'T(n)=2T(n−1)+1', which gives 'T(n)=2^n−1' [Linear: O(n)] [Exponential: O(2^n)]
//You can change the 'MAX_DISKS' value to increase or decrease the maximum disk when inputing
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

const int MAX_DISKS = 10;

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

    auto start = high_resolution_clock::now();

    cout << "\nInitial stacks:";
    game.traverse();

    cout << "\nMoves:\n";
    game.solve();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "\nFinal stacks:";
    game.traverse();

    cout << "\nTime taken to solve Tower of Hanoi for " << numberOfDisks
         << " disks: " << duration.count() << " milliseconds\n";

    cout << "\nNote: Number of moves = 2^n - 1, so the time grows exponentially.\n";

    return 0;
}