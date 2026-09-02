class Solution {
    bool isPossible(vector<int>& bloomDay, int m, int k, int mid)
    {
        int n = bloomDay.size();
        int flower = 0, bouquests = 0;

        for(int i=0; i<n; i++)
        {
            if(bloomDay[i] <= mid)
            {
                flower++;
                if(flower == k)
                {
                    bouquests++;
                    flower = 0;
                }
            }
            else flower = 0;
        }

        return bouquests >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n < (long long)m * k) return -1;

        int low = 1; 
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(isPossible(bloomDay, m, k, mid)) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};