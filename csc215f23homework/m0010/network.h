
#ifndef _NETWORK_H_
#define _NETWORK_H_

enum networkType {INVALID, CLASSA, APRIVATE, LOCALHOST, CLASSB, BPRIVATE, CLASSC
    , CPRIVATE, CLASSD, CLASSE};
typedef unsigned short int octet;
typedef unsigned int ip;


ip compressOctets(octet octet1, octet octet2, octet octet3, octet octet4);
void extractOctets(ip, octet& octet1, octet& octet2, octet& octet3, octet& octet4);
networkType getNetworkType(ip);

#endif // !__Network__H__
