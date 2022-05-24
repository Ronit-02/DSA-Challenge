// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool canAllocate(int arr[], int n, int m, int x){
        
        int tpages = 0;
        int studentCount = 0;
        
        for(int i=0; i<n; i++){
            
            if(tpages + arr[i] <= x)
                tpages += arr[i];
                
            else{
                studentCount++;
                if(studentCount >= m || arr[i] > x)
                    return false;
                    
                tpages = arr[i];
            }
                
        }
        
        return true;
        
    }
    
    int findPages(int a[], int n, int m){
        
        int sum = 0;
        for(int i=0; i<n; i++)
            sum += a[i];
            
        int ans = -1;
        int s = 0;
        int e = sum;
        int mid = s + (e-s)/2;
        
        while(s <= e){
            
            if(canAllocate(a, n, m, mid)){
                ans = mid;
                e = mid-1;
            }
            else
                s = mid+1;
                
            mid = s + (e-s)/2;
        }
        
        // int fans = 0;
        // for(int i=0; i<n; i++){
            
        //     if(fans + a[i] < ans)
        //         fans += a[i];
        // }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends