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

/// <summary>
/// Initialises the pointer with a fixed size and type
/// </summary>
/// <param name="ptr">Specifised the pointer that should be initialised</param>
/// <param name="size">Size of the data within the pointer</param>
/// <param name="type">Type of data the pointer should hold</param>
/// <returns>Initialized u_ptr pointer</returns>
u_ptr* u_ptr_init(void* ptr, size_t size, dataType type);

/// <summary>
/// Gets the data from within the pointer
/// </summary>
/// <param name="ptr">Specifies the unique pointer to get data from</param>
/// <returns>Pointer to the unique pointer data</returns>
void* u_ptr_get(u_ptr* ptr);

/// <summary>
/// Prints the data stored within the pointer
/// </summary>
/// <param name="ptr">Specifies the unique pointer to print data from</param>
void u_ptr_print(u_ptr* ptr);

/// <summary>
/// Resets the pointer to be ready for re-initialisation
/// </summary>
/// <param name="ptr">Specifies the unique pointer that should be reset</param>
void u_ptr_reset(u_ptr* ptr);

/// <summary>
/// Deallocates the memory and deletes the pointer
/// </summary>
/// <param name="ptr">Specifies the unique pointer that should be destroyed</param>
void u_ptr_destroy(u_ptr** ptr);

// Private functions
static void free_ptr_data(u_ptr* ptr); 

#endif