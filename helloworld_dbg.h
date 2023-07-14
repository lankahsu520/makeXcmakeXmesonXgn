/***************************************************************************
 * Copyright (C) 2017 - 2020, Lanka Hsu, <lankahsu@gmail.com>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/
#ifndef __HELLOWORLD_DBG_H__
#define __HELLOWORLD_DBG_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif


//******************************************************************************
//** include **
//******************************************************************************


//******************************************************************************
//** define **
//******************************************************************************
extern int dbg_more;


//******************************************************************************
//** function **
//******************************************************************************
#define gettidv1_ex() syscall(__NR_gettid)
#define gettidv2_ex() syscall(SYS_gettid)

#define DBG_TXT_BUSY "Busy!!!"
#define DBG_TXT_ENTER "__________ Enter __________"
#define DBG_TXT_BYE_BYE "Bye-Bye !!!"
#define DBG_TXT_CRC_ERROR "CRC error !!!"
#define DBG_TXT_FOUND "Found !!!"
#define DBG_TXT_GOT "Got !!!"
#define DBG_TXT_LAUNCH_THREAD "Launch a new thread !!!"
#define DBG_TXT_HELLO_WORLD "Hello world !!!"
#define DBG_TXT_LINKED "Linked !!!"
#define DBG_TXT_NO_SUPPORT "No support !!!"
#define DBG_TXT_NON_IMPLEMENT "Non-implement !!!"
#define DBG_TXT_START "Start !!!"
#define DBG_TXT_UTF8_ERROR "UTF-8 error !!!"
#define DBG_TXT_WRONG "Wrong !!!"
#define DBG_TXT_RUN_LOOP "Run loop ..."

//** debug **
#define COLORX_NONE "\033[0m"
#define COLORX_RED "\033[0;32;31m"
#define COLORX_LIGHT_RED "\033[1;31m"
#define COLORX_GREEN "\033[0;32;32m"
#define COLORX_LIGHT_GREEN "\033[1;32m"
#define COLORX_BLUE "\033[0;32;34m"
#define COLORX_LIGHT_BLUE "\033[1;34m"
#define COLORX_DARY_GRAY "\033[1;30m"
#define COLORX_CYAN "\033[0;36m"
#define COLORX_LIGHT_CYAN "\033[1;36m"
#define COLORX_PURPLE "\033[0;35m"
#define COLORX_LIGHT_PURPLE "\033[1;35m"
#define COLORX_BROWN "\033[0;33m"
#define COLORX_YELLOW "\033[1;33m"
#define COLORX_LIGHT_GRAY "\033[0;37m"
#define COLORX_WHITE "\033[1;37m"

#define DBG_LVL_ERROR        0
#define DBG_LVL_WARN         1
#define DBG_LVL_INFO         2
#define DBG_LVL_DEBUG        3
#define DBG_LVL_TRACE        4
#define DBG_LVL_MAX          5

#define DBG_LN_COLOR(color, format, args...) printf(color"[%02ld/%u] %s:%d - "format""COLORX_NONE"\n",  (long) getpid(), (unsigned int)gettidv1_ex(), __FUNCTION__, __LINE__, ## args)
#define DBG_LN_COLOR_0(color, format, args...) printf(color""format""COLORX_NONE"\n", ## args)

#define DBG_LN_R(format,args...) DBG_LN_COLOR(COLORX_RED, format, ## args)
#define DBG_LN_R_0(format,args...) DBG_LN_COLOR_0(COLORX_RED, format, ## args)
#define DBG_LN_LR(format,args...) DBG_LN_COLOR(COLORX_LIGHT_RED, format, ## args)
#define DBG_LN_LR_0(format,args...) DBG_LN_COLOR_0(COLORX_LIGHT_RED, format, ## args)
#define DBG_LN_G(format,args...) DBG_LN_COLOR(COLORX_GREEN, format, ## args)
#define DBG_LN_G_0(format,args...) DBG_LN_COLOR_0(COLORX_GREEN, format, ## args)
#define DBG_LN_LG(format,args...) DBG_LN_COLOR(COLORX_LIGHT_GREEN, format, ## args)
#define DBG_LN_LG_0(format,args...) DBG_LN_COLOR_0(COLORX_LIGHT_GREEN, format, ## args)
#define DBG_LN_B(format,args...) DBG_LN_COLOR(COLORX_BLUE, format, , ## args)
#define DBG_LN_B_0(format,args...) DBG_LN_COLOR_0(COLORX_BLUE, format, ## args)
#define DBG_LN_LB(format,args...) DBG_LN_COLOR(COLORX_LIGHT_BLUE, format, ## args)
#define DBG_LN_LB_0(format,args...) DBG_LN_COLOR_0(COLORX_LIGHT_BLUE, format, ## args)
#define DBG_LN_DGR(format,args...) DBG_LN_COLOR(COLORX_DARY_GRAY, format, ## args)
#define DBG_LN_C(format,args...) DBG_LN_COLOR(COLORX_CYAN, format, ## args)
#define DBG_LN_C_0(format,args...) DBG_LN_COLOR_0(COLORX_CYAN, format, ## args)
#define DBG_LN_LC(format,args...) DBG_LN_COLOR(COLORX_LIGHT_CYAN, format, ## args)
#define DBG_LN_LC_0(format,args...) DBG_LN_COLOR_0(COLORX_LIGHT_CYAN, format, ## args)
#define DBG_LN_P(format,args...) DBG_LN_COLOR(COLORX_PURPLE, format, ## args)
#define DBG_LN_P_0(format,args...) DBG_LN_COLOR_0(COLORX_PURPLE, format, ## args)
#define DBG_LN_LP(format,args...) DBG_LN_COLOR(COLORX_LIGHT_PURPLE, format, ## args)
#define DBG_LN_LP_0(format,args...) DBG_LN_COLOR_0(COLORX_PURPLE, format, ## args)
#define DBG_LN_BR(format,args...) DBG_LN_COLOR(COLORX_BROWN, format, ## args)
#define DBG_LN_Y(format,args...) DBG_LN_COLOR(COLORX_YELLOW, format, ## args)
#define DBG_LN_Y_0(format,args...) DBG_LN_COLOR_0(COLORX_YELLOW, format, ## args)
#define DBG_LN_LGR(format,args...) DBG_LN_COLOR(COLORX_LIGHT_GRAY, format, ## args)
#define DBG_LN_LGR_0(format,args...) DBG_LN_COLOR_0(COLORX_LIGHT_GRAY, format, ## args)
#define DBG_LN_W(format,args...) DBG_LN_COLOR(COLORX_WHITE, format, ## args)
#define DBG_LN_W_0(format,args...) DBG_LN_COLOR_0(COLORX_WHITE, format, ## args)

#define BUFF_DUMP_BUFF(ibuf, ilen, delim, prefix, obuf, olen) \
	({ int __ret = 0; \
		do { \
			if ( (pcheck(ibuf)) && (pcheck(obuf)) ) \
			{ \
				int k =0; \
				for (k = 0; (k < ilen) && (__ret <(olen-4) ) ; k++) \
				{ \
					if (k>0) __ret += snprintf(obuf + __ret, olen-__ret, delim""prefix"%02X", (0xff & (char)ibuf[k]) ); \
					else __ret += snprintf(obuf + __ret, olen-__ret, prefix"%02X", (0xff & (char)ibuf[k]) ); \
				} \
			} \
		} while(0); \
		__ret; \
	})

#define BUFF_DUMP_FP(fp, ibuf, ilen) \
	{ int k =0; \
		for (k = 0; k < ilen; k++) \
		{ \
			fprintf(fp,"%02X", ibuf[k]); \
		} \
	}

#define DBG_DUMP_COLOR(color, ibuf, ilen, delim, format, args...) \
	{ int k =0; \
		char* dbuf = (char* )ibuf; \
		printf(color"[%02ld/%u] %s:%d - "format" {", (long) getpid(), (unsigned int)gettidv1_ex(),  __FUNCTION__, __LINE__, ## args); \
		for (k=0; k<ilen; k++) \
		{ \
			if ((k%16) ==0) printf("\n    %02X", (0xff & (char)dbuf[k]) ); \
			else printf(delim"%02X", (0xff & (char)dbuf[k]) ); \
		} \
			printf("\n}\n"COLOR_NONE); \
	}

#define DBG_ER_LN(format,args...) if (dbg_more>=DBG_LVL_ERROR) DBG_LN_R(format, ## args)
#define DBG_ER_LN_0(format,args...) if (dbg_more>=DBG_LVL_ERROR) DBG_LN_R_0(format, ## args)
#define DBG_WN_LN(format,args...) if (dbg_more>=DBG_LVL_WARN) DBG_LN_P(format, ## args)
#define DBG_WN_LN_0(format,args...) if (dbg_more>=DBG_LVL_WARN) DBG_LN_P_0(format, ## args)
#define DBG_IF_LN(format,args...) if (dbg_more>=DBG_LVL_INFO) DBG_LN_Y(format, ## args)
#define DBG_IF_LN_0(format,args...) if (dbg_more>=DBG_LVL_INFO) DBG_LN_Y_0(format, ## args)
#define DBG_IF_LN_G(format,args...) if (dbg_more>=DBG_LVL_INFO) DBG_LN_LG(format, ## args)
#define DBG_DB_LN(format,args...) if (dbg_more>=DBG_LVL_DEBUG) DBG_LN_W(format, ## args)
#define DBG_DB_LN_0(format,args...) if (dbg_more>=DBG_LVL_DEBUG) DBG_LN_W_0(format, ## args)
#define DBG_TR_LN(format,args...) if (dbg_more>=DBG_LVL_TRACE) DBG_LN_LGR(format, ## args)
#define DBG_TR_LN_0(format,args...) if (dbg_more>=DBG_LVL_TRACE) DBG_LN_LGR_0(format, ## args)

int dbg_lvl_round(void);
int dbg_lvl_set(int lvl);
int dbg_lvl_get(void);

#ifdef __cplusplus
}
#endif

#endif
