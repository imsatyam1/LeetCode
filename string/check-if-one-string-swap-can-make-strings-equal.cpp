class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;

        int n1 = s1.length();
        int n2 = s2.length();

        if(n1 != n2) return false;

        vector<int> mismatches;

        for(int i=0; i<n1; i++){
            if(s1[i] != s2[i]){
                mismatches.push_back(i);
            }
        }

        return mismatches.size() == 2 && s1[mismatches[0]] == s2[mismatches[1]] && s1[mismatches[1]] == s2[mismatches[0]];
    }
};