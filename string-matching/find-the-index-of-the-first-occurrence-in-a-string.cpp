class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int n1 = needle.length();

        for(int i=0; i<n; i++){
            int j = 0;
            while(j<n1 && haystack[i+j] == needle[j]){
                j++;
            }
            if(j==n1){
                return i;
            }
        }
        return -1;
    }
};