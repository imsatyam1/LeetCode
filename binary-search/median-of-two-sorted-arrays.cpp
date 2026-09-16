class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0, high = m;

        int half = (m + n + 1)/2;

        while(low <= high)
        {
            int mid1 = low + (high - low)/2;
            int mid2 = half - mid1;

            int left1 = (mid1 == 0) ? INT_MIN : nums1[mid1 -1];
            int right1 = (mid1 == m) ? INT_MAX : nums1[mid1];

            int left2 = (mid2 == 0) ? INT_MIN : nums2[mid2 -1];
            int right2 = (mid2 == n) ? INT_MAX : nums2[mid2];

            if(left1 <= right2 && left2 <= right1)
            {
                if((m+n) % 2 == 1)
                {
                    return max(left1, left2);
                }

                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }

            if(left1 > right2)
            {
                high = mid1 - 1;
            }

            else
            {
                low = mid1 + 1;
            }
        }

        return 0.0;
    }
};