#include "stub.h"

#define POOLSIZE 2
typedef struct FreeStore
{
    struct FreeStore* next;
}FreeStore;



class MemoryManager
{
public:
    MemoryManager()
    {
        m_freeStoreHead = nullptr;
        expandFreeStore();
    }
    void* allocate(size_t size)
    {
        if(m_freeStoreHead == nullptr)
        {
            expandFreeStore();
        }
        FreeStore* head = m_freeStoreHead;
        m_freeStoreHead = m_freeStoreHead->next;
        return head;
    }

    void deallocate(void* ptr)
    {
        if(ptr != nullptr)
        {
           FreeStore* head = static_cast<FreeStore*>(ptr);
           head->next = m_freeStoreHead;
           m_freeStoreHead = head;
        }
    }
private:
    void expandFreeStore()
    {
        size_t size = (sizeof(int) > sizeof(FreeStore)) ? sizeof(int) : sizeof(FreeStore);
        FreeStore* head = reinterpret_cast<FreeStore*>(malloc(size));
        m_freeStoreHead = head;

          for (int i = 0; i < POOLSIZE; i++) {
            head->next = reinterpret_cast<FreeStore*>(malloc(size));
            head = head->next;
            }
          head->next = nullptr;
    }

    struct FreeStore* m_freeStoreHead;
};


/*
 MemoryManager gMemoryManager; // Memory Manager, global variable

void* operator new (size_t size)
{
    std::cout << "new operator called" << std::endl;
    return gMemoryManager.allocate(size);
}

void* operator new[] (size_t size)
{
    return gMemoryManager.allocate(size);
}

void operator delete (void* pointerToDelete)
  {
  gMemoryManager.deallocate(pointerToDelete);
  }

*/

