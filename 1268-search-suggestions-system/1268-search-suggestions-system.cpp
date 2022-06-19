class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        vector<vector<string>> ans;
        
        sort(products.begin(), products.end());  // sorting products array in lexographically order
        
        for(int i=0; i < searchWord.length(); i++){
            
            string str = searchWord.substr(0, i+1);
            
            // int s = 0;
            // int e = products.size();
            // int mid = s + (e-s)/2;
            vector<string> temp;
            int count = 0;
            
            for(int j=0; j < products.size() && count < 3; j++){
                
                int idx = 0;
                while(idx < str.size()){
                    if(str[idx] != products[j][idx])
                        break;
                    idx++;
                }
                
                if(idx == str.size()){      // if substr matches -> add the result                    
                    temp.push_back(products[j]);
                    count++;
                }
            }
            
            ans.push_back(temp);
            
        }
        
        return ans;
    }
};