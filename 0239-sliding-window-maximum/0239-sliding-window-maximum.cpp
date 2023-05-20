class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset <int> s;
        vector <int> ans;
        
        int n = nums.size(), i = 0;
        while(i < k){
            s.insert(nums[i]); i++;
        }
        ans.push_back(*s.rbegin());

        for(int j = k; j < n; j++){
            s.insert(nums[j]);
            s.erase(s.find(nums[j-k]));
            ans.push_back(*s.rbegin());
        }
        
        return ans;
    }
};