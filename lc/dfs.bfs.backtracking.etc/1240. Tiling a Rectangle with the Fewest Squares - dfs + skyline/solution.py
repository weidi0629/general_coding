/*
用skyline的思维把二维的图变成一维
代码解释的很详细了，下面中文的是自己补充的
*/

def tilingRectangle(self, width, height):
		
		
        # use area_left as a heuristic function to eliminate unworthy search branches
        # remove the memo used to cache best usedCount obtained for each skyline state,
        # it seems that the collision is quite scarse compared to all the states we had to store.

        # The main idea is that, if there exists a solution,
        # we can always fill in the squares from bottom up.
        # That means any state during this "filling" process can
        # be encoded as a skyline (array of heights at each position)
        # NOTE
        # y = skyline[x] contributes a line at y, from x to x + 1. This eliminates
        # ambiguity at the edge, where there may be edges of 2 square at 1 x position.
        # e.g.
        # placing a 1x1 square at bottom left of 2x1 rectangle, 
        # the skyline is [1, 0]

        # heuristic: given area left to be filled,
        # calculate the least number of squares that can sum up to it.
        # this will be the absolute lower bound for that area.
        # store the result for faster access
        '''
        这个小dp是非常宽泛的优化， 可以说是最理想的情况下的用量。 
        比如横过来的 area = 5， [][][][][] 可能只要2个 ： 4+1
        [][]
        [][] + [] 
        但实际要 5个，因为题设要的正方体。所以这个求的只是一个最优的情况
        '''
        total_area = width * height
        dp = [-1 for i in range(total_area +1)]
        dp[0] = 0
        for i in range(1, total_area + 1):
            # try each possible k
            dp[i] = 1 + min(dp[i - k**2] for k in range(1, int(i ** 0.5) + 1))
        self.res = total_area


        def dfs(skyline, usedCount, area_left):
            # [List Int], Int, Int -> Void
            # - given state as skyline, 
            # - the number of squares already used, 
            # - area left to be filled
            # try to find the min square tiling
            # continuing from this point.

            # no need to search further if the best we can do with this path
            # is no better than the best result so far
            if usedCount + dp[area_left] >= self.res:
                return;

            # solution found iff skyline overlaps with the ceiling
            filled = True
            # the algorithm places squares at left first, so we consider heights only on right edge
            # minimum height and the position.
            min_pos = 0
            min_height = skyline[0]
            for pos in range(width):
                # not filled if any skyline doesn't touch the ceiling
                if (skyline[pos] < height):
                    filled = False
                # update lowest spot
                if (skyline[pos] < min_height):
                    min_pos = pos
                    min_height = skyline[pos]

            # already filled, another solution found.
            if filled:
                self.res = min(usedCount, self.res)
                return
            
            # try to fill the leftmost lowest void, find the maximum size of square
            # we can put there. end represents the x-coordinate of right edge
            # NOTE x = end is where the right edge of this newly placed square will be
            end = min_pos + 1;
            # in order to increment end:
            # - right edge stays in the rectangle 
            # - bottom edge must have same height
            # - top edge stays in the rectangle
            # 这个while只是看min hight的长度有多长
            while (end < width and \
                   skyline[end] == min_height and \
                   (end - min_pos + 1 + min_height) <= height):  # 最后这个因为题设要求每个part都是正方体，所以长度也是高度
                end += 1

            # try fill with larger square first, to exhaust more void
            # and potentially yield better search.
            for right_pos in range(end, min_pos, -1):
                # calcualte size of the square to be used
                sqr_height = right_pos - min_pos 

                new_skyline = list(skyline)
                # increase the skyline at relavent positions
                for i in range(min_pos, right_pos):
                    new_skyline[i] += sqr_height
                # continue dfs from here.
                dfs(new_skyline, usedCount + 1, area_left - sqr_height * sqr_height)
        
        skyline = [0 for i in range(width)]
        dfs(skyline, 0, total_area)

        return self.res;

    # TODO more optimizations
    # - store only (start_x, height) tuples instead, instead of the entire skyline
    #   this is bascially compression. Hopefully saves memory and reduces iteration time.
    # - Use A* algorithm. DFS with heuristics may still dives to unworthy states first.
