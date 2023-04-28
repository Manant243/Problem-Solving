class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char> stk;
        for (auto it : num)
        {
            while (!stk.empty() && k > 0 && stk.top() > it)
            {
                stk.pop();
                k--;
            }
            stk.push(it);
        }
       
        while (k--)
            stk.pop();
        
        string result;
        int size = stk.size();
        for (int i = 0; i<size; i++)
        {
            result.push_back(stk.top());
            stk.pop();
        }
        int i = 0, j = result.size() - 1;
        while (i < j)
            swap(result[i++], result[j--]);
        
        k = 0;
        while (result[k] == '0')
            k++;
        result.erase(begin(result), begin(result) + k);
        if (result.size() == 0)
            result = "0";
        return result;
    }
};