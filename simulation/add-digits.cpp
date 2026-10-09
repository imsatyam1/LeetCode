class Solution {
public:
    int addDigits(int num) {
        int sum;
        if(num == 0){
            return 0;
        }else{
            while(num>9){
            sum = 0;
            while(num > 0){
                sum += num%10;
                num /= 10;
            }
            num = sum;;
        }
        }
        return sum;
    }
};