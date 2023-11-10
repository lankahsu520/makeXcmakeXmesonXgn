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

// a simple cpp
// include here, we don't need to extern "C" in cpp
#include "cppHelloWorld.h"

#ifdef __cplusplus
//extern "C" {
#endif
// include a area or one function
// extern "C" int cppHelloWorld(void)

using namespace std;

int cppHelloWorld(void)
{
	int ret = 0;

	std::cout << "[cppHelloWorld] Hello world - CPP !!!\n";

	return ret;
}

int main(int argc, char** argv)
{
	cppHelloWorld();
}
#ifdef __cplusplus
//}
#endif