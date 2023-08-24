class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        map <int,int> window;
        
        int ans = 0, j = 0;
        multiset <int> st;
        for(int i = 0; i < nums.size(); i++){
            if(st.find(window[nums[i]]) != st.end()){
                st.erase(st.find(window[nums[i]]));
            }
            window[nums[i]]++;
            st.insert(window[nums[i]]);
            if(k >= (i-j+1)-*st.rbegin()){
                ans = max(ans, *st.rbegin());
            }
            else{
                while(j < i && k < (i-j+1)-*st.rbegin()){
                    st.erase(st.find(window[nums[j]]));
                    window[nums[j]]--;
                    st.insert(window[nums[j]]);
                    j++;
                }
            }
        }
        
        return ans;
    }
};