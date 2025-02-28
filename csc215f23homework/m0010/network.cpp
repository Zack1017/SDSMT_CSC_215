#include "network.h"

ip compressOctets(octet octet1, octet octet2, octet octet3, octet octet4)
{
        octet extract = 255;
        ip addr1 = octet1 & extract;
        ip addr2 = octet2 & extract;
        ip addr3 = octet3 & extract;
        ip addr4 = octet4 & extract;
        ip addr = addr1;
        addr = addr << 8;
        addr = addr | addr2;
        addr = addr << 8;
        addr = addr | addr3;
        addr = addr << 8;
        addr = addr | addr4;
        return addr;
}

void extractOctets(ip addr, octet& octet1, octet& octet2, octet& octet3, octet& octet4)
{
    octet extract = 255;
    octet4 = addr & extract;
    addr = addr >> 8;
    octet3 = addr & extract;
    addr = addr >> 8;
    octet2 = addr & extract;
    addr = addr >> 8;
    octet1 = addr & extract;
}

networkType getNetworkType(ip addr)
{
    networkType network;
    octet oct1, oct2, oct3, oct4;
    extractOctets(addr, oct1, oct2, oct3, oct4);
    if (oct1 == 0)
    {
        network = INVALID;
        return network;
    }
    if (oct1 > 0 && oct1 < 128)
    {
        if (10 == oct1)
        {
            network = APRIVATE;
            return network;
        }
        else if (127 == oct1)
        {
            network = LOCALHOST;
            return network;
        }
        network = CLASSA;
        return network;
    }
    else if ( oct1 > 127 && oct1 < 192)
    {
        if (oct1 == 172 && oct2 > 15 && oct2 < 32)
        {
            network = BPRIVATE;
            return network;
        }
        network = CLASSB;
        return network;
    }
    else if (oct1 > 191 && oct1 < 224)
    {
        if (oct1 == 192 && oct2 == 168)
        {
            network = CPRIVATE;
            return network;
        }
        network = CLASSC;
        return network;
    }
    else if (oct1 > 223 && oct1 < 240)
    {
        network = CLASSD;
        return network;
    }
    else
    {
        return CLASSE;
    }
}