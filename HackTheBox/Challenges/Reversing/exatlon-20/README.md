# HTB-Challenges: Reversing: Exatlon
**Category:** Reverse Engineering **Points:** 20 points **Date:** 30/04/2020
</br>
**Zip Password:** hackthebox
**Flag format:** HTB{*some_text*}
</br>
**Description:**
Can you find the password?
</br>
## Write-up
```
$ file exatlon_v1
exatlon_v1: ELF 64-bit LSB executable, x86-64, version 1 (GNU/Linux), statically linked, BuildID[sha1]=99364060f1420e00a780745abcfa419af0b8b0d8, for GNU/Linux 3.2.0, not stripped
```

Let's open it with ghidra:
```cpp
ulong main(void)

{
  bool bVar1;
  basic_ostream *this;
  ulong unaff_R12;
  basic_string<char,std--char_traits<char>,std--allocator<char>> local_58 [32];
  basic_string<char,std--char_traits<char>,std--allocator<char>> local_38 [32];
  
  do {
    operator<<<std--char_traits<char>>((basic_ostream *)cout,"\n");
    operator<<<std--char_traits<char>>
              ((basic_ostream *)cout,
                              
               "âââââââââââ  âââ ââââââ ââââââââââââ      âââââââ ââââ   âââ       âââ   âââ âââ\n"
              );
    operator<<<std--char_traits<char>>
              ((basic_ostream *)cout,
                              
               "ââââââââââââââââââââââââââââââââââââ     ââââââââââââââ  âââ       âââ   âââââââ\n"
              );
    sleep(1);
    operator<<<std--char_traits<char>>((basic_ostream *)cout,&DAT_0054b1a8);
    operator<<<std--char_traits<char>>((basic_ostream *)cout,&DAT_0054b260);
    sleep(1);
    operator<<<std--char_traits<char>>((basic_ostream *)cout,&DAT_0054b320);
    sleep(1);
    operator<<<std--char_traits<char>>((basic_ostream *)cout,&DAT_0054b400);
    sleep(1);
    basic_string(local_58);
                    /* try { // try from 00404cfe to 00404dce has its CatchHandler @ 00404def */
    operator<<<std--char_traits<char>>((basic_ostream *)cout,"[+] Enter Exatlon Password  : ");
    operator>><char,std--char_traits<char>,std--allocator<char>>
              ((basic_istream *)cin,(basic_string *)local_58);
    exatlon((basic_string *)local_38);
    bVar1 = operator==<char,std--char_traits<char>,std--allocator<char>>
                      ((basic_string *)local_38,
                                              
                       "1152 1344 1056 1968 1728 816 1648 784 1584 816 1728 1520 1840 1664 784 1632 1856 1520 1728 816 1632 1856 1520 784 1760 1840 1824 816 1584 1856 784 1776 1760 528 528 2000"
                      );
    ~basic_string(local_38);
    if (bVar1 == false) {
      bVar1 = operator==<char,std--char_traits<char>,std--allocator<char>>
                        ((basic_string *)local_58,"q");
      if (bVar1 == false) {
        this = operator<<<std--char_traits<char>>((basic_ostream *)cout,"[-] ;(\n");
        operator<<((basic_ostream<char,std--char_traits<char>> *)this,
                   endl<char,std--char_traits<char>>);
        bVar1 = true;
      }
      else {
        unaff_R12 = 0;
        bVar1 = false;
      }
    }
    else {
      this = operator<<<std--char_traits<char>>((basic_ostream *)cout,"[+] Looks Good ^_^ \n\n\n");
      operator<<((basic_ostream<char,std--char_traits<char>> *)this,
                 endl<char,std--char_traits<char>>);
      unaff_R12 = 0;
      bVar1 = false;
    }
    ~basic_string(local_58);
  } while (bVar1);
  return unaff_R12 & 0xffffffff;
}
```
As we can observe, the program prints some ASCII art and then prompts us for a password. Stores our input in `local_38`, makes it an argument for function exatlon and then compares it with the string</br>
`"1152 1344 1056 1968 1728 816 1648 784 1584 816 1728 1520 1840 1664 784 1632 1856 1520 1728 816 1632 1856 1520 784 1760 1840 1824 816 1584 1856 784 1776 1760 528 528 2000"`

Let's see what exatlon() function does to our input:
```cpp
/* exatlon(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const&) */

basic_string * exatlon(basic_string *param_1)

{
  bool bVar1;
  char *pcVar2;
  basic_string<char,std--char_traits<char>,std--allocator<char>> *in_RSI;
  undefined8 local_80;
  undefined8 local_78;
  allocator<char> local_69;
  basic_string *local_68 [4];
  basic_string<char,std--char_traits<char>,std--allocator<char>> local_48 [39];
  char local_21;
  basic_string<char,std--char_traits<char>,std--allocator<char>> *local_20;
  
  allocator();
                    /* try { // try from 00404ae8 to 00404aec has its CatchHandler @ 00404bc1 */
  basic_string((char *)param_1,(allocator *)&DAT_0054b00c);
  ~allocator(&local_69);
  local_20 = in_RSI;
  local_78 = begin(in_RSI);
  local_80 = end(local_20);
  while( true ) {
    bVar1 = 
            operator!=<char_const*,std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>
                      ((__normal_iterator *)&local_78,(__normal_iterator *)&local_80);
    if (bVar1 == false) break;
    pcVar2 = (char *)operator*((
                                __normal_iterator<char_const*,std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>
                                *)&local_78);
    local_21 = *pcVar2;
                    /* try { // try from 00404b63 to 00404b67 has its CatchHandler @ 00404bfd */
    to_string((__cxx11 *)local_48,(int)local_21 << 4);
                    /* try { // try from 00404b7d to 00404b81 has its CatchHandler @ 00404bec */
    operator+<char,std--char_traits<char>,std--allocator<char>>(local_68,(char *)local_48);
                    /* try { // try from 00404b93 to 00404b97 has its CatchHandler @ 00404bdb */
    operator+=((basic_string<char,std--char_traits<char>,std--allocator<char>> *)param_1,
               (basic_string *)local_68);
    ~basic_string((basic_string<char,std--char_traits<char>,std--allocator<char>> *)local_68);
    ~basic_string(local_48);
    operator++((
                __normal_iterator<char_const*,std--__cxx11--basic_string<char,std--char_traits<char>,std--allocator<char>>>
                *)&local_78);
  }
  return param_1;
}
```
Exatlon iterates through our string, casts the character to int, left shifts by 4 every and then returns it as a string.
To reverse this we will use a python script that takes the string mentioned before, iterates through it, casts it to int, right shifts it by 4 and converts it to char:
```python
s = '1152 1344 1056 1968 1728 816 1648 784 1584 816 1728 1520 1840 1664 784 1632 1856 1520 1728 816 1632 1856 1520 784 1760 1840 1824 816 1584 1856 784 1776 1760 528 528 2000'
s = s.split(' ')

for i in s:
    print(chr(int(i) >> 4), end='')
```
And we get the flag:</br>
`HTB{l3g1c3l_sh1ft_l3ft_1nsr3ct1on!!}`
