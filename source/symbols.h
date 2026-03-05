#include <GarrysMod/Symbol.hpp>
#include "Platform.hpp"
#include <vector>

#if defined SYSTEM_WINDOWS
#if defined ARCHITECTURE_X86_64
#define GMCOMMON_CALLING_CONVENTION __fastcall
#else // x86
#define GMCOMMON_CALLING_CONVENTION __thiscall
#endif
#define CALLING_CONVENTION_FASTCALL __fastcall
#else // LInux
#define CALLING_CONVENTION_FASTCALL __attribute__((fastcall))
#define GMCOMMON_CALLING_CONVENTION
#endif

#if ARCHITECTURE_IS_X86_64
#define SIMPLETHREAD_RETURNVALUE long long unsigned
#else
#define SIMPLETHREAD_RETURNVALUE unsigned
#endif

class IMatRenderContext;

/*
 * The symbols will have this order:
 * 0 - Linux 32x
 * 1 - Linux 64x
 * 2 - Windows 32x
 * 3 - Windows 64x
 */
namespace Symbols
{
	using CMatQueuedRenderContext_CallQueued = void (GMCOMMON_CALLING_CONVENTION *)(IMatRenderContext*, bool bTermAfterCall);
	extern const std::vector<Symbol> CMatQueuedRenderContext_CallQueuedSym;
}