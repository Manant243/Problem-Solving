class Solution {
public:
    map <string, bool> m;
    
    string ans;
    void func(int ind, int n, string curr){
        if(ind == n && !m[curr]){
            ans = curr; return;
        }
        else if(ind == n) return;
        
        if(!ans.empty()) return;
        
        curr += '0';
        func(ind+1, n, curr);
        curr.pop_back();
        
        curr += '1';
        func(ind+1, n, curr);
        
        return;
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        int k = 0;
        for(auto it : nums){
            k = it.size();
            m[it] = true;
        }
        string curr;
        func(0, k, curr);
        
        return ans;
    }
};