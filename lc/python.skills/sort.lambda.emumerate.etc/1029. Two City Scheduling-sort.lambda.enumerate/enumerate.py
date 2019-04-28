class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        return sum([v[i // (len(costs)//2)] for i, v in enumerate(sorted(costs, key=lambda x: x[0] - x[1]))])
