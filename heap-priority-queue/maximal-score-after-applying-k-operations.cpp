class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long sum = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }

        while(k>0){
            int curr = pq.top();
            sum += curr;
            pq.pop();

            curr= ceil(static_cast<double>(curr)/3);
            pq.push(curr);
            k--;
        }
        return sum;
    }
};