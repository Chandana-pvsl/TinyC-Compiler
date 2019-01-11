	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"Entering the fib function\n"
.LC1:
	.string	"enter i: "
.LC2:
	.string	"\n\nnumber entered:"
.LC3:
	.string	"\ncalculating modified fibonocci numbers\n"
.LC4:
	.string	"\n\nSuccesfully!! Returned from the fib function output is:"
	.text	
	.globl	fib
	.type	fib, @function
fib: 
.LFB0:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$104, %rsp
	movq	%rdi, -20(%rbp)
	movq 	$.LC0, -28(%rbp)
	movl 	-28(%rbp), %eax
	movq 	-28(%rbp), %rdi
	call	prints
	movl	%eax, -32(%rbp)
	movl	$1, %eax
	movl 	%eax, -40(%rbp)
	movl	-40(%rbp), %eax
	movl 	%eax, -36(%rbp)
	movl	$0, %eax
	movl 	%eax, -48(%rbp)
	movl	-48(%rbp), %eax
	movl 	%eax, -44(%rbp)
	movl	$1, %eax
	movl 	%eax, -56(%rbp)
	movl	-56(%rbp), %eax
	movl 	%eax, -52(%rbp)
.L2: 
	movl	-52(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl .L3
	jmp .L4
.L3: 
	movl	-36(%rbp), %eax
	movl 	%eax, -60(%rbp)
	movl	$2, %eax
	movl 	%eax, -68(%rbp)
	movl 	-68(%rbp), %eax
	imull 	-44(%rbp), %eax
	movl 	%eax, -72(%rbp)
	movl 	-36(%rbp), %eax
	movl 	-72(%rbp), %edx
	addl 	%edx, %eax
	movl 	%eax, -76(%rbp)
	movl	-76(%rbp), %eax
	movl 	%eax, -36(%rbp)
	movl	-60(%rbp), %eax
	movl 	%eax, -44(%rbp)
	movl	$1, %eax
	movl 	%eax, -88(%rbp)
	movl 	-52(%rbp), %eax
	movl 	-88(%rbp), %edx
	addl 	%edx, %eax
	movl 	%eax, -92(%rbp)
	movl	-92(%rbp), %eax
	movl 	%eax, -52(%rbp)
	jmp .L2
.L4: 
	movl	-36(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	fib, .-fib
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
	subq	$116, %rsp

	movq 	$.LC1, -28(%rbp)
	movl 	-28(%rbp), %eax
	movq 	-28(%rbp), %rdi
	call	prints
	movl	%eax, -32(%rbp)
	movl	$0, %eax
	movl 	%eax, -40(%rbp)
	movl	-40(%rbp), %eax
	movl 	%eax, -36(%rbp)
	leaq	-44(%rbp), %rax
	movq 	%rax, -52(%rbp)
	movl 	-52(%rbp), %eax
	movq 	-52(%rbp), %rdi
	call	readi
	movl	%eax, -56(%rbp)
	movl	-56(%rbp), %eax
	movl 	%eax, -36(%rbp)
	movq 	$.LC2, -64(%rbp)
	movl 	-64(%rbp), %eax
	movq 	-64(%rbp), %rdi
	call	prints
	movl	%eax, -68(%rbp)
	movl 	-44(%rbp), %eax
	movq 	-44(%rbp), %rdi
	call	printi
	movl	%eax, -76(%rbp)
	movq 	$.LC3, -80(%rbp)
	movl 	-80(%rbp), %eax
	movq 	-80(%rbp), %rdi
	call	prints
	movl	%eax, -84(%rbp)
	movl 	-44(%rbp), %eax
	movq 	-44(%rbp), %rdi
	call	fib
	movl	%eax, -96(%rbp)
	movl	-96(%rbp), %eax
	movl 	%eax, -88(%rbp)
	movq 	$.LC4, -104(%rbp)
	movl 	-104(%rbp), %eax
	movq 	-104(%rbp), %rdi
	call	prints
	movl	%eax, -108(%rbp)
	movl 	-88(%rbp), %eax
	movq 	-88(%rbp), %rdi
	call	printi
	movl	%eax, -112(%rbp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident		"Compiled by 16CS30026"
	.section	.note.GNU-stack,"",@progbits
