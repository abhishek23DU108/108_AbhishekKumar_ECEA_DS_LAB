#include<stdio.h>
int main()
{
    int  n,s;
     printf("Size of array to be entered");
     scanf("%d",&n);
     int arr[n];
     printf("enter the array");
     for (int i = 0; i < n; i++)
     {
         scanf("%d",&arr[i]);
     }
     for(int i=0;i<n-1;i++)           // bubble sort   iterates
    {
      for(int j=0;j<n-i-1;j++)
      {
        if(arr[j+1]<arr[j])
        {
        int t = arr[j+1];                 //swap
        arr[j+1]=arr[j];
        arr[j]=t;
        }
      }
    }
     printf("Enter the no. to be searched");
     scanf("%d",&s);
    int start = 0, end=n-1,c=0;
    while(end>=start)
    {
    int mid = (start+end)/2;
      if(arr[mid ]== s)
      {
        return mid;
      }
      if(arr[mid]<s)
      start=mid+1;
      else{
      end=mid-1;

      c=1;
      break;
     }}
 if(c==1) printf("No. Found");
 else printf("No. not found");
 }