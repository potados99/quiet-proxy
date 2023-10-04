//
// Created by Administrator on 2023-10-04.
//

#include "array_list.h"

#include <string.h>

int array_list_init(struct array_list *list) {
    memset(list->array, 0, sizeof(list->array));
    list->size = 0;

    return 0;
}

int array_list_add(struct array_list *list, int value) {
    if (list->size >= ARRAY_LIST_MAX_SIZE) {
        return -1;
    }

    list->array[list->size++] = value;

    return 0;
}

int array_list_remove(struct array_list *list, int value) {
    int index = -1;
    for (int i = 0; i < list->size; i++) {
        if (list->array[i] == value) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        // no items found
        return -1;
    }

    for (int i = index; i < list->size - 1; i++) {
        // so naive...
        list->array[i] = list->array[i + 1];
    }

    return 0;
}

int array_list_get(struct array_list *list, int index, int *value) {
    if (index < 0 || index >= list->size) {
        return -1;
    }

    *value = list->array[index];

    return 0;
}
