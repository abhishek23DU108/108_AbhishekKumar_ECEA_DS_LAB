
#include<stdio.h>
int rows, cols;
void createSparseMat(int rows, int cols, int arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = 0;
        }
    }
}

void setValue(int rows, int cols, int arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j == 1)
                arr[i][j] = 5;
        }
    }
}
int getValue(int row, int col, int arr[rows][cols]) {
    return arr[row][col];
}

int addValue(int row, int col,int arr[rows][cols],int item)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(i==row && j==col)
            arr[i][j]=item;
        }
    }
}
int removeValue(int row, int col,int arr[rows][cols])
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(i==row && j==col)
            arr[i][j]=0;
        }
    }
}
int getNumRows()
{
    return rows;
}
int getNumCols()
{
    return cols;
}
int transpose(int arr[rows][cols])
{
   for(int i=0;i<cols;i++)
    {
        for(int j=0;j<rows;j++)
        {
            printf("%d ",arr[j][i]);
        }
        printf("\n");
    }
}
int multiplyScalar(int arr[rows][cols],int factor)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            arr[i][j]= factor*arr[i][j];
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
int add(int arr[rows][cols], int arr2[rows][cols])
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
        printf("%d ",(arr2[i][j] + arr[i][j]));
        }
        printf("\n");
    }
}
int multiply(int arr[rows][cols], int arr2[rows][cols])
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            int sum=0;
            for (int k = 0; k < rows; k++) {
                sum = sum + arr[i][k] * arr2[k][j];
            }
            printf("%d ", sum);
        }
        printf("\n");
    }
}
int denseArray(int arr[rows][cols])
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
        if(arr[i][j]!=0)
        {
        printf("%d ",arr[i][j]);
        }
        }
    }
}
int main() {
    int row, col;
    printf("Enter the number of rows and columns for a square matrix: ");
    scanf("%d %d", &rows, &cols);
    int arr[rows][cols];
    int arr2[rows][cols];
    createSparseMat(rows, cols, arr);
    createSparseMat(rows, cols, arr2);
    setValue(rows, cols, arr);
    setValue(rows, cols, arr2);
    printf("Enter the position (row and column) for the desired element: ");
    scanf("%d %d", &row, &col);
    int value = getValue(row, col, arr);
    printf("Value at position (%d, %d) is %d\n", row, col, value);
    printf("Enter the element which you want to insert");
    int item;
    scanf("%d",&item);
    addValue(row,col,arr,item);
    value = getValue(row, col, arr);
    printf("Value at position (%d, %d) is %d\n", row, col, value);
    removeValue(row,col,arr);
    value = getValue(row, col, arr);
    printf("Value at position (%d, %d) after removing is %d\n", row, col, value);
    printf("Transpose Matrix\n");
    transpose(arr);
    printf("Matrix after values are doubled\n");
    multiplyScalar(arr,2);
    printf("Matrix after addition\n");
    add(arr,arr2);
    printf("Matrix after multiplication\n");
    multiply(arr,arr2);
    printf("Dense array : \n");
    denseArray(arr);
    return 0;
}