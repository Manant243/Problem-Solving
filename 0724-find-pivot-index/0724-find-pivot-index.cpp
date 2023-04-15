class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector <int> pref(n+2, 0);
        pref[0] = 0; pref[n+1] = 0;
        
        for(int i = 1; i <= n; i++){
            pref[i] = pref[i-1]+nums[i-1];
        }
        
        int ans = -1;
        for(int i = 1; i <= n; i++){
            if(pref[i-1] == pref[n]-pref[i]){
                ans = i; break;
            }
        }
        
        if(ans == -1) return ans;
        return ans-1;
    }
};