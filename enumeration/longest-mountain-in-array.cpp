class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int mid = 1;
        int length = 0;

        while(mid < n-1){
            if(arr[mid] > arr[mid -1] && arr[mid] > arr[mid+1]){
                int start = mid-1;
                int end = mid+1;

                while(start>0 && arr[start] > arr[start-1]) start--;
                while(end < n-1 && arr[end] > arr[end+1]) end++;

                length = max(length, end-start+1);

                mid = end;
            }
            else mid++;
        }
        return length;
    }
};