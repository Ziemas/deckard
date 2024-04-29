#ifndef APU_H_
#define APU_H_

#include "types.h"

/* MIPS OP number as returned by APU */
enum {
	MIPS_OP_special = 0x0,
	MIPS_OP_bcondz = 0x4,
	MIPS_OP_j = 0x8,
	MIPS_OP_jal = 0xC,
	MIPS_OP_beq = 0x10,
	MIPS_OP_bne = 0x14,
	MIPS_OP_blez = 0x18,
	MIPS_OP_bgtz = 0x1C,
	MIPS_OP_addi = 0x20,
	MIPS_OP_addiu = 0x24,
	MIPS_OP_slti = 0x28,
	MIPS_OP_sltiu = 0x2C,
	MIPS_OP_andi = 0x30,
	MIPS_OP_ori = 0x34,
	MIPS_OP_xori = 0x38,
	MIPS_OP_lui = 0x3C,
	MIPS_OP_COP0 = 0x40,
	MIPS_OP_COP1 = 0x44,
	MIPS_OP_COP2 = 0x48,
	MIPS_OP_COP3 = 0x4C,
	MIPS_OP_lb = 0x80,
	MIPS_OP_lh = 0x84,
	MIPS_OP_lwl = 0x88,
	MIPS_OP_lw = 0x8C,
	MIPS_OP_lbu = 0x90,
	MIPS_OP_lhu = 0x94,
	MIPS_OP_lwr = 0x98,
	MIPS_OP_sb = 0xA0,
	MIPS_OP_sh = 0xA4,
	MIPS_OP_swl = 0xA8,
	MIPS_OP_sw = 0xAC,
	MIPS_OP_swr = 0xB8,
	MIPS_OP_LWC0 = 0xC0,
	MIPS_OP_LWC1 = 0xC4,
	MIPS_OP_LWC2 = 0xC8,
	MIPS_OP_LWC3 = 0xCC,
	MIPS_OP_SWC0 = 0xE0,
	MIPS_OP_SWC1 = 0xE4,
	MIPS_OP_SWC2 = 0xE8,
	MIPS_OP_SWC3 = 0xEC,
	MIPS_OP_sll = 0x100,
	MIPS_OP_srl = 0x108,
	MIPS_OP_sra = 0x10C,
	MIPS_OP_sllv = 0x110,
	MIPS_OP_srlv = 0x118,
	MIPS_OP_srav = 0x11C,
	MIPS_OP_jr = 0x120,
	MIPS_OP_jalr = 0x124,
	MIPS_OP_syscall = 0x130,
	MIPS_OP_break = 0x134,
	MIPS_OP_mfhi = 0x140,
	MIPS_OP_mthi = 0x144,
	MIPS_OP_mflo = 0x148,
	MIPS_OP_mtlo = 0x14C,
	MIPS_OP_mult = 0x160,
	MIPS_OP_multu = 0x164,
	MIPS_OP_div = 0x168,
	MIPS_OP_divu = 0x16C,
	MIPS_OP_add = 0x180,
	MIPS_OP_addu = 0x184,
	MIPS_OP_sub = 0x188,
	MIPS_OP_subu = 0x18C,
	MIPS_OP_and = 0x190,
	MIPS_OP_or = 0x194,
	MIPS_OP_xor = 0x198,
	MIPS_OP_nor = 0x19C,
	MIPS_OP_slt = 0x1A8,
	MIPS_OP_sltu = 0x1AC,
	MIPS_OP_mfc0 = 0x280,
	MIPS_OP_mtc0 = 0x290,
	MIPS_OP_rfe = 0x2C0,
};

enum {
	APU_REG_SATUS = 0x4,
	APU_REG_LUT_CODE = 0x6,

	APU_REG_OP_RD = 0x7,
	APU_REG_OP_CODE = 0x8,
	APU_REG_OP_RS = 0x9,
	APU_REG_OP_RT = 0xA,
	APU_REG_OP_RD2 = 0xB,
	APU_REG_OP_IMM = 0xC,
	APU_REG_OP_TARGET = 0xD,
	APU_REG_OP_FUNCT = 0xE,
	APU_REG_OP_SA = 0xF,

	APU_REG_CYCLES = 0x13,

