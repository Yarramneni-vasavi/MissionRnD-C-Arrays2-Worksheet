/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	struct transaction *result = NULL;
	if (A != NULL && B != NULL)
	{
		result = (struct transaction *)malloc(sizeof(transaction)*(ALen + BLen));
		int i = 0, j = 0, index = 0;
		while (j < BLen && i < ALen)
		{
			if (B[j].amount <= A[i].amount)
			{
				result[index] = B[j];
				j++;	index++;
			}
			else
			{
				result[index] = A[i];
				i++;	index++;
			}
		}
		if (index < (ALen + BLen) && j < BLen)
		{
			for (int h = j; h < BLen; h++)
			{
				result[index] = B[h];	index++;
			}
		}
		if (index < (ALen + BLen) && i < ALen)
		{
			for (int h = i; h < ALen; h++)
			{
				result[index] = A[h];	index++;
			}
		}
	}
	return result;
}