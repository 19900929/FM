#ifndef TY_APP_DLL_API_H_
#define TY_APP_DLL_API_H_

#include <TYApi.h>

#ifdef _WIN32
# ifdef TY_App_WIN32_BUILD_STATIC
#  define TY_App_DLLIMPORT
#  define TY_App_DLLEXPORT
# else
#  define TY_App_DLLIMPORT      __declspec(dllimport)
#  define TY_App_DLLEXPORT      __declspec(dllexport)
# endif
#else
#  define TY_App_DLLIMPORT      __attribute__((visibility("default")))
#  define TY_App_DLLEXPORT      __attribute__((visibility("default")))
#endif

#ifdef TY_App_BUILD_DLL
#  define TY_App_EXPORT     TY_App_DLLEXPORT
#else
#  define TY_App_EXPORT     TY_App_DLLIMPORT
#endif


//------------------------------------------------------------------------------
//  Definitions
//------------------------------------------------------------------------------
#define TY_App_LIB_VERSION_MAJOR       1
#define TY_App_LIB_VERSION_MINOR       0
#define TY_App_LIB_VERSION_PATCH       0 

#define TY_App_CAPI TY_EXTC TY_App_EXPORT TY_STATUS TY_STDC

// ---------------------------------------------------------------------------------------
#include <Percipio/AppInterface/defines.h>

typedef void (TY_STDC *TYApp_Cb)(const BlockHeader* result, void* user_data);
typedef void (TY_STDC *TYAppEvent_Cb)(int32_t id, const char* msg, void* user_data);

TY_EXTC TY_App_EXPORT void TY_STDC TYAppLastError(TY_STATUS* id, char* buf, int32_t buflen);

TY_App_CAPI TYAppInit(int argc, const char* argv[]);
TY_App_CAPI TYAppDeinit();

TY_App_CAPI TYAppModuleEnable(PropertyID grabModule, TYApp_Cb callback, void* user_data);
TY_App_CAPI TYAppModuleDisable(PropertyID grabModule);

TY_App_CAPI TYAppSetEventCallback(TYAppEvent_Cb callback, void* user_data);
TY_App_CAPI TYAppStart();
TY_App_CAPI TYAppStop();
TY_App_CAPI TYAppCalcOnce();

TY_App_CAPI TYAppReadProperty(PropertyID prop_id, void* buf, int32_t buflen);
TY_App_CAPI TYAppWriteProperty(PropertyID prop_id, void* buf, int32_t buflen);
TY_App_CAPI TYAppWriteCmd(CmdID cmd_id);

#endif
