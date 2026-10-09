class Solution {
public:
    string minWindow(string s, string t) {
        int l=0, r= 0, cnt = 0, minLen = 1e7, n = s.length(), m = t.length();
        int startIndx = -1;
        map<char, int> mp;

        for(int i=0; i<m; i++) mp[t[i]]++;

        while(r<n){
            if(mp[s[r]] >0)cnt++;
            mp[s[r]]--;
            while(cnt == m){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    startIndx = l;
                } 
                mp[s[l]]++;
                if(mp[s[l]] > 0)cnt--;
                l++;
            }
            r++;
        }
        return startIndx == -1 ?"" :s.substr(startIndx, minLen);
    }
};