	.file	"asgn1.c"				#source filename
	.section	.rodata				#read-only data section
	.align 8						#align with 8-bytes boundary for optimization
.LC0:								#Label for string in 1st printf function
  .LC1:								#Label for string in 1st scanf function
	.string	"%ld"
	.align 8 						#align with 8-bytes boundary for optimization
.LC2:
	.string	"\nPI: %10.8lf (using Infinite Series)"	#Label for string in 2nd printf function
	.align 8 						#align with 8-bytes boundary for optimization
.LC3:
	.string	"\tPI: %10.8lf (using Monte Carlo method)\n\n"	#Label for string in 3rd printf function
	.text							#start of code
	.globl	main					#global is an export variable must be used for linker(like gcc)
	.type	main, @function			#sets the type of symbol(main) to be function
main:
.LFB2:
	.cfi_startproc					#call frame information directives to manage exception handling and 
									#causes a new CFI table for this function to be initialised
	pushq	%rbp					#pushes base pointer into the stack to save the old address
	.cfi_def_cfa_offset 16			#cfi offset is updated to 16 fr computing cfa address
	.cfi_offset 6, -16				#sets register 6 to (cfi-16) to store rbp 
	movq	%rsp, %rbp				#rbp is set to rsp address
	.cfi_def_cfa_register 6			#register 6 is used to calculate cfa as default
	subq	$48, %rsp				#create space for local variables
	movq	%fs:40, %rax		

	movq	%rax, -8(%rbp)			#(rbp-8)=rax
	xorl	%eax, %eax				#eax = xor(eax,eax)=0

	movl	$.LC0, %edi				#edi = LC0,
									#edi is the first parameter of printf
	movl	$0, %eax				#number of floating point value is set to 0
	call	printf					#printf function is called

	leaq	-32(%rbp), %rax			#rax = &(rbp-32) load effective address
	movq	%rax, %rsi				#rsi = rax second argument of syscall is stored in rsi(address of num is stored)
	movl	$.LC1, %edi				#edi is set to string in LC1
	movl	$0, %eax				#number of floating point value is set to 0
	call	__isoc99_scanf			#scanf is called

	movq	-32(%rbp), %rax			#num is restores from stack to rax
	movq	%rax, %rdi				#rdi = rax (first argument is set num)
	call	monteCarlo				#monteCarlo method is called 

	movq	%xmm0, %rax				#rax --> xmm0 pi from montecarlo method is in xmm0
	movq	%rax, -24(%rbp)			#(rbp-24) = rax = pi

	movq	-32(%rbp), %rax 		#rax = (rbp-32) = num
	movq	%rax, %rdi				#rdi = rax (first argument is set n)
	call	iSeries					#iSeries is called

	movq	%xmm0,%rax  			#rax --> xmm0 pi from infinite series method is in rax(float values are returned in xmm0)
	movq	%rax, -16(%rbp)			#(rbp-16) = rax
	
	movq	-16(%rbp), %rax 		#rax = (rbp-16) pi from iseries
	movq	%rax, -40(%rbp)			#(rbp-40)=rax
	movsd	-40(%rbp), %xmm0		#xmm0 = (rbp-40)

	movl	$.LC2, %edi				#LC2 is loaded as the first argument of printf function
	movl	$1, %eax				#one floating point number is in printf
	call	printf					#pritntf function is called

	movq	-24(%rbp), %rax 		#rax = (rbp-24) pi from montecarlo 
	movq	%rax, -40(%rbp)			#(rbp-40 )= rax
	movsd	-40(%rbp), %xmm0		#xmm0 = (rbp-40) 
	movl	$.LC3, %edi				#LC2 is loaded as the first argument of printf function
	movl	$1, %eax 				#one floating point number is in printf
	call	printf					#printf function is called

	movl	$0, %eax            	#eax--0 (returns 0)
	movq	-8(%rbp), %rdx 			#rdx = (rbp-8)
	xorq	%fs:40, %rdx 			#
	je	.L3 						#jump to L3 if equal
	call	__stack_chk_fail
.L3:
	leave							#stack frame is removed
	.cfi_def_cfa 7, 8				#address is taken from 7th reg and offset 8 is set
	ret 							#returns to caller
	.cfi_endproc 					#procedure ends here
