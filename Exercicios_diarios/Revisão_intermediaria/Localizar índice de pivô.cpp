class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int direita = 0, esquerda = 0;
        for (int &n : nums) // equivaentea ao for n in nums em 
        {
            direita += n;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (esquerda == direita - esquerda - nums[i])
            {
                return i;
            }
            esquerda += nums[i];
        }
        return -1;
    }
};

