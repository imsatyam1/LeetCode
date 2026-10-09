class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int length = 0;
        bool hasOdd = false;

        for(char ch: s) mp[ch]++;

        for(auto &itm: mp)
        {
            if(itm.second %2 == 0)
            {
                length += itm.second;
            }
            else
            {
                length += itm.second-1;
                hasOdd = true;
            }
        }

        if(hasOdd) length++;
        return length;
    }
};