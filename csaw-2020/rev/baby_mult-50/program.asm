section .text:
global _start
_start:


push rbp
mov rbp,rsp
sub rsp,byte +0x18
mov qword [rbp-0x8],0x4f
mov rax,0x14be74f15

mov [rbp-0x10],rax
mov qword [rbp-0x18],0x4
mov qword [rbp-0x20],0x3
mov qword [rbp-0x28],0x13
mov qword [rbp-0x30],0x115
mov rax,0x77cf4b645b61

mov [rbp-0x38],rax
mov qword [rbp-0x40],0x2
mov qword [rbp-0x48],0x11
mov qword [rbp-0x50],0x21c1
mov qword [rbp-0x58],0x182265e9
mov qword [rbp-0x60],0x833
mov qword [rbp-0x68],0xaab
mov qword [rbp-0x70],0x8daaad
mov rax,[rbp-0x8]
imul rax,[rbp-0x10]
mov [rbp-0x78],rax
mov rax,[rbp-0x18]
imul rax,[rbp-0x20]
imul rax,[rbp-0x28]
imul rax,[rbp-0x30]
imul rax,[rbp-0x38]
mov [rbp-0x80],rax
mov rax,[rbp-0x40]
imul rax,[rbp-0x48]
imul rax,[rbp-0x50]
imul rax,[rbp-0x58]
mov [rbp-0x88],rax
mov rax,[rbp-0x60]
imul rax,[rbp-0x68]
imul rax,[rbp-0x70]
mov [rbp-0x90],rax
mov eax,0x0
leave
