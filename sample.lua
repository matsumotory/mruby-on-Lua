require "mruby"

file = "./test.mrb"

print(">> mruby file run ./test.mrb")
mruby.run_file(file)
print(">> mruby code run")
mruby.run("print 'mruby code run on Lua!!\n'")

