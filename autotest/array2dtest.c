#include <assert.h>

char a2[20][10] = {
	#for(i, 200) i,
};

int sumrow(char y)
{
	int s = 0;
	for(char i=0; i<10; i++)
		s += a2[y][i];
	return s;
}

int sumrowp5(char y)
{
	int s = 0;
	for(char i=0; i<10; i++)
		s += a2[y + 5][i];
	return s;
}

int sumrowm5(char y)
{
	int s = 0;
	for(char i=0; i<10; i++)
		s += a2[y - 5][i];
	return s;
}

char pick(char y, char x)
{
	return a2[y][x];
}

char pickp5(char y, char x)
{
	return a2[y + 5][x];
}

char pickm5(char y, char x)
{
	return a2[y - 5][x];
}

char pickm50(char y, char x)
{
	return a2[y - 50][x];
}

char pickp50(signed char y, char x)
{
	return a2[y + 50][x];
}


int main(void)
{
	for(char i=0; i<15; i++)
	{
		assert(sumrow(i) == sumrowm5(i + 5));
		assert(sumrow(i + 5) == sumrowp5(i));		

		for(char j=0; j<10; j++)
		{
			assert(pick(i, j) == pickm5(i + 5, j));
			assert(pick(i + 5, j) == pickp5(i, j));		
			assert(pick(i, j) == pickm50(i + 50, j));
			assert(pick(i, j) == pickp50(i - 50, j));		
		}
	}
}


