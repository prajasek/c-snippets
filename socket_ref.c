#include <sys/socket.h>  // socket
#include <stdio.h>       // printf
#include <string.h>      //strcpy
#include <stdint.h>      // uint32_t

/*
struct sockaddr {                   // Common address structure to be cast into
    unsigned short   sa_family; 2
    char            sa_data[14];    // address+port - not enough for IPv6 (16 bytes)
                                    // the number 14 is variable based on sa_family
}  

struct sockaddr_in {                 // ipv4
    short int          sin_family;   // Address family, AF_INET
    unsigned short int sin_port;     // Port number
    struct in_addr     sin_addr;     // Internet address
    unsigned char      sin_zero[8];  // Same size as struct sockaddr
}           

struct in_addr {
    uint32_t s_addr;                 // 4 bytes ipv4 address (example: 10.12.32.xx)
}

struct sockaddr_in6 {                // ipv6 (almost same as above)
    u_int16_t       sin6_family;     // address family, AF_INET6
    u_int16_t       sin6_port;       // port number, Network Byte Order
    u_int32_t       sin6_flowinfo;   // IPv6 flow information
    struct in6_addr sin6_addr;       // IPv6 address
    u_int32_t       sin6_scope_id;   // Scope ID
}               

struct in6_addr {
    uint8_t s6_addr[16];             // 16 bytes ipv6 address (example: ffee:fdee:efff:11e2::xxxx)
}

struct sockaddr_storage {            // can store both Ipv4 and Ipv6 - with padding
    unsigned char ss_family; 
    .. some padding; 
}  

Byte Ordering
---------------
Networks use big-endian, host may use any. So we need to convert 
it back and forth:
    htons - host to network short
    ntohs - network to host short
    htonl - '' long 
    ntonl - '' long
*/