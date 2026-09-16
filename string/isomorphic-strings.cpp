class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_set<char> st1;
        unordered_set<char> st2;

        for(char &ch: s) st1.insert(ch);
        for(char &ch: t) st2.insert(ch);

        return (st1.size() == st2.size());
    }
};