class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        nums.sort()
        a = []
        for i in range(len(nums)):
            if(nums[i]==target):
                a.append(i)
        return a 
        