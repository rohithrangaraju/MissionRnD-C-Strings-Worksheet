/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
char* reverseSentence(char* str, int len){
	int i = 0;
	int j = len - 1;
	while (i<j){
		str[i] = str[i] ^ str[j];
		str[j] = str[i] ^ str[j];
		str[i] = str[i] ^ str[j];
		i++;
		j--;

	}
	return str;

}
char* reverseWord(char* str, int start, int last){

	//int i=start;
	//int j=last;
	//printf("sds");
	while (start<last){
		str[start] = str[start] ^ str[last];
		str[last] = str[start] ^ str[last];
		str[start] = str[start] ^ str[last];
		start++;
		last--;

	}
	return str;
}


void str_words_in_rev(char *input, int len){
	int i, j = 0;;
	for (i = 0; input[i] != '\0'; i++);
	reverseSentence(input, i);
	i = 0;
	do{
		if (input[j + 1] == '\0') reverseWord(input, i, j);
		else if (input[j] == ' '){

			reverseWord(input, i, j - 1);
			i = j + 1;
		}
		j++;
	} while (input[j] != '\0');
}
