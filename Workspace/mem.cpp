#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // Required for uintptr_t
#include <cstring>
void* aligned_malloc(size_t size, size_t alignment) {
    /*
    
    */

    // We need extra memory to store the original pointer and for alignment padding
    size_t total_size = size + alignment + sizeof(void*);
    void* original_ptr = malloc(total_size);

    if (original_ptr == NULL) {
        return NULL;
    }

    // Calculate the next aligned address
    uintptr_t raw_address = (uintptr_t)original_ptr;
    // Add space for the stored pointer and alignment padding, then mask off the unaligned bits
    uintptr_t aligned_address = (raw_address + sizeof(void*) + alignment - 1) & ~(alignment - 1);

    // Store the original pointer just before the aligned address
    void** ptr_storage = (void**)(aligned_address - sizeof(void*));
    *ptr_storage = original_ptr;

    return (void*)aligned_address;
}

void aligned_free(void* aligned_ptr) {
    if (aligned_ptr != NULL) {
        // Retrieve the original pointer stored just before the aligned block
        void** ptr_storage = (void**)((uintptr_t)aligned_ptr - sizeof(void*));
        free(*ptr_storage);
    }
}













void* aligned_alloc(size_t size, size_t alignment)
{
    void* raw_ptr;
    char* align_ptr;
    size_t align_alloc_size = size + sizeof(void*) + (alignment - 1);
    
    raw_ptr = malloc(align_alloc_size);
    
    //align_ptr = (void*)( ( (char*)raw_ptr + (char*)( (alignment - 1) + sizeof(void*)) ) & (alignment - 1) );
    align_ptr = (char*)raw_ptr + sizeof(void*);

    align_ptr = align_ptr + (alignment - 1);
    align_ptr = (char*)((uint64_t)align_ptr  & ~(alignment - 1));
    //void* store_ptr = (void*)(align_ptr - sizeof(void*));
	void** store_ptr = (void**) (align_ptr - sizeof(void*));
	*store_ptr = raw_ptr;
    //memcpy(store_ptr, raw_ptr, sizeof(void*));

    return align_ptr;

}


void aligned_dealloc(void *aligned_ptr)
{
    void** store_ptr = (void**) ((uint64_t)aligned_ptr - sizeof(void*));
    free(*store_ptr);
}


void* md_alloc(int x, int y, int z)
{

    void*** ptrxyz = (void***)malloc(sizeof(void***) * x);
    for (int i = 0; i < x; i++)
    {
        ptrxyz[i] = (void **) malloc(y);
        for (int j = 0; j < y; j++)
        {
            ptrxyz[i][j] = (void*)malloc(z);
        }
    }
    return ptrxyz;
}

void md_dealloc(void* ptr, int x, int y, int z)
{
    void*** ptrxyz = (void***)ptr;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
			free(ptrxyz[i][j]);
        }
		free(ptrxyz[i]);
    }
	free(ptrxyz);
    return;
}

void mem() 
{

    void *ptr = md_alloc(2, 3, 4);
    md_dealloc(ptr, 2, 3, 4);

    size_t alignment = 64; // Example alignment
    size_t size = 100;
    char* data = (char*)aligned_alloc(size, alignment);

    if (data == NULL) {
        printf("Memory allocation failed\\n");
        return;
    }

    printf("Allocated aligned address: %p \\n", (void*)data);
    printf("Check alignment (address mod %zu): %zu\\n", alignment, (uintptr_t)data % alignment);

    aligned_dealloc(data);













#if 0
    size_t alignment = 64; // Example alignment
    size_t size = 100;
    char* data = (char*)aligned_malloc(size, alignment);

    if (data == NULL) {
        printf("Memory allocation failed\\n");
        return;
    }

    printf("Allocated aligned address: %p \\n", (void*)data);
    printf("Check alignment (address mod %zu): %zu\\n", alignment, (uintptr_t)data % alignment);

    aligned_free(data);
#endif
    return;
}

