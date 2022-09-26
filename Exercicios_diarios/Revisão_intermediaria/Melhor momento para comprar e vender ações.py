class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        menor = INT_MAX
        op = 0
        pist = 0

        for (int i=0
             i < prices.size()
             i++)
        {
            if (prices[i] < menor)
            {
                menor = prices[i]
            }
            pist = prices[i] - menor
            if (op < pist)
            {
                op = pist
            }
        }
        return op
    }
}
