class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> m;
        m[0] = 1;
        
        int cnt = 0, sum = 0;
        for(auto it : nums){
            sum += it;
            cnt += m[sum-k];
            m[sum]++;
        }
        
        return cnt;
    }
};