#Built-in options
#https://mesonbuild.com/Builtin-options.html
#project('helloworld', 'c', version : '0.0.1', default_options : ['b_asneeded=false', 'b_lundef=false'])
project('helloworld', 'c', version : '0.0.1')

VERSION_MAJOR = '0'
VERSION_MINOR = '0'
VERSION_REVISION = '1'
VERSION_FULL = VERSION_MAJOR + '.' + VERSION_MINOR + '.' + VERSION_REVISION


#** ENVIRONMENT **
subdir('meson_public')


#** message **
compiler = meson.get_compiler('c')
if compiler.get_argument_syntax() == 'gcc'
	message('>> gcc !!!')
else
	message('>> Not gcc !!!')
endif

message('>> (project_version: @0@, project_version: @1@)'.format( meson.project_name(), meson.project_version() ))
message('>> (current_source_dir: @0@)'.format( meson.current_source_dir() ))

message('>> (build_machine cpu: @0@, system: @1@, endian: @2@)'.format( build_machine.cpu(), build_machine.system(), build_machine.endian() ))
message('>> (source_root: @0@)'.format( meson.source_root() ))
message('>> (host_machine.system: @0@)'.format( host_machine.system() ))


#** CFLAGS & LDFLAGS **
# I prefer to use CFLAGS_CUSTOMER
COMPILER_ARG = []
COMPILER_ARG += [ '-Wno-unused-value' ]
COMPILER_ARG += [ '-Wno-unused-result' ]
COMPILER_ARG += [ '-Wno-format-truncation' ]
add_project_arguments(COMPILER_ARG, language: 'c')


#** LIBXXX_OBJS **
VERSION = VERSION_FULL#meson.project_version()
LIBNAME = 'helloworld_dbg'
LIBXXX_OBJS = []
LIBXXX_OBJS += [ 'helloworld_dbg.c' ]

#LIBXXX_A = static_library(LIBNAME, LIBXXX_OBJS, c_args: CFLAGS_CUSTOMER, include_directories: INC_DIR_ARY, dependencies: LIB_ARY)
LIBXXX_SO = shared_library(LIBNAME, LIBXXX_OBJS, version: VERSION, c_args: CFLAGS_CUSTOMER, include_directories: INC_DIR_ARY, dependencies: LIB_ARY, install: true, install_dir: INSTALL_LIB_DIR)

LIB_LOCAL = [ ]
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


#** extern **
LIB_GLOBLE += [ LIBXXX_SO ]