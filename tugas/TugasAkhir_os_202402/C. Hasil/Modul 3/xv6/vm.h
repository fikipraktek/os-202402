// vm.h
#ifndef VM_H
#define VM_H

#include "param.h"
#include "mmu.h"
#include "memlayout.h"

// deklarasi cowuvm
pde_t* cowuvm(pde_t *pgdir, uint sz);

pte_t* walkpgdir(pde_t *pgdir, const void *va, int alloc);
void decref(char *pa);


#endif
