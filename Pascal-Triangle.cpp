class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        //define the answer
        vector<vector<int> > ret(numRows);
        //run the loop to generate pascal'triangle
        for(int i=0; i<numRows; ++i)
        {
            //the first row 
            if(0 == i)
                {
                    ret[0].push_back(1);
                    continue;
                }
            //push the left most 1
            ret[i].push_back(1);
            //generate the 2nd to the one but last elements.
            for(int j=1; j<i; ++j)
                ret[i].push_back(ret[i-1][j-1]+ret[i-1][j]);
            //push the right most 1.
            ret[i].push_back(1);
        }
        //return the answer.
        return ret;
    }
}; 
