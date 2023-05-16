class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum = 0, avg = 0, i = 0, ans = 0;
        
        while(i < k){
            sum += arr[i]; i++;
        }
        
        if(sum/k >= threshold) ans++;
        
        i = 0;
        for(int j = k; j < n; j++){
            sum -= arr[i];
            sum += arr[j];
            if(sum / k >= threshold) ans++;
            i++;
        }
        
        return ans;
    }
};