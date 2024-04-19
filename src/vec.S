    .section .vec.critical,"aw",@progbits
critical_vector:
    rfci

    .section .vec.machine,"aw",@progbits
machine_vector:
    rfci

    .section .vec.data_stor,"aw",@progbits
data_stor_vector:
    rfi

    .section .vec.insn_stor,"aw",@progbits
insn_stor_vector:
    rfi

    .section .vec.ext_int,"aw",@progbits
ext_int_vector:
    rfi

    .section .vec.align,"aw",@progbits
align_vector:
    rfi

    .section .vec.program,"aw",@progbits
program_vector:
    rfi

    .section .vec.fpu,"aw",@progbits
fpu_unavail_vector:
    rfi

    .section .vec.syscall,"aw",@progbits
syscall_vector:
    rfi

    .section .vec.apu,"aw",@progbits
apu_unavail_vector:
    rfi

    .section .vec.pit,"aw",@progbits
pit_vector:
    rfi

    .section .vec.fit,"aw",@progbits
fit_vector:
    rfi

    .section .vec.watchdog,"aw",@progbits
watchdog_vector:
    rfci

    .section .vec.data_tlb,"aw",@progbits
data_tlb_vector:
    rfi

    .section .vec.insn_tlb,"aw",@progbits
insn_tlb_vector:
    rfi

    .section .vec.debug,"aw",@progbits
debug_vector:
    rfci
