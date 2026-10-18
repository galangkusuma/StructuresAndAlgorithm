#include <stdio.h>
#include <stdlib.h>

    struct node {
        int info;
        struct node *prev;
        struct node *link;
    };

    struct node *start = NULL;

    struct node *NewNode(int data)
    {
        struct node *tmp = (struct node*)malloc(sizeof(struct node));
        if (!tmp) {
            printf("Memory allocation failed\n");
            return NULL;
        }
        tmp->info = data;
        tmp->prev = NULL;
        tmp->link = NULL;
        return tmp;
    }

    void FreeList(struct node **head)
    {
        struct node *tmp;
        while (*head != NULL) {
            tmp = *head;
            *head = (*head)->link;
            free(tmp);
        }
    }

    void Create_List(int data)
    {
        struct node *q, *tmp;
        tmp = NewNode(data);
        if (tmp == NULL)
            return;
        if (start == NULL) {
            start = tmp;
        } else {
            q = start;
            while (q->link != NULL)
                q = q->link;
            q->link = tmp;
            tmp->prev = q;
        }
    }

    void Concat(struct node **second)
    {
        struct node *last;
        if (*second == NULL)
            return;
        if (start == NULL) {
            start = *second;
        } else {
            last = start;
            while (last->link != NULL)
                last = last->link;
            last->link = *second;
            (*second)->prev = last;
        }
        *second = NULL;
    }

    void AddAtBeg(int data)
    {
        struct node *tmp = (struct node*)malloc(sizeof(struct node));
        if (!tmp) {
            printf("Memory allocation failed\n");
            return;
        }
        tmp->info = data;
        tmp->prev = NULL;
        tmp->link = start;
        if (start != NULL)
            start->prev = tmp;
        start = tmp;
    }

    void AddAfter(int data, int pos)
    {
        struct node *tmp, *q;
        int i;
        if (start == NULL) {
            printf("List is empty\n");
            return;
        }
        q = start;
        for (i = 1; i < pos; ++i) {
            if (q == NULL) {
                printf("There are less than %d elements\n", pos);
                return;
            }
            q = q->link;
        }
        if (q == NULL) {
            printf("Position %d not found\n", pos);
            return;
        }
        tmp = (struct node*)malloc(sizeof(struct node));
        if (!tmp) {
            printf("Memory allocation failed\n");
            return;
        }
        tmp->info = data;
        tmp->prev = q;
        tmp->link = q->link;
        if (q->link != NULL)
            q->link->prev = tmp;
        q->link = tmp;
    }

    void DelValue(int data)
    {
        struct node *tmp, *q;
        if (start == NULL) {
            printf("List is empty\n");
            return;
        }
        if (start->info == data) {
            tmp = start;
            start = start->link;
            if (start != NULL)
                start->prev = NULL;
            free(tmp);
            printf("Element %d deleted\n", data);
            return;
        }
        q = start;
        while (q->link != NULL && q->link->info != data)
            q = q->link;
        if (q->link == NULL) {
            printf("Element %d not found\n", data);
            return;
        }
        tmp = q->link;
        q->link = tmp->link;
        if (q->link != NULL)
            q->link->prev = q;
        free(tmp);
        printf("Element %d deleted\n", data);
    }

    void DelFirst()
    {
        struct node *tmp;
        if (start == NULL) {
            printf("List is empty\n");
            return;
        }
        tmp = start;
        start = start->link;
        if (start != NULL)
            start->prev = NULL;
        printf("Deleted first element: %d\n", tmp->info);
        free(tmp);
    }

    void DelLast()
    {
        struct node *tmp, *q;
        if (start == NULL) {
            printf("List is empty\n");
            return;
        }
        if (start->link == NULL) {
            printf("Deleted last element: %d\n", start->info);
            free(start);
            start = NULL;
            return;
        }
        q = start;
        while (q->link->link != NULL)
            q = q->link;
        tmp = q->link;
        q->link = NULL;
        tmp->prev = NULL;
        printf("Deleted last element: %d\n", tmp->info);
        free(tmp);
    }

    void DelPosition(int position)
    {
        struct node *q = start;
        int i;
        if (position < 1 || start == NULL) {
            printf("Invalid position or empty list\n");
            return;
        }
        for (i = 1; q != NULL && i < position; ++i)
            q = q->link;
        if (q == NULL) {
            printf("Position %d not found\n", position);
            return;
        }
        if (q->prev != NULL)
            q->prev->link = q->link;
        else
            start = q->link;
        if (q->link != NULL)
            q->link->prev = q->prev;
        printf("Deleted element at position %d: %d\n", position, q->info);
        free(q);
    }

    void Display()
    {
        struct node *q = start;
        if (start == NULL) {
            printf("List is empty\n");
            return;
        }
        printf("List (forward): ");
        while (q != NULL) {
            printf("%d ", q->info);
            q = q->link;
        }
        printf("\n");

        printf("List (backward): ");
        q = start;
        while (q->link != NULL)
            q = q->link;
        while (q != NULL) {
            printf("%d ", q->info);
            q = q->prev;
        }
        printf("\n");
    }

    int Count()
    {
        struct node *q = start;
        int cnt = 0;
        while (q != NULL) {
            ++cnt;
            q = q->link;
        }
        return cnt;
    }

    void Rev()
    {
        struct node *current = start;
        struct node *new_start = NULL;

        while (current != NULL) {
            struct node *next = current->link;
            current->link = current->prev;
            current->prev = next;
            new_start = current;
            current = next;
        }
        start = new_start;
    }

    void Search(int data)
    {
        struct node *ptr = start;
        int pos = 1;
        while (ptr != NULL) {
            if (ptr->info == data) {
                printf("Item %d found at position %d\n", data, pos);
                return;
            }
            ptr = ptr->link;
            pos++;
        }
        printf("Item %d not found in list\n", data);
    }

    void FindMinMax(int *min, int *max)
    {
        struct node *q = start;
        if (q == NULL) {
            *min = *max = 0;
            return;
        }
        *min = *max = q->info;
        q = q->link;
        while (q != NULL) {
            if (q->info < *min) *min = q->info;
            if (q->info > *max) *max = q->info;
            q = q->link;
        }
    }

    double Average()
    {
        struct node *q = start;
        long sum = 0;
        int cnt = 0;
        while (q != NULL) {
            sum += q->info;
            ++cnt;
            q = q->link;
        }
        if (cnt == 0) return 0.0;
        return (double)sum / (double)cnt;
    }

    int main()
    {
        int choice, n, m, position, i;
        int minv, maxv;
        start = NULL;
        while (1) {
            printf("\n1.Create List (append)\n");
            printf("2.Add at beginning\n");
            printf("3.Add after (position)\n");
            printf("4.Delete specific value\n");
            printf("5.Delete first\n");
            printf("6.Delete last\n");
            printf("7.Display\n");
            printf("8.Count\n");
            printf("9.Reverse\n");
            printf("10.Search\n");
            printf("11.Min\n");
            printf("12.Max\n");
            printf("13.Average\n");
            printf("14.Concatenate another list\n");
            printf("15.Delete by position\n");
            printf("16.Quit\n");
            printf("Enter your choice: ");
            if (scanf("%d", &choice) != 1) {
                printf("Invalid input. Exiting.\n");
                break;
            }
            switch (choice) {
                case 1:
                    printf("How many nodes you want: ");
                    if (scanf("%d", &n) != 1 || n < 0) {
                        printf("Enter a non-negative number of nodes.\n");
                        break;
                    }
                    for (i = 0; i < n; i++) {
                        printf("Enter the element: ");
                        if (scanf("%d", &m) != 1) {
                            printf("Invalid input. Exiting.\n");
                            while (start != NULL) {
                                struct node *tmp = start;
                                start = start->link;
                                free(tmp);
                            }
                            return 1;
                        }
                        Create_List(m);
                    }
                    break;
                case 2:
                    printf("Enter the element: ");
                    if (scanf("%d", &m) != 1) {
                        printf("Invalid input. Exiting.\n");
                        break;
                    }
                    AddAtBeg(m);
                    break;
                case 3:
                    printf("Enter the element: ");
                    if (scanf("%d", &m) != 1) {
                        printf("Invalid input. Exiting.\n");
                        break;
                    }
                    printf("Enter the position after which this element is inserted: ");
                    if (scanf("%d", &position) != 1) {
                        printf("Invalid input. Exiting.\n");
                        break;
                    }
                    if (position < 1) {
                        printf("Position must be at least 1\n");
                        break;
                    }
                    AddAfter(m, position);
                    break;
                case 4:
                    if (start == NULL) { printf("List is empty\n"); break; }
                    printf("Enter the element for deletion: ");
                    if (scanf("%d", &m) != 1) {
                        printf("Invalid input. Exiting.\n");
                        break;
                    }
                    DelValue(m);
                    break;
                case 5:
                    DelFirst();
                    break;
                case 6:
                    DelLast();
                    break;
                case 7:
                    Display();
                    break;
                case 8:
                    printf("Number of elements are %d\n", Count());
                    break;
                case 9:
                    Rev();
                    printf("List reversed\n");
                    break;
                case 10:
                    printf("Enter the element to be searched: ");
                    if (scanf("%d", &m) != 1) {
                        printf("Invalid input. Exiting.\n");
                        break;
                    }
                    Search(m);
                    break;
                case 11:
                    if (start == NULL) { printf("List is empty\n"); break; }
                    FindMinMax(&minv, &maxv);
                    printf("Minimum = %d\n", minv);
                    break;
                case 12:
                    if (start == NULL) { printf("List is empty\n"); break; }
                    FindMinMax(&minv, &maxv);
                    printf("Maximum = %d\n", maxv);
                    break;
                case 13:
                    if (start == NULL) { printf("List is empty\n"); break; }
                    printf("Average = %.2f\n", Average());
                    break;
                case 14:
                {
                    struct node *second = NULL;
                    struct node *tmp;
                    int count;
                    printf("How many nodes in the second list: ");
                    if (scanf("%d", &count) != 1 || count < 0) {
                        printf("Enter a non-negative number of nodes.\n");
                        break;
                    }
                    for (i = 0; i < count; ++i) {
                        printf("Enter the element: ");
                        if (scanf("%d", &m) != 1) {
                            printf("Invalid input. Exiting.\n");
                            FreeList(&second);
                            FreeList(&start);
                            return 1;
                        }
                        tmp = NewNode(m);
                        if (tmp == NULL)
                            break;
                        if (second == NULL) {
                            second = tmp;
                        } else {
                            struct node *last = second;
                            while (last->link != NULL)
                                last = last->link;
                            last->link = tmp;
                            tmp->prev = last;
                        }
                    }
                    Concat(&second);
                    printf("Lists concatenated\n");
                    break;
                }
                case 15:
                    printf("Enter the position to delete: ");
                    if (scanf("%d", &position) != 1) {
                        printf("Invalid input. Exiting.\n");
                        break;
                    }
                    DelPosition(position);
                    break;
                case 16:
                    FreeList(&start);
                    return 0;
                default:
                    printf("Wrong choice\n");
            }
        }
        return 0;
    }
