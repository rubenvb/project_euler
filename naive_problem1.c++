#include <cstdint>
#include <iostream>

int sum_of_multiples(int N, int Max)
{
  int result = 0;
  for(int current = N; current<Max; current+=N)
    result += current;

  return result;
}

int main()
{
  std::cout << sum_of_multiples(3, 1000) + sum_of_multiples(5, 1000) - sum_of_multiples(15, 1000) << '\n';
}
