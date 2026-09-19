public class Solution {
    public int[] SmallerNumbersThanCurrent(int[] nums) {
        int n = nums.Length;
        int[] ans = new int[n];

        for(int i=0; i<n; i++)
        {
            int count = 0;
            for(int j=0; j<n; j++)
            {
                if(nums[j] < nums[i]) count++;
            }
            ans[i] = count;
        }
        return ans;
    }
}