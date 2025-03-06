#include "Math.h"

uint32_t factorial(const uint32_t n)
{
    return n <= 1 ? 1 : n * factorial(n - 1);
}

uint32_t pick(const uint32_t n, const uint32_t k)
{
    return factorial(n) / factorial(n - k);
}

uint32_t choose(const uint32_t n, const uint32_t k)
{
    return (n < k) ? 0 : factorial(n) / (factorial(n - k) * factorial(k));
}
