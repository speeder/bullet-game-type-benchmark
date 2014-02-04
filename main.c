#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

#define ARRAY_MAX 10000000
#define LOOPS 500

typedef struct 
{
	int x;
	int y;
	short spdx;
	short spdy;
	unsigned char type;
} defaultTypes;
double defaultAverageTime = 0;

typedef struct 
{
	int_fast16_t x;
	int_fast16_t y;
	int_fast8_t spdx;
	int_fast8_t spdy;
	uint_fast8_t type;
} fastTypes;
double fastAverageTime = 0;

typedef struct 
{
	int_least16_t x;
	int_least16_t y;
	int_least8_t spdx;
	int_least8_t spdy;
	uint_least8_t type;
} leastTypes;
double leastAverageTime = 0;

typedef struct 
{
	int16_t x;
	int16_t y;
	int8_t spdx;
	int8_t spdy;
	uint8_t type;
} exactTypes;
double exactAverageTime = 0;

typedef struct 
{
	float x;
	float y;
	float spdx;
	float spdy;
	unsigned char type;
} floatTypes;
double floatAverageTime = 0;

typedef struct 
{
	double x;
	double y;
	double spdx;
	double spdy;
	unsigned char type;
} doubleTypes;
double doubleAverageTime = 0;

typedef struct 
{
	int16_t x;
	int16_t y;
	int16_t spdx;
	int16_t spdy;
	unsigned char type;
} int16Types;
double int16AverageTime = 0;

typedef struct 
{
	int32_t x;
	int32_t y;
	int32_t spdx;
	int32_t spdy;
	unsigned char type;
} int32Types;
double int32AverageTime = 0;

defaultTypes defaultStruct[ARRAY_MAX];
fastTypes fastStruct[ARRAY_MAX];
leastTypes leastStruct[ARRAY_MAX];
exactTypes exactStruct[ARRAY_MAX];
floatTypes floatStruct[ARRAY_MAX];
doubleTypes doubleStruct[ARRAY_MAX];
int16Types int16Struct[ARRAY_MAX];
int32Types int32Struct[ARRAY_MAX];

