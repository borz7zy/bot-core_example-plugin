#include <sdk.hxx>

class PluginExample
{
public:
    PluginExample()
    {
    }

    ~PluginExample()
    {
    }

    Native_Function_List *RegisterNatives()
    {
        return const_cast<Native_Function_List *>(native_list);
    }

    static int native_testFunc(lua_State *L)
    {
        lua_pushstring(L, "Hello from PluginExample!");
        return 1;
    }

private:
    const Native_Function_List native_list[2] = {
        {"TestFunction", native_testFunc},
        {nullptr, nullptr}};
} pluginExample;

extern "C" __attribute__((visibility("default"))) Native_Function_List *RegisterNatives()
{
    return pluginExample.RegisterNatives();
}