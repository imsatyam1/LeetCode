class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunkSum = 0;
        int normalSum = 0;

        int count = 0;

        for(int i=0; i<n; i++){
            chunkSum += arr[i];
            normalSum += i;

            if(chunkSum == normalSum) count++;
        }
        return count;
    }
};