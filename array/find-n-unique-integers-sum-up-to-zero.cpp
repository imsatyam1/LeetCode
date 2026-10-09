class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;

        if(n==1) result.push_back(0);

        else if(n%2 == 0){
            for(int i=0; i<n/2; i++){
                result.push_back(-(i+1));
                result.push_back(i+1);
            }
        }
        else{
            result.push_back(0);
            for(int i=0; i<n/2; i++){
                result.push_back(-(i+1));
                result.push_back(i+1);
            }
        }
        return result;
    }
};