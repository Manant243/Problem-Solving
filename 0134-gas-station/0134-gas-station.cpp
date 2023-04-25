class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
{
    int curr_gas=0,start=0,previous_gas=0;
    
    for(int i=0;i<gas.size();i++)
    {
        curr_gas=curr_gas+(gas[i]-cost[i]);
        if(curr_gas<0)
        {
            start=i+1;
            previous_gas=previous_gas+curr_gas;
            curr_gas=0;
        }
    }
    return ((curr_gas+previous_gas)>=0)?(start):-1;
}
};