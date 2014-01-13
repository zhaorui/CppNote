#include <unistd.h>
#include <stdio.h>
#include <getopt.h> // getopt_long
#include <string.h>

//extern char *optarg;
//extern int optind, opterr, optopt;

/* options descriptor */
int bflag, ch, fd;
int daggerset;
static const char *options = ":bf:k";
static struct option longopts[] = {
     { "buffy",      no_argument,            NULL,           'b' },
     { "fluoride",   required_argument,      NULL,           'f' },
     { "pkinit",     optional_argument,      NULL,           'k'},
     { "daggerset",  no_argument,            &daggerset,     1 },
     { NULL,         0,                      NULL,           0 }
};

void inline printf_optarg()
{
    if(optarg!=NULL && strlen(optarg)!=0)
        printf("optarg: %s\n",optarg);
    else
        printf("optarg:\n");
}

int main(int argc,char *argv[])
{
    printf("++++++ Debug Getopt ++++++\n");
    printf_optarg();
    printf("optind: %d\n",optind);
    printf("opterr: %d\n",opterr);
    printf("optopt: %d\n",optopt);
    printf("++++++++++++++++++++++++++\n\n");

    while((ch=getopt_long(argc-1,argv+1,options,longopts,NULL))!=-1)
    {
        printf("------------------------\n");
        printf("ch:     %c (%d)\n",(char)ch,ch);
        printf("daggerset: %d\n",daggerset);
        printf_optarg();
        printf("optind: %d\n",optind);
        printf("opterr: %d\n",opterr);
        printf("optopt: %c (%d)\n",(char)optopt,optopt);
    }

    optind=2;
    optreset=1;
    printf("----- Second Round -----\n");
    while((ch=getopt_long(argc,argv,options,longopts,NULL))!=-1)
    {
        
        printf("------------------------\n");
        printf("ch:     %c (%d)\n",(char)ch,ch);
        printf("daggerset: %d\n",daggerset);
        printf_optarg();
        printf("optind: %d\n",optind);
        printf("opterr: %d\n",opterr);
        printf("optopt: %c (%d)\n",(char)optopt,optopt);
    }


    printf("\n++++++ Debug Getopt ++++++\n");
    printf_optarg();
    printf("optind: %d\n",optind);
    printf("opterr: %d\n",opterr);
    printf("optopt: %d\n",optopt);
    printf("++++++++++++++++++++++++++\n\n");

    return 0;
}
