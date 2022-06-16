class Solution {
public:
    // Sieve of Eratosthenes
    // Time complexity: O(n*log(logn))
    
    int countPrimes(int n) {
        
        vector<bool> prime(n+1, true);
        prime[0] = prime[1] = false;    // as 1 and 2 are not prime numbers
        
        int cnt = 0;
        
        for(int i=2; i<n; i++){
            
            if(prime[i] == true){
                cnt++;
                    
                for(int j=2*i; j<n; j = j+i)
                    prime[j] = false;
            }
        }
        return cnt;
    }
};