class Solution {
public:
    int maxProfit(vector<int> &prices) {
        //answer we want
        int ret = 0;
        int min;
        //if prices is empty, return 0
        if(0 == prices.size())
            return 0;
        int len = prices.size();
        //min is min{prices[0], ..., prices[i]}
        min = prices[0];
        for(int i = 1; i<len ; ++i)
            {
                //if {prices[i] - min} is bigger than ret
                //then update it
                if(ret < prices[i] - min)
                    ret = prices[i] - min;
                //updat min
                if(prices[i] < min)
                    min = prices[i];
            }
        //return the answer
        return ret;
    }
}; 
