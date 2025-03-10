외울 필요는 없지만 어셈블리가 메모리 주소 공간의 시각에서 
메모리를 어떻게 사용하는가에 대한 흐름을 볼 수 있어야 한다!

### C code
```c
#include <stdio.h>   
  
int Sum;   
  
int func(int a) {   
    int i;   
    for (i = 0 ; i < a ; i++)   
        Sum += i;   
}   
  
int main() {   
    int a = 10;   
    int result;   
    result = func(a);   
    return 0;  
}  
```

### Assembly Code
```assembly
    .file "sample.c"   
    .text   
.globl func   
    .type func,@function   
func:   
    pushl   %ebp   // func 함수의 bp
    movl    %esp, %ebp   
    subl    $4, %esp   // 지역변수 i(int)로 sp 이동  
    movl.   $0, -4(%ebp)   
.L2:   
    movl    -4(%ebp), %eax   
    cmpl.   8(%ebp), %eax   // 조건 분기.
    jl      .L5   
    jmp.    .L3   
.L5:   
    movl.   -4(%ebp), %eax   
    addl    %eax, Sum   
    leal.   -4(%ebp), %eax   
    incl.   (%eax)   
    jmp     .L2 .  
L3:   
    leave   
    ret   
.Lfe1:   
    .size   func,.Lfe1-func   
.globl main   
    .type   main,@function   
main:   
    pushl   %ebp   // (extended, 최신) base pointer
    movl    %esp, %ebp   // stack pointer
    subl.   $8, %esp   
    movl.   $10, -4(%ebp)   // 10칸 위에 할당 (a = 10)
    pushl.  -4(%ebp)   
    call.   func   
    addl.   $4, %esp   
    movl    %eax, -8(%ebp)   
    leave   
    ret   
.Lfe2:   
    .size   main,.Lfe2-main   
    .comm   Sum,4,4   
    .ident  "GCC: (GNU) 3.2.2 20030222 (Red Hat Linux 3.2.2-5)"
```
