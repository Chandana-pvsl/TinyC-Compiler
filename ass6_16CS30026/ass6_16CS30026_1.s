	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"Passing pointers to function f!\n"
.LC1:
	.string	"Value passed to function: "
.LC2:
	.string	"\n"
.LC3:
	.string	"value returned from function is: "
.LC4:
	.string	"give an integer as input"
.LC5:
	.string	"\n"
.LC6:
	.string	"The integer that was read is:"
.LC7:
	.string	"\n"
.LC8:
	.string	"printing array numbers+5"
	.text	
	.globl	f
	.type	f, @function
f: 
.LFB0:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$52, %rsp
	movq	%rdi, -20(%rbp)
	movl	-28(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movl	$2, %eax
	movl 	%eax, -36(%rbp)
	movl 	-24(%rbp), %eax
	movl 	-36(%rbp), %edx
	addl 	%edx, %eax
	movl 	%eax, -40(%rbp)
	movl	-40(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movl	-24(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	f, .-f
	.globl	main
	.type	main, @function
main: 
.LFB1:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$276, %rsp

	movl	$3, %eax
	movl 	%eax, -40(%rbp)
	movl	-40(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movq 	$.LC0, -52(%rbp)
	movl 	-52(%rbp), %eax
	movq 	-52(%rbp), %rdi
	call	prints
	movl	%eax, -56(%rbp)
	movq 	$.LC1, -60(%rbp)
	movl 	-60(%rbp), %eax
	movq 	-60(%rbp), %rdi
	call	prints
	movl	%eax, -64(%rbp)
	movl 	-24(%rbp), %eax
	movq 	-24(%rbp), %rdi
	call	printi
	movl	%eax, -72(%rbp)
	movq 	$.LC2, -76(%rbp)
	movl 	-76(%rbp), %eax
	movq 	-76(%rbp), %rdi
	call	prints
	movl	%eax, -80(%rbp)
	movq 	$.LC3, -84(%rbp)
	movl 	-84(%rbp), %eax
	movq 	-84(%rbp), %rdi
	call	prints
	movl	%eax, -88(%rbp)
	leaq	-28(%rbp), %rax
	movq 	%rax, -96(%rbp)
	movl 	-96(%rbp), %eax
	movq 	-96(%rbp), %rdi
	call	f
	movl	%eax, -100(%rbp)
	movl	-100(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movl	$5, %eax
	movl 	%eax, -108(%rbp)
	movl 	-108(%rbp), %eax
	movq 	-108(%rbp), %rdi
	call	printi
	movl	%eax, -112(%rbp)
	movq 	$.LC4, -116(%rbp)
	movl 	-116(%rbp), %eax
	movq 	-116(%rbp), %rdi
	call	prints
	movl	%eax, -120(%rbp)
	movq 	$.LC5, -124(%rbp)
	movl 	-124(%rbp), %eax
	movq 	-124(%rbp), %rdi
	call	prints
	movl	%eax, -128(%rbp)
	leaq	-28(%rbp), %rax
	movq 	%rax, -136(%rbp)
	movl 	-136(%rbp), %eax
	movq 	-136(%rbp), %rdi
	call	readi
	movl	%eax, -140(%rbp)
	movl	-140(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movq 	$.LC6, -148(%rbp)
	movl 	-148(%rbp), %eax
	movq 	-148(%rbp), %rdi
	call	prints
	movl	%eax, -152(%rbp)
	movl 	-28(%rbp), %eax
	movq 	-28(%rbp), %rdi
	call	printi
	movl	%eax, -156(%rbp)
	movq 	$.LC7, -160(%rbp)
	movl 	-160(%rbp), %eax
	movq 	-160(%rbp), %rdi
	call	prints
	movl	%eax, -164(%rbp)
	movl	$10, %eax
	movl 	%eax, -208(%rbp)
	movq 	$.LC8, -216(%rbp)
	movl 	-216(%rbp), %eax
	movq 	-216(%rbp), %rdi
	call	prints
	movl	%eax, -220(%rbp)
	movl	$0, %eax
	movl 	%eax, -224(%rbp)
	movl	-224(%rbp), %eax
	movl 	%eax, -212(%rbp)
.L4: 
	movl	$10, %eax
	movl 	%eax, -232(%rbp)
	movl	-212(%rbp), %eax
	cmpl	-232(%rbp), %eax
	jl .L6
	jmp .L7
.L5: 
	movl	-212(%rbp), %eax
	movl 	%eax, -236(%rbp)
	addl 	$1, -212(%rbp)
	jmp .L4
.L6: 
	movl 	-212(%rbp), %eax
	imull 	$4, %eax
	movl 	%eax, -240(%rbp)
	movl	$5, %eax
	movl 	%eax, -244(%rbp)
	movl 	-212(%rbp), %eax
	movl 	-244(%rbp), %edx
	addl 	%edx, %eax
	movl 	%eax, -248(%rbp)
	movq	-248(%rbp), %rdx
	movq	%rdx, -168(%rbp)
	movl 	-212(%rbp), %eax
	imull 	$4, %eax
	movl 	%eax, -260(%rbp)
	movq	-168(%rbp), %rax
	movq 	%rax, -264(%rbp)
	movl 	-264(%rbp), %eax
	movq 	-264(%rbp), %rdi
	call	printi
	movl	%eax, -268(%rbp)
	jmp .L5
.L7: 
	movl	$0, %eax
	movl 	%eax, -272(%rbp)
	movl	-272(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident		"Compiled by 16CS30026"
	.section	.note.GNU-stack,"",@progbits
