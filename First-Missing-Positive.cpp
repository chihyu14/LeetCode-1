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
Solution-II:
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        //store all numbers between [1,n] in t
        vector<int> t(n, 0);
        for(int i=0; i<n; ++i)
        {
            if(A[i]>0 && A[i]<=n)
                t[A[i]-1] = 1;
        }
        //loop vector t
        for(int i=0; i<n; ++i)
        {
            if(0 == t[i])//if (i+1) isn't inclueded in t
                return i+1;
        }
        return n+1;//missing positive number is n+1
    }
};