#--------------------------------------------------------------------
#
# Author: Martin Corino
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the R2CORBA LICENSE which is
# included with this program.
#
# Copyright (c) Remedy IT Expertise BV
#--------------------------------------------------------------------

require 'optparse'
require 'lib/assert.rb'
include TestUtil::Assertions

OPTIONS = {
  :use_implement => false,
  :orb_debuglevel => 0,
  :iorfile => 'file://server.ior'
}

ARGV.options do |opts|
    script_name = File.basename($0)
    opts.banner = "Usage: ruby #{script_name} [options]"

    opts.separator ""

    opts.on("--k IORFILE",
            "Set IOR.",
            "Default: 'file://server.ior'") { |v| OPTIONS[:iorfile] = v }
    opts.on("--d LVL",
            "Set ORBDebugLevel value.",
            "Default: 0") { |v| OPTIONS[:orb_debuglevel] = v }
    opts.on("--use-implement",
            "Load IDL through CORBA.implement() instead of precompiled code.",
            "Default: off") { |v| OPTIONS[:use_implement] = v }

    opts.separator ""

    opts.on("-h", "--help",
            "Show this help message.") { puts opts; exit }

    opts.parse!
end

if OPTIONS[:use_implement]
  require 'corba'
  CORBA.implement('supports.idl', OPTIONS)
else
  require 'supportsC'
end

require 'supports_impl'

orb = CORBA.ORB_init(["-ORBDebugLevel", OPTIONS[:orb_debuglevel]], 'myORB')

begin
  # make sure valuetype factory is registered
  BalancedAccount_factory.get_factory(orb)

  obj = orb.string_to_object(OPTIONS[:iorfile])

  assert_not 'Object reference is nil.', CORBA::is_nil(obj)

  account = Account._narrow(obj)

  STDERR.puts "* get start balance"

  balance = account.get_balance();

  balance.print_it()

  account.print_it()

  STDERR.puts "* local deposit"

  balance.deposit(10.5)

  balance.print_it()

  account.print_it()

  STDERR.puts "* remote deposit"

  account.deposit(10.77)

  balance.print_it()

  account.print_it()

  STDERR.puts "* remote withdrawal"

  account.withdraw(3.33)

  balance.print_it()

  account.print_it()

  STDERR.puts "* update balance"

  balance = account.get_balance();

  balance.print_it()

  account.print_it()

  # shutdown Account service

  account.shutdown()

ensure

  orb.destroy()

end
