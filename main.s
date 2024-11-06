	.file	"main.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
main:
	subq	$40, %rsp
	call	__main
	movl	$2, %eax
	addq	$40, %rsp
	ret
	.ident	"GCC: (Rev5, Built by MSYS2 project) 13.2.0"
