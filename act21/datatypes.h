#ifndef _DATATYPES_H_
    #include <stdlib.h>

    #define int_value(p) (*((int *) p))


    typedef void type_t;

    typedef int (*comparator_t)(type_t *, type_t *);
    typedef void (*printfunc_t)(type_t *);

    int *int_new(int i);
    char *string_new(char *s);
#endif 
