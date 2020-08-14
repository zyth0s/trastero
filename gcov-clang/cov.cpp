/*
 * =====================================================================================
 *
 *       Filename:  cov.cpp
 *
 *    Description:  Check that Clang generates coverage report
 *
 *        Version:  1.0
 *        Created:  11/22/2018 02:09:34 PM
 *       Revision:  none
 *       Compiler:  clang++/g++
 *
 *         Author:  Daniel (dmc)
 *
 * =====================================================================================
 */

#define BAR(x) ((x) || (x))
template <typename T> void foo(T x) {
  for (unsigned I = 0; I < 10; ++I) { BAR(I); }
}
int main() {
  foo<int>(0);
  foo<float>(0);
  return 0;
}
