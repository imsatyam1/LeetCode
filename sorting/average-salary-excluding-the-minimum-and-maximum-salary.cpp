class Solution {
public:
    double average(vector<int>& salary) {
        double ans = 0;

        int maxSalary = salary[0], minSalary =salary[0];

        for(int i=0; i<salary.size(); i++){
            maxSalary = max(maxSalary, salary[i]);
            minSalary = min(minSalary, salary[i]);
            ans += salary[i];
        }

        ans = ans - (maxSalary+minSalary);
        ans = ans/(salary.size()-2);
        return ans;
    }
};