//Same Solution as the Permutation without duplicates!!!
//1. Find the largest index k such that A[k] < A[k+1]
//2. Find the largets index l such that A[l] > A[k]
//3. Swap A[k] and A[l]
//4. Reverse all the elements from A[k+1] to A[n](n is the length of A[])
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        //copy num to tmp
        vector<int> tmp(num.begin(), num.end());
        //sort tmp
        sort(tmp.begin(), tmp.end());
        //@ret: answer we will return
        vector<vector<int> > ret;
        //add the initial vector into ret
        ret.push_back(tmp);
        //if tmp.size() is less than 2
        if(tmp.size() < 2)
            return ret;
        //generate all the permutations
        while(true)
        {
            //@idx: the largest index such that tmp[idx] < tmp[idx+1]
            //@i: the largest index such that tmp[i] > tmp[idx]
            int idx, i;
            //find the largest index such that tmp[idx] < tmp[idx+1]
            for(idx=tmp.size()-2; idx>=0; --idx)
            {
                if(tmp[idx]<tmp[idx+1])
                    break;
            }
            //if there's no index that tmp[idx] < tmp[idx+1], then break;
            if(idx<0)
                break;
            //find the largest index such that tmp[i] > tmp[idx]
            for(i=tmp.size()-1; i>=0; --i)
            {
                if(tmp[i]>tmp[idx])
                    break;
            }
            //swap tmp[idx] and tmp[i]
            int t = tmp[idx];
            tmp[idx] = tmp[i];
            tmp[i] = t;
            //reverse the sequence between tmp[idx+1] and tmp[tmp.size()-1]
            for(idx=idx+1,i=tmp.size()-1; idx<i; ++idx, --i)
            {
                t = tmp[idx];
                tmp[idx] = tmp[i];
                tmp[i] = t;
            }
            //add the permutation into ret
            ret.push_back(tmp);
        }
        return ret;
    }
}; 
