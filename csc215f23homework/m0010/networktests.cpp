#include "..\catch_amalgamated.hpp"
#include "network.h"

using namespace Catch;

TEST_CASE("compressOctets - testing first octets/Class B test")
{
    ip resultIP = compressOctets(151, 0, 0, 0);
    REQUIRE(2533359616 == resultIP);
}

TEST_CASE("compressOctets - testing second octets")
{
    ip resultIP = compressOctets(0, 159, 0, 0);
    REQUIRE(10420224 == resultIP);
}

TEST_CASE("compressOctets - testing third octets")
{
    ip resultIP = compressOctets(0, 0, 15, 0);
    REQUIRE(3840 == resultIP);
}

TEST_CASE("compressOctets - testing forth octets")
{
    ip resultIP = compressOctets(0, 0, 0, 20);
    REQUIRE(20 == resultIP);
}

TEST_CASE("compressOctets - testing all octets")
{
    ip resultIP = compressOctets(152, 148, 112, 36);
    REQUIRE(2559864868 == resultIP);
}

TEST_CASE("compressOctets - testing all octets differnt/Class A test")
{
    ip resultIP = compressOctets(15, 10, 12, 36);
    REQUIRE(252316708 == resultIP);
}

TEST_CASE("compressOctets - testing all octets differnt/Class C test ")
{
    ip resultIP = compressOctets(195, 10, 12, 36);
    REQUIRE(3272215588 == resultIP);
}

TEST_CASE("compressOctets - testing Class D ")
{
    ip resultIP = compressOctets(230, 10, 12, 36);
    REQUIRE(3859418148 == resultIP);
}

TEST_CASE("compressOctets - testing Class E ")
{
    ip resultIP = compressOctets(250, 10, 12, 36);
    REQUIRE(4194962468 == resultIP);
}

TEST_CASE("extractOctets - testing forth octet")
{
    octet oct1 = 0;
    octet oct2 = 0;
    octet oct3 = 0;
    octet oct4 = 0;

    extractOctets(32, oct1 , oct2 , oct3,oct4);
    CHECK(oct1 == 0);
    CHECK(oct2 == 0);
    CHECK(oct3 == 0);
    CHECK(oct4 == 32);
}

TEST_CASE("extractOctets - testing thrid octet")
{
    octet oct1 = 0;
    octet oct2 = 0;
    octet oct3 = 0;
    octet oct4 = 0;

    extractOctets(3072, oct1, oct2, oct3, oct4);
    CHECK(oct1 == 0);
    CHECK(oct2 == 0);
    CHECK(oct3 == 12);
    CHECK(oct4 == 0);
}

TEST_CASE("extractOctets - testing second octet")
{
    octet oct1 = 0,
          oct2 = 0,
          oct3 = 0,
          oct4 = 0;

    extractOctets(655360, oct1, oct2, oct3, oct4);
    CHECK(oct1 == 0);
    CHECK(oct2 == 10);
    CHECK(oct3 == 0);
    CHECK(oct4 == 0);
}

TEST_CASE("extractOctets - testing first octet/ classa")
{
    octet oct1 = 0,
          oct2 = 0,
          oct3 = 0,
          oct4 = 0;

    extractOctets(369098752, oct1, oct2, oct3, oct4);
    CHECK(oct1 == 22);
    CHECK(oct2 == 0);
    CHECK(oct3 == 0);
    CHECK(oct4 == 0);
}

TEST_CASE("extractOctets - testing all octet/classb")
{
    octet oct1 = 0,
        oct2 = 0,
        oct3 = 0,
        oct4 = 0;

    extractOctets(2543783700, oct1, oct2, oct3, oct4);
    CHECK(oct1 == 151);
    CHECK(oct2 == 159);
    CHECK(oct3 == 15);
    CHECK(oct4 == 20);
}

TEST_CASE("extractOctets - testing all octet with human reading/classc")
{
    ip addr = compressOctets(215, 112, 49, 183);
    octet oct1,oct2, oct3, oct4;

    extractOctets(addr, oct1, oct2, oct3, oct4);
    CHECK(oct1 == 215);
    CHECK(oct2 == 112);
    CHECK(oct3 == 49);
    CHECK(oct4 == 183);
}

TEST_CASE("extractOctets - testing all octet with human reading/classd")
{
    ip addr = compressOctets(230, 247, 172, 54);
    octet oct1, oct2, oct3, oct4;

    extractOctets(addr, oct1, oct2, oct3, oct4);
    CHECK(oct1 == 230);
    CHECK(oct2 == 247);
    CHECK(oct3 == 172);
    CHECK(oct4 == 54);
}

TEST_CASE("extractOctets - testing all octet with human reading/classe")
{
    ip addr = compressOctets(250, 235, 129, 107);
    octet oct1, oct2, oct3, oct4;

    extractOctets(addr, oct1, oct2, oct3, oct4);
    CHECK(oct1 == 250);
    CHECK(oct2 == 235);
    CHECK(oct3 == 129);
    CHECK(oct4 == 107);
}

TEST_CASE("getNetworkType - testing invalid class")
{
    ip addr = compressOctets(0, 235, 129, 107);
    networkType classified = getNetworkType(15434091);
    REQUIRE(INVALID == classified);
}

TEST_CASE("getNetworkType - testing CLASSA class low")
{
    ip addr = compressOctets(1, 235, 129, 107);
    networkType classified = getNetworkType(addr);
    REQUIRE(CLASSA == classified);
}

