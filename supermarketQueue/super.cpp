#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>

long queueTime(std::vector<int> customers,int n){

  // If there is no customers then there is no queue time
  if ( customers.empty()) {
      return 0;
  }
  // One till ==> sum of time to attend all customers
  if ( n == 1 ) {
    return std::accumulate(customers.begin(), customers.end(), 0);
  }

  std::vector<int> tills(n,0);
  //std::cout << tills[6] << std::endl;
  
  
  long attended_customers = 0;

  // Open the tills, let customers in
  for ( long i = 0; i<n; i++ ) {
    tills[i] = customers[i];
    attended_customers++;
  }
  
  // Let the queue progress until there is nobody
  // waiting to enter the queue.
  if ( customers.size() > n ) {
    while ( attended_customers < customers.size() ) {
      long liberated_till = std::min_element(tills.begin(),tills.end()) - tills.begin();
      tills[liberated_till] += customers[attended_customers];
      //std::cout << tills[0] << " " << tills[1] << std::endl;
      attended_customers++;
    }
    // The total time is the time of the latest queue to end
    //std::cout << tills << std::endl;
    return *std::max_element(tills.begin(),tills.end());
  } else {
    // The total time is the time of the slowest customer
    return *std::max_element(customers.begin(),customers.end());
  }

  //std::cout << tills[0] << " " << tills[1] << std::endl;
  //std::cout << tills[2] << " " << tills[3] << std::endl;
  //std::cout << tills[4] << " " << tills[5] << std::endl;
  
  // The total time is the time of the latest queue to end
  //std::cout << tills << std::endl;
  //return *std::max_element(tills.begin(),tills.end());
}


int main() {
	
  //std::vector<int> c = {10, 2, 3,3};
  //std::vector<int> c = {};
  //std::vector<int> c = {1,2,3,4};
  //std::vector<int> c = {2,2,3,3,4,4};
  std::vector<int> c = {1,2,3,4,5};
  long time = queueTime(c, 100);

  std::cout << time << std::endl;

	return 0;
}
