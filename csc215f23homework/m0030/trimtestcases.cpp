#include "..\\catch_amalgamated.hpp"
#include "trim.h"
using namespace Catch;
TEST_CASE("cTrim - Tesing string only (0)")
{
    char aString[100] = "Catch with Sections!";
    char answer[100] = "Catch with Sections!";
    CHECK(strcmp(aString, answer) == 0);

    SECTION("Font-Just Phrase(0.1)")
    {
        cTrim(aString, FRONT);
        CHECK(strcmp(aString, answer) == 0);
    }
    SECTION("END-Just Phrase(0.2)")
    {
        cTrim(aString, END);
        CHECK(strcmp(aString, answer) == 0);
    }
    SECTION("BOTH-Just Phrase(0.3)")
    {
        cTrim(aString, BOTH);
        CHECK(strcmp(aString, answer) == 0);
    }
}

TEST_CASE("cTrim - Testing C string with just a space (1)")
{
    char aString[100] = " ";
    char answer[100] = "";
    cTrim(aString, FRONT);
    CHECK(strcmp(answer, aString) == 0);
}

TEST_CASE("cTrim - Testing C string with 3 space FRONT (2)")
{
    char aString[100] = "   a";
    char answer[100] = "a";
    cTrim(aString, FRONT);
    CHECK(strcmp(answer, aString) == 0);
    //std::cout << answer << ":" << aString<< endl;
}

TEST_CASE("cTrim - Testing C string with a tab FRONT (3)")
{
    char aString[100] = "\t a";
    char answer[100] = "a";
    cTrim(aString, FRONT);
    CHECK(strcmp(answer, aString) == 0);
    //std::cout << answer << ":" << aString << endl;
}

TEST_CASE("cTrim - Testing C string with a new line FRONT (4)")
{
    char aString[100] = "\n abcd";
    char answer[100] = "abcd";
    cTrim(aString, FRONT);
    CHECK(strcmp(answer, aString) == 0);
    //std::cout << answer << ":" << aString << endl;
}

TEST_CASE("cTrim - Testing C string with a spaces with works and spaces FRONT (5)")
{
    char aString[100] = " ab cd ef gh";
    char answer[100] = "ab cd ef gh";
    cTrim(aString, FRONT);
    CHECK(strcmp(answer, aString) == 0);
    //std::cout << answer << ":" << aString << endl;
}

TEST_CASE("cTrim - Testing C string with a spaces END (6)")
{
    char aString[100] = "gh ";
    char answer[100] = "gh";
    cTrim(aString, END);
    CHECK(strcmp(answer, aString) == 0);
    //std::cout << answer << ":" << aString <<"|" <<endl;
}

TEST_CASE("cTrim - Testing C string with a new line END (7)")
{
    char aString[100] = "gh\n";
    char answer[100] = "gh";
    cTrim(aString, END);
    CHECK(strcmp(answer, aString) == 0);
    //std::cout << answer << ":" << aString << "|" << endl;
}

TEST_CASE("cTrim - Testing C string with a spaces between words END (8)")
{
    char aString[100] = "ab cd ef gh ";
    char answer[100] = "ab cd ef gh";
    cTrim(aString, END);
    CHECK(strcmp(answer, aString) == 0);
    //std::cout << answer << ":" << aString << "|" << endl;
}

TEST_CASE("cTrim - Testing C string with a spaces BOTH (9)")
{
    char aString[100] = " gh ";
    char answer[100] = "gh";
    cTrim(aString, BOTH);
    CHECK(strcmp(answer, aString) == 0);
    //std::cout << answer << ":" << aString <<"|" <<endl;
}

TEST_CASE("cTrim - Testing C string with a new line BOTH (10)")
{
    char aString[100] = "\ngh\n";
    char answer[100] = "gh";
    cTrim(aString, BOTH);
    CHECK(strcmp(answer, aString) == 0);
    //std::cout << answer << ":" << aString << "|" << endl;
}

