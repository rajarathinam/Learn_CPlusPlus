#include "stub.h"
#define STACK_SIZE 3
#define NO_OF_STACKS 3

class N_Stacks_Array
{

public:
	N_Stacks_Array()
	{
		for(int i =0; i <= NO_OF_STACKS; i++)
		{
			d_stack_pointer[i] = -1;
		}
	}
	bool isStackAvailable(int stack_number)
	{
		if( stack_number < NO_OF_STACKS)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void push(int stack_number , int value)
	{
		if(isStackAvailable(stack_number))
		{
			int index =  stack_number * STACK_SIZE + d_stack_pointer[stack_number]  + 1;
		d_stack_pointer[stack_number]++;
		d_full_array[index] = value;
		}
		

	}

	int pop(int stack_number)
	{
		
		if(isStackAvailable(stack_number))
		{
		int temp = d_full_array[stack_number * STACK_SIZE + d_stack_pointer[stack_number]];
		d_stack_pointer[stack_number]--;
		return temp;
		}
	}
	
	bool isEmpty(int stack_number)
	{
		if(isStackAvailable(stack_number))
		{
		if(d_stack_pointer[stack_number] == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
		}
	}

	bool isFull(int stack_number)
	{
		if(isStackAvailable(stack_number))
		{
		if(d_stack_pointer[stack_number] == NO_OF_STACKS -1)
		{
			return true;
		}
		else
		{
			return false;
		}
		}
	}

	int top(int stack_number)
	{
		if(isStackAvailable(stack_number) && !isEmpty(stack_number))
		{
		return (d_full_array[stack_number * STACK_SIZE + d_stack_pointer[stack_number]]);
		}
		else
		{
			return -1;
		}
	}

private:
	//int d_stack[10];
	int d_full_array[STACK_SIZE];
	int d_stack_pointer[NO_OF_STACKS];
	
};

int edefw()
{
	N_Stacks_Array obj;
	obj.push(0,10);
	obj.push(0,20);
	obj.push(0,30);
	obj.push(0,40);
	cout<<obj.top(1)<<"\n";

	cout<<"\n";
	return 0;
}