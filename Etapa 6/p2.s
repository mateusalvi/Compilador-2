	.align 4
	.text 
	.globl	main
	.type	main, @function

#  function begin
main: 
	pushq	%rbp 
	movq	%rsp, %rbp
#----------------

	movl	$771, a(%rip)
	movl	a(%rip), %eax
	movl	%eax, %esi
	leaq	print_int_string(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT


#  function end
	popq	%rbp
	ret
#---------------


#  data begin
	.data	
	

print_int_string:
	.string	"%d\n" 

#  declaration of int a 
a:
	.type	a, @object 
	.size	a, 4
	.long	31 
# -------------

#  declaration of int b 
b:
	.type	b, @object
	.size	b, 4
	.long	33
# -------------

#  declaration of char c 
c:
	.type	c, @object
	.size	c, 1
	.byte	106
# -------------

 

_var_float:
	.type	_var_float, @object
	.size	_var_float, 4
	.long	1078355558
	