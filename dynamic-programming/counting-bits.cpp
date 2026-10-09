class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=1; i<=n; i++){
            int count = 0;
            int num = i;
            while(num){
                if((num&1) == 1){
                    count++;
                }
                num >>= 1;
            }
            ans[i] = count;
        }
        return ans;
    }
};