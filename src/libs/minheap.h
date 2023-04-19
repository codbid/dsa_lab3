#pragma once

struct heapnode {
    int key;
    int value;
};

struct heap {
    int maxsize;
    int nnodes;
    struct heapnode* nodes;
};

struct heap *heap_create(int maxsize);

void heap_free(struct heap* h);

void heap_swap(struct heapnode* a, struct heapnode* b);

struct heapnode* heap_min(struct heap* h);

int heap_insert(struct heap* h, int key, int value);

void heap_heapify(struct heap* h, int index);

struct heapnode heap_extract_min(struct heap* h);

int heap_decrease_key(struct heap* h, int index, int newkey);
