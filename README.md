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
<summary><b>Task 2:</b> Task is to Compile the C program  GCC and SPIKE compilers and verify both the compiler produces same output and observe the performance under the -O1 and -Ofast compiler optimization flags, and to generate and collect the RISC-V object dump for both -O1 and -Ofast optimization.</summary>   
<br>
