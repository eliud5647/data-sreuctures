#include "datatypes.h"

char *string_new(char *s)
{
    char *new = malloc(strlen(s)+1);
    strcpy(new,s);
    return new; 
}

int8_t *int8_new(int8_t n)
{
    int8_t *new = malloc(sizeof(int8_t));
    *new = n;
    return new;
}

uint8_t *uint8_new(uint8_t n)
{
    uint8_t *new = malloc(sizeof(uint8_t));
    *new = n;
    return new;
}

int16_t *int16_new(int16_t n)
{
    int16_t *new = malloc(sizeof(int16_t));
    *new = n;
    return new;
}

uint16_t *uint16_new(uint16_t n)
{
    uint16_t *new = malloc(sizeof(uint16_t));
    *new = n;
    return new;
}

int32_t *int32_new(int32_t n)
{
    int32_t *new = malloc(sizeof(int32_t));
    *new = n;
    return new;
}

uint32_t *uint32_new(uint32_t n)
{
    uint32_t *new = malloc(sizeof(uint32_t));
    *new = n;
    return new;
}