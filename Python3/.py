class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        dic = dict()
        result = []
        
        for num in nums1:
            if num not in dic: dic[num] = 1
            elif num in dic: dic[num] += 1
        
        for num in nums2:
            if num in dic and dic[num] != 0:
                result.append(num)
                dic[num] -= 1
        
        return result
