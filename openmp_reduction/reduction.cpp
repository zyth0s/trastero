/*
 * =====================================================================================
 *
 *       Filename:  reduction.cpp
 *
 *    Description:  Test the flow of variables in openmp regions
 *
 *        Version:  1.0
 *        Created:  12/10/2018 07:51:45 PM
 *       Revision:  none
 *       Compiler:  clang++/g++
 *
 *         Author:  Daniel (dmc)
 *
 * =====================================================================================
 */

#include <iostream>
#include <cassert>

#include <omp.h>

void using_clause() {

  //default(none) shared(suma)
  int suma = 0;
  #pragma omp parallel default(shared) num_threads(2)
  {
    #pragma omp for reduction(+:suma)
    for (int n = 0; n<20; n++ ) {
      for ( int j = 0; j < 30; j++ ) {
        suma += 1;
      }
    }
  }
  printf("[using_clause] suma = %d\n", suma);
  assert( suma == 20*30);
}

void why_works() {

  //default(none) shared(suma)
  int suma = 0;
  #pragma omp parallel default(shared)
  {
    #pragma omp parallel for reduction(+:suma) num_threads(2)
    for (int n = 0; n<20; n++ ) {
      for ( int j = 0; j < 30; j++ ) {
        suma += 1;
      }
    }
  }
  printf("[why_works] suma = %d\n", suma);
  assert( suma == 20*30);
}

void manual() {

  int suma = 0;
  #pragma omp parallel shared(suma) num_threads(4)
  {
    int _suma = 0;
    #pragma omp for 
    for (int n = 0; n<20; n++ ) {
      for ( int j = 0; j < 30; j++ ) {
        _suma += 1;
      }
    }
    #pragma omp critical
    {
      printf("_suma = %d\n", _suma);
      suma += _suma;
    }
  }
  printf("[manual] suma = %d\n", suma);
  assert( suma == 20*30);

}

void manual_double() {

  double suma = 0.;
  #pragma omp parallel shared(suma) num_threads(4)
  {
    suma = 0.0;
    double _suma = 0.;
    #pragma omp for 
    for (int n = 0; n<20; n++ ) {
      for ( int j = 0; j < 30; j++ ) {
        _suma += 1.;
      }
    }
    #pragma omp critical
    {
      printf("_suma = %5.3f\n", _suma);
      suma += _suma;
    }
  }
  printf("[manual_double] suma = %5.3f\n", suma);

}

int main() {

  omp_set_num_threads(2);
  printf("Number of threads = %d\n", omp_get_max_threads());
  using_clause();
  //why_works();
  manual();
  manual_double();

  return 0;
}
