#include <dlfcn.h>

extern "C" {

static __attribute__((used)) void* __ptr_sceRtcGetCurrentDebugNetworkTick;
asm(".intel_syntax noprefix\n"
    ".global sceRtcGetCurrentDebugNetworkTick\n"
    ".type sceRtcGetCurrentDebugNetworkTick @function\n"
    "sceRtcGetCurrentDebugNetworkTick:\n"
    "jmp qword ptr [rip + __ptr_sceRtcGetCurrentDebugNetworkTick]\n");

static __attribute__((used)) void* __ptr_sceRtcSetCurrentDebugNetworkTick;
asm(".intel_syntax noprefix\n"
    ".global sceRtcSetCurrentDebugNetworkTick\n"
    ".type sceRtcSetCurrentDebugNetworkTick @function\n"
    "sceRtcSetCurrentDebugNetworkTick:\n"
    "jmp qword ptr [rip + __ptr_sceRtcSetCurrentDebugNetworkTick]\n");

static void* __handle;
static void __attribute__((constructor(104))) __constructor(void) {
  __handle = dlopen("libSceRtc.sprx", RTLD_LAZY);
  if (!__handle) return;
  __ptr_sceRtcGetCurrentDebugNetworkTick =
      dlsym(__handle, "sceRtcGetCurrentDebugNetworkTick");
  __ptr_sceRtcSetCurrentDebugNetworkTick =
      dlsym(__handle, "sceRtcSetCurrentDebugNetworkTick");
}

static void __attribute__((destructor(104))) __destructor(void) {
  if (__handle) dlclose(__handle);
}

}
