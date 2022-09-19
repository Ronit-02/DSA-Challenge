class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        unordered_map< string, vector<string> > hash;
        
        for(auto path: paths){
            
            stringstream stream(path); // import stringstream
            string location;
            string file;
            getline(stream, location, ' ');   // location will be string till ' '
            
            // for files in same path
            while(getline(stream, file, ' ')){
                
                string fname = location + "/" + file.substr(0, file.find('('));   // name
                string fcontent = file.substr(file.find('(')+1, file.find(')')-file.find('(')-1);   // content
                hash[fcontent].push_back(fname);    // adding in hash
            }   
        }
        vector<vector<string>> ans;
        for(auto it = hash.begin(); it != hash.end(); it++){
            if(it->second.size() > 1)
                ans.push_back(it->second);
        }
        return ans;
    }
};