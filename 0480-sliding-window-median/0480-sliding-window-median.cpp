class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector <double> medians;
        multiset <int> s(nums.begin(), nums.begin()+k);
        
        auto mid = next(s.begin(), k/2);
        for(int i = k; i <= nums.size(); i++){
            medians.push_back((double(*mid) + *prev(mid, 1 - k%2)) / 2);
            
            if(i == nums.size()) break;
            
            s.insert(nums[i]);
            if(nums[i] < *mid){
                mid--;
            }
            
            if(nums[i-k] <= *mid){
                mid++;
            }
            
            s.erase(s.find(nums[i-k]));
        }
        
        return medians;
    }
};