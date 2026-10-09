class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size() == 0) return {};
        vector<pair<int, int>> temp;
        
        for(int i=0; i< arr.size(); i++){
            temp.push_back({arr[i], i});
        }
        
        sort(temp.begin(), temp.end());
        
        int rank = 1;
        int prevValue = temp[0].first;
        
        for(auto &it: temp){
                if(it.first != prevValue){
                    rank++;
                }
                arr[it.second] = rank;
                prevValue = it.first;
            }
            return arr;
    }
};