//ƥ����Ч������
//LeetCode 20

//����һ����������ƥ������

bool isValid(char* s) 
{
	//�жϳ��ȣ�����һ���ǲ�ƥ���

	if (strlen(s) % 2) {
		return false;
	}

	//�մ�����true

	if (strlen(s) == 0) {
		return true;
	}

	int i = 0, left = 0, right = 0, k = 0;
	char str[10000];

	//��һ��Ԫ���Ƿ����ŵ������ֱ�ӷ��ش���

	if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
		return false;
	}

	//��������

	while (s[i] != '\0') 
	{
		//�����Ŵ�������

		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			str[k++] = s[i++];
			left++;
		}

		//������

		else 
		{
			k--;
			right++;

			//ƥ�䣬�Ƴ���Ӧ��������

			if (str[k] == '(' && s[i] == ')') {
				i++;
			}
			else if (str[k] == '[' && s[i] == ']') {
				i++;
			}
			else if (str[k] == '{' && s[i] == '}') {
				i++;
			}

			//��ƥ��ֱ�ӷ���false

			else {
				return false;
			}
		}
	}

	//�����п��ܻ����������е�������
	//������黹�����ݵĻ�
	//����false

	if (left == right) {
		return true;
	}
	else {
		return false;
	}
}

//�����������Լ�д��ջ�Ĳ��������ƥ��

typedef int DataType;

typedef struct Stack
{
	DataType* array;
	int capacity;
	int size;
}Stack;

//ջ�ĳ�ʼ��

void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = (DataType*)malloc(sizeof(DataType) * 10);
	ps->capacity = 10;
	ps->size = 0;
}

//�ж�ջ�Ƿ��ã�������

void CheckCapacity(Stack* ps)
{
	if (ps->size >= ps->capacity)
	{
		//�����¿ռ�

		int newCapacity = ps->capacity * 2;
		DataType* temp = (DataType*)malloc(sizeof(DataType) * newCapacity);

		if (temp)
		{
			//����Ԫ��

			//memcpy(temp, ps->array, sizeof(DataType) * ps->capacity);


			for (int i = 0; i < ps->size; i++)
			{
				temp[i] = ps->array[i];
			}

			//�ͷžɿռ�

			free(ps->array);
			ps->array = temp;
			ps->capacity = newCapacity;
		}
	}
}


//��ջ

void StackPush(Stack* ps, DataType data)
{
	assert(ps);

	//�ж��Ƿ�ռ䲻����������

	CheckCapacity(ps);
	//����Ԫ��
	ps->array[ps->size] = data;
	ps->size++;
}


//�ж�ջ�Ƿ�Ϊ��

int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->size;
}

//��ջ

void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
	{
		return;
	}
	ps->size--;
}

//��ȡջ��Ԫ��

int StackTop(Stack* ps)
{
	assert(ps);
	return ps->array[ps->size - 1];
}

//��ȡջ����ЧԪ�صĸ���

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}


//����ջ

void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->array);
	ps->capacity = 0;
	ps->size = 0;
}

//������ջ����ز���

bool isValid(char* s)
{
	//Ϊ��ֱ�ӷ���true

	if (s == NULL)
	{
		return true;
	}

	int size = strlen(s);

	//ջ�ĳ�ʼ��

	Stack st;
	StackInit(&st);

	//����

	for (int i = 0; i < size; i++)
	{
		//���������ž�ѹջ

		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			StackPush(&st, s[i]);
		}

		//������

		else
		{
			//ջ��û������

			if (StackEmpty(&st))
			{
				return false;
			}

			//ȡ��ջ�������ţ�����ƥ��

			char ch = StackTop(&st);

			//ƥ��ɹ�����ջ

			if ((ch == '(' && s[i] == ')') || (ch == '[' && s[i] == ']') || (ch == '{' && s[i] == '}'))
			{
				StackPop(&st);
			}

			//ʧ�ܣ�����false

			else
			{
				return false;
			}
		}
	}

	//�����������鿴ջ���Ƿ�������
	//û�����ŷ���true

	if (!StackEmpty(&st))
	{
		return false;
	}
	return true;
}