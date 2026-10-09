class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int minPrice = INT_MAX;
        int secMinPrice = INT_MAX;

        int n = prices.size();

        for(int &price: prices){
            if(price < minPrice){
                secMinPrice = minPrice;
                minPrice = price;
            }
            else{
                secMinPrice = min(secMinPrice, price);
            }
        }

        int totalPrice = minPrice + secMinPrice;
        int leftOverMoney = money - totalPrice;

        return (leftOverMoney < 0)? money: leftOverMoney;
    }
};