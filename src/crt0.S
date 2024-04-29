    #include "macro.s"

    .globl _start
_start:
    lis %r4, vectors@ha
    mtivpr %r4

    li %r3, vec_crit@l
    mtivor0 %r3

    li %r3, vec_machine@l
    mtivor1 %r3

    li %r3, vec_data_stor@l
    mtivor2 %r3

    li %r3, vec_insn_stor@l
    mtivor3 %r3

    li %r3, vec_ext@l
    mtivor4 %r3

    li %r3, vec_align@l
    mtivor5 %r3

    li %r3, vec_program@l
    mtivor6 %r3

    li %r3, vec_fpu@l
    mtivor7 %r3

    li %r3, vec_syscall@l
    mtivor8 %r3

    li %r3, vec_apu@l
    mtivor9 %r3

    li %r3, vec_decr@l
    mtivor10 %r3

    li %r3, vec_fit@l
    mtivor11 %r3

    li %r3, vec_watchdog@l
    mtivor12 %r3

    li %r3, vec_data_tlb@l
    mtivor13 %r3

    li %r3, vec_insn_tlb@l
    mtivor14 %r3

    li %r3, vec_debug@l
    mtivor15 %r3

    li %r3, 0
    mtspr 0x30, %r3
    mtsprg0 %r3
    mtsprg1 %r3
    mtsprg2 %r3
    mtsprg3 %r3
    mtsprg4 %r3
    mtsprg5 %r3
    mtsprg6 %r3
    mtsprg7 %r3

    laddr %r1, kernel_stack
    /* Kernel stack size */
    addi %r1, %r1, 0x800

    laddr %r0, deckard_main
    mtlr %r0
    blr
