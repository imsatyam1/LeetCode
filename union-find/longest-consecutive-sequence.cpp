class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for(int i=0; i<nums.size(); i++)
        {
            st.insert(nums[i]);
        }

        int maxLength = 0; 

        for(auto &it: st)
        {
            if(st.find(it -1) == st.end())
            {
                int length = 1;
                int x = it;

                while(st.find(x+1) != st.end())
                {
                    length++;
                    x = x+1;
                }

                maxLength = max(maxLength, length);
            }
        }
        return maxLength;
    }
};