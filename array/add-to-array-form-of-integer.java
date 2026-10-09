class Solution {
    public List<Integer> addToArrayForm(int[] num, int k) {
        List<Integer> result = new ArrayList<>();
        int carry = 0;
        int i = num.length - 1;

        while (i >= 0 || k > 0 || carry > 0) {
            int digit = carry;

            if (i >= 0) {
                digit += num[i];
                i--;
            }
            if (k > 0) {
                digit += k % 10;
                k /= 10;
            }

            result.add(digit % 10);
            carry = digit / 10;
        }

        Collections.reverse(result);
        return result;
    }
}