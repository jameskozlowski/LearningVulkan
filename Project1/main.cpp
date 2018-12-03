#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#endif

#ifdef _DEBUG
#define MYDEBUG_NEW   new( _NORMAL_BLOCK, __FILE__, __LINE__)
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
//allocations to be of _CLIENT_BLOCK type
#else
#define MYDEBUG_NEW
#endif // _DEBUG

#ifdef _DEBUG
#define new MYDEBUG_NEW
#endif

#include <iostream>
#include <stdexcept>
#include <functional>
#include <cstdlib>

#include "vulkanBase.h"






int main() {
	vulkanBase app;

	//char* b = (char*)malloc(sizeof(char[10]));
	try {
		app.run();
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

#ifdef _DEBUG
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();  
#endif

	return EXIT_SUCCESS;
}