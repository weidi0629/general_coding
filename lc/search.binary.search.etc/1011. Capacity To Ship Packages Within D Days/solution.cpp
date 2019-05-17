/*
相同的题还有 410. 
假设某个值是成立的。二分查找。
*/

int shipWithinDays(vector<int>& weights, int D) {
        int left = 0, right = 25000000;
        for (int w: weights)
            left = max(left, w);
        while (left < right) {
            int mid = (left + right) / 2, need = 1, cur = 0; // 假设mid是成立的
            for (int i = 0; i < weights.size() && need <= D; cur += weights[i++]) //自己做的时候把 need <= D 放在程序里，而这里放在条件里更好
                if (cur + weights[i] > mid) //这里是试探，后面超掉的那个i是不要的
                    cur = 0, need++;
            if (need > D) left = mid + 1;
            else right = mid;
        }
        return left;
    }
