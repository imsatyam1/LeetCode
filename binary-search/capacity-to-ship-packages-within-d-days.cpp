class Solution {
    bool isPossible(vector<int>& weights, int days, int mid)
    {
        int n = weights.size();
        int sum = 0;
        int dayCount = 0;

        for(int i=0; i<n; i++)
        {
            if(sum + weights[i] > mid)
            {
                dayCount++;
                sum = weights[i];
            }
            else
            {
                sum += weights[i];
            }
        }
        dayCount++;

        return dayCount <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low < high)
        {
            int mid = low + (high - low)/2;

            if(isPossible(weights, days, mid)) high = mid;
            else low = mid+1;
        }

        return low;
    }
};