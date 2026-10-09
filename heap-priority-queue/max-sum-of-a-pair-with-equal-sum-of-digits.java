class Solution {
    int digitSum(int num)
    {
        int sum = 0;

        while(num != 0)
        {
            int rem = num % 10;
            sum += rem;
            num /= 10;
        }
        return sum;
    }
    public int maximumSum(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        int maxSum = -1;
        int maxIndx = -1;

        for(int i=0; i<nums.length; i++)
        {
            int sum = digitSum(nums[i]);

            if(mp.containsKey(sum))
            {
                int indx = mp.get(sum);
                int currSum = nums[indx] + nums[i];
                maxSum = Math.max(maxSum, currSum);
            }

            if(!mp.containsKey(sum) || nums[i] > nums[mp.get(sum)])
            {
                mp.put(sum, i);
            }
        }

        return maxSum;
    }
}