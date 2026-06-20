#ifndef _DATATYPES_H_
    #include <stdlib.h>

    #define int_value(p) (*((int *) p))
    #define float_value(p) (*((float *) p))
    #define double_value(p) (*((double *) p))
    #define string_value(p) ((char *) p)

    typedef void type_t;

    typedef int (*comparator_t)(type_t *, type_t *);
    typedef void (*printfunc_t)(type_t *);

    int *int_new(int i);
    float *float_new(float f);
    double *double_new(double d);
    char *string_new(char *s);
#endif 
