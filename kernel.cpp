// Load the files
// We can't use frameworks because we are on our own 
// We can't build in a linux enviroments
#include "types.h" 


// This is a very basic printf
// This will show text in the terminal in the OS
void printf(char* str) {
    static uint16_t* VideoMemory = (uint16_t*)0xb8000;

    for(int i = 0; str[i] != '\0'; ++i) {
        VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
    }
}



typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors() {
    for(constructor* i = &start_ctors; i != &end_ctors; i++) {
        (*i)();
    }
}



extern "C" void kernelDidLoad(const void* multiboot_structure, uint32_t /*multiboot_magic*/) {
    printf("Hello World! --- Ashwin Paudel \n \n");

    // We don't want to stop the kernel so we keep a loop
    while(1);
}