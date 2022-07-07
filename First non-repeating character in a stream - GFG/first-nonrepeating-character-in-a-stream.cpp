// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	string FirstNonRepeating(string A){
	    
	    unordered_map <char, int> freq;
	    queue <char> q;
	    string ans = "";
	    
	    for(int i=0; i<A.length(); i++){
	        
	        char ch = A[i];
	        // increase freq
	        freq[A[i]]++;
	        
	        // adding in queue
	        q.push(ch);
	        
	        // modify queue on new addition, remove duplicate char
	        while(!q.empty()){
	            
		        if(freq[q.front()] > 1){
		            // repeating char
		            q.pop();
		        }
		        else{
		            // non-repeating char, add in answer
		            ans += q.front();
		            break;
		        }
	        }
	        
	        // no element remaining ie, no answer
	        if(q.empty()){
	            ans += '#';
	        }
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends