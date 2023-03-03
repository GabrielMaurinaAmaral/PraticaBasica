class Solution:
    def pivotIndex(self, nums: list[int]) -> int:
        total, esquerda, direita = sum(nums), 0, 0
        for i in range(len(nums)):
            direita = total-esquerda-nums[i]
            if direita == esquerda:
                return i
            esquerda += nums[i]
        return -1
