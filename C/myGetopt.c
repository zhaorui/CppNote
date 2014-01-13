#include <unistd.h>
#include <stdio.h>
#include <string.h>
//extern char *optarg;
//extern int optind, opterr, optopt;

//static const char *options = "abcd:efgh::ijklmnopqrstuvwxyz";
static const char *options = ":abcd:efgh::ijklmnopqrst";

void inline printf_optarg()
{
    if(optarg!=NULL && strlen(optarg)!=0)
        printf("optarg: %s\n",optarg);
    else
        printf("optarg:\n");
}

int main(int argc,char *argv[])
{
    int ch;

    printf("++++++ Debug Getopt ++++++\n");
    printf_optarg();
    printf("optind: %d\n",optind);
    printf("opterr: %d\n",opterr);
    printf("optopt: %d\n",optopt);
    printf("++++++++++++++++++++++++++\n\n");

    while((ch=getopt(argc,argv,":a:bcd"))!=-1)
    {
        printf("------------------------\n");
        printf("ch:     %c\n",(char)ch);
        printf_optarg();
        printf("optind: %d\n",optind);
        printf("opterr: %d\n",opterr);
        printf("optopt: %d\n",optopt);
    }

    printf("\n++++++ Debug Getopt ++++++\n");
    printf_optarg();
    printf("optind: %d\n",optind);
    printf("opterr: %d\n",opterr);
    printf("optopt: %d\n",optopt);
    printf("++++++++++++++++++++++++++\n\n");

    return 0;
}
