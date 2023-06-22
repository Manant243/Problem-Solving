class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack <int> st;
        map <int,int> m;
        
        int n = nums2.size(), k = nums1.size();
        for(int i = n-1; i >= 0; i--){
            int a = nums2[i];
            while(!st.empty() && a >= st.top()){
                st.pop();
            }
            if(!st.empty()){
                m[a] = st.top();
            }
            else{
                m[a] = -1;
            }
            st.push(nums2[i]);
        }
        
        vector <int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(m[nums1[i]]);
        }
        
        return ans;
    }
};