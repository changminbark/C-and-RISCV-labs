	.file	"c_mystery.c"
	.option nopic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_zicsr2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.globl	unused
	.section	.sdata,"aw"
	.align	2
	.type	unused, @object
	.size	unused, 4
unused:
	.word	-17973521
	.globl	x
	.align	2
	.type	x, @object
	.size	x, 4
x:
	.word	89
	.section	.rodata
	.align	3
.LC0:
	.string	"%d\n"
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	addi	sp,sp,-32
	.cfi_def_cfa_offset 32
	sd	ra,24(sp)
	sd	s0,16(sp)
	.cfi_offset 1, -8
	.cfi_offset 8, -16
	addi	s0,sp,32
	.cfi_def_cfa 8, 0
	lui	a5,%hi(x)
	sw	zero,%lo(x)(a5)
	sw	zero,-20(s0)
	j	.L2
.L3:
	lui	a5,%hi(x)
	lw	a5,%lo(x)(a5)
	lw	a4,-20(s0)
	addw	a5,a4,a5
	sext.w	a4,a5
	lui	a5,%hi(x)
	sw	a4,%lo(x)(a5)
	lw	a5,-20(s0)
	addiw	a5,a5,1
	sw	a5,-20(s0)
.L2:
	lw	a5,-20(s0)
	sext.w	a4,a5
	li	a5,10
	ble	a4,a5,.L3
	lui	a5,%hi(unused)
	lw	a5,%lo(unused)(a5)
	mv	a1,a5
	lui	a5,%hi(.LC0)
	addi	a0,a5,%lo(.LC0)
	call	printf
	lui	a5,%hi(x)
	lw	a5,%lo(x)(a5)
	mv	a1,a5
	lui	a5,%hi(.LC0)
	addi	a0,a5,%lo(.LC0)
	call	printf
	lui	a5,%hi(x)
	lw	a5,%lo(x)(a5)
	mv	a0,a5
	ld	ra,24(sp)
	.cfi_restore 1
	ld	s0,16(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 32
	addi	sp,sp,32
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (gc891d8dc23e) 13.2.0"
	.section	.note.GNU-stack,"",@progbits
