#include <utility>
#include <vector>
#include <cmath>

class SumSquaredDivisors
{
public:
    static std::vector<std::pair<long long, long long>> listSquared(long long m, long long n);
};

std::vector<std::pair<long long, long long>>
SumSquaredDivisors::listSquared(long long m, long long n) {
  std::vector<std::pair<long long, long long>> ret;
  for(long long cur = m; cur <= n; cur ++) {
    long long sum = 0;
    for(long long i = 1; i <= cur; i ++) {
      if(cur % i == 0) sum += i * i;
    }
    long long sqrted = sqrt(sum);
    if(sum == sqrted * sqrted) {
      ret.push_back({cur, sum});
    }
  }
  return ret;
}

