	.text
	.data
	.globl	main
	.type	main, @function
	
a:
	.globl	a
	.type	a, @object
	.size	a, 4
	.long	555
	.text

main:
	pushq	%rbp
	movq	%rsp, %rbp
	nop
	popq	%rbp
	ret
