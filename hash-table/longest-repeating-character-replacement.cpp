class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int i=0, j=0, maxCount = 0, maxLen = 0, n = s.length();

        while(j<n){
            mp[s[j]]++;
            maxCount = max(maxCount, mp[s[j]]);
            if((j-i+1) - maxCount > k){
                mp[s[i]]--;
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};