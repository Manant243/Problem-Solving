class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> st(wordList.begin(), wordList.end());
        queue <pair<string,int>> que;
        
        que.push({beginWord, 1});
        while(!que.empty()){
            string word = que.front().first;
            int steps = que.front().second;
            que.pop();
            if(word == endWord){
                return steps;
            }
            for(int i = 0; i < word.size(); i++){
                string temp = word;
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        que.push({word, steps+1});
                    }
                }
                word = temp;
            }
        }
        
        return 0;
    }
};