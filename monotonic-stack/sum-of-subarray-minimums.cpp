class Solution {
        vector<int> getNSL(vector<int> &arr, int n){
            stack<int> st;
            vector<int> ans(n, -1);

            for(int i=0; i<n; i++){
                while(!st.empty() && (arr[st.top()]> arr[i])) st.pop();

                if(!st.empty()){
                    ans[i] = st.top();
                }
                st.push(i);
            }
            return ans;
        }

        vector<int> getNSR(vector<int> &arr, int n){
            stack<int> st;
            vector<int> ans(n, n);

            for(int i=n-1; i>= 0; i--){
                while(!st.empty() && (arr[st.top()] >= arr[i])) st.pop();

                if(!st.empty()){
                     ans[i] = st.top();
                }
                st.push(i);
            }
            return ans;
        }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        long long sum = 0;
        int MOD = 1e9+7;

        for(int i=0; i<n; i++){
            long long d1 = i - NSL[i];
            long long d2 = NSR[i] - i;

            long long total_ways_for_i_min = d1*d2;
            long long sum_of_total_ways = arr[i] * total_ways_for_i_min;

            sum = (sum + sum_of_total_ways)%MOD;
        }
        return sum;
    }
};