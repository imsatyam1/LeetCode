class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> marked(n, false);
        long long score = 0;

        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }

        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();

            if(nums[p.second] > 0){
                score += p.first;

                if(p.second == 0){
                    if(nums[0] > 0) nums[0] = nums[0]*-1;
                    if(n > 1 && nums[1] > 0) nums[1] = nums[1]*-1;
                }
                else if(p.second == n-1){
                    if(nums[n-1] > 0) nums[n-1] = nums[n-1]*-1;
                    if(nums[n-2] > 0) nums[n-2] = nums[n-2]*-1;
                }
                else{
                    if(nums[p.second-1] > 0) nums[p.second-1] = nums[p.second-1]*-1;
                    if(nums[p.second] > 0) nums[p.second] = nums[p.second]*-1;
                    if(nums[p.second + 1] > 0) nums[p.second+1] = nums[p.second+1]*-1;
                }
            } 
        }
        return score;
    }
};