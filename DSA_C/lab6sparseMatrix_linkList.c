#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int row_position;
    int col_position;
    int value;
    struct Node *next;
};

void create_new_node(struct Node **start, int non_zero_element, int row_index, int col_index)
{
    struct Node *temp, *r;
    temp = *start;
    if (temp == NULL)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->value = non_zero_element;
        temp->row_position = row_index;
        temp->col_position = col_index;
        temp->next = NULL;
        *start = temp;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        r = (struct Node *)malloc(sizeof(struct Node));
        r->value = non_zero_element;
        r->row_position = row_index;
        r->col_position = col_index;
        r->next = NULL;
        temp->next = r;
    }
}

void PrintList(struct Node *start)
{
    struct Node *temp, *r, *s;
    temp = r = s = start;

    printf("row_position: ");
    while (temp != NULL)
    {

        printf("%d ", temp->row_position);
        temp = temp->next;
    }
    printf("\n");

    printf("column_position: ");
    while (r != NULL)
    {
        printf("%d ", r->col_position);
        r = r->next;
    }
    printf("\n");
    printf("Value: ");
    while (s != NULL)
    {
        printf("%d ", s->value);
        s = s->next;
    }
    printf("\n");
}

int main()
{
    int m, n, counter = 0;

    printf("Enter the size of the array as 'Rows' & 'Column' respectively:\n");
    scanf("%d%d", &m, &n);

    int sparseMatric[m][n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &sparseMatric[i][j]);
        }
    }

    printf("The enetered 2D array is: \n");

    for (int i = 0; i < m; i++)
    {
        printf("         ");
        for (int j = 0; j < n; j++)
        {
            printf("%d ", sparseMatric[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (sparseMatric[i][j] != 0)
            {
                ++counter;
            }
        }
    }

    if (counter <= (m * n) / 2)
    {
        printf("The entered 2D array is a sparse matrix.\n\n");

        struct Node *start = NULL;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (sparseMatric[i][j] != 0)
                {
                    create_new_node(&start, sparseMatric[i][j], i, j);
                }
            }
        }
        PrintList(start);
    }
    else
    {
        printf("The entered matrix is not a sparse matrix.\n");
    }

    return 0;
}