TEST_CASE("cTrim - Testing C string with a spaces between words BOTH (11)")
{
    char aString[100] = " \t ab cd ef gh ";
    char answer[100] = "ab cd ef gh";
    cTrim(aString, BOTH);
    CHECK(strcmp(answer, aString) == 0);
    //std::cout << answer << ":" << aString << "|" << endl;
}

TEST_CASE("sTrim - Testing string wih no we on wither end (12)")
{
    string aString = "Catch with Sections!";
    string answer = "Catch with Sections!";

    SECTION("Front - Just a phrase(12.1)")
    {
        sTrim(aString, FRONT);
        REQUIRE(answer == aString);
    }
    SECTION("END - Just a phrase(12.2)")
    {
        sTrim(aString, END);
        REQUIRE(answer == aString);
    }
    SECTION("BOTH - Just a phrase(12.3)")
    {
        sTrim(aString, BOTH);
        REQUIRE(answer == aString);
    }
}
TEST_CASE("sTrim - Testing C string with just a space FRONT(13)")
{
    string aString = " ";
    string answer = "";
    sTrim(aString, FRONT);
    CHECK(answer == aString);
}
TEST_CASE("sTrim - Testing C string with 3 space FRONT (14)")
{
    string aString = "   a";
    string answer = "a";
    sTrim(aString, FRONT);
    CHECK(answer == aString);
    //std::cout << answer << ":" << aString<< endl;
}

TEST_CASE("sTrim - Testing C string with a tab FRONT (15)")
{
    string aString = "\t a";
    string answer = "a";
    sTrim(aString, FRONT);
    CHECK(answer == aString);
    //std::cout << answer << ":" << aString << endl;
}

TEST_CASE("sTrim - Testing C string with a new line FRONT (16)")
{
    string aString = "\n abcd";
    string answer = "abcd";
    sTrim(aString, FRONT);
    CHECK(answer == aString);
    //std::cout << answer << ":" << aString << endl;
}

TEST_CASE("sTrim - Testing C string with a spaces with works and spaces FRONT (17)")
{
    string aString = " ab cd ef gh";
    string answer = "ab cd ef gh";
    sTrim(aString, FRONT);
    CHECK(answer == aString);
    //std::cout << answer << ":" << aString << endl;
}

TEST_CASE("sTrim - Testing C string with 3 space END (18)")
{
    string aString = "a   ";
    string answer = "a";
    sTrim(aString, END);
    CHECK(answer == aString);
    //std::cout << answer << ":" << aString<< endl;
}

TEST_CASE("sTrim - Testing C string with a tab END (19)")
{
    string aString = "a\t";
    string answer = "a";
    sTrim(aString, END);
    CHECK(answer == aString);
    //std::cout << answer << ":" << aString << endl;
}

TEST_CASE("sTrim - Testing C string with a new line END (20)")
{
    string aString = "abcd\n";
    string answer = "abcd";
    sTrim(aString, END);
    CHECK(answer == aString);
    //std::cout << answer << ":" << aString << endl;
}

TEST_CASE("sTrim - Testing C string with a spaces with works and spaces END (21)")
{
    string aString = "ab cd ef gh ";
    string answer = "ab cd ef gh";
    sTrim(aString, END);
    CHECK(answer == aString);
    //std::cout << answer << ":" << aString << endl;
}

TEST_CASE("sTrim - Testing C string with a spaces BOTH (22)")
{
    string aString = " gh ";
    string answer = "gh";
    sTrim(aString, BOTH);
    CHECK(answer == aString);
    //std::cout << answer << ":" << aString <<"|" <<endl;
}

TEST_CASE("sTrim - Testing C string with a new line BOTH (23)")
{
    string aString = "\ngh\n";
    string answer = "gh";
    sTrim(aString, BOTH);
    CHECK(answer == aString);
    //std::cout << answer << ":" << aString << "|" << endl;
}

TEST_CASE("sTrim - Testing C string with a spaces between words BOTH (24)")
{
    string aString = " \t ab cd ef gh ";
    string answer = "ab cd ef gh";
    sTrim(aString, BOTH);
    CHECK(answer == aString);
    //std::cout << answer << ":" << aString << "|" << endl;
}