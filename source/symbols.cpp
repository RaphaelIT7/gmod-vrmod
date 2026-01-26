#include "symbols.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

static const Symbol NULL_SIGNATURE = Symbol::FromSignature("");

/*
 * The symbols will have this order:
 * 0 - Linux 32x
 * 1 - Linux 64x
 * 2 - Windows 32x
 * 3 - Windows 64x
 */
namespace Symbols
{
	const std::vector<Symbol> CMatQueuedRenderContext_CallQueuedSym = { // Find "%d calls queued for %d bytes in parameters and overhead, %d bytes"
		NULL_SIGNATURE,
		NULL_SIGNATURE,
		Symbol::FromSignature("\x55\x8B\xEC\xA1****\x83\xEC\x08"), // 55 8B EC A1 ?? ?? ?? ?? 83 EC 08
	};
}