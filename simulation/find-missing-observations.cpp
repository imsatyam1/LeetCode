class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total_sum = mean*(m+n);
        int sum_m = accumulate(rolls.begin(), rolls.end(), 0);

        int sum_n = total_sum - sum_m;

        if(sum_n < n|| sum_n >6*n){
            return {};
        }
        vector<int> missing(n,1);
        sum_n -= n;

        for(int i=0; i<n; i++){
            int add = min(5, sum_n);
            missing[i] += add;
            sum_n -= add;
        }
        return missing;
    }
};