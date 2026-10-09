class Solution {
    bool possibleToDis(int mid, vector<int> &quantities, int n){
        for(int &products: quantities){
            n -= (products + mid -1)/mid; // == ceil(products/mid)

            if(n<0) return false;
        }
        return true;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        
        int l =1; 
        int r = *max_element(begin(quantities), end(quantities));
        int result = 0;

        while(l<=r){
            int mid = l+(r-l)/2;
            if(possibleToDis(mid, quantities, n)){
                result = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return result;
    }
};