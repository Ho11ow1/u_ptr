#include "./src/u_ptr.h"

int main(void)
{
    int i_val = 123123123;
    float f_val = 123123.123;
    double d_val = 123123.123;
    char c_val = 'a';
    void* v_val = NULL;

    // Create and initialize the pointers
    u_ptr* i_ptr = u_ptr_init(&i_val, sizeof(i_val), INT);
    u_ptr* f_ptr = u_ptr_init(&f_val, sizeof(f_val), FLOAT);
    u_ptr* d_ptr = u_ptr_init(&d_val, sizeof(d_val), DOUBLE);
    u_ptr* c_ptr = u_ptr_init(&c_val, sizeof(c_val), CHAR);
    u_ptr* v_ptr = u_ptr_init(&v_val, sizeof(v_val), VOID);

    // Print the initial values
    u_ptr_print(i_ptr);
    u_ptr_print(f_ptr);
    u_ptr_print(d_ptr);
    u_ptr_print(c_ptr);
    u_ptr_print(v_ptr);

    // Reset pointers to be ready for re-assignment
    u_ptr_reset(i_ptr);
    u_ptr_reset(f_ptr);
    u_ptr_reset(d_ptr);
    u_ptr_reset(c_ptr);
    u_ptr_reset(v_ptr);

    // Re-assign the values
    i_val = 456;
    f_val = 456.456;
    d_val = 456.456;
    c_val = 's';
    v_val = NULL;

    // Re-Initialize the pointers
    i_ptr = u_ptr_init(&i_val, sizeof(i_val), INT);
    f_ptr = u_ptr_init(&f_val, sizeof(f_val), FLOAT);
    d_ptr = u_ptr_init(&d_val, sizeof(d_val), DOUBLE);
    c_ptr = u_ptr_init(&c_val, sizeof(c_val), CHAR);
    v_ptr = u_ptr_init(&v_val, sizeof(v_val), VOID);

    // Print the values after Re-assignment
    u_ptr_print(i_ptr);
    u_ptr_print(f_ptr);
    u_ptr_print(d_ptr);
    u_ptr_print(c_ptr);
    u_ptr_print(v_ptr);

    // Completely remove the pointers and it's memory
    u_ptr_destroy(&i_ptr);
    u_ptr_destroy(&f_ptr);
    u_ptr_destroy(&d_ptr);
    u_ptr_destroy(&c_ptr);
    u_ptr_destroy(&v_ptr);

    return 0;
} // Automatically deallocates memory (Out of scope)