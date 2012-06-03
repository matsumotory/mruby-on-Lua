#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#include "mruby.h"
#include "mruby/proc.h"
#include "mruby/compile.h"

static int l_mruby_code(lua_State *L)
{
    int ret, n;
    mrb_state *mrb;
    struct mrb_parser_state* p;
    const char *mrb_code;

    mrb = mrb_open();

    mrb_code = lua_tostring(L, 1);

    p = mrb_parse_string(mrb, mrb_code);
    n = mrb_generate_code(mrb, p->tree);

    mrb_run(mrb, mrb_proc_new(mrb, mrb->irep[n]), mrb_nil_value());

    ret =  n > 0 ? 0 : 1;
    lua_pushnumber(L, ret);

    mrb_close(mrb);

    return 1;
}

static int l_mruby_file(lua_State *L)
{
    int ret, n;
    mrb_state *mrb;
    FILE *mrb_file;
    struct mrb_parser_state* p;
    const char *mruby_code_file;

    mrb = mrb_open();

    mruby_code_file = lua_tostring(L, 1);

    if ((mrb_file = fopen(mruby_code_file, "r")) == NULL)
        return -1;

    p = mrb_parse_file(mrb, mrb_file);
    n = mrb_generate_code(mrb, p->tree);

    mrb_run(mrb, mrb_proc_new(mrb, mrb->irep[n]), mrb_nil_value());

    ret =  n > 0 ? 0 : 1;
    lua_pushnumber(L, ret);

    mrb_close(mrb);

    return 1;
}

static const struct luaL_reg mrubylib[] = {
    {"run_file", l_mruby_file},
    {"run", l_mruby_code},
    {NULL, NULL},
};

int luaopen_mruby(lua_State *L)
{
    luaL_register (L, "mruby", mrubylib);
    return 1;
}
