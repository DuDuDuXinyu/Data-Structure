#include "Stack.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

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
			ps->capacity == newCapacity;
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

//判断栈是否为空

int StackEmpty(Stack* ps)
{
	asseert(ps);
	return 0 == ps->size;
}

//销毁栈

void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->array);
}