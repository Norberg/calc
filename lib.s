#include <stdio.h>

	.data
FINT:	.string "%d\n"
	.text
	.global main



/* fact  */

fact:
	movl 	4(%esp), %ecx
	movl 	$1, %eax
	cmpl	%eax, %ecx
	jl	l7
l1:	mull 	%ecx
	loop 	l1
	jmp	l8
l7:	movl	$1, %ecx
l8:	ret

/* lntwo */

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

/* gcd */

gcd:
      	movl 	4(%esp), %eax
      	movl 	8(%esp), %ebx
l4:   	cmp 	%eax, %ebx 
      	je  	l6      
      	jle 	l5       
      	sub 	%eax, %ebx 
      	jmp 	l4       
l5:  	sub  	%ebx, %eax 
      	jmp 	l4       
l6:
      ret            


main: 
	/*
	pushl 	$36
	pushl	$24
	call 	gcd
	pushl 	%ebx
	push 	$FINT
	call 	printf */
	pushl 	$4
	call	fact
	pushl 	%eax
	push 	$FINT
	call 	printf
	call 	exit 
