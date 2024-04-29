/* "Bare" static ELF */

MEMORY
{
	ram (rx) : org = 0x00a00000, len = 1m
	/*ram (rwx) : org = 0x00a02000, len = 1m*/
}

PHDRS
{
	text PT_LOAD;
}

ENTRY(_start);

SECTIONS {
	.vec : { *(.vec) } > ram

	.text : {
		*(.text_entry)
		*(.text)
	} > ram :text

	.rodata ALIGN(4) : {
		*(.rodata)
	} > ram :text

	.data ALIGN(4) : {
		*(.data)
	} > ram :text

	.sdata ALIGN(4) : {
		*(.sdata)
	} > ram :text

	.sdata2 ALIGN(4) : {
		*(.sdata2)
	} > ram :text

	.bss ALIGN(4) : {
		_start_bss  = . ;
		*(COMMON)
		*(.bss)
	} > ram :text

	.sbss ALIGN(4) : {
		*(.sbss)
	} > ram :text
	_end_bss = . ;

	.comment ALIGN(4) : {
		*(.comment)
	} > ram :text

	. = ALIGN(4);
	PROVIDE(UMM_MALLOC_CFG_HEAP_ADDR = .);
	_heap_start = .;
	. = 0x00a00000 + 1m;

	PROVIDE(UMM_MALLOC_CFG_HEAP_SIZE = . - _heap_start);

}
