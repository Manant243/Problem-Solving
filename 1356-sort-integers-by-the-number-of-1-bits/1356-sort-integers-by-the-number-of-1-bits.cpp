class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> ans;
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            int temp = arr[i], cnt = 0;
            while(temp){
                if(temp&1){
                    cnt++;
                }
                temp /= 2;
            }
            ans.push_back({cnt, arr[i]});
        }
        
        sort(ans.begin(), ans.end());
        vector<int>ret;
        
        for(int i = 0; i<arr.size(); i++){
            ret.push_back(ans[i].second);
        }
        
        return ret;
    }
};