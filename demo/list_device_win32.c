
#include "list_device.h"

#include <windows.h>
#include <SetupAPI.h>

static Odd_DriverInfo _odds[MAX_ODD_LEN];

Odd_DriverInfo* get_odd_drivers()
{
    memset(_odds, 0, sizeof(_odds));
    HDEVINFO hDevInfo;
    DWORD dwError = 0;
    PSP_INTERFACE_DEVICE_DETAIL_DATA_A pDetail;
    hDevInfo = SetupDiGetClassDevs(&GUID_DEVINTERFACE_CDROM, NULL, NULL, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);
    if (hDevInfo == INVALID_HANDLE_VALUE)
    {
        dwError = GetLastError();
        printf("SetupDiGetClassDevs err[%d]\n", dwError);
        return _odds;
    }
    SP_DEVICE_INTERFACE_DATA deviceInterfaceData;
    deviceInterfaceData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);
    int deviceIndex = 0;
    while (SetupDiEnumDeviceInterfaces(hDevInfo, NULL, &GUID_DEVINTERFACE_CDROM, deviceIndex, &deviceInterfaceData))
    {
        DWORD bufferSize = 0;
        DWORD requiredSize = 0;
        SetupDiGetDeviceInterfaceDetail(hDevInfo, &deviceInterfaceData, NULL, 0, &requiredSize, NULL);
        pDetail = (PSP_INTERFACE_DEVICE_DETAIL_DATA_A) malloc(requiredSize);
        pDetail->cbSize = sizeof(SP_INTERFACE_DEVICE_DETAIL_DATA_A);
        SP_DEVICE_INTERFACE_DETAIL_DATA detailBufferData;
        detailBufferData.cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);
        SetupDiGetDeviceInterfaceDetail(hDevInfo, &deviceInterfaceData, pDetail, requiredSize, &bufferSize, NULL);
        
        
        memcpy(_odds[deviceIndex].path, pDetail->DevicePath, requiredSize);
        free(pDetail);
        pDetail = NULL;
        SetupDiDestroyDeviceInfoList(hDevInfo);
         
        deviceInterfaceData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);
        deviceIndex++;
    }
    SetupDiDestroyDeviceInfoList(hDevInfo);
    return _odds;
}
