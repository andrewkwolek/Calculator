// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"
#include <vector>

using namespace std;

// Add your test cases here

TEST(test_stub) {
    // Add test code here
    ASSERT_TRUE(true);
}

TEST(default_ctor)
{
    List<int> newList;
    ASSERT_EQUAL(newList.size(), 0);
    ASSERT_TRUE(newList.empty());
}

TEST(push_and_size)
{
    List<int> newList;
    newList.push_front(1);
    newList.push_back(2);
    
    ASSERT_EQUAL(newList.size(), 2);
}

TEST(front)
{
    List<int> newList;
    newList.push_front(1);
    newList.push_back(2);
    newList.push_front(42);
    
    ASSERT_EQUAL(newList.front(), 42);
}

TEST(iter_deref_equal)
{
    List<int> newList;
    newList.push_front(1);
    newList.push_back(2);
    newList.push_front(42);
    
    List<int>::Iterator iter = newList.begin();
    
    ASSERT_EQUAL(*iter, 42);
    
    ++iter;
    
    ASSERT_EQUAL(*iter, 1);
    
    List<int>::Iterator iter2 = newList.begin();
    
    ASSERT_TRUE(iter != iter2);
    
    ++iter2;
    
    ASSERT_TRUE(iter == iter2);
    
    
}

TEST(back)
{
    List<int> newList;
    newList.push_front(1);
    newList.push_back(2);
    newList.push_back(42);
    
    ASSERT_EQUAL(newList.back(), 42);
}

TEST(pop)
{
    List<int> newList;
    newList.push_front(1);
    newList.push_back(2);
    newList.push_back(42);
    newList.push_front(12);
    
    newList.pop_back();
    newList.pop_front();
    
    ASSERT_EQUAL(newList.front(), 1);
    ASSERT_EQUAL(newList.back(), 2);
    ASSERT_EQUAL(newList.size(), 2);
}

TEST(push_back) {
	List<int> newList;
	newList.push_back(7);

	ASSERT_EQUAL(newList.front(), 7);
	ASSERT_EQUAL(newList.back(), 7);
	ASSERT_EQUAL(newList.size(), 1);
}

TEST(pop_back) {
	List<int> newList;
	newList.push_back(3);
	newList.pop_back();

	ASSERT_TRUE(newList.empty());
}

TEST(pop_front) {
	List<int> newList;
	newList.push_back(3);
	newList.pop_front();

    ASSERT_TRUE(newList.empty());
}

TEST(begin)
{
    List<int> newList;
    newList.push_front(3);
    newList.push_front(4);
    newList.push_front(5);
    newList.push_front(6);
    List<int>::Iterator iter = newList.begin();
    ++iter;
    ASSERT_EQUAL(*iter,5);
}

TEST(end)
{
    List<int> newList;
    newList.push_front(3);
    newList.push_front(3);
    newList.push_front(3);
    newList.push_front(3);
    
    for(List<int>::Iterator iter = newList.begin();
        iter != newList.end(); ++iter)
    {
        ASSERT_EQUAL(*iter, 3);
    }
}

TEST(insert_front_mid)
{
    List<int> newList;
    newList.push_front(3);
    newList.push_front(3);
    newList.push_front(3);
    newList.push_front(3);
    
    List<int>::Iterator iter = newList.begin();
    
    newList.insert(iter, 4);
    --iter;
    
    ASSERT_EQUAL(*iter,4);
    ++iter;
    ++iter;
    ++iter;
    newList.insert(iter,5);
    
    --iter;
    ASSERT_EQUAL(*iter,5);
}

TEST(check_movement)
{
    List<int> newList;
    newList.push_front(3);
    newList.push_front(4);
    newList.push_front(5);
    newList.push_front(6);
    
    List<int>::Iterator iter = newList.begin();
    ++iter;
    ++iter;
    ++iter;
    --iter;
    --iter;
    --iter;
    
    ASSERT_EQUAL(*iter, 6)
}

TEST(erase_front)
{
    List<int> newList;
    newList.push_front(3);
    newList.push_front(3);
    newList.push_front(3);
    newList.push_front(4);
    
    List<int>::Iterator iter = newList.begin();
    
    newList.erase(iter);
    
    ASSERT_EQUAL(*(newList.begin()), 3);
}

