
#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define     BUF_LEN     256
#define     MAX_ODD_LEN     128

typedef struct 
{
    char path[BUF_LEN];
}Odd_DriverInfo;

#ifdef __cplusplus
extern "C" {
#endif

Odd_DriverInfo* get_odd_drivers();

#ifdef __cplusplus
}
#endif
