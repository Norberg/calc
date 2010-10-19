#include <stdio.h>

	.data
FINT:	.string "%d\n"
	.text
	.global main



/* fact  */

fact:
	movl 	4(%esp), %ecx
	movl 	$1, %eax
l1:	mull 	%ecx
	loop 	l1
	ret
lntwo:
	movl	4(%esp), %ecx
	movl	$1, %eax
	movl	$0, %ebx
l2:	cmpl	%eax, %ecx
	jbe	l3
	imul	$2, %eax
	inc	%ebx	
	jmp	l2	
l3:	movl	%ebx, %eax
	ret
	

main: 
	pushl 	$64
	call 	lntwo
	pushl 	%eax
	push 	$FINT
	call 	printf
	call 	exit 
