class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftVal(n, 0);
        vector<int> rightVal(n, 0);

        int leftValMax = INT_MIN;
        int rightValMax = INT_MIN;

        for(int i=0; i<n; i++){
            leftValMax = max(leftValMax, height[i]);
            int diff = leftValMax - height[i];

            if(diff > 0) leftVal[i] = diff;
        }

        for(int i=n-1; i>=0; i--){
            rightValMax = max(rightValMax, height[i]);
            int diff = rightValMax - height[i];

            if(diff > 0) rightVal[i] = diff;
        }

        int maxWaterContain = 0;

        for(int i=0; i<n; i++){
            maxWaterContain += min(leftVal[i], rightVal[i]);
        }

        return maxWaterContain;
    }
};