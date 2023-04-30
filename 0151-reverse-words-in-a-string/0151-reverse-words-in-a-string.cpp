class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        stringstream str(s);
        string word;
        while (str >> word) 
            vec.push_back(word);
        
        reverse(vec.begin(), vec.end()); 
        
        string res;
        for (const auto &it : vec) 
            res+=" "+it;
        res.erase(0,1); 
        
        return res;
    }
};