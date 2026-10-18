    // Singly linked list implementation with additional operations:
    // - find minimum and maximum values
    // - compute average
    // - delete first node, delete last node, delete specific value
    // Compatible with modern GCC (uses stdio.h and stdlib.h)

    #include <stdio.h>
    #include <stdlib.h>

    struct node {
        int info;
        struct node *link;
    };

    struct node *start = NULL;

    void Create_List(int data)
    {
        struct node *q, *tmp;
        tmp = (struct node*)malloc(sizeof(struct node));
        if (!tmp) {
            printf("Memory allocation failed\n");
            return;
        }
        tmp->info = data;
        tmp->link = NULL;
        if (start == NULL) {
            start = tmp;
        } else {
            q = start;
            while (q->link != NULL)
                q = q->link;
            q->link = tmp;
        }
    }

    void AddAtBeg(int data)
    {
        struct node *tmp = (struct node*)malloc(sizeof(struct node));
        if (!tmp) {
            printf("Memory allocation failed\n");
            return;
        }
        tmp->info = data;
        tmp->link = start;
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
        tmp->link = q->link;
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
        printf("Deleted last element: %d\n", tmp->info);
        free(tmp);
    }

    void Display()
    {
        struct node *q = start;
        if (start == NULL) {
            printf("List is empty\n");
            return;
        }
        printf("List: ");
        while (q != NULL) {
            printf("%d ", q->info);
            q = q->link;
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
        struct node *p1, *p2, *p3;
        if (start == NULL || start->link == NULL)
            return;
        p1 = start;
        p2 = p1->link;
        p3 = p2->link;
        p1->link = NULL;
        p2->link = p1;
        while (p3 != NULL) {
            p1 = p2;
            p2 = p3;
            p3 = p3->link;
            p2->link = p1;
        }
        start = p2;
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
            printf("14.Quit\n");
            printf("Enter your choice: ");
            if (scanf("%d", &choice) != 1) break;
            switch (choice) {
                case 1:
                    printf("How many nodes you want: ");
                    if (scanf("%d", &n) != 1) break;
                    for (i = 0; i < n; i++) {
                        printf("Enter the element: ");
                        scanf("%d", &m);
                        Create_List(m);
                    }
                    break;
                case 2:
                    printf("Enter the element: ");
                    scanf("%d", &m);
                    AddAtBeg(m);
                    break;
                case 3:
                    printf("Enter the element: ");
                    scanf("%d", &m);
                    printf("Enter the position after which this element is inserted: ");
                    scanf("%d", &position);
                    AddAfter(m, position);
                    break;
                case 4:
                    if (start == NULL) { printf("List is empty\n"); break; }
                    printf("Enter the element for deletion: ");
                    scanf("%d", &m);
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
                    scanf("%d", &m);
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
                    /* free remaining nodes */
                    while (start != NULL) {
                        struct node *tmp = start;
                        start = start->link;
                        free(tmp);
                    }
                    return 0;
                default:
                    printf("Wrong choice\n");
            }
        }
        return 0;
    }
