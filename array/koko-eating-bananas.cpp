class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = -1;

        while(low < high)
        {
            int mid = low + (high - low)/2;

            int sum = 0;

            for(int i=0; i<piles.size(); i++)
            {
                sum += piles[i]/mid;
                if(piles[i]%mid != 0) sum += 1;
            }

            if(sum <= h) high = mid;
            else low = mid+1;
        }
        return high;
    }
};