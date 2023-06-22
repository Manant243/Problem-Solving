class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map <char,int> m;
        for(auto it : tasks){
            m[it]++;
        }
        
        priority_queue<int> q;
        for(auto it : m){
            q.push(it.second);
        }
        
        int ans = 0;
        while(!q.empty()){
            vector <int> temp;
            for(int i = 0; i <= n; i++){
                if(!q.empty()){
                    temp.push_back(q.top()); q.pop();
                }
            }
            for(int i = 0; i < temp.size(); i++){
                if(--temp[i] > 0) q.push(temp[i]);
            }
            ans += q.empty() ? temp.size() : n+1;
        }
        
        return ans;
    }
};