TEST_CASE("getNetworkType - testing CLASSA class high")
{
    ip addr = compressOctets(126, 235, 129, 107);
    networkType classified = getNetworkType(addr);
    REQUIRE(CLASSA == classified);
}

TEST_CASE("getNetworkType - testing CLASSA class")
{
    ip addr = compressOctets(100, 235, 129, 107);
    networkType classified = getNetworkType(addr);
    REQUIRE(CLASSA == classified);
}

TEST_CASE("getNetworkType - testing APRIVATE class lower")
{
    ip addr = compressOctets(10, 0, 0, 0);
    networkType classified = getNetworkType(addr);
    REQUIRE(APRIVATE == classified);
}

TEST_CASE("getNetworkType - testing APRIVATE class upper ")
{
    ip addr = compressOctets(10, 255, 255, 255);
    networkType classified = getNetworkType(addr);
    REQUIRE(APRIVATE == classified);
}

TEST_CASE("getNetworkType - testing LOCALHOST class lower")
{
    ip addr = compressOctets(127, 0, 0, 0);
    networkType classified = getNetworkType(addr);
    REQUIRE(LOCALHOST == classified);
}

TEST_CASE("getNetworkType - testing LOCALHOST class upper")
{
    ip addr = compressOctets(127, 255, 255, 255);
    networkType classified = getNetworkType(addr);
    REQUIRE(LOCALHOST == classified);
}

TEST_CASE("getNetworkType - testing CLASSB class lower")
{
    ip addr = compressOctets(128, 0, 0, 0);
    networkType classified = getNetworkType(addr);
    REQUIRE(CLASSB == classified);
}

TEST_CASE("getNetworkType - testing CLASSB class upper")
{
    ip addr = compressOctets(191, 255, 255, 255);
    networkType classified = getNetworkType(addr);
    REQUIRE(CLASSB == classified);
}

TEST_CASE("getNetworkType - testing BPRIVATE class lower")
{
    ip addr = compressOctets(172, 16, 0, 0);
    networkType classified = getNetworkType(addr);
    REQUIRE(BPRIVATE == classified);
}

TEST_CASE("getNetworkType - testing BPRIVATE class upper")
{
    ip addr = compressOctets(172, 31, 255, 255);
    networkType classified = getNetworkType(addr);
    REQUIRE(BPRIVATE == classified);
}

TEST_CASE("getNetworkType - testing CLASSC class lower")
{
    ip addr = compressOctets(192, 0, 0, 0);
    networkType classified = getNetworkType(addr);
    REQUIRE(CLASSC == classified);
}

TEST_CASE("getNetworkType - testing CLASSC class upper")
{
    ip addr = compressOctets(223, 255, 255, 255);
    networkType classified = getNetworkType(addr);
    REQUIRE(CLASSC == classified);
}

TEST_CASE("getNetworkType - testing CPRIVATE class lower")
{
    ip addr = compressOctets(192, 168, 0, 0);
    networkType classified = getNetworkType(addr);
    REQUIRE(CPRIVATE == classified);
}

TEST_CASE("getNetworkType - testing CPRIVATE class upper")
{
    ip addr = compressOctets(192, 168, 255, 255);
    networkType classified = getNetworkType(addr);
    REQUIRE(CPRIVATE == classified);
}

TEST_CASE("getNetworkType - testing CLASSD class lower")
{
    ip addr = compressOctets(224, 0, 0, 0);
    networkType classified = getNetworkType(addr);
    REQUIRE(CLASSD == classified);
}

TEST_CASE("getNetworkType - testing CLASSD class upper")
{
    ip addr = compressOctets(239, 255, 255, 255);
    networkType classified = getNetworkType(addr);
    REQUIRE(CLASSD == classified);
}

TEST_CASE("getNetworkType - testing CLASSE class lower")
{
    ip addr = compressOctets(240, 0, 0, 0);
    networkType classified = getNetworkType(addr);
    REQUIRE(CLASSE == classified);
} 

TEST_CASE("getNetworkType - testing CLASSE class upper")
{
    ip addr = compressOctets(255, 255, 255, 255);
    networkType classified = getNetworkType(addr);
    REQUIRE(CLASSE == classified);
}

TEST_CASE("getNetworkType - testing random1")
{
    ip addr = compressOctets(172, 20, 34, 138);
    networkType classified = getNetworkType(addr);
    REQUIRE(BPRIVATE == classified);
}

TEST_CASE("getNetworkType - testing random2")
{
    ip addr = compressOctets(132, 193, 172,225);
    networkType classified = getNetworkType(addr);
    REQUIRE(CLASSB == classified);
}

TEST_CASE("getNetworkType - testing random3")
{
    ip addr = compressOctets(49, 180, 232, 192);
    networkType classified = getNetworkType(addr);
    REQUIRE(CLASSA == classified);
}

TEST_CASE("getNetworkType - testing random4")
{
    ip addr = compressOctets(52, 217, 79, 118);
    networkType classified = getNetworkType(addr);
    REQUIRE(CLASSA == classified);
}

TEST_CASE("getNetworkType - testing random5")
{
    ip addr = compressOctets(192, 51, 85, 77);
    networkType classified = getNetworkType(addr);
    REQUIRE(CLASSC == classified);
}