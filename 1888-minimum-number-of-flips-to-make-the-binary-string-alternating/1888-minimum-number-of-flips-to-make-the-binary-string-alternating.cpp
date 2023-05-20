class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;
        
        string s1, s2;
        for(int i = 0; i < s.size(); i++){
            s1 += (i%2 == 1 ? '0' : '1');
            s2 += (i%2 == 0 ? '0' : '1');
        }
        
        int ans = INT_MAX, ans1 = 0, ans2 = 0;
        for(int i = 0; i < int(s.size()); i++){
            if(s1[i] != s[i]) ans1++;
            if(s2[i] != s[i]) ans2++;
            
            if(i >= n){
                if(s1[i-n] != s[i-n]) ans1--;
                if(s2[i-n] != s[i-n]) ans2--;
            }
            
            if(i >= n-1){
                ans = min({ans, ans1, ans2});
            }
        }
        
        return ans;
    }
};