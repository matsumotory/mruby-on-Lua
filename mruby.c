#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#include "mruby.h"
#include "mruby/proc.h"
#include "mruby/compile.h"

static int l_mruby(lua_State *L)
{
    int ret, n;
    FILE *mrb_file;
    struct mrb_parser_state* p;

    mrb_state *mrb = mrb_open();

    const char *mruby_code_file = lua_tostring(L, 1);

    if ((mrb_file = fopen(mruby_code_file, "r")) == NULL)
        return -1;

    p = mrb_parse_file(mrb, mrb_file);
    n = mrb_generate_code(mrb, p->tree);

    mrb_run(mrb, mrb_proc_new(mrb, mrb->irep[n]), mrb_nil_value());
    ret =  n > 0 ? 0 : 1;
    lua_pushnumber(L, ret);

    return 1;
}

static const struct luaL_reg mrubylib[] = {
    {"exec", l_mruby},
    {NULL, NULL},
};

int luaopen_mruby(lua_State *L)
{
    luaL_register (L, "mruby", mrubylib);
    return 1;
}
