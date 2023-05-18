/*
  Output:
  Singleton Instance: 0x407030
  Singleton Instance: 0x407030
*/

#include "Singleton.h"

int main() {
  Singleton* pSingleton;
  pSingleton -> getInstance() -> print();

  Singleton* cSingleton;
  cSingleton -> getInstance() -> print();
  
  return 0;
}
