#include <cmath>
#include <cstdint>
#include <iostream>
#include <type_traits>

using namespace std;

// sum of multiples of N smaller than Max:
//  N * ( (Max-1)/N * ((Max-1)/N +1) /2 )
int sum_of_multiples(int N, int Max)
{
  return N * ((Max-1)/N * ((Max-1)/N + 1) / 2);
}

int main()
{
  std::cout << sum_of_multiples(3, 1000) + sum_of_multiples(5, 1000) - sum_of_multiples(15, 1000) << '\n';
}
