class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;

        if(x> arr[n-1]){
            for(int i=n-1; i>n-1-k; i--){
                ans.push_back(arr[i]);
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
        

        if(x < arr[0]){
            for(int i=0; i<k; i++){
                ans.push_back(arr[i]);
            }
            return ans;
        }

        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(arr[mid] == x){
                ans.push_back(arr[mid]);
                k--;
                low = mid+1;
                high = mid -1;
                break;
            }
            else if(arr[mid] < x){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        for(int i=0; i<k && low <=n-1 && high >=0;){
            if(abs(arr[low] -x) > abs(arr[high] -x)){
                ans.push_back(arr[high]);
                high--;
                k--;
            }
            else if(abs(arr[low] - x) < abs(arr[high] -x)){
                ans.push_back(arr[low]);
                low++;
                k--;
            }
            else if(abs(arr[low] -x) == abs(arr[high] -x)){
                if(low < high){
                    ans.push_back(arr[low]);
                    low++;
                    k--;
                }
                else if(high < low){
                    ans.push_back(arr[high]);
                    high--;
                    k--;
                }
            }
        }

        if((low ==n) && (k!= 0) && (high != -1)){
            for(int i=0; i<k; i++){
                ans.push_back(arr[high]);
                high--;
            }
        }
        else if((high == -1) && (k != 0) && (low != n)){
            for(int i=0; i<k; i++){
                ans.push_back(arr[low]);
                low++;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};