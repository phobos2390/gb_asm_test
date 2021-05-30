IF !DEF(MEMCMP_TEST)
MEMCMP_TEST SET 1

INCLUDE "test_macros.inc"

SECTION "Mem1 sample", ROM0
mem1_start:
DB $1, $2, $3, $5
mem1_end:

SECTION "Mem2 sample", ROM0
mem2_start:
DB $1, $2, $3, $5
mem2_end:

SECTION "Mem3 sample", ROM0
mem3_start:
DB $1, $3, $2, $5
mem3_end:

SECTION "memory equal 1-2", ROM0
mem1_eq_mem2_test:
  REQUIRE_MEM_EQ mem1_start, mem2_start, mem1_end - mem1_start
  ld hl, $1
  ret

SECTION "memory equal 1-3", ROM0
mem1_eq_mem3_test:
  REQUIRE_MEM_EQ mem1_start, mem3_start, mem1_end - mem1_start
  ld hl, $1
  ret

ENDC ; MEMCMP_TEST