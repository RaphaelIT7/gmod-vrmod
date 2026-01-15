#pragma once

#include "LuaInterface.h"

namespace Util
{
	inline void StartTable(GarrysMod::Lua::ILuaInterface* LUA)
	{
		LUA->CreateTable();
	}

	inline void AddFunc(GarrysMod::Lua::ILuaInterface* LUA, GarrysMod::Lua::CFunc Func, const char* Name)
	{
		LUA->PushString(Name);
		LUA->PushCFunction(Func);
		LUA->RawSet(-3);
	}

	inline void AddValue(GarrysMod::Lua::ILuaInterface* LUA, double value, const char* Name)
	{
		LUA->PushString(Name);
		LUA->PushNumber(value);
		LUA->RawSet(-3);
	}

	inline void FinishTable(GarrysMod::Lua::ILuaInterface* LUA, const char* Name)
	{
		LUA->SetField(GarrysMod::Lua::INDEX_GLOBAL, Name);
	}
}