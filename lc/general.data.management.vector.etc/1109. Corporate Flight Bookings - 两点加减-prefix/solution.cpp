https://leetcode.com/problems/corporate-flight-bookings/discuss/328871/C%2B%2BJava-with-picture-O(n)

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n,0);
        for(auto& b:bookings){
            res[b[0]-1]+=b[2];
            if(b[1]<n) res[b[1]]-=b[2];
        }
        for(int i=1;i<n;i++) res[i]+=res[i-1];
        return res;
    }
