// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int partition(long long a[], int lo, int hi, int pivot){
        
        long long i = lo;
        long long j = lo;
        while(i <= hi){
            
            if(a[i] <= pivot){       // if smaller or equal -> swap
                swap(a[i], a[j]);
                i++;
                j++;
            }
            else                       // if larger -> dont swap
                i++;
        }
        return (j-1);      // correct position of pivot element
    }
    int quickSelect(long long a[], long long lo, long long hi, long long k){
     
        long long pivot = a[hi];
        long long pi = partition(a, lo, hi, pivot); 
        
        if(pi == k)         
            return pivot;
        else if(pi > k)   
            return quickSelect(a, lo, pi-1, k);
        else
            return quickSelect(a, pi+1, hi, k);
    }
    
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
     
        int n1 = quickSelect(A, 0, N-1, K1-1);
        int n2 = quickSelect(A, 0, N-1, K2-1);
        
        long long i = 0;
        long long sum = 0;
        
        while(i < N){
            
            if(A[i] == n1){
                
                i++;
                while(A[i] != n2){
                    sum += A[i];
                    i++;
                }
                break;
            }
            i++;
        }
        
        return sum;
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends