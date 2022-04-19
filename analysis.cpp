//
// Created by Lippert Mark on 13.04.2022.
//
#include <iostream>  // cout, cin
#include <ctime>
#include <cstdio>
#include <stdio.h>
#include "include/assignment/cartesian_tree.hpp"
#include <iomanip>
#include <chrono>

using namespace std;
using namespace assignment;

void shuffle(int* arr, int N) {
  // инициализация генератора случайных чисел
  srand(time(NULL));

  // реализация алгоритма перестановки
  for (int i = N - 1; i >= 1; i--) {
    int j = rand() % (i + 1);

    int tmp = arr[j];
    arr[j] = arr[i];
    arr[i] = tmp;
  }
}

void decorator_insert_n_items(int n) {
  CartesianTree tree;
  int key[n];
  int value[n];
  for (int i = 0; i < n; ++i) {
    key[i] = i + 1;
    value[i] = rand() % 10000000;
  }
  shuffle(key, n);
  shuffle(value, n);
  unsigned int start_time = clock();
  //  freopen("insert_time.txt", "w", stdout);
  for (int i = 0; i < n; ++i) {
    tree.Insert(key[i], value[i]);
  }
  unsigned int end_time = clock();  // конечное время
  unsigned int search_time = end_time - start_time;
  cout << n << " " << setprecision(6) << 1000 * float(search_time) / CLOCKS_PER_SEC << endl;
  //  fclose (stdout);
}

//void decorator_insert() {
//  int n = 1000000;
//  CartesianTree tree;
//  int key[n];
//  int value[n];
//  for (int i = 0; i < n; ++i) {
//    key[i] = i + 1;
//    value[i] = rand() % 10000000;
//  }
//  shuffle(key, n);
//  shuffle(value, n);
//  for (int i = 0; i <= n; ++i) {
//    unsigned int start_time = clock();
//    tree.Insert(key[i], value[i]);
//    unsigned int end_time = clock();  // конечное время
//    unsigned int search_time = end_time - start_time;
//    if (i % 100 == 0) {
//      cout << "Время добавления(" << i << "-ого элемента): " << setprecision(10) << search_time << "ms" << endl;
//    }
//  }
//}


int key[100000000];
int value[100000000];

void decorator_contains_one_item() {
  int n = 50000000;
  CartesianTree tree;

  for (int i = 0; i < n; ++i) {
    key[i] = i + 1;
    value[i] = rand() % n;
  }
  shuffle(key, n);
  shuffle(value, n);
  for (int i = 0; i < n; ++i) {
    tree.Insert(key[i], value[i]);
    if ((i%10000==0) and (i>=100)){
      clock_t start = clock();
      tree.Contains(key[i]);
      clock_t end = clock();
      double seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
      printf("%i %f\n", i, seconds);
    }
  }
}

void decorator_remove_one_item() {
  int n = 10000000;
  CartesianTree tree;


  for (int i = 0; i < n; ++i) {
    key[i] = i + 1;
    value[i] = rand() % n;
  }

    shuffle(key, n);
    shuffle(value, n);
  for (int i = 0; i < n; ++i) {
    tree.Insert(key[i], value[i]);
  }
  shuffle(key, n);
  for (int i = 0; i < n; ++i) {
    if (i%10000 == 0){
      clock_t start = clock();
      tree.Remove(key[i]);
      clock_t end = clock();
      double seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
      //      cout<< i<< " " << seconds<<endl;
      printf("%i %f\n", n - i, seconds);
    }
    else{
      tree.Remove(key[i]);
    }
  }
}

int main(int args, char** argv) {
  for (int i = 100; i <= 1000000; i += 1000) {
    decorator_insert_n_items(i);
  }

  decorator_contains_one_item();
  decorator_remove_one_item();

  return 0;
}