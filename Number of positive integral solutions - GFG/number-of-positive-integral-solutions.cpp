// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    long posIntSol(string s)
    {
        // Whole problem boils down to mathematical formula
        // Ans for this equation -> (k-1)C(n-1), k = value, n = variables

        int index = 0;
        int n = 1;   // number is 1 more than no of plus
        for(int i=0; i<s.length(); i++){
            if(s[i] == '+') 
                n++;
            if(s[i] == '=')
                index = i;
        }
        
        string str = s.substr(index+1);
        int k = stoi(str);     // converting string to integer
        
        // Calculating (k)C(n)
        // => (k)!/(n)!*(k-n)! = k*(k-1)*(k-2)* ... (k-n-1) / n!
        
        k = k-1;
        n = n-1;
        long long num= 1;
        for(int i=0; i<n; i++){
            num = num * k;
            k--;
        }
        
        long long den = fact(n);
        
        long long ans = num / den;
        return ans;
    }
    int fact(int n){
        
        // base case
        if(n == 0) return 1;
        // recursive call
        return n * fact(n-1);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends