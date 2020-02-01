class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        self.visited = set()
        graph = collections.defaultdict(set)
        self.heap = []
        
        for u, v, distance in edges:
            if distance <= distanceThreshold:
                graph[u].add((v, distance))
                graph[v].add((u, distance))
        
        def run_dijkstra(source):
            # bound by distanceThreshold
            heapq.heappush(self.heap, (distanceThreshold * -1, source))
            count = 0
            while self.heap:
                neg_remaining_distance, node = heapq.heappop(self.heap)
                remaining_distance = neg_remaining_distance * -1
                
                if node not in self.visited:
                    self.visited.add(node)
                    count += 1
                
                    for neighbor, distance in graph[node]:
                        # only add a neighbor if we can still reach neighbor
                        if neighbor not in self.visited and remaining_distance >= distance:
                            # negation to make sure heappop returns biggest remaining distance i.e. closest neighbor
                            # we always pick closest neighbor (dijsktra's greedy property)
                            heapq.heappush(self.heap, ((remaining_distance - distance) * -1, neighbor))
            return count - 1
        
        min_count, ans = float('inf'), -1
        for source in range(n):
            count = run_dijkstra(source)
            if count <= min_count:
                min_count = count
                ans = source
                
            self.visited = set()
        
        return ans 
