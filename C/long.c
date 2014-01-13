#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>

//extern char *optarg;
//extern int optind, opterr, optopt;

int dick;
static struct option long_options[] = {
    {"ass",no_argument,0,'a'},
    {"batman",required_argument,0,'b'},
    {"cox",optional_argument,0,'c'},
    {"dick",no_argument,&dick,'d'},
    {0,0,0,0}
};

const char * options = ":ab:cd";

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
    int option_index = 0;
    printf("++++++ Debug Getopt ++++++\n");
    printf_optarg();
    printf("optind: %d\n",optind);
    printf("opterr: %d\n",opterr);
    printf("optopt: %d\n",optopt);
    printf("++++++++++++++++++++++++++\n\n");

    while((ch=getopt_long(argc,argv,options,long_options,&option_index))!=-1)
    {
        printf("------------------------\n");
        printf("ch:     %c %d\n",(char)ch,ch);
        printf_optarg();
        printf("optind: %d\n",optind);
        printf("opterr: %d\n",opterr);
        printf("optopt: %d\n",optopt);
    }

    printf("++++++ Debug Getopt ++++++\n");
    printf_optarg();
    printf("optind: %d\n",optind);
    printf("opterr: %d\n",opterr);
    printf("optopt: %d\n",optopt);
    printf("++++++++++++++++++++++++++\n\n");

    return 0;
}
