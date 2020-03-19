//匹配有效的括号
//LeetCode 20

//方法一：用数组来匹配括号

bool isValid(char* s) 
{
	//判断长度，奇数一定是不匹配的

	if (strlen(s) % 2) {
		return false;
	}

	//空串返回true

	if (strlen(s) == 0) {
		return true;
	}

	int i = 0, left = 0, right = 0, k = 0;
	char str[10000];

	//第一个元素是反括号的情况，直接返回错误

	if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
		return false;
	}

	//遍历数组

	while (s[i] != '\0') 
	{
		//正括号存入数组

		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			str[k++] = s[i++];
			left++;
		}

		//反括号

		else 
		{
			k--;
			right++;

			//匹配，移除对应的正括号

			if (str[k] == '(' && s[i] == ')') {
				i++;
			}
			else if (str[k] == '[' && s[i] == ']') {
				i++;
			}
			else if (str[k] == '{' && s[i] == '}') {
				i++;
			}

			//不匹配直接返回false

			else {
				return false;
			}
		}
	}

	//结束有可能还有在数组中的正括号
	//如果数组还有数据的话
	//返回false

	if (left == right) {
		return true;
	}
	else {
		return false;
	}
}

//方法二：用自己写的栈的操作来完成匹配

typedef int DataType;

typedef struct Stack
{
	DataType* array;
	int capacity;
	int size;
}Stack;

//栈的初始化

void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = (DataType*)malloc(sizeof(DataType) * 10);
	ps->capacity = 10;
	ps->size = 0;
}

//判断栈是否够用，并扩容

void CheckCapacity(Stack* ps)
{
	if (ps->size >= ps->capacity)
	{
		//申请新空间

		int newCapacity = ps->capacity * 2;
		DataType* temp = (DataType*)malloc(sizeof(DataType) * newCapacity);

		if (temp)
		{
			//拷贝元素

			//memcpy(temp, ps->array, sizeof(DataType) * ps->capacity);


			for (int i = 0; i < ps->size; i++)
			{
				temp[i] = ps->array[i];
			}

			//释放旧空间

			free(ps->array);
			ps->array = temp;
			ps->capacity = newCapacity;
		}
	}
}


//入栈

void StackPush(Stack* ps, DataType data)
{
	assert(ps);

	//判断是否空间不够，并扩容

	CheckCapacity(ps);
	//插入元素
	ps->array[ps->size] = data;
	ps->size++;
}


//判断栈是否为空

int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->size;
}

//出栈

void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
	{
		return;
	}
	ps->size--;
}

//获取栈顶元素

int StackTop(Stack* ps)
{
	assert(ps);
	return ps->array[ps->size - 1];
}

//获取栈中有效元素的个数

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}


//销毁栈

void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->array);
	ps->capacity = 0;
	ps->size = 0;
}

//以上是栈的相关操作

bool isValid(char* s)
{
	//为空直接返回true

	if (s == NULL)
	{
		return true;
	}

	int size = strlen(s);

	//栈的初始化

	Stack st;
	StackInit(&st);

	//遍历

	for (int i = 0; i < size; i++)
	{
		//遇见左括号就压栈

		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			StackPush(&st, s[i]);
		}

		//右括号

		else
		{
			//栈中没有括号

			if (StackEmpty(&st))
			{
				return false;
			}

			//取出栈顶的括号，进行匹配

			char ch = StackTop(&st);

			//匹配成功，出栈

			if ((ch == '(' && s[i] == ')') || (ch == '[' && s[i] == ']') || (ch == '{' && s[i] == '}'))
			{
				StackPop(&st);
			}

			//失败，返回false

			else
			{
				return false;
			}
		}
	}

	//遍历结束，查看栈中是否有括号
	//没有括号返回true

	if (!StackEmpty(&st))
	{
		return false;
	}
	return true;
}