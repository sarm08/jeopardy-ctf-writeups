
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
                              
               "███████╗██╗  ██╗ █████╗ ████████╗██╗      ██████╗ ███╗   ██╗       ██╗   ██╗ ██╗\n"
              );
    operator<<<std--char_traits<char>>
              ((basic_ostream *)cout,
                              
               "██╔════╝╚██╗██╔╝██╔══██╗╚══██╔══╝██║     ██╔═══██╗████╗  ██║       ██║   ██║�██║\n"
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
                                              
                       "1152 1344 1056 1968 1728 816 1648 784 1584 816 1728 1520 1840 1664 784 16321856 1520 1728 816 1632 1856 1520 784 1760 1840 1824 816 1584 1856 784 17761760 528 528 2000 "
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

�
