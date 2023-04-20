class Solution {
public:
    string decodeString(string s) {
        stack <char> st;
        
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] != ']'){
                st.push(s[i]);
            }
            else{
                string cur = "";
                while(st.top() != '['){
                    cur = st.top() + cur;
                    st.pop();
                }
                st.pop();
                string num = "";
                while(!st.empty() && isdigit(st.top())){
                    num = st.top() + num;
                    st.pop();
                }
                
                int curr = stoi(num);
                while(curr--){
                    for(int j = 0; j < cur.size(); j++){
                        st.push(cur[j]);
                    }
                }
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};