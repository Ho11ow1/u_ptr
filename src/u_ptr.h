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
    VOID
} dataType;

typedef struct u_ptr
{
    void* data;
    size_t size;
    dataType type;
} u_ptr;

// Public functions
u_ptr* u_ptr_init(void* ptr, size_t size, dataType type);
void* u_ptr_get(u_ptr* ptr);
void u_ptr_print(u_ptr* ptr);
void* u_ptr_reset(u_ptr* ptr);
void u_ptr_destroy(u_ptr** ptr);

// Private functions
static void u_ptr_free(u_ptr* ptr);
static void free_ptr_data(u_ptr* ptr); 

#endif