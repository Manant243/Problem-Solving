class Solution {
public:
    int characterReplacement(string s, int k) {
        int right = 0, left = 0, maxLetter = 0;
        int alphabet[26] = {0};
        while(right < s.length()) {
            alphabet[s[right] - 'A']++;
            maxLetter = max(maxLetter, alphabet[s[right] - 'A']);
            right++;
            
            if(right - left - maxLetter > k) {
                alphabet[s[left] - 'A']--;
                left++;
            }
        }
        return right - left;
    }
};