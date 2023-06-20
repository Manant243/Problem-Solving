class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        map <int,double> pos;
        
        for(int i = 0; i < n; i++){
            pos[-position[i]] = (double)(target-position[i])/speed[i];
        }
        
        double cur = 0, ans = 0;
        for(auto it : pos){
            if(it.second > cur) cur = it.second, ans++;
        }
        
        return ans;
    }
};