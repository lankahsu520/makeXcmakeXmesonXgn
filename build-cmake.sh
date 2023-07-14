#!/bin/bash

RUN_SH=`basename $0`
HINT="$0 {start|clean|distclean}"

ACTION=$1

#** Toolchain **

#** Setup Environment **
export PJ_ROOT=`pwd`
[ ! -z "$PJ_INSTALL" ] || export PJ_INSTALL="${PJ_ROOT}/install"
[ ! -z "$PJ_CPACK" ] || export PJ_CPACK="${PJ_ROOT}/install_Cpack"
[ ! -z "$SDK_ROOT_DIR" ] || export SDK_ROOT_DIR="${PJ_INSTALL}"
export SDK_USR_PREFIX_DIR="usr"

export CONFIG_CUSTOMER_DEF_H="${PJ_ROOT}/include/customer_def.h"

export CROSS_FILE="${PJ_ROOT}/cmake/build_x86.cmake"

export PJ_BUILD_DIR="build_xxx"
export PJ_BUILD_VERBOSE="-v"
#export PJ_MAKE_VERBOSE="VERBOSE=1"

#export PKG_CONFIG_SYSROOT_DIR="${PJ_INSTALL}"

now_fn()
{
	NOW_t=`date +"%Y%m%d%H%M%S"`
	return $NOW_t
}

datetime_fn()
{
	PROMPT=$1

	if [ "${PROMPT}" = "" ]; then
		echo
	else
		now_fn
		DO_COMMAND_NOW="echo \"$NOW_t ${RUN_SH}|${PROMPT}\" $TEE_ARG"; sh -c "$DO_COMMAND_NOW"
	fi

	return 0
}

do_command_fn()
{
	FUNCX=$1
	LINEX=$2
	DO_COMMAND=$3
	datetime_fn "${FUNCX}:${LINEX}- [$DO_COMMAND]"
	sh -c "$DO_COMMAND"
}

do_env_fn()
{
	. confs/simple.conf >/dev/null 2>&1
	return 0
}

die_fn()
{
	datetime_fn "$@"; datetime_fn ""
	exit 1
}

distclean_install_fn()
{
	while true; do
		echo
		echo "install: ${SDK_ROOT_DIR}"
		echo "Cpack: ${PJ_CPACK}"
		read -p "WARNING! They will be removed [y/N] ? " yn
		case $yn in
			[Yy]* )
				DO_COMMAND="rm -rf ${SDK_ROOT_DIR} ${PJ_CPACK}"
				do_command_fn "${FUNCNAME[0]}" "${LINENO}" "${DO_COMMAND}"
				break
				;;
			[Nn]* )
				break
				;;
			* )
				break
			;;
		esac
	done

	return 0
}

distclean_fn()
{
	datetime_fn "${FUNCNAME[0]}:${LINENO}- ($PID) ..."

	DO_COMMAND="(rm -rf ${PJ_BUILD_DIR})"
	do_command_fn "${FUNCNAME[0]}" "${LINENO}" "${DO_COMMAND}"

	distclean_install_fn

	datetime_fn "${FUNCNAME[0]}:${LINENO}- ($PID) ok."
	return 0
}

cfg_fn()
{
	datetime_fn "${FUNCNAME[0]}:${LINENO}- ($PID) ..."

	#** customer_def.h **

	#** build_xxx **
	DO_COMMAND="(mkdir -p ${PJ_BUILD_DIR})"
	do_command_fn "${FUNCNAME[0]}" "${LINENO}" "${DO_COMMAND}"

	datetime_fn "${FUNCNAME[0]}:${LINENO}- ($PID) ok."
	datetime_fn
	return 0
}

showusage_fn()
{
	#datetime_fn "${FUNCNAME[0]}:${LINENO}- ($PID) ..."
	printf "$HINT"; datetime_fn ""; exit 1

	return 0
}

build_setup_fn()
{
	datetime_fn "${FUNCNAME[0]}:${LINENO}- ($PID) ..."

	#** build setup **
	if [ -d ${PJ_BUILD_DIR} ]; then
		DO_COMMAND="(cd ${PJ_BUILD_DIR}; cmake -DCMAKE_INSTALL_PREFIX=${SDK_ROOT_DIR} -DCMAKE_TOOLCHAIN_FILE=${CROSS_FILE}  ..)"
		do_command_fn "${FUNCNAME[0]}" "${LINENO}" "${DO_COMMAND}"
	fi

	datetime_fn "${FUNCNAME[0]}:${LINENO}- ($PID) ok."
	datetime_fn
}

build_run_fn()
{
	datetime_fn "${FUNCNAME[0]}:${LINENO}- ($PID) ..."

	if [ -d ${PJ_BUILD_DIR} ]; then
		DO_COMMAND="(cd ${PJ_BUILD_DIR}; make ${PJ_MAKE_VERBOSE})"
		do_command_fn "${FUNCNAME[0]}" "${LINENO}" "${DO_COMMAND}"
	fi

	datetime_fn "${FUNCNAME[0]}:${LINENO}- ($PID) ok."
	datetime_fn
}

build_install_fn()
{
	datetime_fn "${FUNCNAME[0]}:${LINENO}- ($PID) ..."

	if [ -d ${PJ_BUILD_DIR} ]; then
		DO_COMMAND="(cd ${PJ_BUILD_DIR}; make install)"
		do_command_fn "${FUNCNAME[0]}" "${LINENO}" "${DO_COMMAND}"
	fi

	datetime_fn "${FUNCNAME[0]}:${LINENO}- ($PID) ok."
	datetime_fn
}

build_clean_fn()
{
	datetime_fn "${FUNCNAME[0]}:${LINENO}- ($PID) ..."

	if [ -d ${PJ_BUILD_DIR} ]; then
		DO_COMMAND="(cd ${PJ_BUILD_DIR}; make clean)"
		do_command_fn "${FUNCNAME[0]}" "${LINENO}" "${DO_COMMAND}"
	fi

	datetime_fn "${FUNCNAME[0]}:${LINENO}- ($PID) ok."
	datetime_fn
}

build_cpack_fn()
{
	datetime_fn "${FUNCNAME[0]}:${LINENO}- ($PID) ..."

	if [ -d ${PJ_BUILD_DIR} ]; then
		DO_COMMAND="(cd ${PJ_BUILD_DIR}; make package)"
		do_command_fn "${FUNCNAME[0]}" "${LINENO}" "${DO_COMMAND}"
	fi

	datetime_fn "${FUNCNAME[0]}:${LINENO}- ($PID) ok."
	datetime_fn
}

start_fn()
{
	datetime_fn "${FUNCNAME[0]}:${LINENO}- ($PID) ..."

	cfg_fn

	build_setup_fn

	build_run_fn

	build_install_fn

	build_cpack_fn
}

main_fn()
{
	do_env_fn

	case $ACTION in
		start)
			start_fn
		;;
		clean)
			build_clean_fn
		;;
		distclean)
			distclean_fn
		;;
		*)
			showusage_fn
		;;
	esac
}

main_fn

exit 0
