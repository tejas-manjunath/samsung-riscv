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
lui a0, 0x21  
```  
> * Opcode for LUI = 0110111
>   
> * rd = a0 = 00001
> 
> * imm[19:0] = 0x21 = 0000 0000 0000 0010 0001

**32 bits instruction :** ```00000000000000100001_00001_0110111``` 

------------------------------------------------

```
li a1, 50  
```  
> * Opcode for LI = 0010011
>   
> * rd = a1 = 00001
>  
> * rs1 = x0 = 00000
>  
> * imm[11:0] = 50 = 0000 0011 0010
> 
> * func3 = 000 

**32 bits instruction :** ```000000110010_00000_000_00001_0010011``` 

------------------------------------------------

```
addi sp, sp, -16
```
> * Opcode for ADDI = 0010011
>   
> * rd = sp = 00010
> 
> * rs1 = sp = 00010
> 
> * imm[11:0] = 5 = 1111 1111 0000
> 
> * func3 = 000 

**32 bits instruction :** ```111111110000_00010_000_00010_0010011``` 

------------------------------------------------

```
sd ra, 8(sp) 
```
> * Opcode for SD = 0100011
>   
> * rs2 = sp = 00010
>
> * rs1 = ra = 00001
> 
> * imm[11:0] = 8 = 0000 0000 1000
>   
> * func3 = 011

**32 bits instruction :** ```0000000_00010_00001_011_01000_0100011``` 

------------------------------------------------

```
jal ra,10408 <printf>  
```  
> * Opcode for JAL = 1101111
>   
> * rd = ra = 00001
> 
> * imm[19:0] = 0x21 =  0000 0010 1000 1010 1000

**32 bits instruction :** ```00010101000000000101_00001_0110111``` 

------------------------------------------------

```
ld ra, 8(sp) 
```
> * Opcode for LD = 0000011
>   
> * rs2 = sp = 00010
> 
> * rs1 = ra = 00001
> 
> * imm[11:0] = 8 = 0000 0000 1000
> 
> * func3 = 011

**32 bits instruction :** ```000000001000_00001_011_00010_0000011``` 

------------------------------------------------

```
ret 
```
> * Opcode for RET = 1100111 
>   
> * rd = 0 = 00000
> 
> * rs1 = ra = 00001
> 
> * imm[11:0] = 0 = 0000 0000 0000
> 
> * func3 = 000

**32 bits instruction :** ```000000000000_00001_000_00000_1100111``` 

------------------------------------------------

```
auipc a5, 0xffff0 
```  
> * Opcode for AUIPC = 0010111
>   
> * rd = a5 = 00101
> 
> * imm[31:12] = 0xFFFF0 = 1111 1111 1111 0000 0000

**32 bits instruction :** ```11111111111100000000_00101_0010111``` 

------------------------------------------------

```
beqz a5, 100f4
```
> * Opcode for BEQZ = 1100011
>   
> * rs2 = x0 = 00000
> 
> * rs1 = a5 = 00101
> 
> * imm[11:0] = 8 = 0000 1111 0100
> 
> * func3 = 000

**32 bits instruction :** ```0001111_00000_00101_000_0100_0_1100011``` 

------------------------------------------------

```
j 101b0 
```  
> * Opcode for J = 1101111
>   
> * rd = x0 = 00000 
> 
> * imm[19:0] = 0x101b0 =  0001 0000 0001 1011 0000

**32 bits instruction :** ```0_0110110000_0_00100000_00000_1101111``` 

------------------------------------------------

```
sub a2, a2, a0
```  
> * Opcode for SUB = 0110011
>   
> * rd = a2 = 00010
>   
> * rs1 = a0 = 00001
>   
> * rs2 = a2 = 00010
>   
> * func3 = 000
>   
> func7 = 0100000

**32 bits instruction :** ```0100000_00010_00001_000_00010_0110011``` 

------------------------------------------------

```
lw a0, 0(sp)
```
> * Opcode for LW = 0000011
>   
> * rd = a0 = 01010
> 
> * rs1 = sp = 00010
> 
> * imm[11:0] = 8 = 0000 0000 0000
> 
> * func3 = 010

**32 bits instruction :** ```000000000000_00010_010_01010_0000011``` 

------------------------------------------------

```
mv a1,a0
```
> * Opcode for MV = 0010011
>   
> * rd = a1 = 01011
> 
> * rs1 = a0 = 01010
> 
> * imm[11:0] = 0 = 0000 0000 0000
> 
> * func3 = 000

**32 bits instruction :** ```000000000000_01010_000_01011_0010011``` 

------------------------------------------------

```
jr #0 <main-0x100b0>
```
> * Opcode for JR = 1100111
>   
> * rd = x0 = 00000
> 
> * imm[20:1] = 0 = 0000 0000 0000 0000 0000

**32 bits instruction :** ```00000000000000000000_00000_1100111``` 

------------------------------------------------

```
sb a5, 1944(gp)
```
> * Opcode for SB = 0100011
>   
> * rs2 = a5 = 01111
> 
> * rs1 = gp = 00011
> 
> * imm[11:0] = 0 = 0111 1001 1000
> 
> * func3 = 000

**32 bits instruction :** ```0111100_01111_00011_000_11000_0100011``` 

------------------------------------------------

</details>


<details>
<summary><b>Task 4:</b> By making use of RISCV Core: Verilog Netlist and Testbench, perform an experiment of Functional Simulation and observe the waveforms</summary>  
<br>

>***NOTE:** Since the designing of RISCV Architecture and writing it's testbench is not the part of this Research Internship, so we will use the Verilog Code and Testbench of RISCV that has already been designed. The reference GitHub repository is : [iiitb_rv32i](https://github.com/vinayrayapati/rv32i/)*    
  
### Steps to perform functional simulation of RISCV  
1. Create a new directory with your name ```mkdir <your_name>```
2. Create two files by using ```touch``` command as ```tejas_rv32i.v``` and ```tejas_rv32i_tb.v```  
3. Copy the code from the reference github repo and paste it in your verilog and testbench files  
  
  
4. To run and simulate the verilog code, enter the following command:  
	```
	$ iverilog -o Tejas tejas_rv32i.v tejas_rv32i_tb.v
	$ ./Tejas
	```
5. To see the simulation waveform in GTKWave, enter the following command:
	```
	$ gtkwave tejas_rv32i.vcd
	```


6. The GTKWave will be opened and following window will be appeared  
  
![4](https://github.com/user-attachments/assets/18e4242c-7bd2-4994-ac23-0e653dbd0b8d)

 
#### As shown in the figure below, all the instructions in the given verilog file is hard-coded. Hard-coded means that instead of following the RISCV specifications bit pattern, the designer has hard-coded each instructions based on their own pattern. Hence the 32-bits instruction that we generated in Task-2 will not match with the given instruction.  
  
<img width="500" alt="Instructions" src="https://github.com/user-attachments/assets/34570419-881d-4c8b-b2c3-a6e80279b566">
  
#### Following are the differences between standard RISCV ISA and the Instruction Set given in the reference repository:  
  
|  **Operation**  |  **Standard RISCV ISA**  |  **Hardcoded ISA**  |  
|  :----:  |  :----:  |  :----:  |  
|  ADD R6, R2, R1  |  32'h00110333  |  32'h02208300  |  
|  SUB R7, R1, R2  |  32'h402083b3  |  32'h02209380  |  
|  AND R8, R1, R3  |  32'h0030f433  |  32'h0230a400  |  
|  OR R9, R2, R5  |  32'h005164b3  |  32'h02513480  |  
|  XOR R10, R1, R4  |  32'h0040c533  |  32'h0240c500  |  
|  SLT R1, R2, R4  |  32'h0045a0b3  |  32'h02415580  |  
|  ADDI R12, R4, 5  |  32'h004120b3  |  32'h00520600  |  
|  BEQ R0, R0, 15  |  32'h00000f63  |  32'h00f00002  |  
|  SW R3, R1, 2  |  32'h0030a123  |  32'h00209181  |  
|  LW R13, R1, 2  |  32'h0020a683  |  32'h00208681  |  
|  SRL R16, R14, R2  |  32'h0030a123  |  32'h00271803  |
|  SLL R15, R1, R2  |  32'h002097b3  |  32'h00208783  |   
  

#### *Analysing the Output Waveform of various instructions that we have covered in TASK-2*  
**```Instruction 1: ADD R6, R2, R1```**  
  
![add](https://github.com/user-attachments/assets/24709cd8-0dfa-487a-94a8-dae6a344caf2)


**```Instruction 2: SUB R7, R1, R2```**  

![sub](https://github.com/user-attachments/assets/04b1dfb7-b3b9-46f5-8b3f-7b404b11a43e)


**```Instruction 3: AND R8, R1, R3```**  

![and](https://github.com/user-attachments/assets/82f52967-fcbd-4ffc-b9d8-823ff6fdcb63)


**```Instruction 4: OR R9, R2, R5```**  

![or](https://github.com/user-attachments/assets/af1f2d16-18b7-4473-b875-39ca98aae187)


**```Instruction 5: XOR R10, R1, R4```**  

![xor](https://github.com/user-attachments/assets/4a9da356-7b2d-4270-9d32-b841d625cb95)


**```Instruction 6: SLT R1, R2, R4```**  

![SLT](https://github.com/user-attachments/assets/59db4dc7-613f-456a-be7c-6b67605ee811)


**```Instruction 7: ADDI R12, R4, 5```**  

![addi](https://github.com/user-attachments/assets/d572f42e-857e-44e9-bb57-5f181e508e12)


**```Instruction 8: BEQ R0, R0, 15```**  
  
![BEQ](https://github.com/user-attachments/assets/005112a3-8571-41ad-9f83-5cf8cfadc7d1)

 
**```Instruction 9: SW R3, R1, 2```**

![SW](https://github.com/user-attachments/assets/5190c5e1-ef7e-460e-9d8d-c51520b3e288)

  
**```Instruction 10: LW r13, г1, 2.```**  

![LW](https://github.com/user-attachments/assets/976ca115-b958-4ad3-81ac-724c307fae4d)


</details>  

--------------------------------------------------------------- 
