class Solution {
    public int minOperations(String s) {
        int startwith0 = 0;
        int startwith1 = 0;
        
        int n = s.length();

        for(int i=0; i<n; i++)
        {
            char expected0 = (i % 2 == 0) ? '0': '1';
            char expected1 = (i % 2 == 0) ? '1': '0';

            if(s.charAt(i) != expected0) startwith0++;
            if(s.charAt(i) != expected1) startwith1++;
        }

        return Math.min(startwith0, startwith1);
    }
}