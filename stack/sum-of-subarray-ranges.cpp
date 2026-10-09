class Solution {
    vector<int> getNSL(vector<int> &nums, int n){
        stack<int> st;
        vector<int> ans(n, -1);

        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> getNSR(vector<int> &nums, int n){
        stack<int> st;
        vector<int> ans(n, n);

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> getNLL(vector<int> &nums, int n){
        stack<int> st;
        vector<int> ans(n, -1);

        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> getNLR(vector<int> &nums, int n){
        stack<int> st;
        vector<int> ans(n, n);

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> NSL = getNSL(nums, n);
        vector<int> NSR = getNSR(nums, n);
        vector<int> NLL = getNLL(nums, n);
        vector<int> NLR = getNLR(nums, n);

        long long sum = 0;

        for(int i=0; i<n; i++){
            long long d1 = i-NSL[i];
            long long d2 = NSR[i] - i;
            long long d3 = i-NLL[i];
            long long d4 = NLR[i] - i;

            long long total_ways_for_i_min = d1*d2;
            long long total_ways_for_i_max = d3*d4;

            long long diff = (total_ways_for_i_max -total_ways_for_i_min)*nums[i];

            sum = (sum+diff);
        }
        return sum;
    }
};