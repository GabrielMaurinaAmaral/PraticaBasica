class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int menor = INT_MAX;
        int op = 0;
        int pist = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < menor)
            {
                menor = prices[i];
            }
            pist = prices[i] - menor;
            if (op < pist)
            {
                op = pist;
            }
        }
        return op;
    }
};