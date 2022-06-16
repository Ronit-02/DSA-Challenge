class Solution 
{
public:
    int countPrimes(int n) 
    {
        std::vector<bool> table(n + 1, true);
        for (int i = 2; i * i <= n; i++)
        {
            if (table[i])
            {
                for (int p = i * i; p <= n; p += i)
                {
                    table[p] = false;
                }
            }
        }
        
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            count += table[i];
        }
        return count;
    }
};