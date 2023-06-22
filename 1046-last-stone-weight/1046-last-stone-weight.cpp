class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> q;
        
        for(int i = 0; i < stones.size(); i++){
            q.push(stones[i]);
        }
        
        int ans = 0;
        while(!q.empty()){
            int a = q.top(); q.pop();
            if(q.empty()){
                ans = a; break;
            }
            
            int b = q.top(); q.pop();
            if(a == b) continue;
            q.push(a-b);
        }
        
        return ans;
    }
};