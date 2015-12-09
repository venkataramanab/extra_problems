#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct test
{
	int input[10], size;
}test[7] = { 
	{ { 0, 0, 0, 0 }, 4 },//zero output
	{ { 0, 0, -100, -1 }, 4 },
	{ { -1,-2,-3,-4 }, 4 },//negative sum
	{ { -1 }, 1 },
	{ { 1, 2, 3, 4, 5, -5 }, 6 },//positive sum
	{ { 1, 2, 3, 4}, 4},
	{ { 3, 5, -15, 2, 4 }, 5}
};
int maxSum(int *Arr, int size)
{
	int  sum, max_sum=Arr[0];
	for (int i=0; i < size; i++)
	{
		sum = 0;
		for (int j = i; j < size; j++)
		{
			sum =sum + Arr[j];
			if (sum > max_sum){
				max_sum = sum;
			}	
		}
	}
	printf("\n max sum is %d", max_sum);
	return max_sum;
}
void main()
{
	for (int i = 0; i < 7; i++){
		maxSum(test[i].input, test[i].size);
	}
	_getch();
}