class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack <int> st;
        
        for(int i = n-1; i >= 0; i--){
            if(st.empty()){
                st.push(s[i]); continue;
            }
            if(s[i] == '(' && st.top() == ')'){
                st.pop();
            }
            else if(s[i] == '{' && st.top() == '}'){
                st.pop();
            }
            else if(s[i] == '[' && st.top() == ']'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        
        if(!st.empty()) return false;
        return true;
    }
};