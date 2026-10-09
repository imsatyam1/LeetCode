class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        vector<int> vec(1001, 0);
        int totalSkill = 0;

        for(int num: skill){
            totalSkill += num;
            vec[num]++;
        }

        int teams = n/2;
        if(totalSkill%teams != 0) return -1;

        int skillEachTeam = totalSkill/teams;

        long long chem = 0;

        for(int i=0; i<n; i++){
            int currSkill = skill[i];
            int reqSkill = skillEachTeam - currSkill;

            if(vec[reqSkill] <= 0){
                return -1;
            }

            chem += (long long)currSkill * (long long)(reqSkill);
            vec[reqSkill] -= 1;
        }
        return chem/2;
    }
};