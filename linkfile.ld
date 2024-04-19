/* "Bare" static ELF */

MEMORY
{
	vec (rx) : org = 0x00a00000, len = 8k + 0x100
	ram (wx) : org = 0x00a02100, len = 1m
}

ENTRY(_start);

SECTIONS {
	.vec 0x00a00100: { *(.vec.critcal) } > vec
	.vec 0x00a00200: { *(.vec.machine) } > vec
	.vec 0x00a00300: { *(.vec.data_stor) } > vec
	.vec 0x00a00400: { *(.vec.insn_stor) } > vec
	.vec 0x00a00500: { *(.vec.ext_int) } > vec
	.vec 0x00a00600: { *(.vec.align) } > vec
	.vec 0x00a00700: { *(.vec.program) } > vec
	.vec 0x00a00800: { *(.vec.fpu) } > vec
	.vec 0x00a00c00: { *(.vec.syscall) } > vec
	.vec 0x00a00f20: { *(.vec.apu) } > vec
	.vec 0x00a01000: { *(.vec.pit) } > vec
	.vec 0x00a01010: { *(.vec.fit) } > vec
	.vec 0x00a01020: { *(.vec.watchdog) } > vec
	.vec 0x00a01100: { *(.vec.data_tlb) } > vec
	.vec 0x00a01200: { *(.vec.insn_tlb) } > vec
	.vec 0x00a02000: { *(.vec.debug) } > vec

	.text : {
		*(.text_entry)
		*(.text)
	} > ram

	.rodata ALIGN(4) : {
		*(.rodata)
	} > ram

	.data ALIGN(4) : {
		*(.data)
	} > ram

	.sdata ALIGN(4) : {
		*(.sdata)
	} > ram

	.sdata2 ALIGN(4) : {
		*(.sdata2)
	} > ram

	.bss ALIGN(4) : {
		_start_bss  = . ;
		*(COMMON)
		*(.bss)
	} >ram

	.sbss ALIGN(4) : {
		*(.sbss)
	} > ram
	_end_bss = . ;

	.comment ALIGN(4) : {
		*(.comment)
	} > ram


	PROVIDE(__stack = 0x00bdf000);
}
