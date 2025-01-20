#  Samsung-RISCV

This hands-on program helps participants learn **RISC-V** and **Semiconductor technologies** through practical training. It covers **VLSI chip design** and **RISC-V architecture** using open-source tools, with guidance from **Kunal Ghosh** to develop practical skills.

##  Basic Details

**Name:** TEJAS M 

**College:** Vidya Vardhaka College of Engineering

**Email ID:** tejasmanjunath381@gmail.com 

**LinkedIN Profile:** www.linkedin.com/in/tejas---m

----------------------------------------------------------------------------------------------------------------

<details>
<summary><b>Task 1:</b> Install the RISC-V toolchain using the VDI link, then compile the C code using both the normal GCC compiler and the RISC-V GCC compiler to compare the results. Refer to the provided C-based and RISC-V lab videos for guidance on completing the task.</summary>   
<br>
  
**C Program**

We start by creating a file in our directory using a simple editor like Leafpad. After writing the program to calculate the sum of numbers from 1 to n, save the file, close the editor, and compile it using GCC. Once compiled, you can run the program to fetch the output.

### Program to calculate 1 to n numbers
```
#include<stdio.h>
int main()
{
  int i, sum=0, n=50;
  for(i=0;i<=n;++i)
    {
      sum+=i;
    }
  printf("Sum of numbers from 1 to %d is %d\n",n,sum);
  return 0;
}
```

**Commands used to compile and fetch the output are**
```
gcc sum1ton.c
./a.out
```

**C Program output on compiling using GCC compiler**
![sum 1 to n](https://github.com/user-attachments/assets/a8080e4b-37b7-4122-a000-383612a9c3cf)

### RISC-V instructions 

It involves viewing the C code with the cat command which as been written using the leafpad.

```
cat sum1ton.c
```

### Generating Object file using RISC-V 64 bit compiler.

```
riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
```

![Code compiled using riscv compiler](https://github.com/user-attachments/assets/5a5451a8-a061-4b9a-8f14-3658add2c727)

After compiling, type
```
riscv64-unknown-elf-objdump -d sum1ton.o
```
to disassemble the code and examine its assembly language version. This provides a closer look at how the program works at the hardware level.

### The Assembly language code is displayed.
![objdump using O1](https://github.com/user-attachments/assets/2c0ffa3e-1f74-4f6f-a0e0-ebe481fc9cfb)

**O1 Optimization**

![Objdump using Ofast](https://github.com/user-attachments/assets/6189df23-9da1-46e5-adcb-18d85c85d52e)

**Ofast Optimization** 
</details>

<details>
<summary><b>Task 2:</b> Task is to compile the C program using GCC and SPIKE compilers and verify both the compiler produces the same output and observe the performance under the -O1 and -Ofast compiler optimization flags, and to generate and collect the RISC-V object dump for both -O1 and -Ofast optimization.</summary>   
<br>

**C program to calculate factorial of number**
```
#include<stdio.h>
int fact(int n);
void main()
{
int digit = 25, factorial;
factorial = fact(digit);
printf("\n the factorial of the number %d is %d \n",digit,factorial);
}
int fact(int n)
{
if (n == 0 || n== 1)
return 1;
else
return(n* fact(n-1));
}
```

The code has to be simulated using both gcc and riscv compiler. Same output should be displayed on the terminal for both.

The commands used are as follows:

### For gcc compiler
```
gcc swap.c
./a.out
```
### For riscv compiler
```
spike pk swap.o
```
![gcc and spike output](https://github.com/user-attachments/assets/33518772-9e1b-403f-b0b0-69796f24c75e)

Object dump for C code using Ofast and O1

![Objdump using Ofast](https://github.com/user-attachments/assets/1fe955a2-e168-444c-9635-2fbe5b8f4888)

**Using Ofast**

![Objdump using O1](https://github.com/user-attachments/assets/c7fd357c-b231-4c59-96cf-782473a7cd0d)

**Using O1**

To debug the assembly language program use the following commands

1. To open the object dump
   ```
   riscv64-unknown-elf-objdump -d swap.o | less
   ```
2. To debug
   ```
   spike -d pk swap.o
   ```

The debugging operations are performed as follows
![Ofast complete](https://github.com/user-attachments/assets/abb9e8c4-8487-45f8-a0ff-2fda66e8c99b)
**Debugging -Ofast object dump file** 

![O1 complete](https://github.com/user-attachments/assets/adbafd8d-7609-4db6-9040-dfa4d397a4a0)
**Debugging -O1 object dump file**
</details>

  
<details>
<summary><b>Task 3:</b> Task is to identify 15 different instruction in the object dump file with its exact 32 bits instruction code in the desired instruction type format</summary>
  
## INSTRUCTIONS FORMAT IN RISC-V  
The instruction format of a processor defines how machine language instructions are structured and organized, enabling the processor to execute operations. It consists of binary patterns (0s and 1s) that specify the operation to be performed and the data or location involved.
There are 6 instruction formats in RISC-V:  
1. R(Register)-format 
2. I(Immediate)-format  
3. S(Store)-format  
4. B(Branch)-format  
5. U(Upper)-format  
6. J(Jump)-format

![RISCV Instruction Types](https://github.com/user-attachments/assets/cf2b535c-e9b5-46b9-9020-943223206153)

### *15 Different instructions and their 32 bits instruction code*  

------------------------------------------------

```
li a0, 0x21  
```  
> * Opcode for LI = 0010011  
> rd : a0 = 00001 
> rs1: x0 = 00000  
> imm[11:0]: 0x21 = 0000 0010 0001
> func3 = 000 

**32 bits instruction :** ```0000 0010 0001 | 00000| 000 | 00001 | 0010011``` 

------------------------------------------------

```
ADDI sp, sp, -16
```
> * Opcode for ADDI = 0010011  
> rd = sp = 00010  
> rs1 = sp = 00010  
> imm[11:0] = 5 = 1111 1111 0000  
> func3 = 000 

**32 bits instruction :** ```1111 1111 0000 | 00010 | 000 | 00010 | 0010011``` 
