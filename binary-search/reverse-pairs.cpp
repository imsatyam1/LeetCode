class Solution {
private:
    void merge(vector<int>& nums, int start, int mid, int end)
    {
        int left = start;
        int right = mid + 1;
        int k = 0;

        vector<int> temp(end - start + 1);

        while (left <= mid && right <= end)
        {
            if (nums[left] <= nums[right])
            {
                temp[k++] = nums[left++];
            }
            else
            {
                temp[k++] = nums[right++];
            }
        }

        while (left <= mid)
        {
            temp[k++] = nums[left++];
        }

        while (right <= end)
        {
            temp[k++] = nums[right++];
        }

        for (int i = start; i <= end; i++)
        {
            nums[i] = temp[i - start];
        }
    }

    int countPair(vector<int>& nums, int start, int mid, int end)
    {
        int right = mid + 1;
        int count = 0;

        for (int i = start; i <= mid; i++)
        {
            while (right <= end &&
                   nums[i] > 2LL * nums[right])
            {
                right++;
            }

            count += right - (mid + 1);
        }

        return count;
    }

    int mergeSort(vector<int>& nums, int start, int end)
    {
        if (start >= end)
            return 0;

        int mid = start + (end - start) / 2;

        int cnt = 0;

        // Sort left half
        cnt += mergeSort(nums, start, mid);

        // Sort right half
        cnt += mergeSort(nums, mid + 1, end);

        // Count reverse pairs BEFORE merging
        cnt += countPair(nums, start, mid, end);

        // Merge both sorted halves
        merge(nums, start, mid, end);

        return cnt;
    }

public:
    int reversePairs(vector<int>& nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};