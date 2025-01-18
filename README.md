# Binnary tree usage
*Make a main node*
```cpp
    std::shared_ptr<binary_node> main = std::make_shared<binary_node>(15);
```
*Add nodes and leafes*
```cpp
    main->add(main, 13);
    main->add(main, 14);
    main->add(main, 10);
    main->add(main, 11);
    main->add(main, 12);
    main->add(main, 9);
    main->add(main, 8);
    main->add(main, 20);
    main->add(main, 21);
    main->add(main, 18);
```
*Symmetric print 'symm_print()' of all elements*
```cpp
    main->symm_print();
```
*Reverse print 'reverse_print()' of all elements*
```cpp
    main->reverse_print();
```
*Direct print 'direct_print()' of all elements*
```cpp
    main->direct_print();
```
*Find element method 'find()'*
```cpp
    main->find(main, 18);
```
*Print all elements by using find method for particular element*
*the same pattern will work with other print methods*
```cpp
    main->find(main, 10)->symm_print();
```
*Get max 'get_max()' or min 'get_min()' value in the tree*
```cpp
    main->get_max(main)->get_data();
    main->get_min(main)->get_data();
```
*Remove particular element by using find method*
```cpp
    main->remove(main->find(main, 8));
```

