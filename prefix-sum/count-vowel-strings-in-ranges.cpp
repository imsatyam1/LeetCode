class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n+1, 0);
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};

        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i];

            if(vowel.count(words[i].front()) && vowel.count(words[i].back())){
                prefix[i+1]++;
            }
        }

        vector<int> ans;

        for(auto &query: queries){
            int L = query[0], R = query[1];
            ans.push_back(prefix[R+1] - prefix[L]);
        }
        return ans;
    }
};