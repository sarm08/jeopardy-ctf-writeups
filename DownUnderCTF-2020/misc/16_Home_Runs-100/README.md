# DownUnder CTF 2020: Misc: 16 Home Runs
</br>**Category:** Miscellaneous **Points:** 100 points
</br></br>
**Description:**</br>
How does this string relate to baseball in anyway? What even is baseball? And how does this relate to Cyber Security? ¯(ツ)/¯
> RFVDVEZ7MTZfaDBtM19ydW41X20zNG41X3J1bm4xbjZfcDQ1N182NF9iNDUzNX0=
</br>

## Solution
Looking at the string we can guess that's a base64 encoded string based on the equal sign '=' at the end.

```
$ echo -n RFVDVEZ7MTZfaDBtM19ydW41X20zNG41X3J1bm4xbjZfcDQ1N182NF9iNDUzNX0= | base64 -d
```
## FLag
> DUCTF{16_h0m3_run5_m34n5_runn1n6_p457_64_b4535}
