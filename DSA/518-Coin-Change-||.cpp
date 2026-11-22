class Solution {
public:
    vector<int> coinc;
    vector<vector<int> > memory;
    int am;

    int changed(int idx, int curr_sum){
        if(curr_sum == am)
            return 1; // +counter

        if(idx == coinc.size() || curr_sum > am)
            return 0;

        int &ret = memory[idx][curr_sum];
        if(ret != -1)
            return ret;

        int lev_me = changed(idx + 1, curr_sum);

        int take_me = 0;
        if(curr_sum + coinc[idx] <= am){
            take_me = changed(idx, curr_sum + coinc[idx]);
        }
        
        return ret = lev_me + take_me;
    }

    int change(int amount, vector<int>& coins) {
        coinc = coins;
        am = amount;
        memory.assign(coins.size() + 1, vector<int>(amount + 1, -1));   
        
        return changed(0, 0);
    }
};
