struct Node
{
    int val, idx;//val: value idx: index of this value
    Node(int a, int b){val=a; idx=b;}
};
bool cmp(Node a, Node b)
{
    if(a.val<b.val)
        return true;
    return false;
}
//Solution: O(n)
//store numbers into vector<Node>, then, sort vecotr<Node>
//loop the first number, then, use binary search to find the second number
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int size = numbers.size();
        vector<Node> tmp;
        //transform all numbers into vector<Node>
        for(int i=0; i<size; ++i)
        {
            Node a(numbers[i], i+1);
            tmp.push_back(a);
        }
        //sort tmp
        sort(tmp.begin(), tmp.end(), cmp);
        int left, right;
        int mid, t;
        vector<int> ret;
        //loop the first number
        for(int i=0; i<size-1; ++i)
        {
            left = i+1;
            right = size-1;
            t = target - tmp[i].val;
            while(left<=right)//use binary search to find the second number
            {
                mid = (left+right)>>1;
                if(tmp[mid].val == t)//find the solution.
                {
                    int aa = tmp[i].idx;
                    int bb = tmp[mid].idx;
                    if(aa<bb)
                    {
                        ret.push_back(aa);
                        ret.push_back(bb);
                    }
                    else
                    {
                        ret.push_back(bb);
                        ret.push_back(aa);
                    }
                    return ret;//return the answer
                }
                if(tmp[mid].val>t)
                    right = mid-1;
                else
                    left = mid+1;
            }
        }
        return ret;
    }
};