class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto myComprator = [](int& num1, int& num2){
            string s1 = to_string(num1);
            string s2 = to_string(num2);

            return s1+s2 > s2+s1;
        };

        sort(begin(nums), end(nums), myComprator);

        if(nums[0] == 0) return "0";

        string result = "";

        for(auto &num: nums){
            result += to_string(num);
        }
        return result;
    }
};