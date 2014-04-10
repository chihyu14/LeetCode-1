class Solution {
//use a auxilary array a[] to hold the candies of each child has
//then, if ratings[i]>ratings[i-1], we set a[i]=a[i-1]+1
//and, we do this reverse, so, all child with higher rating get more candies than their neighbors
public:
    int candy(vector<int> &ratings) {
        int size = ratings.size();
        //@a: hold the candies of each child has
        vector<int> a(size, 1);
        int i, j;
        //set all a[i] to a[i-1]+1 if ratings[i]>ratings[i-1]
        for(i=0; i<size; i = j)
        {
            for(j=i+1; j<size; ++j)
            {
                if(ratings[j]>ratings[j-1])
                {
                    a[j] = a[j-1]+1;
                }
                else
                    break;
            }
        }
        //set all a[i] to a[i+1]+1 if ratings[i]>ratings[i+1]
        for(i=size-1; i>=0; i=j)
        {
            add = 1;
            for(j=i-1; j>=0; --j)
            {
                if(ratings[j]>ratings[j+1])
                {
                    if(a[j]<=a[j+1])
                        a[j] = a[j+1]+1;
                }
                else
                    break;
            }
        }
        return accumulate(a.begin(), a.end(), 0);
    }
};