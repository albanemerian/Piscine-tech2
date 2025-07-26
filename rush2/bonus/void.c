#include "void.h"
#include <stdlib.h>
#include <string.h>

void init_void(Void *v, void *value, Type type) {
    v->type = type;
    switch (type) {
        case INT:
            v->value = malloc(sizeof(int));
            memcpy(v->value, value, sizeof(int));
            break;
        case FLOAT:
            v->value = malloc(sizeof(float));
            memcpy(v->value, value, sizeof(float));
            break;
        case CHAR:
            v->value = malloc(sizeof(char));
            memcpy(v->value, value, sizeof(char));
            break;
        case CHAR_PTR:
            v->value = strdup((char *)value);
            break;
        case CHAR_PTR_PTR:
            // Assuming a NULL-terminated array of strings
            {
                char **src = (char **)value;
                size_t count = 0;
                while (src[count]) count++;
                v->value = malloc((count + 1) * sizeof(char *));
                for (size_t i = 0; i < count; i++) {
                    ((char **)v->value)[i] = strdup(src[i]);
                }
                ((char **)v->value)[count] = NULL;
            }
            break;
        case SHORT:
            v->value = malloc(sizeof(short));
            memcpy(v->value, value, sizeof(short));
            break;
    }
}

void free_void(Void *v) {
    if (v->type == CHAR_PTR) {
        free(v->value);
    } else if (v->type == CHAR_PTR_PTR) {
        char **arr = (char **)v->value;
        for (size_t i = 0; arr[i]; i++) {
            free(arr[i]);
        }
        free(arr);
    } else {
        free(v->value);
    }
    v->value = NULL;
}

void add_void(Void *result, Void *v1, Void *v2) {
    if (v1->type != v2->type) return; // Types must match for this example
    result->type = v1->type;
    switch (v1->type) {
        case INT:
            {
                int sum = *(int *)v1->value + *(int *)v2->value;
                init_void(result, &sum, INT);
            }
            break;
        case FLOAT:
            {
                float sum = *(float *)v1->value + *(float *)v2->value;
                init_void(result, &sum, FLOAT);
            }
            break;
        case SHORT:
            {
                short sum = *(short *)v1->value + *(short *)v2->value;
                init_void(result, &sum, SHORT);
            }
            break;
        // Add more cases as needed
        default:
            break;
    }
}
