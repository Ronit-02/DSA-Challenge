// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
    bool allocateTime(int arr[], int n, int k, long long int mid){
        
        long long int painterscount = 0;
        long long int ttime = 0;
        
        for(int i=0; i<n; i++){
            
            if(ttime + arr[i] <= mid){
                ttime += arr[i];
            }
            else{
                painterscount++;
                if(painterscount >= k || arr[i] > mid)
                    return false;
                    
                ttime = arr[i];
            }
        }
        return true;
    }
  
    long long minTime(int arr[], int n, int k)
    {
        long long int sum = 0;         // total time
        for(int i=0; i<n; i++)
            sum += arr[i];
            
        long long int ans = -1;
        long long int s = 0;
        long long int e = sum;
        long long int mid = s + (e-s)/2;
        
        while(s <= e){
            
            if(allocateTime(arr, n, k, mid)){     //if time allocated is possible
                ans = mid;
                e = mid-1;
            }
            else
                s = mid+1;
            
            mid = s + (e-s)/2;
        }
        return ans;
        
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends