class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& nums, vector<int>& p)
    {
        map<int,int>mp{{0,0}};
        for(auto &it:nums)
        {
            mp[it[0]]++;
            mp[it[1]+1]--;
        }
        int sum=0;
        for(auto &[value,counter]:mp)
        {
            sum+=counter;
            counter=sum;
        }
        vector<int>ans;
        for(int i=0;i<p.size();i++)
        {
            auto it=mp.upper_bound(p[i]);
            ans.push_back(prev(it)->second);
        }
        return ans;
    }
};