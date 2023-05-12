class Solution {
public:
    vector <string> ans;
    void func(int ind, int cnt, string current, string& s){
        if(ind == s.size() && cnt == 4){
            ans.push_back(current); return;
        }
        string res;
        for(int i = ind; i < s.size(); i++){
            res += s[i];
            if(res.size() == 3){
                if(res[0] > '2'){
                    break;
                }
                if(res[0] == '2' && res[1] > '5'){
                    break;
                }
                if(res[0] == '2' && res[1] == '5' && res[2] > '5'){
                    break;
                }
            }
    
            if(!current.empty()){
                current += '.';
                current += res;
            }
            else{
                current += res;
            }
            
            func(i+1, cnt+1, current, s);
            
            int j = current.size()-1;
            while(j >= 0 && current[j] != '.'){
                current.pop_back(); j--;
            }
            if(!current.empty()){
                current.pop_back();
            }
            
            if(res == "0" || res.size() == 3) break;
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        string current;
        func(0, 0, current, s);
        
        return ans;
    }
};