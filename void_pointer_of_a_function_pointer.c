#include <stdio.h>

void * add(const void * , const void *);
void * subt(const void * , const void * );
void * mul(const void * , const void *);

int main(void)
{
	int  num1;
	int  num2;
	int choice;
	int *result;
	void * (*ptr)[3](const void *, const void *);

	ptr[0] = add;
	ptr[1] = subt;
	ptr[2] = mul;
	printf("Enter num1 num2 : ");
	scanf("%d %d", &num1, &num2);

	printf("Enter choice [0] add [1] subt [2] mul : ");
	scanf("%d", &choice);

	result = (int *)ptr[choice](&num1, &num2);
	printf("The result is %d\n", *result);

	return (0);

}

void * add(const void * num1, const void * num2)
{
	static int result;
	result = (*(int *)num1) + (*(int *)num2);
	return &result;
}

void * subt(const void * num1, const void * num2)
{
	static int result;
        result = (*(int *)num1) - (*(int *)num2);
        return &result;
}

void * mul(const void * num1, const void * num2)
{
	static int result;
        result = (*(int *)num1) * (*(int *)num2);
        return &result;
}
