class Solution {
public:
	int singleNumber(int A[], int n) {
		//use xor to kick off the numbers which apper twice
		int ret = 0;
		for(int i=0; i<n; ++i)
			ret ^= A[i];
		return ret;
	}
}
