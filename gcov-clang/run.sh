#!/bin/bash

#clang++ --coverage cov.cpp -o cov
clang++ -pg -fprofile-instr-generate -fcoverage-mapping cov.cpp -o cov
./cov
llvm-profdata merge -sparse default.profraw -o default.profdata
llvm-cov show ./cov -instr-profile=default.profdata
llvm-cov show -format=html -instr-profile=default.profdata ./cov . > coverage.html
