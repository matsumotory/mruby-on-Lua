* Install

        make

* Example

    ```lua
    require "mruby"
     
    mruby.run([[
     
    def tak(x, y, z)
     
        if y >= x
            z
        else
            tak(tak(x - 1, y, z),tak(y - 1, z, x),tak(z - 1, x, y))
        end
    end
     
    print tak(20, 12, 7)
     
    ]])
    ```

* Test

    ```lua
    require "mruby"
     
    file = "./test.mrb"
     
    print(">> mruby file run ./test.mrb")
    mruby.run_file(file)
     
    print(">> mruby code run")
    mruby.run("puts 'mruby code run on Lua!!'")
    ```

** run

        lua sample.lua
        lua mruby_on.lua

        >> mruby file run ./test.mrb
        mruby file run on Lua!!
        >> mruby code run
        mruby code run on Lua!!
