class Solution {
    void solve(int curr, int n, vector<int> &result){
        if(curr > n){
            return;
        }

        result.push_back(curr);

        for(int i=0; i<=9; i++){
            int nextNum = curr*10 + i;

            if(nextNum > n){
                return;
            }

            solve(nextNum, n, result);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;

        for(int i=1; i<=9; i++){
            solve(i, n, result);
        }
        return result;
    }
};