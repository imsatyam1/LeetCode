class Solution {
    void solve(string &s, int indx, unordered_set<string> &st,int currCount, int &maxCount){
        if(currCount + (s.length() - indx) <= maxCount) return;

        if(indx == s.length()) {
            maxCount = max(maxCount, currCount);
        }

        for(int j=indx; j<s.length(); j++){
            string sub = s.substr(indx, j-indx+1);
            if(st.find(sub) == st.end()){
                st.insert(sub);
                solve(s, j+1, st, currCount+1, maxCount);
                st.erase(sub);
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        int currCount = 0;
        int maxCount = 0;
        unordered_set<string> st;

        solve(s, 0, st, currCount, maxCount);

        return maxCount;
    }
};