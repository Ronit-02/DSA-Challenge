// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    void recurSubsets(vector<int> &arr, vector<int> &temp, int index, vector<vector<int>> &ans) {
        
        ans.push_back(temp);
        
        if(index == arr.size())
            return;
        
        for(int i = index; i < arr.size(); i++) {
            
            if(i > index and arr[i]==arr[i-1])
                continue;           // For Repeated Elements
            temp.push_back(arr[i]);
            recurSubsets(arr, temp, i+1, ans);
            temp.pop_back();
        }
        return;
    }
    
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        vector<vector<int>>ans;
        vector<int>temp;
        
        sort(arr.begin(), arr.end());
        int index = 0; 
        recurSubsets(arr, temp, index, ans);
        
        return ans; 
    }
};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends