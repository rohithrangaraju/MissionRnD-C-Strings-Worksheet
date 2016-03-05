/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
int enter(char *str, int num,int i);
int enter1(char *str, int x, int i);
void reverse(char *str, int start, int end);

void number_to_str(float number, char *str, int afterdecimal){

	if (number > 0){
		int num = (int)number;
		float x = number - (float)num;
		if (number - num != 0){
			int i;
			//printf("%f",x);
			i = enter(str, num, 0);
			printf("\n%d", i);
			int k = i - 1;
			printf("\n%d\n", k);
			reverse(str, 0, k);
			//printf("\n%d",i);
			str[i] = '.';
			int u = i + 1;
			//puts(str);
			//printf("%d\n",i);
			while (afterdecimal--){
				x = x * 10;
			}
			i = enter1(str, x, i);
			printf("%d\n", i);
			str[++i] = '\0';
			printf("%d\n", i);
			reverse(str, u, i - 1);

		}
		else if (number - num == 0 && number > 0){
			int i;
			//printf("%f",x);
			i = enter(str, num, 0);
			printf("\n%d", i);
			int k = i - 1;
			printf("\n%d\n", k);
			reverse(str, 0, k);
			//printf("\n%d",i);
			str[i] = '\0';
		}
	}

	else if (number < 0){
		number = (-1)*number;
		int i;
		int num = (int)number;
		float x = number - (float)num;
		if (number - num == 0){
			str[0] = '-';
			i = enter(str, num, 1);
			//	printf("\n%d", i);
			int k = i - 1;
			//printf("\n%d\n", k);
			reverse(str, 1, k);
			//printf("\n%d",i);
			str[i] = '\0';
		}

	 else if (number-num!=0){
		//number = (-1)*number;
		int i;
		int num = (int)number;
		float x = number - (float)num;
		str[0] = '-';
		i = enter(str, num, 1);
		//	printf("\n%d", i);
		int k = i - 1;
		//printf("\n%d\n", k);
		reverse(str, 1, k);
		//printf("\n%d",i);
		str[i] = '.';
		int u = i + 1;
		//puts(str);
		//printf("%d\n",i);
		while (afterdecimal--){
			x = x * 10;
		}
		i = enter1(str, x, i);
		printf("%d\n", i);
		str[++i] = '\0';
		printf("%d\n", i);
		reverse(str, u, i - 1);


	}
	}
}
int enter(char *str, int num, int i){
	int t;
	while (num != 0){
		t = num % 10;
		str[i++] = t + '0';
		num = num / 10;
	}
	return i;

}
void reverse(char *str, int start, int end){
	int temp;
	while (start < end){
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}

}
int enter1(char *str, int num, int i){
	int t;
	while (num != 0){
		t = num % 10;
		str[++i] = t + '0';
		num = num / 10;
		//i++;
	}
	return i;

}

