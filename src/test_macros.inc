IF !DEF(TEST_MACROS_INC)
TEST_MACROS_INC=1

include "mem_utils.inc"
include "register_utils.inc"
include "print_utils.inc"

SECTION "TEST Macros strings", ROM0
memcmp_failed_str:
  DB "memcmp failed. ", $0
difference_str:
  DB "Difference: ", $0
expected_str:
  DB "Expected: ", $0
actual_str:
  DB "Actual: ", $0

REQUIRE_MEM_EQ : MACRO
  PUSH_HL_BC_DE
    ld hl, \1 ; first
    ld de, \2 ; second
    ld bc, \3 ; size
    call memcmp
  POP_HL_BC_DE
  push af
    cp $0
    jp z, .end\@
    call print_newline
    ld hl, memcmp_failed_str
    call print_hl
    call print_newline
    ld hl, difference_str
    call print_hl
  pop af
  call print_hex_a
  
  IF _NARG >= 4
    PRINT_ADDR \4 ; Address of string
  ENDC
  ld hl, 0
  ret
.end\@:
ENDM

ENDC ; TEST_MACROS_INC