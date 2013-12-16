class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        //binary  search!!!!!!!!!
        int r = matrix.size();
        int c = matrix[0].size();
        //@l : low boundary
        //@h : upper boundary
        int h = r * c-1;
        int l = 0;
        //while l is less than h
        while(l <= h)
            {
                //@mid midlle positon of the current interval
               int mid = (l+h)>>1;
               //if we have found it
               if(matrix[mid/c][mid%c] == target)
                {
                    return true;
                }
               //updates the boundary!!!!!!
               if(matrix[mid/c][mid%c] > target)
                {
                    h = mid-1;
                }
               else
                {
                    l = mid+1;
                }
            }
        //return false!!!!!
        return false;
    }
}; 
