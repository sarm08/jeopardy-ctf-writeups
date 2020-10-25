# Dam CTF 2020: Misc: side-channel
</br>**Category:** Miscellaneous **Points:** 390 points
</br></br>
**Description:**</br>
We built a super-secure password checker. Can you guess what my password is?</br>
This challenge does NOT require brute forcing, you can get the flag with one connection.
> nc chals.damctf.xyz 30318

**Attachment:** [side-channel.py](side-channel.py) (sha256sum: 069e5ebc35212f23cedf148d614f6509b15c09bedfa777f8e15e1191444dd80c)

## Solution
#### The program:
```python
#!/usr/bin/env python3

import secrets
import codecs
import time

# init with dummy data
password = 'asdfzxcv'
sample_password = 'qwerasdf'


# print flag! call this!
def cat_flag():
    with open("./flag", 'rt') as f:
        print(f.read())

# initialize password
def init_password():
    global password
    global sample_password
    # seems super secure, right?
    password = "%08x" % secrets.randbits(32)
    sample_password = "%08x" % secrets.randbits(32)

# convert hex char to a number
# '0' = 0, 'f' = 15, '9' = 9...
def charactor_position_in_hex(c):
    string = "0123456789abcdef"
    return string.find(c[0])

# the function that matters..
def guess_password(s):
    print("Password guessing %s" % s)
    typed_password = ''
    correct_password = True
    for i in range(len(password)):
        user_guess = input("Guess character at position password[%d] = %s?\n" \
                % (i, typed_password))
        typed_password += user_guess
        if user_guess != password[i]:
            # we will punish the users for supplying wrong char..
            time.sleep(0.1 * charactor_position_in_hex(password[i]))
            correct_password = False

    # to get the flag, please supply all 8 correct characters for the password..
    if correct_password:
        cat_flag()

    return correct_password

# main function!
def main():
    init_password()
    print("Can you tell me what my password is?")
    print("We randomly generated 8 hexadecimal digit password (e.g., %s)" % sample_password)
    print("so please guess the password character by character.")
    print("You have only 2 chances to test your guess...")
    guess_password("Trial 1")
    if not guess_password("Trial 2"):
        print("My password was %s" % password)

if __name__ == '__main__':
    main()
```

We have two attempts to guess the password, the password is 8 hexadecimal digits long. The program checks every digit, if it's wrong, the program sleeps for 0.1* right_digit seconds.

#### The plan:
In our first attempt, we send 'qqqqqqqq' as the password, note that the right password only has '0123456789abcdef' characters in it, so we will fail for every character, make the program go to sleep.</br>
So, if we calculate the time between when we send the character, until the program sends us a response we will be able to calculate the right charater and send it in our second attempt.

#### The exploit:
```python
from pwn import *

local = False

if local:
    p = process('./side-channel.py')
else:
    p = remote('chals.damctf.xyz', 30318)

alphabet = '0123456789abcdef'
password = ''
p.recvuntil('Guess character at position password[0] = ?\n')
for i in range(0,8):
    p.sendline('q')
    start_time = time.time()
    p.recvline()
    elapsed_time = time.time() - start_time
    print(elapsed_time)
    password += alphabet[int(elapsed_time * 10)-1]

print('password is '+password)

for i in range(0,8):
    p.sendline(password[i])
    print(p.recvline())

p.interactive()
```

## Flag
> dam{d0nT_d3l4y_th3_pRoC3sSiNg}
