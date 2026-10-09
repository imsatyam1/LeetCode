class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1){
            sort(begin(s), end(s));
        }
        string result = s;
        int n = s.length();
        for(int i=1; i<= n-1; i++){
            s = s.substr(1,n-1) + s.substr(0,1);
            result = min(s, result);
        }
        return result;
    }
};