class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;

        int ltime = -1, rtime = -1;

        if(left.size() > 0) ltime = *max_element(left.begin(), left.end());

        if(right.size() > 0){
            rtime = *min_element(right.begin(), right.end());
            rtime = n-rtime;
        }

        return max(ltime, rtime);
    }
};