TEST(erase_back)
{
    List<int> newList;
    newList.push_front(4);
    newList.push_front(3);
    newList.push_front(3);
    newList.push_front(3);
    
    List<int>::Iterator iter = newList.begin();
    ++iter;
    ++iter;
    ++iter;
    newList.erase(iter);
    
    ASSERT_EQUAL(newList.size(), 3);
    for(List<int>::Iterator iter = newList.begin();
        iter != newList.end(); ++iter)
    {
        ASSERT_EQUAL(*iter, 3);
    }
}

TEST(string_lists)
{
    List<string> stringList;
    stringList.push_back("apple");
    stringList.push_back("pie");
    stringList.push_back("Kwolek licks toes");
    
    stringList.pop_front();
    
    ASSERT_EQUAL(stringList.size(), 2);
    List<string>::Iterator iter = stringList.begin();
    ASSERT_EQUAL(*iter, "pie");
}

TEST(empty_insert)
{
    List<int> newList;
    List<int>::Iterator iter = newList.begin();
    newList.insert(iter,3);
    iter = newList.begin();
    ASSERT_EQUAL(*iter, 3);
}

TEST(equals_notequals)
{
    List<int> newList;
    newList.push_front(4);
    newList.push_front(3);
    newList.push_front(3);
    newList.push_front(3);
    
    List<int>::Iterator iter = newList.begin();
    List<int>::Iterator iter2 = newList.begin();
    
    ASSERT_TRUE(iter == iter2);
    ++iter;
    
    ASSERT_TRUE(iter != iter2);
}

TEST(erase_bug)
{
    List<int> newList;
    newList.push_front(5);
    newList.push_front(4);
    newList.push_front(3);
    newList.push_front(62);
    newList.push_front(2);
    newList.push_front(1);
    
    List<int>::Iterator iter = newList.begin();
    ++iter;
    ++iter;
    ASSERT_TRUE(*iter == 62)
    
    newList.erase(iter);
    
    int j = 1;
    for(List<int>::Iterator i = newList.begin();
        i != newList.end(); ++i)
    {
        ASSERT_EQUAL(*i, j);
        ++j;
    }
}

TEST(vector_lists_wow)
{
    List< vector<int> > vecList;
    vector<int> vec1{1, 2, 3};
    vector<int> vec2{4, 5, 6};
    vector<int> vec3{7, 8, 9};
    
    vecList.push_back(vec1);
    vecList.push_back(vec2);
    vecList.push_back(vec3);
    
    
    vecList.pop_front();
    
    ASSERT_EQUAL(vecList.size(), 2);
    List< vector<int> >::Iterator iter = vecList.begin();
    ASSERT_EQUAL((*iter)[2], 6);
}

TEST(assignment_op)
{
    List<double> list1;
    list1.push_back(1.0);
    list1.push_back(1.5);
    list1.push_back(2.05);
    
    List<double> list2;
    list2.push_back(5.0);
    list2.push_back(6.5);
    list2.push_back(8.05);
    
    list1 = list2;
    
    List<double>::Iterator iter = list1.begin();
    
    ASSERT_EQUAL(*iter, 5.0);
    ++iter;
    ASSERT_EQUAL(*iter, 6.5);
}

TEST(copy_constr)
{
    List<double> list2;
    list2.push_back(5.0);
    list2.push_back(6.5);
    list2.push_back(8.05);
    
    List<double> list1 = list2;
    
    List<double>::Iterator iter = list1.begin();
    
    ASSERT_EQUAL(*iter, 5.0);
    ++iter;
    ASSERT_EQUAL(*iter, 6.5);
}

TEST(self_assign)
{
    List<double> list1;
    list1.push_back(1.0);
    list1.push_back(1.5);
    list1.push_back(2.05);
    
    list1 = list1;
    
    List<double>::Iterator iter = list1.begin();
    
    ASSERT_EQUAL(*iter, 1.0);
    ++iter;
    ASSERT_EQUAL(*iter, 1.5);
}

TEST(empty_lists)
{
    List<int> list1;
    List<int> list2;
    list1.push_back(2);
    
    list1 = list2;
    List<int> list3 = list2;
    
    ASSERT_TRUE(list1.empty());
    ASSERT_TRUE(list3.empty());
}

TEST(empty_copy)
{
    List<int> list1;
    List<int> list2;
    list1.push_back(2);
    
    list2 = list1;
    List<int>::Iterator iter = list2.begin();
    
    ASSERT_EQUAL(*iter, 2);
}

TEST_MAIN()
