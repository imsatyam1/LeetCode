class Solution {
    public int minFlips(String s) {
        int n = s.length();

        int i=0, j=0;

        int result1 =0, result2 =0; 
        int result = Integer.MAX_VALUE;

        while(j < 2*n)
        {
            int expectedCharS1 = (j%2 == 0) ? '0' : '1';
            int expectedCharS2 = (j%2 == 0) ? '1' : '0';

            if(s.charAt(j%n) != expectedCharS1) result1++;
            if(s.charAt(j%n) != expectedCharS2) result2++;

            if(j -i + 1 > n)
            {
                expectedCharS1 = (i%2 == 0) ? '0' : '1';
                expectedCharS2 = (i%2 == 0) ? '1' : '0';

                if(s.charAt(i%n) != expectedCharS1) result1--;
                if(s.charAt(i%n) != expectedCharS2) result2--;
                i++;
            }

            if(j-i+1 == n)
            {
                result = Math.min(result, Math.min(result1, result2));
            }

            j++;
        }

        return result;
    }
}