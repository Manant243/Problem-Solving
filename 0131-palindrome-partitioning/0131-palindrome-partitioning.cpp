class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string& s){
        int n = s.size();
        for(int i = 0; i < n/2; i++){
            if(s[i] != s[n-i-1]){
                return false;
            }
        }
        return true;
    }
    
    void dfs(int ind, vector<string>current, string& s){
        if(ind == s.size()){
            ans.push_back(current);
        }
        
        string res;
        for(int i = ind; i < s.size(); i++){
            res += s[i];
            if(isPalindrome(res)){
                current.push_back(res);
                dfs(i+1, current, s);
                current.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector <string> current;
        dfs(0, current, s);
        
        return ans;
    }
};