class Solution {
public:
    map <int, vector<int>> ok;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int curr = abs(arr[i]-x);
            ok[curr].push_back(arr[i]);
        }
        
        for(auto it : ok){
            vector<int> s = it.second;
            sort(s.begin(), s.end());
            ok[it.first] = s;
        }
        
        vector <int> ans;
        bool ok1 = true;
        for(auto it : ok){
            for(auto is : it.second){
                k--;
                ans.push_back(is);
                if(k == 0){
                    ok1 = false; break;
                }
            }
            if(!ok1) break;
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};