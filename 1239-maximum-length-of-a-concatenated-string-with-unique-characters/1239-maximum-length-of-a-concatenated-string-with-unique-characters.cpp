class Solution {
public:
    map <char, int> ok;
    int ans = 0;
    void func(int ind, string curr, vector<string>& arr){
        if(ind == arr.size()){
            cout << curr << "\n";
            ans = max(ans, int(curr.length()));
            return;
        }
        
        bool res = false;
        for(auto it : arr[ind]){
            if(ok[it] >= 1){
                res = true;
            }
        } 
        
        bool pos = false;
        for(auto it : arr[ind]){
            ok[it]++;
            if(ok[it] > 1){
                pos = true;
            }
        }
        
        if(!res && !pos){
            func(ind+1, curr+arr[ind], arr);
        }
        
        for(auto it : arr[ind]){
            ok[it]--;
            if(ok[it] == 0){
                ok.erase(it);
            }
        }
        
        func(ind+1, curr, arr);
        
    }
    
    int maxLength(vector<string>& arr) {
        string curr;
        ok.clear();
        func(0, curr, arr);
        
        return ans;
    }
};