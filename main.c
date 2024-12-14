#include "./src/u_ptr.h"

int main(void)
{
    int i_val = 123123123;
    double d_val = 123123123.123;
    char c_val = 'a';

    u_ptr* i_ptr = u_ptr_init(&i_val, sizeof(i_val), INT);
    u_ptr* d_ptr = u_ptr_init(&d_val, sizeof(d_val), DOUBLE);
    u_ptr* c_ptr = u_ptr_init(&c_val, sizeof(c_val), CHAR);
    // Print the data from the unique_ptr with automatic type detection from u_ptr_init
    u_ptr_print(i_ptr);
    u_ptr_print(d_ptr);
    u_ptr_print(c_ptr);
    // Reset the unique_ptr to NULL ready for re assignment with u_ptr_init
    u_ptr_reset(i_ptr);
    u_ptr_reset(d_ptr);
    u_ptr_reset(c_ptr);
    // Will not print anything as data is NULL and has no size
    u_ptr_print(i_ptr);
    u_ptr_print(d_ptr);
    u_ptr_print(c_ptr);
    // ToDo: Automatically free memory when unique_ptr goes out of scope
    free(i_ptr);
    free(d_ptr);
    free(c_ptr);

    return 0;
}