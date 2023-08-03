class Solution {
public:
    map <char, vector<char>> m;
    vector<string> ans;
    
    void dfs(int index, string& digits, string& temp){
        if(index == digits.size()){
            ans.push_back(temp);
            return;
        }
        char curr = digits[index];
        
        for(auto it : m[curr]){
            temp += it;
            dfs(index+1, digits, temp);
            temp.pop_back();
        }        
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return ans;
        }
        
        char c = 'a';
        for(int i = 2; i <= 9; i++){
            int times = 3;
            if(i == 7 || i == 9){
                times++;
            }
            for(int j = 0; j < times; j++){
                m[(i+'0')].push_back(c); c++;
            }
        }
        string empty = "";
        dfs(0, digits, empty);
        return ans;
    }
};