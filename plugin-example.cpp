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