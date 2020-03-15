#include "Stack.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

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

//�ж�ջ�Ƿ�Ϊ��

int StackEmpty(Stack* ps)
{
	asseert(ps);
	return 0 == ps->size;
}

//����ջ

void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->array);
	ps->capacity = 0;
	ps->size = 0;
}