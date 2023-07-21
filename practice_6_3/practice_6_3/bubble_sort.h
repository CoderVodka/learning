#pragma once

#include <stdio.h>

int CompareInt(const void* num1, const void* num2);

void Swap(char* elem1, char* elem2, int width);

void BubbleSort(void* base, int num, int width,
	int (*compare)(const void* elem1, const void* elem2));