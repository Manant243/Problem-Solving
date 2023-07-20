class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack <int> st;
        
        vector <int> ans;
        for(int i = n-1; i >= 0; i--){
            if(asteroids[i] < 0){
                st.push(asteroids[i]);
            }
            else{
                int k = asteroids[i];
                if(st.empty()){
                    ans.push_back(k);
                    continue;
                }
                else{
                    while(!st.empty() && k > abs(st.top())){
                        st.pop();
                    }
                    if(!st.empty() && abs(st.top()) > k){
                        continue;
                    }
                    if(!st.empty() && abs(st.top()) == k){
                        st.pop(); continue;
                    }
                    else{
                        ans.push_back(k);
                    }
                }
            }
        }
        
        vector <int> temp;
        while(!st.empty()){
            temp.push_back(st.top()); st.pop();
        }
        reverse(temp.begin(), temp.end());
        for(int i = 0; i < temp.size(); i++){
            ans.push_back(temp[i]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};