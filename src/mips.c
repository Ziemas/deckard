#include "apu.h"
#include "types.h"
#include "utils.h"

uint32 unk[0x40][2];

void
reset_apu_regs()
{
	/* Bugged originally, bad loop count and missing return */
	for (int i = 0; i < 64; i++) {
		apu_set_reg(0x40 + i, 0);
	}
}

void
reset_apu_gp()
{
	for (int i = 0; i < 32; i++) {
		apu_mtgp(i, 0);
	}
}

void
unk_gte(uint32 insn)
{
	uint32 status;

	while (1) {
		do {
			status = apu_mfgte(GTE_REG_STATUS);
		} while (status & 7);

		if ((status & 0x1ffff0) == 0) {
			apu_mtgte(GTE_REG_INSN, insn);
			return;
		}

		if ((status & 0x10) == 0) {
			return;
		}

		status = apu_mfgte(GTE_REG_INSN);
		if (unk[status & 0x3f][1] == 0) {
			break;
		}

		apu_mtgte(GTE_REG_STATUS, 0x10);
		insn = 0x80; // ???
		apu_mtgte(GTE_REG_INSN,
			(status & ~unk[status & 0x3f][1]) | unk[status & 0x3f][0]);
	}
}

int
mips_run()
{
	struct exec_result res;
	uint32 pc = apu_mfpc();
	uint32 *insn = (uint32 *)pc;

	do {
		res = apu_exec(*insn);
		insn++;
	} while (res.flags & 8);

	return 0;
}
