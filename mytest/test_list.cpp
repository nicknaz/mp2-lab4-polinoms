#include "pch.h"

#include "../include/list.h"

TEST(List, constructor)
{
	ASSERT_NO_THROW(List<int> list);
}

TEST(List, addNode)
{
	List<int> list1;
	ASSERT_NO_THROW(list1.addNode(5));
}

TEST(List, constructor_copy)
{
	List<int> list1;
	list1.addNode(5);
	ASSERT_NO_THROW(List<int> list(list1));
}

TEST(List, getHead)
{
	List<int> list1;
	list1.addNode(5);
	list1.addNode(3);
	EXPECT_EQ(3, list1.getHead());
}

TEST(List, isEmpty)
{
	List<int> list1;
	EXPECT_EQ(true, list1.isEmpty());
}
