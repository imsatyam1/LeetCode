class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0.0;
        int n = customers.size();

        vector<int> sum(n);
        double avgTime = 0;

        sum[0] = customers[0][0] +customers[0][1];

        for(int i=1; i<n; i++){
            if(customers[i][0] <= sum[i-1]){
                sum[i] = sum[i-1] + customers[i][1];
            }
            else{
                sum[i] = customers[i][0] + customers[i][1];
            }
        }

        for(int i=0; i<n; i++){
            avgTime += sum[i] - customers[i][0];
        }
        
        ans = static_cast<double>(avgTime)/n;
        return ans;
    }
};