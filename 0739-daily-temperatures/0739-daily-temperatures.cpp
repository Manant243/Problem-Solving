class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int,int>> st;
        
        vector<int>ans;
        for(int i = n-1; i >= 0; i--){
            int a = temperatures[i];
            while(!st.empty() && a >= st.top().first){
                st.pop();
            }
            if(!st.empty()){
                ans.push_back(st.top().second-i);
            }
            else{
                ans.push_back(0);
            }
            st.push({a, i});
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};