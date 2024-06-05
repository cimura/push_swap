void	swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

#include <stdlib.h>
#include <stdio.h>

int	bubble_sort(int arr[], int n)
{
	int i = 0;
	int j = 0;
	int count = 0;

	while (i < n - 1)
	{
		j = 0;
		while (j < n - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int main(int argc, char *argv[])
{
	int	arr[argc - 1];
	if (argc != 1)
	{
		for (int i = 0; i < argc - 1; i++)
		{
			arr[i] = atoi(argv[i + 1]);
		}
		
		int n = argc - 1;
		int count = bubble_sort
		(arr, n);

		printf("count: %d\n", count);

		int tmp = 0;
		// while (tmp < n)
		// {
		// 	printf("%d ", arr[tmp]);
		// 	tmp++;
		// }
		// printf("\n");
	}
}
