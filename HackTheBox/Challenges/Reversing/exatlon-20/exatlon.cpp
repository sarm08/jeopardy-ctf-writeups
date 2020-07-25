
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
