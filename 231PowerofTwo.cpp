#include<iostream>
#include<limits.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        int ans = 1;

        for(int i=0; i<=30; i++){
            if(ans == n)
                return true;
            if(ans < INT_MAX/2)
                ans = ans*2;
        }
        return false;
    }
};

int main(){

    Solution s;
    int output = s.isPowerOfTwo(32);
    cout << output;
}