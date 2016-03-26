/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

int findSingleOccurenceNumber(int *A, int len) 
{
	int num = -1;
	if (A != 0)
	{
		int rem1 = 0, rem2 = 0, rem3 = 0, rem4 = 0;
		for (int i = 0; i < len; i++)
		{
			//adding all first bits of given numbers
			rem1 = rem1 + A[i] % 2;
			A[i] = A[i] / 2;
			//adding all second bits of given numbers
			rem2 = rem2 + A[i] % 2;
			A[i] = A[i] / 2;
			//adding all third bits of given numbers
			rem3 = rem3 + A[i] % 2;
			A[i] = A[i] / 2;
			//adding all fourth bits of given numbers
			rem4 = rem4 + A[i] % 2;
			A[i] = A[i] / 2;
		}
		//converting these remainder bits to integer gives number
		num = (8 * (rem4 % 3) + 4 * (rem3 % 3) + 2 * (rem2 % 3) + (rem1 % 3));
		if (num == 0)
			num = -1;
	}
	return num;
}