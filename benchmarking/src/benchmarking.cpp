#pragma once

#include <iostream>
#include <benchmark/benchmark.h>
#include <univariate/function.h>
#include <operation/operation.h>

static void BM_gradSinZero(benchmark::State& state) {
  for (auto _ : state) {
    int x = 0;

    autodiff::univariate::Function operations;

    operations.push(autodiff::operation::Addition(3)); 
    operations.push(autodiff::operation::Sin()); 

    operations.call(x); // eval operations at x
    operations.grad(x); // eval operations at grad x
  }
}


BENCHMARK(BM_gradSinZero);

static void BM_grad10Sins(benchmark::State& state) {
  for (auto _ : state) {
    int x = 0;
  
    autodiff::univariate::Function operations;

    for (int i = 0 ; i < 10 ; ++i) {
      operations.push(autodiff::operation::Sin()); 
    }

    operations.call(x); // eval operations at x
    operations.grad(x); // eval operations at grad x
  }
}

BENCHMARK(BM_grad10Sins);

BENCHMARK_MAIN();
