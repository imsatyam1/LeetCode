class Solution {
    public String findDifferentBinaryString(String[] nums) {
        int n = nums.length;
        StringBuilder sb = new StringBuilder();

        for(int i=0; i<n; i++)
        {
            String temp = nums[i];

            sb.append((temp.charAt(i) == '0')? '1' : '0');
        }

        return sb.toString();
    }
}