	/* mips */
	APU_REG_HI = 0x18,
	APU_REG_LO = 0x19,
	APU_REG_PC = 0x1A,
	/* COP0 */
	APU_REG_DCIC = 0x1B,
	APU_REG_BPC = 0x1C,
	APU_REG_BPCM = 0x1D,
	APU_REG_BDA = 0x1E,
	APU_REG_BDAM = 0x1F,
};

enum {
	GTE_REG_INSN = 0x80,
	GTE_REG_STATUS = 0x81,
	GTE_REG_CYCLE = 0x82,
};

struct exec_result {
	u32 address;
	u8 flags;
};

static inline struct exec_result
apu_exec(u32 insn)
{
	struct exec_result res;

	/* we need the flags from 24:27 */
	__asm__ volatile("aexec %0, %2 \n"
					 "mfcr %1 \n"
					 : "=&r"(res.address), "=&r"(res.flags)
					 : "r"(insn));

	res.flags = (res.flags >> 4) & 0xf;
	return res;
}

// static inline struct exec_result
// apu_exec(u32 insn)
//{
//     struct exec_result res;
//     u32 temp;
//
//     /* we need the flags from 24:27 */
//     __asm__ volatile("aexec %0, %3 \n"
//                      "mfcr %2 \n"
//                      "extrwi %1, %2, 4, 24 \n"
//                      : "=&r"(res.address), "=&r"(res.flags), "=&r"(temp)
//                      : "r"(insn));
//
//     return res;
// }

static inline u32
apu_get_reg(u32 reg)
{
	u32 data;

	__asm__ volatile("mtdcr 0x180, %1 \n"
					 "mfdcr %0, 0x181 \n"
					 : "=&r"(data)
					 : "r"(reg));

	return data;
}

static inline void
apu_set_reg(u32 reg, u32 val)
{
	__asm__ volatile("mtdcr 0x180, %0 \n"
					 "mtdcr 0x181, %1 \n"
					 :
					 : "r"(reg), "r"(val));
}

static inline u32
apu_get_gte(u32 reg)
{
	u32 data;

	__asm__ volatile("mtdcr 0x21, %1 \n"
					 "mfdcr %0, 0x22 \n"
					 : "=&r"(data)
					 : "r"(reg));

	return data;
}

static inline void
apu_set_gte(u32 reg, u32 val)
{
	__asm__ volatile("mtdcr 0x21, %0 \n"
					 "mtdcr 0x22, %1 \n"
					 :
					 : "r"(reg), "r"(val));
}

static inline u32
apu_mfgp(u32 gpr)
{
	u32 res;
	__asm__ volatile("amfgp %0, %1 \n" : "=&r"(res) : "r"(gpr) :);
	return res;
}

static inline void
apu_mtgp(u32 gpr, u32 value)
{
	__asm__ volatile("amtgp %0, %1 \n" : : "r"(gpr), "r"(value) :);
}

static inline u32
apu_mfgte(u32 reg)
{
	u32 res;
	__asm__ volatile("amfgte %0, %1 \n" : "=&r"(res) : "r"(reg) :);
	return res;
}

static inline void
apu_mtgte(u32 reg, u32 value)
{
	__asm__ volatile("amtgte %0, %1 \n" : : "r"(reg), "r"(value) :);
}

static inline u32
apu_mfhi()
{
	u32 res;
	__asm__ volatile("amfhi %0 \n" : "=&r"(res) : :);
	return res;
}

static inline void
apu_mthi(u32 value)
{
	__asm__ volatile("amthi %0 \n" : : "r"(value) :);
}

static inline u32
apu_mflo()
{
	u32 res;
	__asm__ volatile("amflo %0 \n" : "=&r"(res) : :);
	return res;
}

static inline void
apu_mtlo(u32 value)
{
	__asm__ volatile("amtlo %0 \n" : : "r"(value) :);
}

static inline u32
apu_mfpc()
{
	u32 res;
	__asm__ volatile("amfpc %0 \n" : "=&r"(res) : :);
	return res;
}

static inline void
apu_mtpc(u32 value)
{
	__asm__ volatile("amtpc %0 \n" : : "r"(value) :);
}

static inline u32
apu_mfcc()
{
	u32 res;
	__asm__ volatile("amfcc %0 \n" : "=&r"(res) : :);
	return res;
}

static inline void
apu_mtcc(u32 value)
{
	__asm__ volatile("amtcc %0 \n" : : "r"(value) :);
}

#endif // APU_H_
