
#include "sg_lib.h"
#include "sg_pt.h"
#include "list_device.h"

#include <string.h>

int main(int argc, const char** argv)
{
    const char* sg_lib_v = sg_lib_version();
    Odd_DriverInfo* odds =  get_odd_drivers();

    int fd = -1;

    int intTemp = 0;
    for (intTemp = 0; intTemp < MAX_ODD_LEN; ++intTemp)
    {
        if (strlen(odds[intTemp].path))
        {
            fd = scsi_pt_open_device(odds[intTemp].path, true, 1);
            if (fd)
            {
                break;
            }
        }
    }

    printf("sg_version:[%s]\n", sg_lib_v);
    return 0;
}
