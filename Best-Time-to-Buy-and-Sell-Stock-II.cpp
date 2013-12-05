class Solution {
public:
    int maxProfit(vector<int> &prices) {
        //because you must sell the stock before you buy again.
        //so we process the array like(we use 3 4 1 4 3 5 to explain): 
        //1. we only need to process the increase subarray, such as {3,4},{1,4},{3,5}, not {1,4,3}(3<4)
        //2. we scan every element, if it less than its previous element,
        //   then we get an increase subarray(may contain only *one* element) end at the previous element.
        //   add the sum to ret(the answer we will return), and update the 
        //   small element of the increase subarray.
        //3. add the last increase subarray to the answer, because we find
        //   an increase subarray after we go over the subarray, such as
        //   we find the {3, 4} when we process item {1}. but, there isn't
        //   an element after the last item of the array.
        
        //the answer we will return
        int ret = 0;
        //len: the array size
        int len = prices.size();
        //if the array's element is less than 2, then, return 0 directly.
        if(len<2)
            return 0;
        //now: the smallest item of the current increase subarray
        //first, we set to prices[0]
        int now = prices[0];
        //process prices[1] to prices[len-1]
        for(int i=1; i< len; ++i)
            {
                //if we find an increase subarray
                if(prices[i]<prices[i-1]) 
                    {
                        //add the profit to the answer
                        ret += prices[i-1] - now;
                        //updates the smallest item of the current increase subarray
                        now = prices[i];
                    }
            }
        //adds the last increase subarray's profit to the answer
        ret += prices[len-1]-now;
        //return the answer
        return ret;
    }
}; 
