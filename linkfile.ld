/* "Bare" static ELF */

MEMORY
{
	vec (rx) : org = 0x00a00000, len = 8k
	ram (wx) : org = 0x00a02000, len = 1m
}

ENTRY(_start);

SECTIONS {
	.vec 0x00a00000: { *(.vec.test) } > vec

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
