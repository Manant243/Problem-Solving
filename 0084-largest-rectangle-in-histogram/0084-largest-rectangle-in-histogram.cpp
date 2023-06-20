class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <pair<int,int>> st;
        
        int ans = 0;
        for(int i = 0; i < heights.size(); i++){
            if(st.empty()){
                st.push({i, heights[i]});
                continue;
            }
            int start = i;
            while(!st.empty() && st.top().second > heights[i]){
                int ind = st.top().first;
                int val = st.top().second;
                
                st.pop();
                start = ind;
                ans = max(ans, val*(i-ind));
            }
            st.push({start, heights[i]});
        }
        
        int ind = heights.size()-1;
        while(!st.empty()){
            int val = st.top().second;
            ans = max(ans, val*(ind-st.top().first+1));
            st.pop();
        }
        
        return ans;
    }
};