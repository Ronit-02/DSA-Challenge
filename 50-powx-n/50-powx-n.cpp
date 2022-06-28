class Solution {
public:
    double power(double x, long int n){
        
        if(n < 0){
            return (1/power(x, n*-1));
        }
        
        if(n == 0)
            return 1;
        
        if(n % 2 == 0){
            double a = power(x, n/2);
            return a*a;
        }
        else{
            double a = power(x, n/2);
            return a*a*x;
        }
    }
    double myPow(double x, int n) {
     
        double ans;
        ans = power(x, n);
        
        return ans;
    }
};