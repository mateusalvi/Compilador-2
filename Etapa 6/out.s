#HEADER
.text
.data

H45H_T3MP2:	.long	0

H45H_T3MP0:	.long	0

H45H_T3MP1:	.long	0

ffafafafa:
	.globl ffafafafa
	.type  ffafafafa, @object
	.size  ffafafafa, 4
	.long  0
    .text

adas:
	.globl adas
	.type  adas, @object
	.size  adas, 4
	.long  1074161254
    .text

bob:
	.globl bob
	.type  bob, @object
	.size  bob, 4
	.long  1
    .text

chacha:
	.globl chacha
	.type  chacha, @object
	.size  chacha, 4
	.long  39
    .text

.globl main
.type main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl 	ffafafafa(%rip), %eax
	movl 	ffafafafa(%rip), %edx
	addl 	%eax, %edx
	movl 	%edx, H45H_T3MP0(%rip)
	movl 	H45H_T3MP0(%rip), %eax
	movl 	%eax, ffafafafa(%rip)
	popq	%rbp
	ret

.globl foo
.type foo, @function
foo:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	adas(%rip), %eax
	movl	adas(%rip), %edx
	imull	%eax, %edx
	movl	%edx, H45H_T3MP1(%rip)
	movl 	H45H_T3MP1(%rip), %eax
	movl 	%eax, adas(%rip)
	movl 	adas(%rip), %eax
	movl 	ffafafafa(%rip), %edx
	addl 	%eax, %edx
	movl 	%edx, H45H_T3MP2(%rip)
	movl 	H45H_T3MP2(%rip), %eax
	movl 	%eax, ffafafafa(%rip)
	popq	%rbp
	ret

