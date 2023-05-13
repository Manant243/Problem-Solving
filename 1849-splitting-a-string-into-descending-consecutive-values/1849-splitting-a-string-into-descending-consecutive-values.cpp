class Solution {
public:
    bool splitString(string &s, int i = 0, long prev = 0) {
    long num = 0;
    for (int j = i; num < 1e+10 && j < s.size() - (i == 0 ? 1 : 0); ++j) {
        num = num * 10 + (s[j] - '0');
        if ((i == 0 || prev - 1 == num) && splitString(s, j + 1, num))
            return true;
    }
    return i == s.size();
}
};