.LFE2:
	.size	main, .-main 		
	.globl	iSeries
	.type	iSeries, @function
iSeries:
.LFB3:								#label LFB3
	.cfi_startproc					#start of LFB3
	pushq	%rbp 					#save old base pointer
	.cfi_def_cfa_offset 16			#set offset to 16
	.cfi_offset 6, -16				#set offset of register 6 to 16
	movq	%rsp, %rbp 				#stack pointer is saved into base pinter
	.cfi_def_cfa_register 6			#register 6 is used to store stack values
	movq	%rdi, -24(%rbp)			#(rbp-24) = rdi = n
	pxor	%xmm0, %xmm0			#xmm0 =0  pi is set to 1
	movsd	%xmm0, -8(%rbp)			#(rbp-8)=xmm0 pi is stored in rbp-8
	movl	$1, -12(%rbp)			#(rbp-12) = 1 i is set to 1
	jmp	.L5 						#jump to L5
.L8:
	movl	-12(%rbp), %eax			#move i to eax
	andl	$1, %eax 				#eax = eax and 1
	testl	%eax, %eax				#checks if eax is 0 or not
	jne	.L6 						#if eax != 0 jumps to L6 implies if i is odd
	movl	-12(%rbp), %eax     	#move i to eax
	addl	%eax, %eax				#eax = eax+eax i.e. 2*i
	subl	$1, %eax 				#calculating (2*i-1)
	pxor	%xmm0, %xmm0        	#sets xmmo to 0
	cvtsi2sd	%eax, %xmm0     	# eax is converted into double and stored in xmm0
	movsd	.LC5(%rip), %xmm1		#xmm1 is made assigned to 4
	divsd	%xmm0, %xmm1        	#xmm1 = xmm1/xmm0
	movapd	%xmm1, %xmm0			#moves xmm1 into xmm0
	movsd	-8(%rbp), %xmm1			#xmm1 = (rbp-8) = pi
	subsd	%xmm0, %xmm1			#pi = pi - xmm0(i.e. 4/(2*i-1))
	movapd	%xmm1, %xmm0 			#moves xmm1 to xmm0
	movsd	%xmm0, -8(%rbp) 		#(rbp-8) = xmm0
	jmp	.L7 						#jump to L7
.L6:
	movl	-12(%rbp), %eax     	#eax = i
	addl	%eax, %eax				#i = 2*i 
	subl	$1, %eax				#i = 2*i-1
	pxor	%xmm0, %xmm0			#xmm0 is set to 1
	cvtsi2sd	%eax, %xmm0			#eax is converted into double and stored in xmm0
	movsd	.LC5(%rip), %xmm1		#xmm1 = 4
	divsd	%xmm0, %xmm1			#xmm1 = xmm1/xmm0 = 4 / i
	movapd	%xmm1, %xmm0 			#xmm0 = xmm1
	movsd	-8(%rbp), %xmm1			#xmm1 = (rbp-8)=pi
	addsd	%xmm1, %xmm0			#xmm0 = xmm1 + xmm0 (pi = pi + 4/(2*i-1))
	movsd	%xmm0, -8(%rbp)			#(rbp-8)=pi=xmm0
.L7:
	addl	$1, -12(%rbp) 			#i = i+1
.L5:
	movl	-12(%rbp), %eax			#eax = (rbp-12) i.e. i
	cltq							#promotes eax to rax
	cmpq	-24(%rbp), %rax 		#compares rax and (rbp - 24) i.e. i and n
	jle	.L8 						#if i<=n jump to L8
	movsd	-8(%rbp), %xmm0			#xmm0 = pi stored in rbp-8
	popq	%rbp 					#rbp is popped from the stack
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	iSeries, .-iSeries
	.globl	monteCarlo
	.type	monteCarlo, @function
monteCarlo:
.LFB4:
	.cfi_startproc
	pushq	%rbp					#save old base pointer
	.cfi_def_cfa_offset 16			#new offset is set to be 16
	.cfi_offset 6, -16				#register offset is set to be 16
	movq	%rsp, %rbp 				#stack pointer is saved into base pointer
	.cfi_def_cfa_register 6			#register 6 is used as stack
	subq	$48, %rsp				#create space for local variables(6)
	movq	%rdi, -40(%rbp)			#store (rbp-40)-->rdi-->num which is passed from main function
	movl	$0, -20(%rbp)			#store (rbp-20)-->0  count-->0
	movl	$12345, %edi			#first parameter of srand set to 12345
	call	srand					#srand function is called
	movl	$1, -24(%rbp)			#(rbp-24)-->1 i.e. i=1
	jmp	.L11						#for loop starts
