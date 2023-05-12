class Solution {
public:
    int need = 0;
    bool func(int ind, vector<int>curr, vector<int>& sticks){
        if(ind == sticks.size()) return true;
        if(sticks[ind] > need) return false;
        
        for(int j = 0; j < 4; j++){   
            if(curr[j]+sticks[ind] <= need){
                curr[j] += sticks[ind];
                if(func(ind+1, curr, sticks)){
                    return true;
                };
                curr[j] -= sticks[ind];
                if(!curr[j]) break;
            }
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& sticks) {
        vector <int> curr(4, 0);
        
        for(auto it : sticks){
            need += it;
        }
        
        if(need % 4 != 0) return false;
        need /= 4;
        
        sort(sticks.rbegin(), sticks.rend());
        if(func(0, curr, sticks)){
            return true;
        }
        return false;
    }
};