    #include "macro.s"

    .section .vec,"aw",@progbits
    .p2align 4
    .globl vectors
vectors:
    .p2align 4
    .globl vec_crit
vec_crit:
    rfci

    .p2align 4
    .globl vec_machine
vec_machine:
    rfci

    .p2align 4
    .globl vec_data_stor
vec_data_stor:
    rfi

    .p2align 4
    .globl vec_insn_stor
vec_insn_stor:
    rfi

    .p2align 4
    .globl vec_ext
vec_ext:
    rfi

    .p2align 4
    .globl vec_align
vec_align:
    rfi

    .p2align 4
    .globl vec_program
vec_program:
    rfi

    .p2align 4
    .globl vec_fpu
vec_fpu:
    rfi

    .p2align 4
    .globl vec_syscall
vec_syscall:
    rfi

    .p2align 4
    .globl vec_apu
vec_apu:
    rfi

    .p2align 4
    .globl vec_decr
vec_decr:
    rfi

    .p2align 4
    .globl vec_fit
vec_fit:
    rfi

    .p2align 4
    .globl vec_watchdog
vec_watchdog:
    rfci

    .p2align 4
    .globl vec_data_tlb
vec_data_tlb:
    rfi

    .p2align 4
    .globl vec_insn_tlb
vec_insn_tlb:
    rfi

    .p2align 4
    .globl vec_debug
vec_debug:
    rfci