.L14:
	call	rand					#rand function is called
	pxor	%xmm0, %xmm0			#initializes xmm0 to 0
	cvtsi2sd	%eax, %xmm0			#converts an integer to a double in an XMM register(here eax is stored in xmm0)
	movsd	.LC6(%rip), %xmm1		#moves xmm1 to .LC6(%rip) xmm1 = RAND_MAX movsd
									#moves a single 64 bit floating point value
	divsd	%xmm1, %xmm0			#xmm0 = xmm0/xmm1--> (double)rand()/RAND_MAX
	movsd	%xmm0, -16(%rbp)		#(rbp-16) = xmm0
	call	rand 					#rand function is called
	pxor	%xmm0, %xmm0 			#initializes xmm0 to 0
	cvtsi2sd	%eax, %xmm0			#converts an integer to a double in an XMM register
	movsd	.LC6(%rip), %xmm1		#moves xmm1 to .LC6(%rip) xmm1 = RAND_MAX
	divsd	%xmm1, %xmm0			#xmm0 = xmm0/xmm1--> (double)rand()/RAND_MAX
	movsd	%xmm0, -8(%rbp)			#(rbp-8) = xmm0 = y
	movsd	-16(%rbp), %xmm0		#xmm0 = (rbp-16)=x
	movapd	%xmm0, %xmm1			#movapd moves 2 doubles to/from a memory address aligned at a 16
									#byte boundary
	mulsd	-16(%rbp), %xmm1		#xmm1 = (rbp-16)*xmm1 (x*x)
	movsd	-8(%rbp), %xmm0			#xmm0 = (rbp-8)=y
	mulsd	-8(%rbp), %xmm0			#xmm0 = xmm0*(rbp-8)=y*y
	addsd	%xmm1, %xmm0			#xmm0 = xmm0+xmm1 = x*x+y*y
	movsd	.LC7(%rip), %xmm1		#1 is stored in xmm0
	ucomisd	%xmm0, %xmm1			#ucomisd compares doubles
	jb	.L12						#jump to L12 if below (if xmm0<xmm1)
	addl	$1, -20(%rbp)			#(rbp-20)=count is incremented by 1
.L12:
	addl	$1, -24(%rbp)			#rbp-24 = (rbp-24)+1  i is incremented by 1
.L11:
	movl	-24(%rbp), %eax			#rbp-24-->i is stored into eax
	cltq							#cltq promotes an int to an int64 here eax is converted to rax
	cmpq	-40(%rbp), %rax			#compares rax and (rbp-40) (i.e. i and count)
	jle	.L14						#jump to label L14 if i<=count
	pxor	%xmm0, %xmm0			#sets xmm0 = 0(pxor performs bitwise xor)
	cvtsi2sd	-20(%rbp), %xmm0	# xmm0 is converted into double and set to (rbp-20)=count
	pxor	%xmm1, %xmm1			#xmm1 = 0
	cvtsi2sdq	-40(%rbp), %xmm1	#xmm1 is converted to double and set to n which is stored in (rbp-40)
	divsd	%xmm1, %xmm0     		#xmm0 = xmm0/xmm1 = count/n
	movsd	.LC5(%rip), %xmm1		#xmm1 = 4
	mulsd	%xmm1, %xmm0			#xmm0 = xmm0*xmm1
	leave
	.cfi_def_cfa 7, 8				#set offset of register 7 to 8
	ret 							#return to caller
	.cfi_endproc
.LFE4:
	.size	monteCarlo, .-monteCarlo
	.section	.rodata
	.align 8
.LC5:
	.long	0 						#lc5 sets 4
	.long	1074790400
	.align 8
.LC6:
	.long	4290772992				#RANDMAX is set
	.long	1105199103
	.align 8
.LC7:
	.long	0
	.long	1072693248   			#LC7 set 1
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
