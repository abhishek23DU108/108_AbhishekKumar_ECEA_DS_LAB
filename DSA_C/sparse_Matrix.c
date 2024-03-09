

// #include<stdio.h>
// int main()
// {
//     int arr[4][4]={{0,0,3,4},{5,0,7,0},{0,6,0,7},{6,0,0,0}};
//     int size=0,elements=0;
//     for(int i=0;i<4;i++)
//     {
//         for(int j=0;j<4;j++)
//         {
//             if(arr[i][j]!=0)
//             {
//                 size++;
//             }
//             else
//             elements++;
//         }
//     }
//     int sparse[3][size];
//     int k=0;
//     if(elements>8)
//     {
//     printf("Sparse Matrix : \n");
//     for(int i=0;i<4;i++)
//     {
//         for(int j=0;j<4;j++)
//         {
//             if(arr[i][j]!=0)
//             {
//                 sparse[0][k]=i;
//                 sparse[1][k]=j;
//                 sparse[2][k]=arr[i][j];
//                 k++;
//             }
//         }
//     }
//     for(int i=0;i<3;i++)
//     {
//         for(int j=0;j<size;j++)
//         {
//             printf("%d ",sparse[i][j]);
//         }
//         printf("\n");
//     }
//     }
//     else
//     {
//         printf("It is not a sparse matrix");
//     }
    
// }



#include<stdio.h>
int main(){
    int m,n;
    printf("enter the number of rows:\n");
    scanf("%d",&m);
    printf("enter the number of columns:\n");
    scanf("%d",&n);
    int arr[m][n];
    printf("enter the elements of the matrix:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }printf("the matrix you entered is:\n");
    int zero=0,nzero=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",arr[i][j]);
            if(arr[i][j]==0)
                zero++;
            else
                nzero++;
        }printf("\n");
    }if(zero>nzero){
        printf("the matrix is a sparse matrix:\n");
        int s[3][nzero],k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]!=0){
                    s[0][k]=i;
                    s[1][k]=j;
                    s[2][k]=arr[i][j];
                    k++;
                }
            }
        }printf("the sparse matrix is:\n");
        for(int i=0;i<3;i++){
            for(int j=0;j<nzero;j++){
                printf("%d\t",s[i][j]);
            }printf("\n");
        }
        }
}