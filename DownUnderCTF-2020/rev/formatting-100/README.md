# DownUnder CTF 2020: Rev: Formatting
</br>**Category:** Reverse Engineering **Points:** 100 points
</br></br>
**Description:**</br>
Its really easy, I promise.
</br>
**Attachment:**
[formatting](formatting) (sha256sum: 2750d3a0f0fd094ac4f16b026c62536be92c535d6eb858fef9be736f2e95c60a)

## Solution
```
$ file formatting
formatting: ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=bd9f51c1f1535b269a0707054009063f984f6738, for GNU/Linux 3.2.0, not stripped
```

Let's run it and see what it does:
```
$ ./formatting
haha its not that easy}
```

Let's examine with ltrace:
```
$ ltrace ./formatting
sprintf("d1d_You_Just_ltrace_296faa2990ac"..., "%s%02x%02x%02x%02x%02x%02x%02x%0"..., "d1d_You_Just_ltrace_", 0x29, 0x6f, 0xaa, 0x29, 0x90, 0xac, 0xbc, 0x36) = 37
puts("haha its not that easy}"haha its not that easy}
)                                                                         = 24
+++ exited (status 0) +++
```
It looks like sprintf string isn't complete, let's add the -s flag to ltrace so that the maximum string size is bigger.
```
$ ltrace -s 200 ./formatting
sprintf("d1d_You_Just_ltrace_296faa2990acbc36}", "%s%02x%02x%02x%02x%02x%02x%02x%02x}", "d1d_You_Just_ltrace_", 0x29, 0x6f, 0xaa, 0x29, 0x90, 0xac, 0xbc, 0x36) = 37
puts("haha its not that easy}"haha its not that easy}
)                                                                         = 24
+++ exited (status 0) +++

```
And now we have the entire flag.

## Flag
> DUCTF{d1d_You_Just_ltrace_296faa2990acbc36}
