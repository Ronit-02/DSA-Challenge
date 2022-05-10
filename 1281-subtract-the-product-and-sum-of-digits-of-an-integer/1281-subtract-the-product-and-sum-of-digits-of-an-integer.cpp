class Solution {
public:
    int subtractProductAndSum(int n) {

        int sum = 0;
        int product = 1;
        int m = n;

        while(m>0){
            
            int lastDigit = m % 10;
            sum += lastDigit;
            product *= lastDigit;
            m = m/10;
        }
        return (product - sum);
    }
};