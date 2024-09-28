#include <sdk.hxx>
#include <cstdint>

class PluginExample
{
public:
    PluginExample();

    ~PluginExample();

    Native_Function_List *RegisterNatives();

    static int native_testFunc(lua_State *L);

    void TickUpdate();

private:
    const Native_Function_List native_list[2] = {
        {"TestFunction", native_testFunc},
        {nullptr, nullptr}};

    uint16_t ticks;
} pluginExample;

extern "C" __attribute__((visibility("default"))) Native_Function_List *RegisterNatives()
{
    return pluginExample.RegisterNatives();
}

extern "C" void update_ticks()
{
    pluginExample.TickUpdate();
}