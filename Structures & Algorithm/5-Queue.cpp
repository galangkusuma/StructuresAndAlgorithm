//FIFO, Array & Pointer disesuaikan dengan projek
// PROGRAM 4.2
// PROGRAM TO IMPLEMENT CIRCULAR QUEUE USING ARRAY

#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 5

// A class is created for the circular queue
class circular_queue
{
    int cqueue_arr[MAX];
    int front, rear;

public:
    // Constructor to initialize the variables
    circular_queue()
    {
        front = -1;
        rear = -1;
    }

    // Function declarations
    void insert();
    void del();
    void display();
};

// Function to insert an element into the circular queue
void circular_queue::insert()
{
    int added_item;

    // Checking for overflow condition
    if ((front == 0 && rear == MAX - 1) ||
        (front == rear + 1))
    {
        cout << "\nQueue Overflow\n";
        return;
    }

    if (front == -1) // If queue is empty
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX - 1) // rear is at last position
    {
        rear = 0;
    }
    else
    {
        rear = rear + 1;
    }

    cout << "\nInput the element for insertion in queue: ";
    cin >> added_item;

    cqueue_arr[rear] = added_item;
}

// Function to delete an element from the queue
void circular_queue::del()
{
    // Checking for queue underflow
    if (front == -1)
    {
        cout << "\nQueue Underflow\n";
        return;
    }

    cout << "\nElement deleted from queue is: "
         << cqueue_arr[front] << "\n";

    if (front == rear) // Queue has only one element
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front = front + 1;
    }
}

// Function to display the elements in the queue
void circular_queue::display()
{
    int front_pos = front;
    int rear_pos = rear;

    // Checking whether the circular queue is empty
    if (front == -1)
    {
        cout << "\nQueue is empty\n";
        return;
    }

    cout << "\nQueue elements:\n";

    if (front_pos <= rear_pos)
    {
        while (front_pos <= rear_pos)
        {
            cout << cqueue_arr[front_pos] << ", ";
            front_pos++;
        }
    }
    else
    {
        while (front_pos <= MAX - 1)
        {
            cout << cqueue_arr[front_pos] << ", ";
            front_pos++;
        }

        front_pos = 0;

        while (front_pos <= rear_pos)
        {
            cout << cqueue_arr[front_pos] << ", ";
            front_pos++;
        }
    }

    cout << "\n";
}

// Main function
int main()
{
    int choice;

    // Creating object for the circular queue
    circular_queue co;

    while (true)
    {
        cout << "\n1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Quit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            co.insert();
            break;

        case 2:
            co.del();
            break;

        case 3:
            co.display();
            break;

        case 4:
            exit(0);

        default:
            cout << "\nWrong choice\n";
        }
    }

    return 0;
}