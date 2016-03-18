/*
OVERVIEW:  
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/
//sir here i am solving the above problem using knuth morris pratt algorithm.Dividing the string2 into words and sending each word as a pattern to my kmp function.

#include <stdio.h>
#include <malloc.h>

#define SIZE 31
int kmp(char *pat, char *txt);
void Lps(char *pat, int M, int *lps);
char ** commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL) return NULL;
	char** Res = (char**)calloc(SIZE, sizeof(char*));
	int i, j, k;
	for (i = 0; i < 31; i++){
		Res[i] = (char*)calloc(10, sizeof(char));
	}
	char a[10][20];
	if (str2[0] == ' '){
		
		i = 1;
		k = 0; j = 0;
		while (str2[i] != '\0'){
			if (str2[i] == ' '){
				a[k][j] = '\0';
				k++;
				j = 0;
			}
			else{
				a[k][j++] = str2[i];
			}
			i++;
		}
		a[k][j] = '\0';
	}
	else{
		i = 0;
		k = 0; j = 0;
		while (str2[i] != '\0'){
			if (str2[i] == ' '){
				a[k][j] = '\0';
				k++;
				j = 0;
			}
			else{
				a[k][j++] = str2[i];
			}
			i++;
		}
		a[k][j] = '\0';
	}
	char c[100];
	int st = 0, x, z = 0;
	for (i = 0; i <= k; i++){
		j = 0;
		st = 0;
		while (a[i][j] != '\0'){
			c[st++] = a[i][j];
			j++;
		}
		c[st] = '\0';
		x = kmp(c, str1);
		if (x == 1){
			int w,v;
			v=w=0;
			while(a[i][v] != '\0'){
				Res[z][w] = a[i][v];
			      w++; v++;
			}
			z++;
		}
	}
	if (x == -1)
		return NULL;
	else
		return Res;

}
int kmp(char *pat, char *txt){
	int i, j;
	for (i = 0; pat[i] != '\0'; i++);
	for (j = 0; txt[j] != '\0'; j++);
	int M = i;
	int N = j;
	int count = -1;
	int *lps = (int *)malloc(sizeof(int)*M);
	Lps(pat, M, lps);
	j = 0;
	i = 0;
	while (i < N)
	{
		if (pat[j] == txt[i])
		{
			j++;
			i++;
		}

		if (j == M)
		{
			count = 1;
			j = lps[j - 1];
        }
		else if (i < N && pat[j] != txt[i])
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}

	free(lps);
	if(count==1) 
		return 1;
	else 
		return -1;
}

void Lps(char *pat, int M, int *lps)
{
	int len = 0;
	int	i;

	lps[0] = 0; 
	i = 1;
	while (i < M)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
			{
				len = lps[len - 1];


			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}