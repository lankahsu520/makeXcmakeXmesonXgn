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
#include <iostream>

//#define USE_UTILIX9
#ifdef USE_UTILIX9
#include "utilx9.h"
#endif

#define USE_CPP_HELLOWORLD
#ifdef USE_CPP_HELLOWORLD
#include "cppHelloWorld.h"
#endif

//#define USE_CPP_HELLOWORLD_ORG
#ifdef USE_CPP_HELLOWORLD_ORG
#include "cppHelloWorld_org.h"
#endif

//#define USE_CPP_WRAPPER
#ifdef USE_CPP_WRAPPER
#include "cppClass.h"
#endif

using namespace std;

#ifdef USE_UTILIX9
static void *thread_handler(void *user)
{
	ThreadX_t *tidx_req = (ThreadX_t*)user;

	threadx_detach(tidx_req);

	int count = 0;
	DBG_IF_LN("(count: %d)", count++);

	while (threadx_isquit(tidx_req)==0)
	{
		if (threadx_ispause(tidx_req)==0)
		{
			if (count >= 6)
			{
				break;
			}
			DBG_IF_LN("(name: %s, count: %d)", tidx_req->name, count++);
			if ((count % 3) == 0)
			{
				DBG_IF_LN("wait 3 seconds ...");
				threadx_timewait_simple(tidx_req, 3*1000);
				//break;
			}
		}
		else
		{
			threadx_wait_simple(tidx_req);
		}
	}

	threadx_leave(tidx_req);
	DBG_IF_LN(DBG_TXT_BYE_BYE);

	return NULL;
}

void poniter_learning(int x, int *pnum, int &rnum)
{
	DBG_IF_LN("(x: %d %p)", x, &x);

	int &rx = x;
	DBG_IF_LN("(rx: %d %p)", rx, &rx);

	DBG_IF_LN("(pnum: %d %p)", *pnum, pnum);

	DBG_IF_LN("(rnum: %d %p)", rnum, &rnum);

}
#endif

int main(int argc, char** argv)
{
#ifdef USE_CPP_HELLOWORLD
	cppHelloWorld();
#endif
#ifdef USE_CPP_HELLOWORLD_ORG
	cppHelloWorld_org();
#endif
#ifdef USE_CPP_WRAPPER
	Member lanka("lanka", 1);
	lanka.whoAreyou();
#endif

#ifdef USE_UTILIX9
	// call C
	unsigned char payload[] = { 0xFF,0xFE,0x7B,0x22,0x75,0x73,0x65,0x72,0x22,0x3A,0x22,0x6C,0x61,0x6E,0x6B,0x61,0x22,0x7D,0xFF,0xFF };
	unsigned short cksum = buf_cksum((unsigned short *)payload, 20);
	DBG_ER_LN("(cksum: %d)", cksum);
	cksum = buff_crc16((const unsigned char *)payload, 20, 0xFFFF);
	DBG_ER_LN("(cksum: %d)", cksum);

	ThreadX_t tidx_data_A;
	tidx_data_A.thread_cb = thread_handler;
	tidx_data_A.data = (void *)&tidx_data_A;
	threadx_init(&tidx_data_A, (char*)"thread_A");

	{
		int num = 123;
		DBG_IF_LN("(num: %d, &num: %p)", num, &num);
		poniter_learning(num, &num, num);
	}

	while ((threadx_isquit(&tidx_data_A)==0))
	{
		// busy loop
		sleep(1);
	}

	DBG_IF_LN(DBG_TXT_BYE_BYE);
#endif

	return 0;
}