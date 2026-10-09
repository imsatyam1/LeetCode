class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st;
        int ans = -1;

        for(int &num: nums){
            if(st.count(-num)){
                ans = max(ans, abs(num));
            }
            st.insert(num);
        }
        return ans;
    }
};