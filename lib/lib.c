#include "lib/kprintf.h"
#include "lib/lib.h"

#include "arch/screen.h"

void* memset(void* ptr, uint8_t value, size_t num)
{
    uint8_t* d = ptr;
    while (num--) {
        *d = value;
        ++d;
    }
    return ptr;
}

void* memcpy(void* destination, const void* source, size_t num)
{
    uint8_t* d = destination;
    const uint8_t* s = source;
    while (num--) {
        *d = *s;
        ++d;
        ++s;
    }
    return destination;
}

void __assert(const char* file, int line, const char* expr)
{
    kprintf("%$Assertion failed!: \"%s\", file:%s, line:%u\n", SCREEN_COLOR(RED, WHITE), expr, file, line);
}

void panic(const char *msg, const char *file, const int line)
{
    kprintf("%$Panic: %s %s:%i\n", SCREEN_COLOR(RED, WHITE), msg, file, line);
    for (; ; ) { }
}
