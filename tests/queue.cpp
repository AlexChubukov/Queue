#include <catch.hpp>
#include "queue.cpp"

TEST_CASE("push")
{
 Queue<int> queue;
 queue.push(1);
 REQUIRE( queue.front() == 1);
 REQUIRE( queue.back() == 1);
 queue.push(2);
 REQUIRE( queue.front() == 1);
 REQUIRE( queue.back() == 2);
 queue.push(3);
 REQUIRE( queue.front() == 1);
 REQUIRE( queue.back() == 3);
}

TEST_CASE("pop")
{
 Queue<int> queue;
 queue.push(1);
 queue.push(2);
 queue.push(3);
 int tmp = queue.front();
 REQUIRE (tmp == 1);
 queue.pop();
 tmp = queue.front();
 REQUIRE (tmp == 2);
 queue.pop();
 tmp = queue.front();
 REQUIRE (tmp == 3);
 queue.pop();
 REQUIRE(queue.size()==0);
}

TEST_CASE("copy")
{
 Queue<int> queue1;
 queue1.push(1);
 queue1.push(2);
 queue1.push(3);
 
 Queue<int> queue2{queue1};
 REQUIRE( queue2.front() == 1);
 REQUIRE( queue2.back() == 3);
 
}


