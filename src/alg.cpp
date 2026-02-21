// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value == 1)
    {
	    return false;
    }
    for (int i = 2; i <= sqrt(value); i++)
    {
        if (value % i == 0)
        {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
	int count = 0, i = 2;
	while (count != n)
	{
		if (checkPrime(i))
		{
			count++;
		}
		i++;
	}
	return i-1;
}

uint64_t nextPrime(uint64_t value) {
	int i = 1;
	while (!checkPrime(value + i))
	{
		i++;
	}
	return value + i;
}

uint64_t sumPrime(uint64_t hbound) {
	int psum = 0;
	for (int i = 2; i < hbound; i++)
	{
		if (checkPrime(i))
			psum += i;
	}
	return psum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
	int twinp_count = 0;
	for (int i = lbound; i < hbound; i++)
	{
		if (checkPrime(i) && checkPrime(i+2) && (i+2) < hbound)
			twinp_count++;
	}
	return twinp_count;
}
