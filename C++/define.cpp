#ifdef __cplusplus
    #include <iostream>
#else
    #include <stdio.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct{
        int num;
        char **object;
        int sorted;
        int num_alloc;
        int (*comp) (const void *,const void *);
    }_STACK;

#ifdef __cplusplus
}
#endif

#define STACK_OF(type) struct stack_##type
#define DECLARE_STACK_OF(type)  \
    STACK_OF(type)              \
    {                           \
        _STACK stack;           \
    }                           \


int main(int argc, char * argv[])
{
    DECLARE_STACK_OF(Books);
#ifdef __cplusplus
    std::cout<<sizeof(_STACK)<<std::endl;
    std::cout<<sizeof(STACK_OF(Books))<<std::endl;
#else
    printf("%d\n",sizeof(_STACK));
    printf("%d\n",sizeof(STACK_OF(Books)));
#endif
    return 0;
}
