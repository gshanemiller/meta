#include <stdio.h>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <assert.h>
#include <sys/types.h>

class CityPop {
  std::random_device                d_randDevice;
  std::mt19937                      d_gen;
  const std::vector<std::string>&   d_city;
  std::uniform_real_distribution<>  d_dist;
  std::vector<double>               d_weight;

public:
  CityPop() = delete;
  CityPop(const CityPop& other) = delete;
  CityPop& operator=(const CityPop& rhs) = delete;
  ~CityPop() = default;
  explicit CityPop(double total, const std::vector<std::string>& city, const std::vector<int32_t>& population);
  void print();
};

CityPop::CityPop(double total, const std::vector<std::string>& city, const std::vector<int32_t>& population)
: d_gen(d_randDevice())
, d_city(city)
{
  assert(d_city.size()>1);
  assert(d_city.size()==population.size());
  d_weight.resize(population.size());
  d_weight[0]=population[0]/total;
  for (u_int64_t i=1; i<population.size(); ++i) {
    d_weight[i]=d_weight[i-1]+population[i]/total;
  }
}

void CityPop::print() {
  const double sample = d_dist(d_gen);
  for (u_int64_t i=0; i<d_weight.size(); ++i) {
    if (sample<d_weight[i]) {
      printf("%s\n", d_city[i].c_str());
      return;
    }
  }
  printf("%s\n", d_city[d_city.size()-1].c_str());
}

int main() {
  std::vector<std::string> city = {"LA", "NY", "SF"};
  std::vector<int32_t>     pop  = {30, 20, 10};
  CityPop obj(60.0, city, pop);
  for (u_int64_t i=0; i<10000; ++i) {
    obj.print();
  }
  return 0;
}
