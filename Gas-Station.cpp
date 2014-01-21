class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        //if sum(gas) < sum(cost) then return -1
        if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
            return -1;
        //@size: number of gas
        //@l: current gas number
        int size = gas.size(), l=0;
        int t;
        for(int i=0; ;)
        {
            t = 0;
            int j;
            for(j=i, l=0; l<size; j=(j+1)%size)
            {
                //@t: remain gas in gas tank
                t += gas[j]-cost[j];
                if(t<0)//can't reach the next gas station
                    break;
                ++l;//
            }
            if(l == size)//find the start gas station
                return j;
            i = (j+1);//move to next gas station!!!
            //we don't have to test the gas stations between (i,j+1),
            //because they won't be the beginning of the travel!!!!
        }
    }
};
