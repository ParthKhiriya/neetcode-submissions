class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        mpp = {}

        for i, num in enumerate(nums):
            diff = target - num
            if diff in mpp:
                return [mpp[diff], i]
            mpp[num] = i
        
        