class Solution {
public:
    string check(int l, int r, int n, string& s){  
        while(l >= 0 && r < n && s[l] == s[r]){
            l--; r++;
        }
        l++; r--;
        string k;
        while(l <= r){
            k += s[l]; l++;
        }
        return k;
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        
        string ans = "";
        for(int i = 0; i < n; i++){
            if(i-1 >= 0 && i+1 < n){
                string k = check(i-1, i+1, n, s);
                if(k.size() > ans.size()) ans = k;
            }
            if(i+1 < n){
                string k = check(i, i+1, n, s);
                if(k.size() > ans.size()) ans = k;
            }
        }
        
        if(ans.empty()) ans += s[0];
        return ans;
    }
};