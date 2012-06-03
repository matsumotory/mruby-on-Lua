require "mruby"

file = "./test.mrb"

print(">> mruby file run ./test.mrb")
mruby.run_file(file)
print(">> mruby code run")
mruby.run("puts 'mruby code run on Lua!!'")
mruby.run("['hoge','fuga','foo'].each {|x| p x }")

