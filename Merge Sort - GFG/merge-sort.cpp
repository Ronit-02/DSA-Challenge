// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int len1 = m - l + 1;
        int len2 = r - m;
    
        vector<int> arr1(len1);
        vector<int> arr2(len2);
    
        int i, j, k = l;   // indexes for 3 arrays
    
        for(i = 0; i < len1; i++, k++)
            arr1[i] = arr[k];
    
        for(j = 0; j < len2; j++, k++)
            arr2[j] = arr[k];
    
    
        k = l;   // index of merged array
        i = 0;
        j = 0;
    
        while(i < len1 && j < len2){
            if(arr1[i] <= arr2[j])
                arr[k++] = arr1[i++];
            else
                arr[k++] = arr2[j++];
        }
    
        while(i < len1)
            arr[k++] = arr1[i++];
    
        while(j < len2)
            arr[k++] = arr2[j++];
    }
    void mergeSort(int arr[], int l, int r)
    {
        // Base Case  
        if(l >= r)  // when single element is sorted
            return;
    
        int m = l + (r-l)/2;
    
        // Left part 
        mergeSort(arr, l, m);
    
        // Right part
        mergeSort(arr, m+1, r);
    
        // Merging both parts
        merge(arr, l, m, r);
    }
    
};
// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends