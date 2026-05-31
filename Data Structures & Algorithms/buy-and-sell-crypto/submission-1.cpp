class Solution
{
   public:
    int maxProfit(vector<int>& prices)
    {
        int buy = INT_MAX;
        int maxProfit = 0;
    
        for (int price : prices)
        {
            buy = std::min(buy, price);
            maxProfit = std::max(maxProfit, price - buy);
        }
        return (maxProfit);
    }
};
