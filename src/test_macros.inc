IF !DEF(TEST_MACROS_INC)
TEST_MACROS_INC SET 1

include "mem_utils.inc"
include "register_utils.inc"

REQUIRE_MEM_EQ : MACRO
  PUSH_HL_BC_DE
    ld hl, \1 ; first
    ld de, \2 ; second
    ld bc, \3 ; size
    call memcmp
  POP_HL_BC_DE
  cp $0
  jp z, .end\@
  ld hl, 0
  ret
.end\@:
ENDM

ENDC ; TEST_MACROS_INC