int main()
{
	printf("pointer to char size %zu\n", sizeof(char*));

	srand(32);
	int counter = 0;
	while(counter < ARRAY_MAX)
	{
		defaultTypes tempStruct = {rand()%200-100, rand()%200-100, rand()%10-5, rand()%10-5, 1};
		defaultStruct[counter] = tempStruct;
		++counter;
	}
	srand(32);
	counter = 0;
	while(counter < ARRAY_MAX)
	{
		fastTypes tempStruct = {rand()%200-100, rand()%200-100, rand()%10-5, rand()%10-5, 1};
		fastStruct[counter] = tempStruct;
		++counter;
	}
	srand(32);
	counter = 0;
	while(counter < ARRAY_MAX)
	{
		leastTypes tempStruct = {rand()%200-100, rand()%200-100, rand()%10-5, rand()%10-5, 1};
		leastStruct[counter] = tempStruct;
		++counter;
	}
	srand(32);
	counter = 0;
	while(counter < ARRAY_MAX)
	{
		exactTypes tempStruct = {rand()%200-100, rand()%200-100, rand()%10-5, rand()%10-5, 1};
		exactStruct[counter] = tempStruct;
		++counter;
	}
	srand(32);
	counter = 0;
	while(counter < ARRAY_MAX)
	{
		floatTypes tempStruct = {rand()%200-100, rand()%200-100, rand()%10-5, rand()%10-5, 1};
		floatStruct[counter] = tempStruct;
		++counter;
	}
	srand(32);
	counter = 0;
	while(counter < ARRAY_MAX)
	{
		doubleTypes tempStruct = {rand()%200-100, rand()%200-100, rand()%10-5, rand()%10-5, 1};
		doubleStruct[counter] = tempStruct;
		++counter;
	}
	srand(32);
	counter = 0;
	while(counter < ARRAY_MAX)
	{
		int16Types tempStruct = {rand()%200-100, rand()%200-100, rand()%10-5, rand()%10-5, 1};
		int16Struct[counter] = tempStruct;
		++counter;
	}
	srand(32);
	counter = 0;
	while(counter < ARRAY_MAX)
	{
		int32Types tempStruct = {rand()%200-100, rand()%200-100, rand()%10-5, rand()%10-5, 1};
		int32Struct[counter] = tempStruct;
		++counter;
	}


	int counter2=0;
	while(counter2 < LOOPS)
	{
		clock_t start, end;
		double elapsedTime = 0;
		counter = 0;
		start = clock();
		while(counter < ARRAY_MAX)
		{
			defaultStruct[counter].x+=defaultStruct[counter].spdx;
			defaultStruct[counter].y+=defaultStruct[counter].spdy;
			++counter;
		}
		end = clock();
		elapsedTime = ((double) (end - start)) / CLOCKS_PER_SEC;
		defaultAverageTime+=elapsedTime/LOOPS;

		printf("default types array[%zu] size %zu struct size %zu, int size %zu, short size %zu, unsigned char size %zu, calculation speed %f\n", ARRAY_MAX, sizeof defaultStruct, sizeof(defaultTypes), sizeof(int), sizeof(short), sizeof(unsigned char), elapsedTime);

		counter = 0;
		start = clock();
		while(counter < ARRAY_MAX)
		{
			fastStruct[counter].x+=fastStruct[counter].spdx;
			fastStruct[counter].y+=fastStruct[counter].spdy;
			++counter;
		}
		end = clock();
		elapsedTime = ((double) (end - start)) / CLOCKS_PER_SEC;
		fastAverageTime+=elapsedTime/LOOPS;

		printf("fast types array[%zu] size %zu struct size %zu, int_fast16_t size %zu, int_fast8_t size %zu, uint_fast8_t size %zu, calculation speed %f\n", ARRAY_MAX, sizeof fastStruct, sizeof(fastTypes), sizeof(uint_fast16_t), sizeof(int_fast8_t), sizeof(uint_fast8_t), elapsedTime);

		counter = 0;
		start = clock();
		while(counter < ARRAY_MAX)
		{
			leastStruct[counter].x+=leastStruct[counter].spdx;
			leastStruct[counter].y+=leastStruct[counter].spdy;
			++counter;
		}
		end = clock();
		elapsedTime = ((double) (end - start)) / CLOCKS_PER_SEC;
		leastAverageTime+=elapsedTime/LOOPS;

		printf("least types array[%zu] size %zu struct size %zu, int_least16_t size %zu, int_least8_t size %zu, uint_least8_t size %zu, calculation speed %f\n", ARRAY_MAX, sizeof leastStruct, sizeof(leastTypes), sizeof(int_least16_t), sizeof(int_least8_t), sizeof(uint_least8_t), elapsedTime);

		counter = 0;
		start = clock();
		while(counter < ARRAY_MAX)
		{
			exactStruct[counter].x+=exactStruct[counter].spdx;
			exactStruct[counter].y+=exactStruct[counter].spdy;
			++counter;
		}
		end = clock();
		elapsedTime = ((double) (end - start)) / CLOCKS_PER_SEC;
		exactAverageTime+=elapsedTime/LOOPS;

		printf("exact types array[%zu] size %zu struct size %zu, int16_t size %zu, int8_t size %zu, uint8_t size %zu, calculation speed %f\n", ARRAY_MAX, sizeof exactStruct, sizeof(exactTypes), sizeof(int16_t), sizeof(int8_t), sizeof(uint8_t), elapsedTime);

		counter = 0;
		start = clock();
		while(counter < ARRAY_MAX)
		{
			floatStruct[counter].x+=floatStruct[counter].spdx;
			floatStruct[counter].y+=floatStruct[counter].spdy;
			++counter;
		}
		end = clock();
		elapsedTime = ((double) (end - start)) / CLOCKS_PER_SEC;
		floatAverageTime+=elapsedTime/LOOPS;

		printf("float types array[%zu] size %zu struct size %zu, float size %zu, float size %zu, unsigned char size %zu, calculation speed %f\n", ARRAY_MAX, sizeof floatStruct, sizeof(floatTypes), sizeof(float), sizeof(float), sizeof(unsigned char), elapsedTime);

		counter = 0;
		start = clock();
		while(counter < ARRAY_MAX)
		{
			doubleStruct[counter].x+=doubleStruct[counter].spdx;
			doubleStruct[counter].y+=doubleStruct[counter].spdy;
			++counter;
		}
		end = clock();
		elapsedTime = ((double) (end - start)) / CLOCKS_PER_SEC;
		doubleAverageTime+=elapsedTime/LOOPS;

		printf("double types array[%zu] size %zu struct size %zu, double size %zu, double size %zu, unsigned char size %zu, calculation speed %f\n", ARRAY_MAX, sizeof doubleStruct, sizeof(doubleTypes), sizeof(double), sizeof(double), sizeof(unsigned char), elapsedTime);

		counter = 0;
		start = clock();
		while(counter < ARRAY_MAX)
		{
			int16Struct[counter].x+=int16Struct[counter].spdx;
			int16Struct[counter].y+=int16Struct[counter].spdy;
			++counter;
		}
		end = clock();
		elapsedTime = ((double) (end - start)) / CLOCKS_PER_SEC;
		int16AverageTime+=elapsedTime/LOOPS;

		printf("int16 types array[%zu] size %zu struct size %zu, int16_t size %zu, int16_t size %zu, unsigned char size %zu, calculation speed %f\n", ARRAY_MAX, sizeof int16Struct, sizeof(int16Types), sizeof(int16_t), sizeof(int16_t), sizeof(unsigned char), elapsedTime);

		counter = 0;
		start = clock();
		while(counter < ARRAY_MAX)
		{
			int32Struct[counter].x+=int32Struct[counter].spdx;
			int32Struct[counter].y+=int32Struct[counter].spdy;
			++counter;
		}
		end = clock();
		elapsedTime = ((double) (end - start)) / CLOCKS_PER_SEC;
		int32AverageTime+=elapsedTime/LOOPS;

		printf("int32 types array[%zu] size %zu struct size %zu, int32_t size %zu, int32_t size %zu, unsigned char size %zu, calculation speed %f\n", ARRAY_MAX, sizeof int32Struct, sizeof(int32Types), sizeof(int32_t), sizeof(int32_t), sizeof(unsigned char), elapsedTime);

		++counter2;
	}

	printf("Average Time of defaultStruct %f\n", defaultAverageTime);
	printf("Average Time of fastStruct %f\n", fastAverageTime);
	printf("Average Time of leastStruct %f\n", leastAverageTime);
	printf("Average Time of exactStruct %f\n", exactAverageTime);
	printf("Average Time of floatStruct %f\n", floatAverageTime);
	printf("Average Time of doubleStruct %f\n", doubleAverageTime);
	printf("Average Time of int16Struct %f\n", int16AverageTime);
	printf("Average Time of int32Struct %f\n", int32AverageTime);

	return 0;
}