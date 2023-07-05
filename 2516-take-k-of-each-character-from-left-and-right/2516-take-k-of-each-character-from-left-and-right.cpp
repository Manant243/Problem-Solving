class Solution {
public:
    int takeCharacters(string s, int k) {
        int a = 0, b = 0, c = 0;
        int n = s.size();
        
        if(k == 0) return 0;
        
        for(int i = 0; i < n; i++){
            if(s[i] == 'a') a++;
            else if(s[i] == 'b') b++;
            else c++;
        }
        
        if(a < k || b < k || c < k) return -1;
        a -= k; b -= k; c -= k;
        
        int ans = 0, j = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'a') a--;
            else if(s[i] == 'b') b--;
            else c--;
            
            if(a < 0 || b < 0 || c < 0){
                ans = max(ans, i-j);
                while(j <= i && (a < 0 || b < 0 || c < 0)){
                    if(s[j] == 'a') a++;
                    else if(s[j] == 'b') b++;
                    else c++;
                    j++;
                }
            }
        }
        ans = max(ans, n-j);
        return n-ans;
    }
};