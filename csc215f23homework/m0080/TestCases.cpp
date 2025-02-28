#include "sortedSingle.h"
#include "..\\catch_amalgamated.hpp"
#include <sstream>
#include <iostream>

using namespace std;


TEST_CASE("sortedSingle::sortedSingle - the constructor")
{
    sortedSingle(list1);
    REQUIRE(list1.empty() == true);
    REQUIRE(list1.size() == 0);
}


TEST_CASE("sortedSingle::~sortedSingle - the deconstructor")
{
    sortedSingle(list1);

    SECTION("Test destructor with non-empty list")
    {
        list1.insert(5);
        list1.insert(10);
        REQUIRE(list1.size() == 2);
        list1.~sortedSingle();
        REQUIRE(list1.size() == 0);
    }
    SECTION("Test destructor with empty list")
    {
        REQUIRE(list1.empty() == true);
        list1.~sortedSingle();
        REQUIRE(list1.empty() == true);
    }
}



TEST_CASE("sortedSingle::find - Test find operation")
{
    sortedSingle(list);
    SECTION("find at start of list")
    {
        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(50);
        REQUIRE(list.find(10) == true);
    }
    SECTION("find at middle of list")
    {
        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(50);
        REQUIRE(list.find(30) == true);
    }
    SECTION("find at end of list")
    {
        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(50);
        REQUIRE(list.find(50) == true);
    }
    SECTION("find not in list")
    {
        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(50);
        REQUIRE(list.find(5) == false);
        REQUIRE(list.find(35) == false);
        REQUIRE(list.find(55) == false);
    }
    SECTION("find in empty list")
    {
        REQUIRE(list.find(5) == false);
    }
    
}



TEST_CASE("sortedSingle::retrievePosition - Test retrieve position")
{
    sortedSingle(list);
    SECTION("find at start of list")
    {
        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(50);
        REQUIRE(list.retrievePosition(10) == 1);
    }
    SECTION("find at middle of list")
    {
        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(50);
        REQUIRE(list.retrievePosition(30) == 3);
    }
    SECTION("find at end of list")
    {
        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(50);
        REQUIRE(list.retrievePosition(50) == 5);
    }
    SECTION("find not in list")
    {
        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(50);
        REQUIRE(list.retrievePosition(5) == 0);
        REQUIRE(list.retrievePosition(35) == 0);
        REQUIRE(list.retrievePosition(55) == 0);
    }
    SECTION("find in empty list")
    {
        REQUIRE(list.retrievePosition(5) == 0);
    }
}



TEST_CASE("sortedSingle::size - Test insertion and size")
{
    sortedSingle(list);
    SECTION("list of 1")
    {
        list.insert(10);
        REQUIRE(list.size() == 1);
    }
    SECTION("list of 5")
    {
        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(50);
        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(50);
        REQUIRE(list.size() == 10);
    }
    SECTION("list of empty")
    {
        REQUIRE(list.size() == 0);
    }
}



TEST_CASE("sortedSingle::empty - Test empty list")
{
    sortedSingle(list);
    SECTION("list of empty")
    {
        sortedSingle(list);
        REQUIRE(list.empty() == true);
        REQUIRE(list.size() == 0);
    }
    SECTION("list of not empty")
    {
        sortedSingle(list);
        list.insert(50);
        REQUIRE(list.empty() == false);
    }
}



TEST_CASE("sortedSingle::insert - Insertion into list")
{
    sortedSingle(list);
    sortedSingle(list1);
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);
    SECTION("find at start of list")
    {
        list.insert(5);
        REQUIRE(list.size() == 6);
    }
    SECTION("find at middle of list")
    {
        list.insert(35);
        REQUIRE(list.size() == 6);
    }
    SECTION("find at end of list")
    {
        list.insert(55);
        REQUIRE(list.size() == 6);
    }
    SECTION("insert into empty list")
    {
        list1.insert(10);
        REQUIRE(list1.size() == 1);
    }
}



TEST_CASE("sortedSingle::print")
{
    sortedSingle(list); 
    ostringstream sout;

    SECTION("prints list of 5 test ")
    {
        list.insert(3);
        list.insert(1);
        list.insert(4);
        list.insert(2);
        list.insert(5);
        list.print(sout);
        
        REQUIRE(sout.str() == "1, 2, 3, 4, 5");

    }
    SECTION("print empty list")
    {
        list.print(sout);
        REQUIRE(sout.str() == "");

    }
}


TEST_CASE("sortedSingle::remove - testing removing from list")
{
    sortedSingle(list);
    SECTION("remove at start of list")
    {
        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(50);
        REQUIRE(list.remove(10) == true);
    }
    SECTION("remove at middle of list")
    {
        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(50);
        REQUIRE(list.remove(30) == true);
    }
    SECTION("remove at end of list")
    {
        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(50);
        REQUIRE(list.remove(50) == true);
    }
    SECTION("remove not in list")
    {
        list.insert(10);
        list.insert(20);
        list.insert(30);
        list.insert(40);
        list.insert(50);
        REQUIRE(list.remove(5) == false);
        REQUIRE(list.remove(35) == false);
        REQUIRE(list.remove(55) == false);
    }
    SECTION("remove in empty list")
    {
        REQUIRE(list.remove(5) == false);
    }
}


TEST_CASE("sortedSingle::clear - Test clear list")
{
    sortedSingle(list);
    SECTION("clear list")
    {
        list.insert(10); 
        list.insert(20); 
        list.insert(30); 
        list.insert(40); 
        list.insert(50);
        list.clear();
        REQUIRE(list.empty() == true);
        REQUIRE(list.size() == 0);
    }
}


TEST_CASE("sortedSingle::sortedSingle(sortedSingle& s) - Test partD")
{
    sortedSingle(list);
    SECTION("empty list")
    {
        sortedSingle copiedEmptyList(list);
        REQUIRE(copiedEmptyList.size() == 0);
    }

    SECTION("one item list")
    {
        list.insert(5);
        sortedSingle copiedOneList(list);
        REQUIRE(copiedOneList.size() == 1);
    }

    SECTION("multi item list")
    {
        list.insert(5);
        list.insert(10);
        list.insert(7);
        list.insert(3);
        sortedSingle copiedMultiList(list);
        REQUIRE(copiedMultiList.size() == 4);
    }
}