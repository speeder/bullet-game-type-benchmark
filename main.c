#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

#define ARRAY_MAX 10000000

typedef struct 
{
	int x;
	int y;
	short spdx;
	short spdy;
	unsigned char type;
} defaultTypes;

typedef struct 
{
	int_fast16_t x;
	int_fast16_t y;
	int_fast8_t spdx;
	int_fast8_t spdy;
	uint_fast8_t type;
} fastTypes;

typedef struct 
{
	int_least16_t x;
	int_least16_t y;
	int_least8_t spdx;
	int_least8_t spdy;
	uint_least8_t type;
} leastTypes;

typedef struct 
{
	int16_t x;
	int16_t y;
	int8_t spdx;
	int8_t spdy;
	uint8_t type;
} exactTypes;

typedef struct 
{
	float x;
	float y;
	float spdx;
	float spdy;
	unsigned char type;
} floatTypes;

typedef struct 
{
	double x;
	double y;
	double spdx;
	double spdy;
	unsigned char type;
} doubleTypes;

typedef struct 
{
	int16_t x;
	int16_t y;
	int16_t spdx;
	int16_t spdy;
	unsigned char type;
} int16Types;

typedef struct 
{
	int32_t x;
	int32_t y;
	int32_t spdx;
	int32_t spdy;
	unsigned char type;
} int32Types;

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
	printf("pointer to char size %d\n", sizeof(char*));

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

	printf("default types array[%d] size %d struct size %d, int size %d, short size %d, unsigned char size %d, calculation speed %f\n", ARRAY_MAX, sizeof defaultStruct, sizeof(defaultTypes), sizeof(int), sizeof(short), sizeof(unsigned char), elapsedTime);

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

	printf("fast types array[%d] size %d struct size %d, int_fast16_t size %d, int_fast8_t size %d, uint_fast8_t size %d, calculation speed %f\n", ARRAY_MAX, sizeof fastStruct, sizeof(fastTypes), sizeof(uint_fast16_t), sizeof(int_fast8_t), sizeof(uint_fast8_t), elapsedTime);

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

	printf("least types array[%d] size %d struct size %d, int_least16_t size %d, int_least8_t size %d, uint_least8_t size %d, calculation speed %f\n", ARRAY_MAX, sizeof leastStruct, sizeof(leastTypes), sizeof(int_least16_t), sizeof(int_least8_t), sizeof(uint_least8_t), elapsedTime);

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

	printf("exact types array[%d] size %d struct size %d, int16_t size %d, int8_t size %d, uint8_t size %d, calculation speed %f\n", ARRAY_MAX, sizeof exactStruct, sizeof(exactTypes), sizeof(int16_t), sizeof(int8_t), sizeof(uint8_t), elapsedTime);

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

	printf("float types array[%d] size %d struct size %d, float size %d, float size %d, unsigned char size %d, calculation speed %f\n", ARRAY_MAX, sizeof floatStruct, sizeof(floatTypes), sizeof(float), sizeof(float), sizeof(unsigned char), elapsedTime);

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

	printf("double types array[%d] size %d struct size %d, double size %d, double size %d, unsigned char size %d, calculation speed %f\n", ARRAY_MAX, sizeof doubleStruct, sizeof(doubleTypes), sizeof(double), sizeof(double), sizeof(unsigned char), elapsedTime);

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

	printf("int16 types array[%d] size %d struct size %d, int16_t size %d, int16_t size %d, unsigned char size %d, calculation speed %f\n", ARRAY_MAX, sizeof int16Struct, sizeof(int16Types), sizeof(int16_t), sizeof(int16_t), sizeof(unsigned char), elapsedTime);

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

	printf("int32 types array[%d] size %d struct size %d, int32_t size %d, int32_t size %d, unsigned char size %d, calculation speed %f\n", ARRAY_MAX, sizeof int32Struct, sizeof(int32Types), sizeof(int32_t), sizeof(int32_t), sizeof(unsigned char), elapsedTime);

	return 0;
}