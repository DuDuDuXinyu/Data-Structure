//堆排序

void HeapAdjust(int array[], int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child + 1] < array[child])
		{
			child += 1;
		}
		if (array[child] < array[parent])
		{
			int temp = array[child];
			array[child] = array[parent];
			array[parent] = temp;

			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

void HeapSort(int array[], int size)
{
	//建堆

	for (int root = (size - 2) >> 1; root = 0; root--)
	{
		HeapAdjust(array, size, root);
	}

	//采用堆删除的思想来进行排序

	int end = size - 1;
	while (end)
	{
		int temp = array[0];
		array[0] = array[end];
		array[end] = temp;

		HeapAdjust(array, end, 0);
		end--;
	}
}