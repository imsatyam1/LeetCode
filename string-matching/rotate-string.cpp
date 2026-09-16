class Solution {
public:
    bool rotateString(string s, string goal) {
        int i=0;

        if(s.length() != goal.length()) return false;

        while(i< s.length() && s[i] != goal[0]) i++;

        string newStr = s.substr(i, s.length()) + s.substr(0, i);

        return (newStr == goal);
    }
};