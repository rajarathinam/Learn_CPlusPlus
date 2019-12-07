#include <malloc/malloc.h>
#include <assert.h>
#include <stddef.h>
#include <iostream>
using namespace std;

typedef void FDEL(void* p, size_t size);
typedef FDEL* PFDEL;

class A
{
	int a;
	static void sfree(void* p, size_t size);
	static void sfreedebug(void* p, size_t size);
public:
	virtual ~A() {}
	void* operator new(size_t size);
	void operator delete(void* p, size_t size);
	void* operator new(size_t size, int iline, char* szfile); // debug version
};

void A::operator delete(void* p, size_t size)
{
	char* pb = (char*) p;
	pb -= sizeof(PFDEL);
	PFDEL pfdel = *(PFDEL*)pb;
	(*pfdel)(pb, size);
}

void A::sfree(void* p, size_t size)
{
	free(p);
}

void* A::operator new(size_t size)
{
	char* pb = (char*) malloc(size + sizeof(PFDEL));
	*(PFDEL*)pb = &sfree;
	return (pb + sizeof(PFDEL));
}

struct DEBUGHDR
{
	size_t size;
	int iline;
	char* szfile;
	PFDEL pfdel;
};

void A::sfreedebug(void* p, size_t size)
{
	char* pb = (char*) p;
	pb += (sizeof(PFDEL) - sizeof(DEBUGHDR));
	DEBUGHDR* phdr = (DEBUGHDR*) pb;

	assert(size == phdr->size);

	cout << "freeing " << phdr->size 
		<< " bytes allocated at line " << phdr->iline
		<< " in file " << phdr->szfile << "\n";

	free(pb);
}

void* A::operator new(size_t size, int iline, char* szfile)
{
	char* pb = (char*) malloc(size + sizeof(DEBUGHDR));
	DEBUGHDR* phdr = (DEBUGHDR*) pb;
	phdr->size = size;
	phdr->iline = iline;
	phdr->szfile = szfile;
	phdr->pfdel = &sfreedebug;

	cout << "new'ing " << phdr->size 
		<< " bytes allocated at line " << phdr->iline
		<< " in file " << phdr->szfile << "\n";

	return (pb + sizeof(DEBUGHDR));
}

class B : public A
{
	double b;
};

int qqw()
{
	A* pa1 = new A;
	B* pb1 = new B;
	A* pa2 = new(__LINE__, __FILE__) A;
	B* pb2 = new(__LINE__, __FILE__) B;

	delete pa1;
	delete pb1;
	delete pa2;
	delete pb2;

	return 0;
}
