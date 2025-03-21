# u_ptr
![Status](https://img.shields.io/badge/🚧_Status-In_Progress-blue)
<br>
A lightweight implementation of a unique pointer in C, providing automatic memory management and type-safe operations.

## Features
- Automatic memory management
- Type-safe operations
- Support for basic data types (char, int, float, double, void*)
- Simple API for pointer manipulation
- Print functionality with automatic type detection

## API Reference

### u_ptr_init
Initializes a new unique pointer with the given data.
```c
u_ptr* u_ptr_init(void* ptr, size_t size, dataType type);
```

### u_ptr_get
Retrieves the data stored in the unique pointer.
```c
void* u_ptr_get(u_ptr* ptr);
```

### u_ptr_print
Prints the data stored in the unique pointer with automatic type detection.
```c
void u_ptr_print(u_ptr* ptr);
```

### u_ptr_reset
Resets the unique pointer to NULL and sets the Size to 0
```c
void* u_ptr_reset(u_ptr* ptr);
```

### u_ptr_destroy
Completely deallocates the pointer and its data.
```c
void u_ptr_destroy(u_ptr** ptr);
```

## Usage example
```c
int i_val = 123;
u_ptr* i_ptr = u_ptr_init(&i_val, sizeof(i_val), INT);
u_ptr_print(i_ptr); // Prints: 123

u_ptr_reset(i_ptr);

i_val = 456;
i_ptr = u_ptr_init(&i_val, sizeof(i_val), INT); // re-initialise to change value
u_ptr_print(i_ptr); // Prints: 456

u_ptr_destroy(&i_ptr);
```

## Building
The project can be built using any standard C compiler:
```bash
gcc main.c src/u_ptr.c -o u_ptr
```
```bash
# Using the Visual Studio Native tools 
cl main.c src/u_ptr.c /I.
```

## Todo
- [ ]  Implement move semantics
- [ ]  Add array support
