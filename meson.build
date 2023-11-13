project('helloworld', 'c', version : '0.0.1')
#Built-in options
#https://mesonbuild.com/Builtin-options.html
#project('helloworld', 'c', version : '0.0.1', default_options : ['b_asneeded=false', 'b_lundef=false'])

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