a:
	.long	555
	.globl	b
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	666
	.globl	c
	.type	c, @object
	.size	c, 1
c:
	.byte	97
	.globl	d
	.section	.rodata
.LC0:
	.string	"fffff"
	.section	.data.rel.local,"aw"
	.align 8
	.type	d, @object
	.size	d, 8
d:
	.quad	.LC0
	.section	.rodata
.LC1:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	a(%rip), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	popq	%rbp
	ret
foo:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, %eax
	movb	%al, -12(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
	nop
	popq	%rbp
	ret
