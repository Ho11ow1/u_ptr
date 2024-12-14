#include "./u_ptr.h"

u_ptr* u_ptr_init(void* ptr, size_t size, dataType type)
{
    u_ptr* uptr = (u_ptr*)malloc(sizeof(u_ptr));
    uptr->data = malloc(size);
    memcpy(uptr->data, ptr, size);
    uptr->size = size;
    uptr->type = type;

    return uptr;
}

void* u_ptr_get(u_ptr* ptr)
{
    return ptr->data;
}

void u_ptr_print(u_ptr* ptr) 
{
    switch (ptr->type) 
    {
        case CHAR:
            printf("%c ", *(char*)ptr->data);
            break;
        case INT:
            printf("%d ", *(int*)ptr->data);
            break;
        case FLOAT:
            printf("%f ", *(float*)ptr->data);
            break;
        case DOUBLE:
            printf("%lf ", *(double*)ptr->data);
            break;
        default:
            printf("Unknown type");
    }
}

void* u_ptr_reset(u_ptr* ptr)
{
    void* old = ptr->data;
    ptr->data = NULL;
    ptr->size = 0;

    return old;
}

