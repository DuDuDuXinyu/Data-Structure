#include <iostream>

using namespace std;

//��������ֱ�Ӳ�������

void InsertSort(int* arr, int size)
{
	int i = 1;
	for (; i < size; i++)
	{
		/*����д���е��˷�ʱ�䣬ÿ�αȽϳɹ���Ҫ����λ��
		while (i > 0 && arr[i - 1] < arr[i])
		{
			int temp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = temp;
			i--;
		}*/

		int temp = arr[i], j = i - 1;
		while (i > 0 && temp < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		if (j != i - 1)
			arr[j + 1] = temp;
	}
}

//ϣ�����򡪡�����������Ż�

void ShellSort(int* arr, int size)
{
	int gap = size / 2;

	while (gap >= 1)
	{
		for (int i = gap; i < size; i++)
		{
			int key = arr[i];
			int end = i - gap;

			while (end >= 0 && key < arr[end])
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			if (end != i - gap)
				arr[end + gap] = key;
		}
		gap /= 2;
	}
}

// ѡ������ 

void swap(int* arr, int num1, int num2)
{
	int temp = arr[num1];
	arr[num1] = arr[num2];
	arr[num2] = temp;
}

void SelectSort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int j = i;
		int min = i;
		for (; j < size; j++)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		if (i != min)
			swap(arr, min, i);
	}
}

// ������ 

void Swap(int* left, int* right)
{
	int temp = *left;
	* left = *right;
	*right = temp;
}

void AdjustDwon(int* arr, int size, int parent)
{
	//ȷ���ýڵ�����ӵ�λ��

	int child = parent * 2 + 1;

	while (child < size)
	{
		//�ҵ��������������ĺ���

		if (child + 1 < size && arr[child] < arr[child + 1])
			child += 1;

		//���˫���Ƿ�������ĺ���

		if (arr[parent] < arr[child])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}
void HeapSort(int* arr, int size)
{
	//����

	for (int root = (size - 2) >> 1; root >= 0; root--)
	{
		AdjustDwon(arr, size, root);
	}

	//��ʼ����

	int end = size - 1;
	while (end)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDwon(arr, end, 0);
		end--;
	}
}
// ð������ 
#if 0
void BubbleSort(int* arr, int size)
{
	int i = 0;
	for (; i < size; i++)
	{
		int j = 1;
		for (; j < size - i; j++)
		{
			if (arr[j] > arr[j - 1])
			{
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}
#endif

void BubbleSort(int* arr, int size)
{
	int i = 0;
	for (; i < size - 1; i++)
	{
		int j = 0;
		int end = 0;
		for (; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				end = 1;
			}
		}
		if (end == 0)
			return;
	}
}

// ��������ݹ�ʵ�� 

//������ȡֵΪ�м������

int GetIndexMid(int* arr, int left, int right)
{
	//�������м�ֵ��һ��СС�ļ���
	//��������Сֵ+�����Ĳ��һ��
	//����������Ч�ı�������Խ�����������

	int mid = left + ((right - left) >> 1);

	if (arr[left] < arr[right])
	{
		if (arr[mid] < arr[left])
			return left;
		else if (arr[mid] > arr[right])
			return right ;
		else
			return mid;
	}
	else {
		if (arr[mid] > arr[left])
			return left;
		else if (arr[mid] < arr[right])
			return right;
		else
			return mid;
	}
}

//��������hoare�汾 
int PartSort1(int* arr, int left, int right)
{
	int end = right;
	int key;
	int mid = GetIndexMid(arr, left, right);

	if (mid != end)
	{
		int temp = arr[mid];
		arr[mid] = arr[end];
		arr[end] = temp;
	}

	key = arr[right];

	while (left < right)
	{
		while (left < right && arr[left] <= key)
			left++;

		while (left < right && arr[right] >= key)
			right--;
		if (left < right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}

	if (left != end)
	{
		int temp = arr[left];
		arr[left] = arr[end];
		arr[end] = temp;
	}

	return left;
}

// ���������ڿӷ� 
int PartSort2(int* arr, int left, int right)
{
	int end = right;
	int key;
	int mid = GetIndexMid(arr, left, right);

	if (mid != end)
	{
		int temp = arr[mid];
		arr[mid] = arr[end];
		arr[end] = temp;
	}

	key = arr[right];

	while (left < right)
	{
		//�ҵıȻ�׼ֵ���ֵ

		while (left < right && arr[left] <= key)
			left++;

		//��left��ֵ����right�Ŀ�
		//left����һ���¿�

		if (left < right)
			arr[right--] = arr[left];

		//�ҵ��Ȼ�׼ֵС��ֵ

		while (left < right && arr[right] >= key)
			right--;

		//��right��ֵ����left�Ŀ�
		//right����һ���¿�

		if (left < right)
			arr[left++] = arr[right];
	}

	//��׼ֵ�������Ŀ�

	arr[left] = key;
	return left;
}

// ��������ǰ��ָ�뷨 

int PartSort3(int* arr, int left, int right)
{
	int cur = left;
	int prev = left - 1;
	int mid = GetIndexMid(arr, left, right);

	if (mid != right)
	{
		int temp = arr[mid];
		arr[mid] = arr[right];
		arr[right] = temp;
	}
	int key = arr[right];

	while (cur < right)
	{
		if (arr[cur] < key && ++prev != cur)
		{
			int temp = arr[cur];
			arr[cur] = arr[prev];
			arr[prev] = temp;
		}

		cur++;
	}
	if (++prev != right)
	{
		int temp = arr[prev];
		arr[prev] = arr[right];
		arr[right] = temp;
	}
	return prev;
}

void QuickSort(int* arr, int left, int right)
{
	if (right - left > 1)
	{
		int mid = PartSort3(arr, left, right);
		QuickSort(arr, left, mid - 1);
		QuickSort(arr, mid + 1, right);
	}
}

// �������� �ǵݹ�ʵ�� void QuickSortNonR(int* a, int left, int right)

// �鲢����ݹ�ʵ�� void MergeSort(int* a, int n) 
// �鲢����ǵݹ�ʵ�� void MergeSortNonR(int* a, int n)

// �������� void CountSort(int* a, int n
int main()
{
	int arr[] = { 5,8,9,0,3,1,6,2,7,4 };

	QuickSort(arr, 0,sizeof(arr)/sizeof(arr[0])-1);

	for (auto i : arr)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}