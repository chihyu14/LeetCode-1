Solution-I:
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        //insert all positive numbers into a set
        //then loop the set to find the missing positive number
        set<int> tmp;
        //insert all positive numbers into tmp
        for(int i=0; i<n; ++i)
        {
            if(A[i]>0)
                tmp.insert(A[i]);
        }
        //loop all the numbers in the set
        set<int>::iterator ite = tmp.begin();
        int l = 1;
        while(ite != tmp.end())
        {
            if(*ite != l)////if l is missing
                break;
            ++ite;
            ++l;
        }
        return l;//return the missing number
    }
};