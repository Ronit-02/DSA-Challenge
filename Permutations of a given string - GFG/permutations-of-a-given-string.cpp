// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void recurPermute(string s, int index, vector<string> &ans, unordered_map<string, int> &set){
        
            // base case
            if(index == s.length()){
                if(set.find(s) == set.end()){
                    set[s] = 1;
                    ans.push_back(s);
                }
                return;
            }
            
            for(int j=index; j<s.length(); j++){
                
                swap(s[index], s[j]);
                recurPermute(s, index+1, ans, set);
                swap(s[index], s[j]);    // Backtracking
            }
        }
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
		    unordered_map<string, int> set;
        
            int index = 0;
            recurPermute(S, index, ans, set);
            
            sort(ans.begin(), ans.end());
            
            return ans;
		}
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends