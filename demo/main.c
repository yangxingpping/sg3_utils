
#include "sg_lib.h"
#include "list_device.h"

int main(int argc, const char** argv)
{
    const char* sg_lib_v = sg_lib_version();
    get_odd_drivers();
    printf("sg_version:[%s]\n", sg_lib_v);
    return 0;
}
