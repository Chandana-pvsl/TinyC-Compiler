	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"Hello World\n"
.LC1:
	.string	"abcd"
.LC2:
	.string	"Please enter a number for recursive fibonacci: "
.LC3:
	.string	"You Entered "
.LC4:
	.string	"\n"
.LC5:
	.string	"Now testing for recursive fibonacci number ....Entering the function\n"
.LC6:
	.string	"\n\nReturned from recursive fibonacci function output is"
.LC7:
	.string	"\n"
.LC8:
	.string	"Please enter a number for recursive fun function: "
.LC9:
	.string	"You Entered "
.LC10:
	.string	"\n"
.LC11:
	.string	"recursive fun function....Entering the function\n"
.LC12:
	.string	"\n\nReturned from recursive fun function output is"
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
	subq	$112, %rsp
	movq	%rdi, -20(%rbp)
	movl	$1, %eax
	movl 	%eax, -28(%rbp)
	movl 	-20(%rbp), %eax
	movl 	-28(%rbp), %edx
	subl 	%edx, %eax
	movl 	%eax, -32(%rbp)
	movl	-32(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movl	$0, %eax
	movl 	%eax, -48(%rbp)
	movl	-24(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jle .L2
	jmp .L3
	jmp .L4
.L2: 
	movl	$1, %eax
	movl 	%eax, -52(%rbp)
	movl 	-24(%rbp), %eax
	movl 	-52(%rbp), %edx
	addl 	%edx, %eax
	movl 	%eax, -56(%rbp)
	movl	-56(%rbp), %eax
	movl 	%eax, -44(%rbp)
	jmp .L4
.L3: 
	movl 	-24(%rbp), %eax
	movq 	-24(%rbp), %rdi
	call	fib
	movl	%eax, -68(%rbp)
	movl	-68(%rbp), %eax
	movl 	%eax, -36(%rbp)
	movl	$1, %eax
	movl 	%eax, -76(%rbp)
	movl 	-24(%rbp), %eax
	movl 	-76(%rbp), %edx
	subl 	%edx, %eax
	movl 	%eax, -80(%rbp)
	movl	-80(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movl 	-24(%rbp), %eax
	movq 	-24(%rbp), %rdi
	call	fib
	movl	%eax, -88(%rbp)
	movl	-88(%rbp), %eax
	movl 	%eax, -40(%rbp)
	movl 	-36(%rbp), %eax
	movl 	-40(%rbp), %edx
	addl 	%edx, %eax
	movl 	%eax, -96(%rbp)
	movl	-96(%rbp), %eax
	movl 	%eax, -36(%rbp)
	movl	-36(%rbp), %eax
	movl 	%eax, -44(%rbp)
.L4: 
	movl	-44(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	fib, .-fib
	.globl	fun
	.type	fun, @function
fun: 
.LFB1:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$76, %rsp
	movq	%rdi, -20(%rbp)
	movl	$2, %eax
	movl 	%eax, -28(%rbp)
	movl 	-20(%rbp), %eax
	cltd
	idivl 	-28(%rbp)
	movl 	%edx, -32(%rbp)
	movl	$1, %eax
	movl 	%eax, -36(%rbp)
	movl	-32(%rbp), %eax
	cmpl	-36(%rbp), %eax
	je .L7
	jmp .L8
	jmp .L9
.L7: 
	movl	-20(%rbp), %eax
	movl 	%eax, -40(%rbp)
	addl 	$1, -20(%rbp)
	movl	-40(%rbp), %eax
	movl 	%eax, -24(%rbp)
	jmp .L9
.L8: 
	movl	$1, %eax
	movl 	%eax, -52(%rbp)
	movl 	-20(%rbp), %eax
	movl 	-52(%rbp), %edx
	subl 	%edx, %eax
	movl 	%eax, -56(%rbp)
	movl 	-56(%rbp), %eax
	movq 	-56(%rbp), %rdi
	call	fun
	movl	%eax, -60(%rbp)
	movl 	-60(%rbp), %eax
	movq 	-60(%rbp), %rdi
	call	fun
	movl	%eax, -64(%rbp)
	movl	-64(%rbp), %eax
	movl 	%eax, -24(%rbp)
.L9: 
	movl	-24(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	fun, .-fun
	.globl	main
	.type	main, @function
main: 
.LFB2:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$282, %rsp

	movl	$5, %eax
	movl 	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movl	$2, %eax
	movl 	%eax, -36(%rbp)
	movl	-36(%rbp), %eax
	movl 	%eax, -32(%rbp)
	movb	$0, -45(%rbp)
	movl	-45(%rbp), %eax
	movl 	%eax, -44(%rbp)
	movq 	$.LC0, -50(%rbp)
	movl	-50(%rbp), %eax
	movl 	%eax, -46(%rbp)
	movq 	$.LC1, -62(%rbp)
	movl	-62(%rbp), %eax
	movl 	%eax, -58(%rbp)
	movl	-24(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl .L12
	jmp .L13
	jmp .L14
.L12: 
	movl	-24(%rbp), %eax
	movl 	%eax, -78(%rbp)
	addl 	$1, -24(%rbp)
	jmp .L14
.L13: 
	movl 	-24(%rbp), %eax
	movl 	-32(%rbp), %edx
	addl 	%edx, %eax
	movl 	%eax, -82(%rbp)
	movl	-82(%rbp), %eax
	movl 	%eax, -40(%rbp)
.L14: 
	movq 	$.LC2, -94(%rbp)
	movl 	-94(%rbp), %eax
	movq 	-94(%rbp), %rdi
	call	prints
	movl	%eax, -98(%rbp)
	leaq	-74(%rbp), %rax
	movq 	%rax, -106(%rbp)
	movl 	-106(%rbp), %eax
	movq 	-106(%rbp), %rdi
	call	readi
	movl	%eax, -110(%rbp)
	movl	-110(%rbp), %eax
	movl 	%eax, -70(%rbp)
	movq 	$.LC3, -118(%rbp)
	movl 	-118(%rbp), %eax
	movq 	-118(%rbp), %rdi
	call	prints
	movl	%eax, -122(%rbp)
	movl 	-74(%rbp), %eax
	movq 	-74(%rbp), %rdi
	call	printi
	movl	%eax, -130(%rbp)
	movl	-130(%rbp), %eax
	movl 	%eax, -40(%rbp)
	movq 	$.LC4, -138(%rbp)
	movl 	-138(%rbp), %eax
	movq 	-138(%rbp), %rdi
	call	prints
	movl	%eax, -142(%rbp)
	movq 	$.LC5, -146(%rbp)
	movl 	-146(%rbp), %eax
	movq 	-146(%rbp), %rdi
	call	prints
	movl	%eax, -150(%rbp)
	movl	$0, %eax
	movl 	%eax, -158(%rbp)
	movl	-158(%rbp), %eax
	movl 	%eax, -154(%rbp)
	movl 	-74(%rbp), %eax
	movq 	-74(%rbp), %rdi
	call	fib
	movl	%eax, -166(%rbp)
	movl	-166(%rbp), %eax
	movl 	%eax, -154(%rbp)
	movq 	$.LC6, -174(%rbp)
	movl 	-174(%rbp), %eax
	movq 	-174(%rbp), %rdi
	call	prints
	movl	%eax, -178(%rbp)
	movl 	-154(%rbp), %eax
	movq 	-154(%rbp), %rdi
	call	printi
	movl	%eax, -182(%rbp)
	movq 	$.LC7, -186(%rbp)
	movl 	-186(%rbp), %eax
	movq 	-186(%rbp), %rdi
	call	prints
	movl	%eax, -190(%rbp)
	movq 	$.LC8, -194(%rbp)
	movl 	-194(%rbp), %eax
	movq 	-194(%rbp), %rdi
	call	prints
	movl	%eax, -198(%rbp)
	leaq	-74(%rbp), %rax
	movq 	%rax, -202(%rbp)
	movl 	-202(%rbp), %eax
	movq 	-202(%rbp), %rdi
	call	readi
	movl	%eax, -206(%rbp)
	movl	-206(%rbp), %eax
	movl 	%eax, -70(%rbp)
	movq 	$.LC9, -214(%rbp)
	movl 	-214(%rbp), %eax
	movq 	-214(%rbp), %rdi
	call	prints
	movl	%eax, -218(%rbp)
	movl 	-74(%rbp), %eax
	movq 	-74(%rbp), %rdi
	call	printi
	movl	%eax, -222(%rbp)
	movl	-222(%rbp), %eax
	movl 	%eax, -40(%rbp)
	movq 	$.LC10, -230(%rbp)
	movl 	-230(%rbp), %eax
	movq 	-230(%rbp), %rdi
	call	prints
	movl	%eax, -234(%rbp)
	movq 	$.LC11, -238(%rbp)
	movl 	-238(%rbp), %eax
	movq 	-238(%rbp), %rdi
	call	prints
	movl	%eax, -242(%rbp)
	movl	$0, %eax
	movl 	%eax, -250(%rbp)
	movl	-250(%rbp), %eax
	movl 	%eax, -246(%rbp)
	movl 	-74(%rbp), %eax
	movq 	-74(%rbp), %rdi
	call	fun
	movl	%eax, -258(%rbp)
	movl	-258(%rbp), %eax
	movl 	%eax, -246(%rbp)
	movq 	$.LC12, -266(%rbp)
	movl 	-266(%rbp), %eax
	movq 	-266(%rbp), %rdi
	call	prints
	movl	%eax, -270(%rbp)
	movl 	-246(%rbp), %eax
	movq 	-246(%rbp), %rdi
	call	printi
	movl	%eax, -274(%rbp)
	movl	$0, %eax
	movl 	%eax, -278(%rbp)
	movl	-278(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident		"Compiled by 16CS30026"
	.section	.note.GNU-stack,"",@progbits
