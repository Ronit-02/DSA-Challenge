#include<iostream>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {

        int mask = 0;
        int m = n;
        
        if(n==0)                //for the edge case
            return 1;
        
        while(m != 0){
            
            mask = (mask<<1) | 1;
            m = m>>1;
        }      

        int ans = mask & (~n);
        return ans;
    }
};

int main(){

    Solution s;
    int output = s.bitwiseComplement(5);
    cout << output;
}