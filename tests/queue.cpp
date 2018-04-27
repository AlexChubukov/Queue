#include <catch.hpp>
#include <sstream>
#include <fstream>
#include "queue.h"
using namespace std;

TEST_CASE("varios queues")
{
    Queue <int> q1;
    Queue <int> q2 = {1, 2, 3, 4};
    Queue <int> q3{q2};
    REQUIRE( q2 == q3);
}

TEST_CASE("swap")
{
    Queue <int> q1;
    Queue <int> q2 = {1, 2, 3, 4};
    Queue <int> q3{q2};
    Queue <int> temp = q3;
    q1.swap(q3);
    REQUIRE( q1 == temp);
    REQUIRE( q3.empty() == true);
    REQUIRE( q1.size() == 4);
}

TEST_CASE("push")
{
    Queue <int> q1;
    Queue <int> q2 = {1, 2, 3, 4};
    Queue <int> q3{q2};
    q3.push(5);
    REQUIRE( q3.size() == 5);
}
TEST_CASE("pop#1")
{
    Queue<int> q4;
    q4.pop();
    REQUIRE( q4.size() == 0);
	q4.push(1);
	q4.pop();
	REQUIRE( q4.size() == 0);
}

TEST_CASE("pop#3")
{
    Queue<int> q5 = {1, 2, 3, 4, 5};
    q5.pop();
    REQUIRE( q5.size() == 4);
}

TEST_CASE("eq")
{
    Queue <int>  q1;
    Queue <int>  q2 = {1, 2, 3, 4};
    Queue <int>  q3{q2};
    q3.push(5);
    ofstream output{ "queue.bin" };
    output << q3;
    Queue <int> q4;
    ifstream input{ "queue.bin" };
    input >> q4;
    REQUIRE(! q4.empty() );
}
