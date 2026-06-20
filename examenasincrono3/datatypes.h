#ifndef _DATATYPES_H

#define _DATATYPES_H

#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef void type_t;
typedef int (*comparator_t)(type_t *,type_t *);
typedef void (*printfunc_t)(type_t *);


char *string_new(char *s);

int8_t *int8_new(int8_t n);
uint8_t *uint8_new(uint8_t n);
int16_t *int16_new(int16_t n);
uint16_t *uint16_new(uint16_t n);
int32_t *int32_new(int32_t n);
uint32_t *uint32_new(uint32_t n);

#define sint8_val(p) (*((int8_t *) p))
#define uint8_val(p) (*((uint8_t *) p))
#define sint16_val(p) (*((int16_t *) p))
#define uint16_val(p) (*((uint16_t *) p))
#define sint32_val(p) (*((int32_t *) p))
#define uint32_val(p) (*((uint32_t *) p))



#endif