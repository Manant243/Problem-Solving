class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        vector <int> chars(128, 0);
        
        int left = -1, right = -1;
        for(int i = 0; i < int(t.size()); i++){
            chars[t[i]]++;
        }
        
        int j = 0, ans = 1e6, n = s.size();
        for(int i = 0; i < n; i++){
            chars[s[i]]--;
            while(j < i){
                if(chars[s[j]] < 0){
                    chars[s[j]]++; j++;
                }
                else{
                    break;
                }
            }
            bool ok = true;
            for(int m = 0; m < 128; m++){
                if(chars[m] > 0){
                    ok = false; break;
                }
            }
            
            if(ok){
                if(i-j+1 < ans){
                    ans = i-j+1;
                    left = j; right = i;
                }
            }
        }
        
        string res;
        if(left != -1 && right != -1){
            for(int l = left; l <= right; l++){
                res += s[l];
            }
        }
        
        return res;
    }
};