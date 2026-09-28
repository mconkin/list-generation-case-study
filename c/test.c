  #include "list.h"

#include <assert.h>
#include <stdio.h>

static void test_push_and_values(void) {
    List list;
    list_init(&list);

    list_push_back(&list, 2);
    list_push_front(&list, 1);
    list_push_back(&list, 3);

    assert(list_len(&list) == 3);

    int values[3];
    size_t count = list_values(&list, values, 3);
    int want[3] = {1, 2, 3};
    assert(count == 3);
    for (size_t i = 0; i < count; i++) {
        assert(values[i] == want[i]);
    }

    list_free(&list);
}

static void test_pop_front_and_reuse(void) {
    List list;
    list_init(&list);
    list_push_back(&list, 1);
    list_push_back(&list, 2);

    int out;
    assert(list_pop_front(&list, &out) && out == 1);
    assert(list_pop_front(&list, &out) && out == 2);
    assert(list_len(&list) == 0);

    list_push_back(&list, 3);
    int values[1];
    size_t count = list_values(&list, values, 1);
    assert(count == 1);
    assert(values[0] == 3);

    list_free(&list);
}

static void test_pop_front_when_empty(void) {
    List list;
    list_init(&list);

    int out = -1;
    assert(!list_pop_front(&list, &out));
    assert(out == -1);

    list_free(&list);
}

int main(void) {
    test_push_and_values();
    test_pop_front_and_reuse();
    test_pop_front_when_empty();

    printf("All tests passed.\n");
    return 0;
}
