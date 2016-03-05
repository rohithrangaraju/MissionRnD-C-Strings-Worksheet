/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/

char KthIndexFromEnd(char *str, int K) {
	if (str == '\0') return '\0';
	int i;
	for (i = 0; str[i] != '\0'; i++);
	if (i < K || K<0) return '\0';
	else if (i > K){
	    return str[i - K - 1];
	}
	//else if (i<K || K < 0 || str == '\0') return '\0';
	else
		return '\0';
}