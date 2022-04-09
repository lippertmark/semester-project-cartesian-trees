#pragma once  // директива "pragma once" всегда записывается в самом начале заголовочного файла

#include <ostream>   // ostream
#include <optional>  // ???

#include "node.hpp"  // Node

namespace assignment {

  struct CartesianTree final {

    // конструктор
    CartesianTree() = default;

    // деструктор
    ~CartesianTree();

    void Clear();

    void Split(Node* node, int key, Node*& left, Node*& right);

    Node* Merge(Node* left_tree, Node* right_tree);

    void Insert(int key, int priority);

    bool Contains(int key);

    bool Remove(int key);

    bool IsEmpty() const;

    Node* root() const;

   private:
    // корневой узел
    Node* root_{nullptr};

    void clear(Node* node);

   public:
    friend std::ostream& operator<<(std::ostream& os, const CartesianTree& tree);
  };

  // Можете реализовать оператор вывода << (os - поток вывода)
  inline std::ostream& operator<<(std::ostream& os, const CartesianTree& tree) {
    os << "Cartesian tree" << '\n';
    return os;
  }

}  // namespace assignment