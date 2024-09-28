#include "plugin-export.hpp"
#include <iostream>

PluginExample::PluginExample()
{
    ticks = 0;
}

PluginExample::~PluginExample()
{
}

Native_Function_List *PluginExample::RegisterNatives()
{
    return const_cast<Native_Function_List *>(native_list);
}

int PluginExample::native_testFunc(lua_State *L)
{
    lua_pushstring(L, "Hello from PluginExample!");
    return 1;
}

void PluginExample::TickUpdate()
{
    ++ticks;
    if (ticks > 1000)
    {
        std::cout << "PluginExample: 1000 ticks left!" << std::endl;
        ticks = 0;
    }
    else
    {
        return;
    }
}