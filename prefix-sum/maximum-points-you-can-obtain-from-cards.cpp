class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0, rightSum = 0, rightIndx = cardPoints.size() -1, maxSum = 0;

        for(int i=0; i<k; i++) leftSum += cardPoints[i];
        maxSum = leftSum;

        for(int i=k-1; i>=0; i--){
            leftSum = leftSum - cardPoints[i];
            rightSum += cardPoints[rightIndx];
            rightIndx--;
            maxSum = max(maxSum, leftSum + rightSum);
        }
        return maxSum;
    }
};