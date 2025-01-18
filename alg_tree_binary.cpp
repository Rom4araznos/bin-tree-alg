#include <cstddef>
#include <cstdio>
#include <functional>
#include <memory>
#include <utility>
#include <vector>
#include <array>
#include <iostream>

class binary_node {

    public:
        binary_node(int data) : _data(data) {
            left = nullptr;
            right = nullptr;
        };

        auto get_max(std::shared_ptr<binary_node> &el)
            -> std::shared_ptr<binary_node> & {

            if (el->right == nullptr) return el;

            else if (el->right != nullptr && el->right->right == nullptr)
                return el->right;

            return get_max(el->right);
        }

        auto get_min(std::shared_ptr<binary_node> &el)
            -> std::shared_ptr<binary_node> & {

            if (el->left == nullptr) return el;

            else if (el->left != nullptr && el->left->left == nullptr)
                return el->left;

            return get_min(el->left);
        }

        auto add(std::shared_ptr<binary_node> &el, int data) -> void {

            if (el->_data < data) {

                if (el->right == nullptr)
                    el->right = std::make_shared<binary_node>(data);


                else add(el->right, data);
            }

            else if (el->_data > data) {

                if (el->left == nullptr)
                    el->left = std::make_shared<binary_node>(data);

                else add(el->left, data);
            }
        }

        auto find(std::shared_ptr<binary_node> &tree_el,
                  int data) -> std::shared_ptr<binary_node> & {

            if (tree_el->_data == data) return tree_el;

            else if (tree_el->_data > data) return find(tree_el->left, data);

            else return find(tree_el->right, data);
        }

        auto remove(std::shared_ptr<binary_node> &del_el) -> void {

            // auto del_el =
            // *foo_find.target<std::shared_ptr<binary_tree_val>>();

            if (del_el->left == nullptr && del_el->right == nullptr)
                del_el = nullptr;

            else if (del_el->left != nullptr && del_el->right == nullptr) {

                del_el = del_el->left;
                del_el->left = nullptr;

            }

            else if (del_el->left == nullptr && del_el->right != nullptr) {

                del_el = del_el->right;
                del_el->right = nullptr;
            }

            else {

                auto min_el_right = get_min(del_el->right);

                del_el = min_el_right;

                min_el_right = nullptr;
            }
        }

        auto symm_print() -> void {

            if (this->left != nullptr) this->left->symm_print();

            std::cout << this->_data << '\n';

            if (this->right != nullptr) this->right->symm_print();
        }

        auto reverse_print() -> void {

            if (this->left != nullptr) this->left->reverse_print();

            if (this->right != nullptr) this->right->reverse_print();

            std::cout << this->_data << '\n';
        }

        auto direct_print() -> void {

            std::cout << this->_data << '\n';

            if (this->left != nullptr) this->left->direct_print();

            if (this->right != nullptr) this->right->direct_print();
        }

        auto get_data() -> int {
            return _data;
        }

    protected:
        int _data;

        std::shared_ptr<binary_node> left;
        std::shared_ptr<binary_node> right;
};