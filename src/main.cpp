#include <dlfcn.h>
#include <stdio.h>

int main() {
    void* h = dlopen("libunique_identifier_msgs__rosidl_generator_py.so", RTLD_NOW);
    if (!h) {
        printf("dlopen failed: %s\n", dlerror());
        return 1;
    }
    printf("OK\n");
    dlclose(h);
    return 0;
}
