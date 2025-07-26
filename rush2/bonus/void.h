#ifndef VOID_H
#define VOID_H

typedef enum {
    INT,
    FLOAT,
    CHAR,
    CHAR_PTR,
    CHAR_PTR_PTR,
    SHORT
} Type;

typedef struct {
    void *value;
    Type type;
} Void;

void init_void(Void *v, void *value, Type type);
void free_void(Void *v);
void add_void(Void *result, Void *v1, Void *v2);

#endif // VOID_H
