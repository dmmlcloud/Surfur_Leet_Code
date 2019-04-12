#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int take = -1;
        int profit = 0;
        if(prices.empty() || prices.size() == 1)
            return profit;
        for(int i = 0; i < prices.size(); i++){
            if(take == -1){
                if(i+1 == prices.size())
                    break;
                else if(prices[i] >= prices[i+1])
                    continue;
                else
                    take = prices[i];
            }else{
                if(i+1 == prices.size())
                    profit = profit + prices[i]-take;
                else if(prices[i] < prices[i+1])
                    continue;
                else if(prices[i] >= prices[i+1]){
                    profit = profit + prices[i] - take;
                    take = -1;
                }
            }
        }
        return profit;
    }
};