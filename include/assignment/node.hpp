#pragma once

namespace assignment {

  struct Node final {
    // данные узла
    int key{0};
    int priority{0};

    // указатели
    Node *left{nullptr};
    Node *right{nullptr};

    // конструкторы
    Node() = default;
    Node(int key, int priority) : key{key}, priority{priority} {}
  };

}  // namespace assignment