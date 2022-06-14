// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string reverse(string s){
        
        int st = 0;
        int e = s.length() - 1;
        
        while(st < e){
            swap(s[st++], s[e--]);
        }
        
        return s;
    }
    
    string encryptString(string s){
    
        string ans = "";
        int n = 1;
        
       for(int i=0;i<s.size();i++){
            
            if(s[i]==s[i+1]){
               n++;
            }
            else{
               ans += s[i] + to_string(n);
               n = 1;
            }
        }
        
        ans = reverse(ans);
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
	    string s;
		cin>>s;
		Solution ob;
		string ans = ob.encryptString(s);
		cout<<ans<<endl;
	}
}
  // } Driver Code Ends