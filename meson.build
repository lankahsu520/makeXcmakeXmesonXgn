project('helloworld-123', 'c', version : '0.0.1')
#Built-in options
#https://mesonbuild.com/Builtin-options.html
#project('helloworld', 'c', version : '0.0.1', default_options : ['b_asneeded=false', 'b_lundef=false'])
message('>> 00 - meson.build')

LIB_REQUIRE_FULL=false
subdir('meson_public')

# I prefer to use CFLAGS_CUSTOMER
COMPILER_ARG = []
COMPILER_ARG += [ '-Wno-unused-value' ]
COMPILER_ARG += [ '-Wno-unused-result' ]
COMPILER_ARG += [ '-Wno-format-truncation' ]
add_project_arguments(COMPILER_ARG, language: 'c')

#** LIBXXX_OBJS **
VERSION = meson.project_version()
LIBNAME = 'helloworld_dbg'
LIBXXX_OBJS = []
LIBXXX_OBJS += [ 'helloworld_dbg.c' ]

LIBXXX_A = []
#LIBXXX_A += static_library(LIBNAME, LIBXXX_OBJS, c_args: CFLAGS_CUSTOMER, include_directories: INC_DIR_ARY, dependencies: LIB_ARY)
LIBXXX_SO = []
LIBXXX_SO += shared_library(LIBNAME, LIBXXX_OBJS, version: VERSION, c_args: CFLAGS_CUSTOMER, include_directories: INC_DIR_ARY, dependencies: LIB_ARY, install: true, install_dir: INSTALL_LIB_DIR)

LIB_LOCAL = [ ]
LIB_LOCAL += [ LIBXXX_A ]
LIB_LOCAL += [ LIBXXX_SO ]


#** HEADER_FILES **
HEADER_FILES = []
HEADER_FILES += [ 'helloworld_dbg.h' ]

install_headers(HEADER_FILES, install_dir: INSTALL_INC_DIR)


#** Target (DUMMY_BINS) **
PROJECT_NAME = meson.project_name()

executable(PROJECT_NAME, PROJECT_NAME + '.c', c_args: CFLAGS_CUSTOMER, link_with: LIB_LOCAL, dependencies: LIB_ARY, include_directories: INC_DIR_ARY, install: true, install_dir: INSTALL_BIN_DIR)
executable('pipe2', 'pipe2.c', c_args: CFLAGS_CUSTOMER, link_with: LIB_LOCAL, dependencies: LIB_ARY, install: true, install_dir: INSTALL_BIN_DIR)
executable('helloworld', 'helloworld.c', c_args: CFLAGS_CUSTOMER, link_with: LIB_LOCAL, dependencies: LIB_ARY, install: true, install_dir: INSTALL_BIN_DIR)


#** Target (SHELL_SBINS) **
SHELL_SBINS = []

install_data(SHELL_SBINS, install_dir : INSTALL_SBIN_DIR)


#** Target (CONFS) **
CONFS = []

install_data(CONFS, install_dir : INSTALL_IOT_RELATIVE_DIR)


#** message **
message('>> (project_version: @0@, project_version: @1@, current_source_dir: @2@)'.format( meson.project_name(), meson.project_version(), meson.current_source_dir() ))

message('>> (build_machine cpu: @0@, system: @1@, endian: @2@)'.format( build_machine.cpu(), build_machine.system(), build_machine.endian() ))
message('>> (project_source_root: @0@)'.format( meson.project_source_root() ))
message('>> (host_machine.system: @0@)'.format( host_machine.system() ))

message('>> (libdir: @0@, libdir: @1@, prefix: @2@)'.format( get_option('libdir'), get_option('localstatedir'), get_option('prefix') ))

message('>> (SDK_BIN_DIR: @0@)'.format( get_option('SDK_BIN_DIR')))

compiler = meson.get_compiler('c')
if compiler.get_argument_syntax() == 'gcc'
	message('>> gcc !!!')
else
	message('>> Not gcc !!!')
endif

message('>> (COMPILER_ARG: @0@)'.format( COMPILER_ARG ))
message('>> (COMPILER_ARG: @0@)'.format( COMPILER_ARG ))
message('>> (INC_DIR_ARY: @0@)'.format( INC_DIR_ARY ))
message('>> (CFLAGS_CUSTOMER: @0@)'.format( CFLAGS_CUSTOMER ))
message('>> (CFLAGS_CUSTOMER: @0@)'.format( CFLAGS_CUSTOMER ))

#** extern **
LIB_GLOBLE += [ LIBXXX_SO ]

pkg = import('pkgconfig')
zdep = dependency('zlib', version : '>=1.2.8')
#zdep = dependency('zlib', method : 'pkg-config')
#zdep = dependency('zlib', method : 'config-tool')
#zdep = dependency('zlib', version : '>=1.2.8', fallback: ['zlib', 'libz_dep'])
glib_deps = dependency('glib-2.0')
#gio_dep = dependency('gio-2.0', fallback: ['glib', 'libgio_dep'])

#zdep = dependency('ZLIB', method : 'cmake', modules : ['ZLIB::ZLIB'])
#glib_deps = dependency('glib-2.0', version : '>= 2.44.0', fallback: ['glib', 'libglib_dep'])
#glib_deps = dependency('glib-2.0', version : '>= 2.44.0')
#zdep_prefix = zdep.get_pkgconfig_variable('prefix')

#message('>> (zdep: @0@)'.format( zdep_prefix ))
if zdep.found()
   message('>>>>>>>>>>>>>>> zdep.name():', zdep.name())
   #message('>>>>>>>>>>>>>>> zdep.get_variable():', zdep.get_variable('Libs'))
   message('>>>>>>>>>>>>>>> zdep.include_type():', zdep.include_type())
   #message('>>>>>>>>>>>>>>> zdep.partial_dependency():', zdep.partial_dependency())
   message('>>>>>>>>>>>>>>> zdep.type_name():', zdep.type_name())
   message('>>>>>>>>>>>>>>> zdep.version():', zdep.version())
endif
#message('>> (zdep: @0@)'.format( zdep ))
#message('>> (glib_deps: @0@)'.format( glib_deps ))
#message('>> (glib_deps: @0@)'.format( glib_deps ))
#message('>> (glib_deps: @0@)'.format( glib_deps ))
