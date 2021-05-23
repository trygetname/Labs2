#pragma once
#include <iostream>

#ifdef _DEBUG   
#ifndef DBG_NEW     
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )  
#define new DBG_NEW  
#endif
#endif  // _DEBUG

void leaksChecker()
{
#if _DEBUG
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	_CrtDumpMemoryLeaks();
#endif
}