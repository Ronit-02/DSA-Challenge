class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        sort(products.begin(), products.end());   // it will sort lexographically
        vector<vector<string>> ans;        
        
        int start = 0; 
        int end = products.size() - 1;    // start, end -> 2 pointer method
        
        for(int i=0; i < searchWord.length(); i++) {
                
            vector<string> temp;
            char ch = searchWord[i];    // we'll check char by char
            
            while(start <= end && products[start][i] < ch)
                start++;                   // till it reaches word which contains ch
            
            while(start <= end && products[end][i] > ch)
                end--;
                             
            int count = 0;            // Start -> End, we will insert only 3 strings
            for(int j=start; j <= end && count < 3; j++, count++){
                temp.push_back(products[j]);
            }
            
            ans.push_back(temp);   // adding list to the ans
            
        }
        
        return ans;
    }
};