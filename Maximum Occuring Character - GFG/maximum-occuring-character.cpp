// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        int freq[26] = {0};
        
        for(int i=0; i<str.length(); i++){
            
            char ch = str[i];
            int index = ch - 'a';
            
            freq[index]++;
        }
        
        // traversing freq array to find max occuring element
        int idx = 0;
        int maxi = freq[0];
        for(int i=0; i<26; i++){
            
            if(maxi < freq[i]){
                idx = i;
                maxi = freq[i];
            }
        }
        
        char ans = 'a' + idx;
        return ans;
        
    }

};

// { Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}  // } Driver Code Ends