class Solution {
public:
    map <int, vector<int>> ok;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(), curr = INT_MAX, pos = 0;
        for(int i = 0; i < n; i++){
            if(curr > abs(arr[i]-x)){
                curr = abs(arr[i]-x); pos = i;
            }
        }
        
        vector <int> ans;
        ans.push_back(arr[pos]); k--;
        
        int left = -1, right = n;
        if(pos > 0) left = pos-1;
        if(pos < n-1) right = pos+1;
        
        while(true){
            if(k <= 0) break;
            if(left >= 0 && right <= n-1){
                if(abs(arr[right]-x) < abs(arr[left]-x)){
                    ans.push_back(arr[right]); right++;
                }
                else{
                    ans.push_back(arr[left]); left--;
                }
            }
            else if(right <= n-1){
                ans.push_back(arr[right]); right++;
            }
            else if(left >= 0){
                ans.push_back(arr[left]); left--;
            }
            k--;
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};