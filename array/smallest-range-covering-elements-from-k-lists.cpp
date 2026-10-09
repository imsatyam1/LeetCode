class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int maxEl = INT_MIN;
        
        for(int i=0; i<k; i++){
            pq.push({nums[i][0], i, 0});
            maxEl = max(maxEl, nums[i][0]);
        }

        vector<int> result = {-1000000, 1000000};

        while(!pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();

            int minEl = curr[0];
            int minIndx = curr[1];
            int indx = curr[2];

            if((maxEl-minEl) < (result[1] - result[0])){
                result[0] = minEl;
                result[1] = maxEl;
            }

            if(indx+1 <nums[minIndx].size()){
                int nextElement = nums[minIndx][indx+1];
                pq.push({nextElement, minIndx, indx+1});
                maxEl = max(maxEl, nextElement);
            }
            else{
                break;
            }
        }
        return result;
    }
};