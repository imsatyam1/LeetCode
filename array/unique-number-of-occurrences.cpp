class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> vec;
        int i=0;
        while(i < arr.size()){
            int count = 1;
            for(int j=i+1; j<arr.size(); j++){
                if(arr[i] == arr[j]){
                    count++;
                }
                else{
                    break;
                }
            }
            vec.push_back(count);
            i=i+count;
        }

        sort(vec.begin(), vec.end());
        for(int i=1; i<vec.size(); i++){
            if(vec[i] == vec[i-1]){
                return false;
            }
        }
        return true;
    }
};