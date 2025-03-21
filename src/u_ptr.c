#include "./u_ptr.h"

u_ptr* u_ptr_init(void* ptr, size_t size, dataType type)
{
    if (!ptr || size <= 0) { return NULL; }

    u_ptr* uptr = (u_ptr*)malloc(sizeof(u_ptr));
    if (!uptr) { return NULL; }

    uptr->data = malloc(size);

    memcpy(uptr->data, ptr, size);
    uptr->size = size;
    uptr->type = type;

    return uptr;
}

void* u_ptr_get(u_ptr* ptr)
{
    if (!ptr) { return NULL; }

    return ptr->data;
}

void u_ptr_print(u_ptr* ptr) 
{
    if (!ptr || !ptr->data) { return; }

    switch (ptr->type) 
    {
        case CHAR:
            printf("%c \n", *(char*)ptr->data);
            break;
        case INT:
            printf("%d \n", *(int*)ptr->data);
            break;
        case FLOAT:
            printf("%f \n", *(float*)ptr->data);
            break;
        case DOUBLE:
            printf("%lf \n", *(double*)ptr->data);
            break;
        case VOID:
            printf("Void type \n");
            break;
        default:
            printf("Unknown type");
    }
}

static void u_ptr_free(u_ptr* ptr) 
{
    if (!ptr) { return; }

    free_ptr_data(ptr);
}

static void free_ptr_data(u_ptr* ptr) 
{
    if (ptr) 
    {
        free(ptr->data);
        ptr->data = NULL;
        ptr->size = 0;
    }
}

void u_ptr_reset(u_ptr* ptr)
{
    if (!ptr) { return; }

    free_ptr_data(ptr);
}

void u_ptr_destroy(u_ptr** ptr) 
{
    if (!ptr) { return; }

    free_ptr_data(*ptr);
    free(*ptr);
    *ptr = NULL;
}