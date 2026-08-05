class Solution {
public:
    bool helper(string s, int start, int end)
    {
        while(start < end && !isalnum(s[start])) start++;
        while(start < end && !isalnum(s[end])) end--;

        if(start >=  end) return true;

        if(tolower(s[start]) != tolower(s[end])) return false;

        return helper(s, start+1, end-1);
    }

    bool isPalindrome(string s) {
        int end = s.length() - 1;
        return helper(s, 0, end);
    }
};