class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long long, long long> mp1;
        unordered_map<long long, long long> mp2;

        int count = 0;

        int n = nums1.size();
        int m = nums2.size();

        int i =0;
        while(i< n-1){
            int j = i+1;
            while(j<n){
                long long int product = static_cast<long long>(nums1[i]) * static_cast<long long>(nums1[j]);
                mp1[product]++;
                
                j++;
            }
            i++;
        }

        int k =0;
        while(k< m-1){
            int l = k+1;
            while(l<m){
                long long product = static_cast<long long>(nums2[k]) * static_cast<long long>(nums2[l]);
                mp2[product]++;
                
                l++;
            }
            k++;
        }

        for(int i=0; i<n; i++){
            long long int square = static_cast<long long>(nums1[i]) * static_cast<long long>(nums1[i]);

            if(mp2.count(square)){
                count += mp2[square];
            }
        }

        for(int i=0; i<m; i++){
            long long square = static_cast<long long>(nums2[i]) * static_cast<long long>(nums2[i]);

            if(mp1.count(square)){
                count += mp1[square];
            }
        }

        return count;
    }
};