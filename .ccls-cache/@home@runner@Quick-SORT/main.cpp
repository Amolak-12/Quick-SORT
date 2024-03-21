#include <iostream>
using namespace std;

   int Partition(int *arr , int s , int e)
   {
     //Step 1 : Choose Pivot element
     int pivotIndex = s;
     int pivotEle = arr[pivotIndex];

     //Step 2 : Find Right Position For Pivot Element
     int count = 0;
     for(int i = s+1;i<=e;i++)
       {
         if(arr[i] <= pivotEle)
         {
           count++;
         }
       }
     //Step 3 : Placed at right position
     int RightIndex = s+count;
     swap(arr[pivotIndex] , arr[RightIndex]);
     pivotIndex = RightIndex;
     int i = s;
     int j = e;

     while(i<pivotIndex && j>pivotIndex)
       {
         while(arr[i] <= pivotEle) 
         {
            i++ ;
         }
         while(arr[j] > pivotEle)
         {
           j-- ;
         }
         if(i<pivotIndex && j>pivotIndex)
         {
           swap(arr[i] , arr[j]);
         }
       }
     return pivotIndex;
   }
    void QuickSort(int *arr , int s , int e)
   {
     //Base Case
     // s == e -> single element
     // s > e -> invalid array
     if(s>=e)
     {
       return;
     }

     // Step 1
     //Partition logic
     int p = Partition(arr , s , e);

     // Step 2
     //Recursive Calls
       //Sub step 1 : left
       QuickSort(arr,s,p-1);
       //Sub step 2 : right
       QuickSort(arr,p+1,e);
   }

   int main() {
     int arr[] = {8,1,3,5,60,55,5,55,5,5,5,1,1,1,1,11,8,8,8,8,7,50,20,30};
     int n = sizeof(arr)/sizeof(int);
     int s = 0;
     int e = n-1;

     //Quick Sort
     QuickSort(arr,s,e);

     for(int i=0;i<n;i++)
       {
         cout << arr[i] << " ";
       }
     cout << endl;

 }