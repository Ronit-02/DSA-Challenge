#include<iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {

        int counter = 0;
        while(n != 0){

            //If last digit is 1, it will give 1 when & with 000....0001 (1)
            if(n&1){
                counter++;
            }
            //Right shifting
            n = n>>1;
        }   
        return counter;
    }
};  

int main(){

    Solution s;
    int output = s.hammingWeight(00000000000000000000000000001011);
    cout << output;
}