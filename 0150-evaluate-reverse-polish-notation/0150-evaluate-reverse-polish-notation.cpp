class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] != "+" && tokens[i] != "-"  && tokens[i] != "*" && tokens[i] != "/"){
                int k = stoi(tokens[i]);
                st.push(k);
            } 
            if(tokens[i] == "+"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                
                int num = a+b;
                st.push(num);
            }
            if(tokens[i] == "-"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                
                int num = b-a;
                st.push(num);
            }
            if(tokens[i] == "*"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                
                int num = b*a;
                st.push(num);
            }
            if(tokens[i] == "/"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                
                int num = b/a;
                st.push(num);
            }
        }
        
        int ans = st.top();
        return ans;
    }
};