	.file	"addmatsSimple.c"
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
	subl	$64, %esp
	call	___main
	movl	$0, 20(%esp)
	movl	$0, 24(%esp)
	movl	$0, 28(%esp)
	movl	$0, 32(%esp)
	movl	$0, 36(%esp)
	movl	$1, 20(%esp)
	movl	$0, (%esp)
	movl	$0, 4(%esp)
	movl	$0, 8(%esp)
	movl	$0, 12(%esp)
	movl	$0, 16(%esp)
	movl	$2, (%esp)
	movl	$0, 60(%esp)
	jmp	L2
L3:
	movl	60(%esp), %eax
	movl	20(%esp,%eax,4), %edx
	movl	60(%esp), %eax
	movl	(%esp,%eax,4), %eax
	addl	%eax, %edx
	movl	60(%esp), %eax
	movl	%edx, 40(%esp,%eax,4)
	addl	$1, 60(%esp)
L2:
	cmpl	$4, 60(%esp)
	jle	L3
	movl	$1, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE0:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
