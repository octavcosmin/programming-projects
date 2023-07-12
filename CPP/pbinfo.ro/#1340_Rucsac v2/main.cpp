#include <iostream>
using namespace std;


struct Object {
  int weight, value;
};

istream & operator >> (istream &in, Object &o) {
  in >> o.weight >> o.value;
  return in;
}

Object stock[1001];
int n, max_weight;

int main() {
  cin >> n >> max_weight;
  for(int i = 0; i < n; ++i) cin >> stock[i];

  // Sort (descending) by VALUE/WEIGHT ratio
  for(int i = 0; i < n-1; ++i)
    for(int j = i+1; j < n; ++j)
      if(stock[i].value * stock[j].weight < stock[i].weight * stock[j].value) {
        Object tmp;

        tmp.value = stock[i].value;
        tmp.weight = stock[i].weight;

        stock[i].value = stock[j].value;
        stock[i].weight = stock[j].weight;

        stock[j].value = tmp.value;
        stock[j].weight = tmp.weight;
      }

  double stolen_weight{}, stolen_value{};
  for(int i = 0; i < n && stolen_weight < max_weight; ++i) {
    if(stolen_weight + stock[i].weight < max_weight) {
      stolen_weight += stock[i].weight;
      stolen_value += stock[i].value;
    }
    else {
      stolen_value += ( (double)stock[i].value/stock[i].weight ) * ( max_weight - stolen_weight );
      stolen_weight = max_weight;
    }
  }

  cout << stolen_value;
  return 0;
}