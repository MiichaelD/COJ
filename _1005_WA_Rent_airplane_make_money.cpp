#include <algorithm>
#include <memory>
#include <vector>
#include <climits>
#include <string>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <utility>
#include <string.h>

/**
  Link:           http://coj.uci.cu/24h/problem.xhtml?pid=1005

  Description:    ABEAS Corp." is a very small company that owns a single
      airplane. The customers of ABEAS Corp are large airline companies which
      rent the airplane to accommodate occasional overcapacity.

      Customers send renting orders that consist of a time interval and a price
      that the customer is ready to pay for renting the airplane during the
      given time period. Orders of all the customers are known in advance. Of
      course, not all orders can be accommodated and some orders have to be
      declined. Eugene LAWLER, the Chief Scientific Officer of ABEAS Corp would
      like to maximize the profit of the company.

      You are requested to compute an optimal solution.

  Small Example:  Consider the case where the company has 4 orders:

                  Order 1 (start time 0, duration 5, price 10)
                  Order 2 (start time 3, duration 7, price 8)
                  Order 3 (start time 5, duration 9, price 7)
                  Order 4 (start time 6, duration 9, price 8)

      The optimal solution consists in declining Order 2 and 3 and the gain is
      10+8 = 18.

      Note that the solution made of Order 1 and 3 is feasible (the airplane is
      rented with no interruption from time 0 to time 14) but non-optimal.


  Input:        The first line of the input contains a number T ≤ 30 that
      indicates the number of test cases to follow. The first line of each test
      case contains the number of orders n (n ≤ 10000). In the following n lines
      the orders are given. Each order is described by 3 integer values: The
      start time of the order st (0 ≤ st < 1000000), the duration d of the order
      (0 < d < 1000000), and the price p (0 < p < 100000) the customer is ready
      to pay for this order.

Input:
1
4
0 5 10
3 7 14
5 9 7
6 9 8

  Output:       You are required to compute an optimal solution. For each test
      case your program has to write the total price paid by the airlines.

Output:
18


*/

using namespace std;

struct Order {
  uint32_t start, duration, end, price;
  Order(uint32_t stTime, uint32_t dur, uint32_t pri)
  :start(stTime), duration(dur), price(pri), end(stTime + dur) { }
};

bool ordersAttractivenessComparator(const Order &o1, const Order &o2) {
  float attractive1 = static_cast<float>(o1.price)/o1.duration;
  float attractive2 = static_cast<float>(o2.price)/o2.duration;

  if (attractive1 != attractive2){
    return attractive1 > attractive2;
  }

  if (o1.duration != o2.duration)
    return o1.duration < o2.duration;

  return o1.start < o2.start;
}

bool ordersComparator(const Order &o1, const Order &o2) {
  return o1.end < o2.end;
}

class Problem {
private:
  vector<Order> orders;

public:
  Problem(){
    int ordersCount;
    cin >> ordersCount;
    orders.reserve(ordersCount);

    uint32_t st, dur, pri;
    for (int i = 0 ; i < ordersCount; ++i) {
      cin >> st >> dur >> pri;
      addOrder(st, dur, pri);
    }
  }

  void addOrder(uint32_t stTime, uint32_t dur, uint32_t price) {
    orders.emplace_back(stTime, dur, price);
  }

  void addOrder(Order &&order) {
    orders.emplace_back(order);
  }

  void printAllOrders() {
    cout << "Total orders: " << orders.size() << ':' << endl;
    for (const Order &order : orders) {
      printOrder(order);
    }
  }

  void printOrders(const vector<int> &orderIndexes) {
    for (int i = 0; i < orderIndexes.size(); ++i) {
      cout << "Order: " << orderIndexes[i] << ": ";
      printOrder(orders[orderIndexes[i]]);
    }
  }

  static void printOrder(const Order &d) {
    float attractive = static_cast<float>(d.price)/d.duration;
    cout << "[Start: " << d.start << ",\tduration: " << d.duration;
    cout << ",\t$: " <<d.price << ",\t atractiveness: " <<  attractive;
    cout << "]" << endl;
  }

  uint32_t solve() {
    uint32_t maxPrice = 0;
    sort(orders.begin(), orders.end(), ordersComparator);
    for (int i = 0; i < orders.size(); ++i) {
      vector<int> orderInds;
      orderInds.push_back(i);
      uint32_t price = orders[i].price;
      int index = i;
      while((index = findNextPossibleOrder(index)) >= 0) {
        price += orders[index].price;
        orderInds.push_back(index);
      }
      if (price > maxPrice) {
        maxPrice = price;
        // cout << "MaxPrixe: " << price << ". Orders completed:" << endl;
        // printOrders(orderInds);
      }
    }
    return maxPrice;
  }

  int findNextPossibleOrder(int i) {
    uint32_t endTime = orders[i].end;
    for (++i; i < orders.size(); ++i) {
      if (orders[i].start >= endTime) 
        return i;
    }
    return -1;
  }

};

int main(){
  std::ios::sync_with_stdio(false); // http://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio
  cin.tie(NULL);

  int cases, orders;
  cin >> cases;
  while(cases--) {
    Problem problem;
    // printAllOrders();
    cout << problem.solve() << endl;
  }
 
  return EXIT_SUCCESS;
}