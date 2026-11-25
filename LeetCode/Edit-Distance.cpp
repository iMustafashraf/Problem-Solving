// ===================[ Dynamic Programming - Top Down ]===================

class Solution {
public:
string w1, w2;
int memory[501][501];

    int minO(int fir, int sec){
        if(fir < 0)
            return sec + 1;

        if(sec < 0)
            return fir + 1;

        int &ret = memory[fir][sec];
        if(ret != -1)
            return ret;

        if(w1[fir] == w2[sec])
            return minO(fir - 1, sec - 1); // nothing to do

        auto add = 1 + minO(fir - 1, sec); // addition
        auto del = 1 + minO(fir, sec - 1); // Deletion
        auto rep = 1 + minO(fir - 1, sec - 1); // Replace

        return ret = min(min(add, del), rep);
    }

    int minDistance(string word1, string word2) {
        w1 = word1, w2 = word2;
        memset(memory, -1, sizeof(memory));
        return minO(w1.size() - 1, w2.size() - 1);
    }
};
