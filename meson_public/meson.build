message('>> 01 - meson_public/meson.build')

#********************************************************************************
#** Built-in options **
#********************************************************************************
message('>> (prefix: @0@)'.format( get_option('prefix') ))
message('>> (bindir: @0@)'.format( get_option('bindir') ))
message('>> (datadir: @0@)'.format( get_option('datadir') ))
message('>> (includedir: @0@)'.format( get_option('includedir') ))
message('>> (infodir: @0@)'.format( get_option('infodir') ))
message('>> (libdir: @0@)'.format( get_option('libdir') ))
message('>> (libexecdir: @0@)'.format( get_option('libexecdir') ))
message('>> (localedir: @0@)'.format( get_option('localedir') ))
message('>> (localstatedir: @0@)'.format( get_option('localstatedir') ))
message('>> (mandir: @0@)'.format( get_option('mandir') ))
message('>> (sbindir: @0@)'.format( get_option('sbindir') ))
message('>> (sharedstatedir: @0@)'.format( get_option('sharedstatedir') ))
message('>> (sysconfdir: @0@)'.format( get_option('sysconfdir') ))

#********************************************************************************
#** get_option (meson_options.txt) **
#********************************************************************************
# https://mesonbuild.com/Builtin-options.html
PJ_ROOT = meson.source_root()#get_option('PJ_ROOT')
PJ_REVISION = get_option('PJ_REVISION')
PKG_CONFIG_SYSROOT_DIR = get_option('PKG_CONFIG_SYSROOT_DIR')

#** INSTALL **
#SDK_BIN_DIR = get_option('SDK_BIN_DIR')
#SDK_ETC_DIR = get_option('SDK_ETC_DIR')
SDK_INC_DIR = get_option('SDK_INC_DIR')
#SDK_IOT_DIR = get_option('SDK_IOT_DIR')
SDK_LIB_DIR = get_option('SDK_LIB_DIR')
SDK_ROOT_DIR = get_option('SDK_ROOT_DIR')
#SDK_SBIN_DIR = get_option('SDK_SBIN_DIR')
SDK_USR_PREFIX_DIR = get_option('SDK_USR_PREFIX_DIR')

message('>> (SDK_INC_DIR: @0@)'.format( SDK_INC_DIR ))
message('>> (SDK_LIB_DIR: @0@)'.format( SDK_LIB_DIR ))
message('>> (SDK_ROOT_DIR: @0@)'.format( SDK_ROOT_DIR ))
message('>> (SDK_USR_PREFIX_DIR: @0@)'.format( SDK_USR_PREFIX_DIR ))

INSTALL_IOT_DIR = get_option('PJ_INSTALL_IOT')
INSTALL_IOT_RELATIVE_DIR = get_option('PJ_INSTALL_IOT_RELATIVE')

INSTALL_BIN_DIR = 'bin'
INSTALL_ETC_DIR = 'etc'
INSTALL_INC_DIR = 'include'
INSTALL_LIB_DIR = 'lib'
INSTALL_SBIN_DIR = 'sbin'
INSTALL_MODULES_DIR = INSTALL_IOT_RELATIVE_DIR + '/modules'

message('>> (INSTALL_IOT_DIR: @0@)'.format( INSTALL_IOT_DIR ))

message('>> (INSTALL_BIN_DIR: @0@)'.format( INSTALL_BIN_DIR ))
message('>> (INSTALL_ETC_DIR: @0@)'.format( INSTALL_ETC_DIR ))
message('>> (INSTALL_INC_DIR: @0@)'.format( INSTALL_INC_DIR ))
message('>> (INSTALL_LIB_DIR: @0@)'.format( INSTALL_LIB_DIR ))
message('>> (INSTALL_SBIN_DIR: @0@)'.format( INSTALL_SBIN_DIR ))
message('>> (INSTALL_MODULES_DIR: @0@)'.format( INSTALL_MODULES_DIR ))

#********************************************************************************
#** INC_DIR_ARY **
#********************************************************************************
INC_DIR_ARY = [ './' ]

if ( SDK_INC_DIR != '' ) and ( run_command('[', '-d', SDK_INC_DIR , ']', check : false).returncode() == 0 )
	INC_DIR_ARY += [ SDK_INC_DIR ]
endif

if ( PKG_CONFIG_SYSROOT_DIR != '' ) and ( run_command('[', '-d', PKG_CONFIG_SYSROOT_DIR + '/usr/include' + '/apache2', ']', check : false).returncode() == 0 )
	found_apache2 = 1
	INC_DIR_ARY += [ PKG_CONFIG_SYSROOT_DIR + '/usr/include' + '/apache2' ]
else
	found_apache2 = 0
endif

#********************************************************************************
#** CFLAGS_CUSTOMER **
#********************************************************************************
CFLAGS_CUSTOMER = []
if ( SDK_INC_DIR != '' ) and ( run_command('[', '-f', SDK_INC_DIR + '/customer_def.h', ']', check : false).returncode() == 0 )
	CFLAGS_CUSTOMER += ['-include', SDK_INC_DIR + '/customer_def.h' ]
endif
CFLAGS_CUSTOMER += ['-D_GNU_SOURCE' ]

#********************************************************************************
#** LIB_DIR_ARY **
#********************************************************************************
LIB_DIR_ARY = [ ]
if ( SDK_LIB_DIR != '' ) and ( run_command('[', '-d', SDK_LIB_DIR , ']', check : false).returncode() == 0 )
	LIB_DIR_ARY += [ SDK_LIB_DIR ]
endif

if ( PKG_CONFIG_SYSROOT_DIR != '' ) and ( run_command('[', '-d', PKG_CONFIG_SYSROOT_DIR + '/usr/lib', ']', check : false).returncode() == 0 )
	LIB_DIR_ARY += [ PKG_CONFIG_SYSROOT_DIR + '/usr/lib' ]
endif

#********************************************************************************
#** dependency **
#********************************************************************************
if is_variable('LIB_REQUIRE_FULL')
else
	LIB_REQUIRE_FULL=false
endif

# I prefer to use find_library.
# Some libs don't follow pkgconfig.
cc = meson.get_compiler('c')
LIB_ARY = []

#dependency('curl')
dep_curl = cc.find_library('curl', required : LIB_REQUIRE_FULL)
LIB_ARY += dep_curl

#dependency('z')
dep_z = cc.find_library('z', required : LIB_REQUIRE_FULL)
LIB_ARY += dep_z

#dependency('dl')
dep_dl = cc.find_library('dl', required : true)
LIB_ARY += dep_dl

#dependency('pthread')
dep_pthread = cc.find_library('pthread', required : true)
LIB_ARY += dep_pthread

#dependency('m')
dep_m = cc.find_library('m', required : true)
LIB_ARY += dep_m

#********************************************************************************
#** LIB_GLOBLE (Please put local libs) **
#********************************************************************************
LIB_GLOBLE = []

