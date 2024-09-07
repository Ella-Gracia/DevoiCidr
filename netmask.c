#include "netmask.h"
void getdata(char **ip)
{
    int d = 255;
    *ip = (char *)malloc(d * sizeof(char));
    printf("Enter CIDR:");
    scanf("%s", *ip);
}
int* netmaskValue(char *ip)
{
    int i;
    int j;
    int tmp1,
        tmp2,
        tmp3,
        tmp4;
    int t0[8];
    int t1[8];
    int t2[8];
    int t3[8];
    int bits[32];
    int *t = NULL;
    int *val = NULL;
    int *netmask = NULL;

    t = (int *)malloc(8 * sizeof(int));
    val = (int *)malloc(4 * sizeof(int));
    netmask = (int *)malloc(4 * sizeof(int));

    // printf("%s\n",ip);
    sscanf(ip, "%d.%d.%d.%d/%d", &val[0], &val[1], &val[2], &val[3], &val[4]);
    printf("%d.%d.%d.%d/%d\n", val[0], val[1], val[2], val[3], val[4]);
    
    for (i = 0; i < val[4]; i++)
    {
        t[i] = 1;
        bits[i] = t[i];
        // printf("%d", bits[i]);
    }
    for (i = val[4]; i < 32; i++)
    {
        t[i] = 0;
        bits[i] = t[i];
        // printf("%d", bits[i]);
    }
    for (i = 0; i < 32; i++)
    {
        // printf("%d", bits[i]);
    }

    for (i = 0; i < 8; i++)
    {
        t0[i] = bits[i];
        // printf("%d", t0[i]);
    }
    // printf("\n\t%d\n", bitToDec(t0));
    netmask[0] = bitToDec(t0);
    for (i = 8,j=0; i < 16 && j<8 ; i++, j++)
    {
              t1[j]=bits[i];
            //   printf("%d",t1[j]);
    }
    netmask[1] = bitToDec(t1);
    for (i = 16, j=0; i < 24 && j<8; i++, j++)
    {
            t2[j] = bits[i];
            // printf("%d",t2[j]);
    }
    netmask[2] = bitToDec(t2);
    for (i = 24, j=0; i < 32, j<8; i++, j++)
    {
            t3[j] = bits[i];
            // printf("%d",t3[j]);
    }
    netmask[3] = bitToDec(t3);
    return (netmask);
}

int bitToDec(int t[])
{
    int i;
    int j;
    int dec=0;

    for(i=0, j=7; i<8 && j>=0; i++, j--)
    {
        dec += pow(2, j)*t[i];
    }
    return (dec);
}
void displayIntTab(int t[])
{
    int i;

    printf("\n");
    for(i=0; i<4; i++)
    {
        printf("%d", t[i]);
        if(i!=3)
        {
            printf(".");
        }
    }
}