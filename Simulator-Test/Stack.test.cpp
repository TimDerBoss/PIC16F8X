#include "gtest/gtest.h"

#include <RegisterData.h>


TEST(StackTest, PushData)
{
	Stack stack;
	stack.push(123);
	stack.push(33);
	stack.push(36);
	stack.push(2);

	EXPECT_EQ(stack.top(), 2);
}

TEST(StackTest, PopData)
{
	Stack stack;
	stack.push(123);
	stack.push(33);
	stack.push(36);
	stack.push(2);

	stack.pop();
	stack.pop();
	stack.pop();

	EXPECT_EQ(stack.top(), 123);
}