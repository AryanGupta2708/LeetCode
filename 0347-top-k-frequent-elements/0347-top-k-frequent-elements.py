class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        c = Counter(nums)
        k_most_frequent = c.most_common(k)
        result = [k[0] for k in k_most_frequent]
        return result