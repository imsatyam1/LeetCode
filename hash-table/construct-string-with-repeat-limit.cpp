class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.length();
        unordered_map<char, int> mp;
        priority_queue<char> pq;

        for(char ch: s){
            mp[ch]++;
        }

        for(auto &it: mp){
            pq.push(it.first);
        }

        string new_str = "";

        while(!pq.empty()){
            
            char ch = pq.top();
            pq.pop();
            int count = min(repeatLimit, mp[ch]);
            new_str.append(count, ch);
            mp[ch] -= count;

            if(mp[ch] > 0){
                if(pq.empty()) break;

                char second_char = pq.top();
                pq.pop();
                mp[second_char]--;
                new_str += second_char;
                if(mp[second_char]>0){
                    pq.push(second_char);
                }
                pq.push(ch);
            }
        }
        return new_str;
    }
};