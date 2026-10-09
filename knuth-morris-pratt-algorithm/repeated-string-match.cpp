#define MOD 1000000007
#define BASE 256

class Solution {
    long long calculateHash(const string &str, int len){
        long long hashVal = 0;
        for(int i=0; i<len; i++){
            hashVal = (hashVal*BASE+str[i]) % MOD;
        }
        return hashVal;
    }

    bool rabin_karp(const string &a,const string &b, int repeat){
        string newStr = "";
        for(int i=0; i<repeat; i++){
            newStr += a;
        }

        int len1 = newStr.length();
        int len2 = b.length();

        if(len2 > len1) return false;

        long long hash_b = calculateHash(b, len2);
        long long hash_newStr = calculateHash(newStr, len2);

        long long power = 1;
        for(int i=1; i<len2; i++){
            power = (power*BASE)%MOD;
        }

        for(int i=0; i<= len1-len2; i++){
            if(hash_newStr == hash_b){
                if(newStr.substr(i, len2) == b) return true;
            }
            if(i < len1 - len2){
                hash_newStr = (hash_newStr - newStr[i] * power % MOD + MOD) % MOD;
                hash_newStr = (hash_newStr * BASE + newStr[i + len2]) % MOD;
            }
        }
        return false;
    }
public:
    int repeatedStringMatch(string a, string b) {
        int repeat = (b.length() / a.length());

        if(rabin_karp(a,b, repeat)) return repeat;
        if(rabin_karp(a,b, repeat+1)) return repeat+1;
        if(rabin_karp(a,b, repeat+2)) return repeat+2;

        return -1;
    }
};