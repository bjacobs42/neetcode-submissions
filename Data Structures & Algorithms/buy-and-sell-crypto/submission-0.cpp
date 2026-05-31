class Solution
{
   public:
    int maxProfit(vector<int>& prices)
    {
        int i = 0;
        int highestProfit = 0;
    
        while (i < prices.size())
        {
            int buy = prices[i];
            int j = i + 1;

            while (j < prices.size()) 
            {
                int profit = prices[j] - buy;

                if (profit < 0)
                    break;
                highestProfit = std::max(profit, highestProfit);
                ++j;
            }
            i = j;
        }
        return (highestProfit);
    }
};
