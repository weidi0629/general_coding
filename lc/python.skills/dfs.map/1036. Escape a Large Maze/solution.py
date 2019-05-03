def isEscapePossible(self, blocked, source, target):
        blocked = set(map(tuple, blocked))
        seen = set()

        def dfs(x, y, target, step=0):
            if not (0 <= x < 10**6 and 0 <= y < 10**6) or (x, y) in blocked or (x, y) in seen: return False
            seen.add((x, y))
            if step > 20000 or [x, y] == target: return True
            return dfs(x + 1, y, target, step + 1) or \
                dfs(x - 1, y, target, step + 1) or \
                dfs(x, y + 1, target, step + 1) or \
                dfs(x, y - 1, target, step + 1)
        return dfs(source[0], source[1], target) and dfs(target[0], target[1], source)
