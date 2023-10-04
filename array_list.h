//
// Created by Administrator on 2023-10-04.
//

#ifndef QUIET_PRACTICE_ARRAY_LIST_H
#define QUIET_PRACTICE_ARRAY_LIST_H

#define ARRAY_LIST_MAX_SIZE 32

struct array_list {
    int array[ARRAY_LIST_MAX_SIZE];
    int size;
};

int array_list_init(struct array_list *list);
int array_list_add(struct array_list *list, int value);
int array_list_remove(struct array_list *list, int value);
int array_list_get(struct array_list *list, int index, int *value);

#define array_list_foreach(list, value) \
    for (int i = 0; i < (list)->size && (value = (list)->array[i], 1); i++)

#endif //QUIET_PRACTICE_ARRAY_LIST_H
