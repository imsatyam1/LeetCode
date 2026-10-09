class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int first = 1;   // ways for 1 stair
        int second = 2;  // ways for 2 stairs

        for (int i = 3; i <= n; i++) {
            int third = first + second;

            first = second;
            second = third;
        }

        return second;
    }
};