#include "netmask.h"

int main()
{
    char *ip = NULL;
    int *netmask = NULL;

    getdata(&ip);
    netmask = netmaskValue(ip);
    displayIntTab(netmask);
    return 0;
}