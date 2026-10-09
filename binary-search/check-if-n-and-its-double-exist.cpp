class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int zeroCount = 0;
        for(int i=0; i<arr.size(); i++){
            int n = arr[i];
            if(n == 0) zeroCount++;
            auto findElement = find(arr.begin(), arr.end(), 2*n);
            if(n == 0 && zeroCount > 1) return true;
            if((n != 0) && (findElement != arr.end())) return true;
            
        }
        return false;
    }
};