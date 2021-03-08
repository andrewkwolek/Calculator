// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "Stack.h"
#include "Stack.h" // check for proper include guards

#include "unit_test_framework.h"

#include <iostream>
#include <string>

using namespace std;


TEST(test_stack_default_ctor) {
    Stack<int> s;
    ASSERT_TRUE(s.empty());
}

TEST(test_stack_push_and_pop_basic) {
    Stack<int> s;
    s.push(3);
    s.push(5);
    ASSERT_TRUE(!s.empty());
    ASSERT_EQUAL(s.pop(), 5);
    ASSERT_TRUE(!s.empty());
    ASSERT_EQUAL(s.pop(), 3);
    ASSERT_TRUE(s.empty());
}

TEST(test_stack_other_functions_compile) {
    Stack<int> my_stack;
    my_stack.size();
    cout << my_stack << endl;
    my_stack.push(42);
    my_stack.top();
    Stack<int> stack_cpy(my_stack);
    my_stack = stack_cpy;
}

TEST_MAIN()
