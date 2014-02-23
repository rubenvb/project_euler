#include <cmath>
#include <cstdint>
#include <iostream>
#include <type_traits>

using namespace std;

// sum of multiples of N smaller than Max:
//  N * ( (Max-1)/N * ((Max-1)/N +1) /2 )
template<typename Number, Number Max, Number N>
constexpr typename enable_if<is_integral<Number>::value, Number>::type
sum_of_multiples_impl()
{
  return N * ((Max-1)/N * ((Max-1)/N + 1) / 2);
}

template<typename Number, Number Max, Number N>
constexpr typename enable_if<!is_integral<Number>::value, Number>::type
sum_of_multiples_impl()
{
  return N * ( std::floor((Max-1)/N) * (std::floor((Max-1)/N) + 1) / 2);
}

template<typename Number, Number Max, Number N1, Number N2>
struct sum_of_multiples_direct
{
  static constexpr const Number value = sum_of_multiples_impl<Number, Max, N1>()
                                        + sum_of_multiples_impl<Number, Max, N2>();
};

template<typename Number, Number Max, Number N1, Number... Numbers>
struct sum_of_multiples
{
  static constexpr const Number value = sum_of_multiples_impl<Number, Max, N1>()
                                        + sum_of_multiples<Number, Max, Numbers...>::value
                                        - std::conditional<(sizeof...(Numbers) > 2),
                                                           sum_of_multiples<Number, Max, N1*Numbers...>,
                                                           sum_of_multiples_direct<Number, Max, N1*Numbers...>>::type::value;
};

template<typename Number, Number Max, Number N>
struct sum_of_multiples<Number, Max, N>
{
  static constexpr const Number value = sum_of_multiples_impl<Number, Max, N>();

  constexpr operator Number() { return value; }
};

int main()
{
  constexpr int result = sum_of_multiples<int, 1000, 3, 5, 7>::value;
  std::cout << result << '\n';

  constexpr int manual_result = sum_of_multiples_impl<int, 1000, 3>()
      + sum_of_multiples_impl<int, 1000, 5>()
      + sum_of_multiples_impl<int, 1000, 7>()
      - sum_of_multiples_impl<int, 1000, 7*3>()
      - sum_of_multiples_impl<int, 1000, 3*5>()
      - sum_of_multiples_impl<int, 1000, 7*5>()
      - sum_of_multiples_impl<int, 1000, 7*5*3>();
  std::cout << manual_result << '\n';
}
