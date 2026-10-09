class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> vec;
	int i = 0;
	int j =0;
    int lastNum = INT_MIN;
	while(i< nums1.size() && j < nums2.size()){
		if(nums1[i] ==nums2[j])
		{
			if(lastNum != nums1[i]){
                lastNum = nums1[i];
                vec.push_back(nums1[i]);
            }
			i++;
			j++;
		}
		else if(nums1[i] < nums2[j]){
			i++;
		}
		else{
			j++;
		}
	}
	return vec;
    }
};