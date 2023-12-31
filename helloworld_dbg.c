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
#include "helloworld_dbg.h"

int dbg_more = DBG_LVL_INFO;//DBG_LVL_INFO;

int dbg_lvl_round(void)
{
	dbg_more++;
	dbg_more %= DBG_LVL_MAX;
	return dbg_more;
}

int dbg_lvl_set(int lvl)
{
	dbg_more = lvl;
	dbg_more %= DBG_LVL_MAX;
	return dbg_more;
}

int dbg_lvl_get(void)
{
	return dbg_more;
}

