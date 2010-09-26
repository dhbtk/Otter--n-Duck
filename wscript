#!/usr/bin/env python
import Options
import os
VERSION = '0.1'
APPNAME = 'otternduck'

top = '.'
out = 'build'

def is_mingw (env):
	if 'CC' in env:
		cc = env['CC']
		if not isinstance (cc, str):
			cc = ''.join (cc)
		return cc.find ('mingw') != -1# or cc.find ('wine') != -1
	return False

def set_options(opt):
	opt.tool_options('compiler_cc')

def configure(conf):
	conf.check_tool('compiler_cc')
	conf.env['LMINGW'] = ''
	conf.env.append_value('CPPPATH','/usr/include/SDL')
	if is_mingw(conf.env):
		if not 'AR' in os.environ and not 'RANLIB' in os.environ:
			conf.env['AR'] = os.environ['CC'][:-3] + 'ar'
		Options.platform = 'win32'
		conf.env['program_PATTERN'] = '%s.exe'
		conf.env.append_value('CCFLAGS','-mms-bitfields')
		conf.env.append_value ('CCFLAGS', '-mwindows')
		conf.env.append_value('CCFLAGS','-DWINDOWS')
		conf.env["LMINGW"] = 'mingw32'
	conf.check_cfg(package='glib-2.0',uselib_store = 'GLIB',mandatory = 1,args = '--cflags --libs')
	conf.check_cfg(path='sdl-config',package='',uselib_store = 'SDL',mandatory = 1,args = '--cflags --libs')
	conf.check(header_name='sdl_mixer.h',mandatory=1)
	conf.check(header_name='sdl_gfx.h',mandatory=1)
	conf.check(header_name='sdl_image.h',mandatory=1)
	conf.check(header_name='sdl_ttf.h',mandatory=1)
	conf.define('VERSION',VERSION)
	conf.env['VERSION'] = VERSION
	conf.write_config_header('config.h')
	conf.env.append_value('VALAFLAGS','-g')
	conf.env.append_value('CCFLAGS','-g')
	conf.env.append_value('LDFLAGS','-g')

def build(bld):
	bld.add_subdirs('src')
