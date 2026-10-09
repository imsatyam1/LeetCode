class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> mp;

        for(int &t: time){
            mp[t%60]++;
        }

        long long result = 0;

        for(int i=0; i<time.size(); i++){
            int rem = time[i]%60;

            if(mp.find(rem) != mp.end()){
                if(rem == 0 || rem == 30){
                int n = mp[rem];
                result += static_cast<long long>(n)*(n-1)/2;
                }
                else{
                    int diff = 60 - rem;
                    result += mp[rem]*mp[diff];
                }
                mp.erase(rem);
            }
        }
        return result;
    }
};