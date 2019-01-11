	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"\n\nEntered the function \n"
.LC1:
	.string	"number is divisible by the other "
.LC2:
	.string	"number is not divisible by the other"
.LC3:
	.string	"\n"
.LC4:
	.string	"enter i: "
.LC5:
	.string	"You Entered "
.LC6:
	.string	"enter j: "
.LC7:
	.string	"You Entered "
.LC8:
	.string	"Entering the function divisible... \n"
.LC9:
	.string	"succesfully returned from function \n"
	.text	
	.globl	div
	.type	div, @function
div: 
.LFB0:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$80, %rsp
	movq	%rdi, -20(%rbp)
	movq	%rsi, -16(%rbp)
	movq 	$.LC0, -28(%rbp)
	movl 	-28(%rbp), %eax
	movq 	-28(%rbp), %rdi
	call	prints
	movl	%eax, -32(%rbp)
	movl 	-20(%rbp), %eax
	cltd
	idivl 	-16(%rbp)
	movl 	%edx, -40(%rbp)
	movl	-40(%rbp), %eax
	movl 	%eax, -36(%rbp)
	movl	$0, %eax
	movl 	%eax, -48(%rbp)
	movl	-36(%rbp), %eax
	cmpl	-48(%rbp), %eax
	je .L2
	jmp .L3
	jmp .L4
.L2: 
	movq 	$.LC1, -52(%rbp)
	movl 	-52(%rbp), %eax
	movq 	-52(%rbp), %rdi
	call	prints
	movl	%eax, -56(%rbp)
	jmp .L4
.L3: 
	movq 	$.LC2, -60(%rbp)
	movl 	-60(%rbp), %eax
	movq 	-60(%rbp), %rdi
	call	prints
	movl	%eax, -64(%rbp)
.L4: 
	movq 	$.LC3, -68(%rbp)
	movl 	-68(%rbp), %eax
	movq 	-68(%rbp), %rdi
	call	prints
	movl	%eax, -72(%rbp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	div, .-div
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
	subq	$136, %rsp

	movl	$1, %eax
	movl 	%eax, -32(%rbp)
	movl	-32(%rbp), %eax
	movl 	%eax, -28(%rbp)
	movq 	$.LC4, -44(%rbp)
	movl 	-44(%rbp), %eax
	movq 	-44(%rbp), %rdi
	call	prints
	movl	%eax, -48(%rbp)
	leaq	-24(%rbp), %rax
	movq 	%rax, -56(%rbp)
	movl 	-56(%rbp), %eax
	movq 	-56(%rbp), %rdi
	call	readi
	movl	%eax, -60(%rbp)
	movq 	$.LC5, -64(%rbp)
	movl 	-64(%rbp), %eax
	movq 	-64(%rbp), %rdi
	call	prints
	movl	%eax, -68(%rbp)
	movl 	-24(%rbp), %eax
	movq 	-24(%rbp), %rdi
	call	printi
	movl	%eax, -76(%rbp)
	movq 	$.LC6, -80(%rbp)
	movl 	-80(%rbp), %eax
	movq 	-80(%rbp), %rdi
	call	prints
	movl	%eax, -84(%rbp)
	leaq	-28(%rbp), %rax
	movq 	%rax, -88(%rbp)
	movl 	-88(%rbp), %eax
	movq 	-88(%rbp), %rdi
	call	readi
	movl	%eax, -92(%rbp)
	movq 	$.LC7, -96(%rbp)
	movl 	-96(%rbp), %eax
	movq 	-96(%rbp), %rdi
	call	prints
	movl	%eax, -100(%rbp)
	movl 	-28(%rbp), %eax
	movq 	-28(%rbp), %rdi
	call	printi
	movl	%eax, -104(%rbp)
	movq 	$.LC8, -108(%rbp)
	movl 	-108(%rbp), %eax
	movq 	-108(%rbp), %rdi
	call	prints
	movl	%eax, -112(%rbp)
	movl 	-24(%rbp), %eax
	movq 	-24(%rbp), %rdi
movl 	-28(%rbp), %eax
	movq 	-28(%rbp), %rsi
	call	div
	movl	%eax, -120(%rbp)
	movq 	$.LC9, -124(%rbp)
	movl 	-124(%rbp), %eax
	movq 	-124(%rbp), %rdi
	call	prints
	movl	%eax, -128(%rbp)
	movl	$0, %eax
	movl 	%eax, -132(%rbp)
	movl	-132(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident		"Compiled by 16CS30026"
	.section	.note.GNU-stack,"",@progbits
