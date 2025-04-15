	.file	"basic.c"
	.globl	_a
	.data
	.align 4
_a:
	.long	1
	.globl	_c
_c:
	.byte	97
	.globl	_f
	.align 4
_f:
	.long	1067320848
	.globl	_string
	.align 4
_string:
	.ascii "the bear at the grub\0"
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
	call	___main
	movl	$0, 12(%esp)
	jmp	L2
L3:
	movl	_a, %eax
	movl	%eax, _a
	addl	$1, 12(%esp)
L2:
	cmpl	$9, 12(%esp)
	jle	L3
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE0:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
