class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int max_El = *max_element(arr.begin(), arr.end());

        if(k>=n) return max_El;

        int winner = arr[0];
        int win = 0;

        for(int i=1; i<n; i++){
            if(winner > arr[i]) win++;
            else{
                winner = arr[i];
                win = 1;
            }

            if((win == k) || (winner == max_El))return winner;
        }
        return winner;
    }
};