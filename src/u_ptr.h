#ifndef U_PTR_H
#define U_PTR_H

#include <stdio.h>
#include <stdlib.h>

typedef enum dataType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
} dataType;

typedef struct u_ptr
{
    void* data;
    size_t size;
    dataType type;
} u_ptr;

u_ptr* u_ptr_init(void* ptr, size_t size, dataType type);
void* u_ptr_get(u_ptr* ptr);
void u_ptr_print(u_ptr* ptr);
void* u_ptr_reset(u_ptr* ptr);

#endif