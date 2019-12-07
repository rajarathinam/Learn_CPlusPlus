#ifndef TEST_H
#define TEST_H
#include "stub.h"
class Static_Test
{
public:
	static int m_static_test;
};
int Static_Test::m_static_test = 100;
#endif