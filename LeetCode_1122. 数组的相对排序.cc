int* relativeSortArray(int *arr1, int arr1Size, int *arr2, int arr2Size,int *returnSize)
{
	int arr[1001] = { 0 };

	for (int i = 0; i<arr1Size; i++)
	{
		arr[arr1[i]]++;
	}

	int j = 0;

	for (int i = 0; i<arr2Size; i++)
	{
		while (arr[arr2[i]] > 0)
		{
			arr1[j] = arr2[i];
			j++;
			arr[arr2[i]]--;
		}
	}

	for (int i = 0; i<1001; i++)
	{
		while (arr[i] > 0)
		{
			arr1[j++] = i;
			arr[i]--;
		}
	}

	*returnSize = arr1Size;
	return arr1;
}