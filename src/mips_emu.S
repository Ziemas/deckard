    #include "macro.s"

    /* Mips emulator using hardware APU hardware assistance*/
    /* Fixed registers: */
    /* R22 - opcode table */

    .data
ppc_stack_save: .word 0
unk1:           .word 0

    .text
    .globl mips_run_a
mips_run_a:
    mflr    %r0
    mfcr    %r12
    // allocate 64 bytes of stack space
    stwu    %r1, -64(%r1)
    stw     %r0, 68(%r1)
    stw     %r12, 4(%r1)
    // save r20 - r31
    stmw    %r20, 8(%r1)
    xor     %r3, %r3, %r3
    laddr   %r22, opcode_table
    mtcr    %r3 // clear cr
    laddr   %r4, ppc_stack_save
    stw     %r1, 0(%r4)
    laddr   %r3, unk1
    lwz     %r3, 0(%r3)



    nop
logic_insn:
    b_logic logic_insn
    blr

    .data
opcode_table:
    .space 4*200
