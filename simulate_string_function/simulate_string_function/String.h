#pragma once

#include <stdio.h>
#include <assert.h>

char* StringNumCopy(char* destination, const char* source, int count);

char* StringNumCat(char* front, const char* back, int count);

int StringNumCompare(const char* string1, const char* string2, int count);

char* StringString(const char* string, const char* objString);