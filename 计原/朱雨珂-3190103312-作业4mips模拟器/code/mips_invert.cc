bplist00?XUTI-Data?	
_public.utf16-plain-textZpublic.rtf_ public.utf16-external-plain-text_public.utf8-plain-text_$com.apple.traditional-mac-plain-textO?# i n c l u d e " m i p s _ i n v e r t . h "   M i p s I n v e r t : : M i p s I n v e r t ( s t r i n g   p a t h ) {          i f s t r e a m   i f s ( p a t h ) ;          i n f o   t m p ;          w h i l e   ( ! i f s . e o f ( ) )   {                  i f s   > >   t m p . t y p e   > >   t m p . n a m e   > >   t m p . o p ;                  i f   ( t m p . t y p e   = =   " R " )                          r _ . p u s h _ b a c k ( t m p ) ;                  e l s e   i f   ( t m p . t y p e   = =   " I " )                          i _ . p u s h _ b a c k ( t m p ) ;                  e l s e                          j _ . p u s h _ b a c k ( t m p ) ;          }          i f s . c l o s e ( ) ;          s o r t ( r _ . b e g i n ( )   ,   r _ . e n d ( )   ,   c m p ) ;          s o r t ( i _ . b e g i n ( )   ,   i _ . e n d ( )   ,   c m p ) ;          s o r t ( j _ . b e g i n ( )   ,   j _ . e n d ( )   ,   c m p ) ;  }   v o i d   M i p s I n v e r t : : C o n v e r t ( s t r i n g   p a t h 1   ,   s t r i n g   p a t h 2 ) {          i f s t r e a m   i f s ( p a t h 1 ) ;          o f s t r e a m   o f s ( p a t h 2 ) ;          w h i l e   ( ! i f s . e o f ( ) )   {                  s t r i n g   s ;                  i f s   > >   s ;                  s t r i n g   o p   =   s . s u b s t r ( 0   ,   6 ) ;                  i f   ( o p   = =   " 0 0 0 0 0 0 " )   {                          s t r i n g   i n s t r u c t o r _ n a m e   =   B i n a r y S e a r c h ( r _   ,   s . s u b s t r ( 2 6   ,   6 ) ) ;                          s t r i n g   r s   ,   r t   ,   r d   ,   s h a m t ;                          r s   =   s . s u b s t r ( 6   ,   5 ) ;                          r t   =   s . s u b s t r ( 1 1   ,   5 ) ;                          r d   =   s . s u b s t r ( 1 6   ,   5 ) ;                          s h a m t   =   s . s u b s t r ( 2 1   ,   5 ) ;                          o f s   < <   i n s t r u c t o r _ n a m e   < <   "   $ " ;                          i f   ( i n s t r u c t o r _ n a m e   = =   " s l l "   | |   i n s t r u c t o r _ n a m e   = =   " s r l "   | |   i n s t r u c t o r _ n a m e   = =   " s r a " )                                  o f s   < <   B i n a r y S t r i n g T o I n t ( r d )   < <   " , $ "   < <   B i n a r y S t r i n g T o I n t ( r t )   < <   " , "   < <   B i n a r y S t r i n g T o I n t ( s h a m t )   < <   e n d l ;                          e l s e   i f   ( i n s t r u c t o r _ n a m e   = =   " s l l v "   | |   i n s t r u c t o r _ n a m e   = =   " s r l v "   | |   i n s t r u c t o r _ n a m e   = =   " s r a v " )                                  o f s   < <   B i n a r y S t r i n g T o I n t ( r d )   < <   " , $ "   < <   B i n a r y S t r i n g T o I n t ( r t )   < <   " , $ "   < <   B i n a r y S t r i n g T o I n t ( r s )   < <   e n d l ;                          e l s e   i f   ( i n s t r u c t o r _ n a m e   = =   " j r " )                                  o f s   < <   B i n a r y S t r i n g T o I n t ( r s )   < <   e n d l ;                          e l s e                                  o f s   < <   B i n a r y S t r i n g T o I n t ( r d )   < <   " , $ "   < <   B i n a r y S t r i n g T o I n t ( r s )   < <   " , $ "   < <   B i n a r y S t r i n g T o I n t ( r t )   < <   e n d l ;                  }                  e l s e   i f   ( o p   = =   " 0 0 0 0 1 0 "   | |   o p   = =   " 0 0 0 0 1 1 " )   {                          s t r i n g   i n s t r u c t o r _ n a m e   =   B i n a r y S e a r c h ( j _   ,   o p ) ;                          s t r i n g   a d d r e s s   =   s . s u b s t r ( 6   ,   2 6 ) ;                          o f s   < <   i n s t r u c t o r _ n a m e   < <   "   "   < <   B i n a r y S t r i n g T o I n t ( a d d r e s s )   < <   e n d l ;                  }                  e l s e   {                          s t r i n g   i n s t r u c t o r _ n a m e   =   B i n a r y S e a r c h ( i _   ,   o p ) ;                          s t r i n g   r s   ,   r t   ,   i m m e d i a t e ;                          r s   =   s . s u b s t r ( 6   ,   5 ) ;                          r t   =   s . s u b s t r ( 1 1   ,   5 ) ;                          i m m e d i a t e   =   s . s u b s t r ( 1 6   ,   1 6 ) ;                          o f s   < <   i n s t r u c t o r _ n a m e   < <   "   $ " ;                          i f   ( i n s t r u c t o r _ n a m e   = =   " l u i " )                                  o f s   < <   B i n a r y S t r i n g T o I n t ( r t )   < <   " , "   < <   B i n a r y S t r i n g T o I n t ( i m m e d i a t e )   < <   e n d l ;                          e l s e   i f   ( i n s t r u c t o r _ n a m e   = =   " l w "   | |   i n s t r u c t o r _ n a m e   = =   " s w " )                                  o f s   < <   B i n a r y S t r i n g T o I n t ( r t )   < <   " , "   < <   B i n a r y S t r i n g T o I n t ( i m m e d i a t e )   < <   " ( $ "   < <   B i n a r y S t r i n g T o I n t ( r s )   < <   " ) "   < <   e n d l ;                          e l s e   i f   ( i n s t r u c t o r _ n a m e   = =   " b e q "   | |   i n s t r u c t o r _ n a m e   = =   " b n e " )                                  o f s   < <   B i n a r y S t r i n g T o I n t ( r s )   < <   " , $ "   < <   B i n a r y S t r i n g T o I n t ( r t )   < <   " , "   < <   B i n a r y S t r i n g T o I n t ( i m m e d i a t e )   < <   e n d l ;                          e l s e                                  o f s   < <   B i n a r y S t r i n g T o I n t ( r t )   < <   " , $ "   < <   B i n a r y S t r i n g T o I n t ( r s )   < <   " , "   < <   B i n a r y S t r i n g T o I n t ( i m m e d i a t e )   < <   e n d l ;                  }          }           i f s . c l o s e ( ) ;          o f s . c l o s e ( ) ;  }   b o o l   M i p s I n v e r t : : c m p ( i n f o   a   ,   i n f o   b ) {          r e t u r n   a . o p   <   b . o p ;  }   s t r i n g   M i p s I n v e r t : : B i n a r y S e a r c h ( c o n s t   v e c t o r < i n f o >   & v   ,   s t r i n g   s ) {          i n t   s t a r t   =   0   ,   e n d   =   v . s i z e ( )   -   1 ;          w h i l e ( s t a r t   < =   e n d ) {                  i n t   m i d   =   ( s t a r t   +   e n d )   /   2 ;                  i f   ( v [ m i d ] . o p   = =   s )                          r e t u r n   v [ m i d ] . n a m e ;                  e l s e   i f   ( v [ m i d ] . o p   <   s )                          s t a r t   =   m i d   +   1 ;                  e l s e                          e n d   =   m i d   -   1 ;          }          r e t u r n   " " ;  }   i n t   M i p s I n v e r t : : B i n a r y S t r i n g T o I n t ( s t r i n g   s ) {          i n t   r e s   =   0 ;          f o r   ( i n t   i   =   0 ;   i   <   s . l e n g t h ( ) ; + + i ) {                  r e s   =   r e s   *   2   +   ( s [ i ]   -   ' 0 ' ) ;          }          r e t u r n   r e s ;  }    _?{\rtf1\ansi\ansicpg936\cocoartf2636
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red255\green255\blue255;\red196\green26\blue22;
\red0\green0\blue0;\red15\green104\blue160;\red155\green35\blue147;\red28\green0\blue207;}
{\*\expandedcolortbl;;\csgenericrgb\c39147\c22031\c12446;\csgenericrgb\c100000\c100000\c100000;\csgenericrgb\c77000\c10200\c8600;
\csgenericrgb\c0\c0\c0\c85000;\csgenericrgb\c5882\c40784\c62745;\csgenericrgb\c60759\c13753\c57628;\csgenericrgb\c11000\c0\c81000;}
\deftab593
\pard\tx593\pardeftab593\pardirnatural\partightenfactor0

\f0\fs24 \cf2 \cb3 #include\cf4 "mips_invert.h"\cf5 \
\
\cf6 MipsInvert\cf5 ::\cf6 MipsInvert\cf5 (string path)\{\
    ifstream ifs(path);\
    info tmp;\
    
\f1\b \cf7 while
\f0\b0 \cf5  (!ifs.eof()) \{\
        ifs >> tmp.type >> tmp.name >> tmp.op;\
        
\f1\b \cf7 if
\f0\b0 \cf5  (tmp.type == \cf4 "R"\cf5 )\
            r_.push_back(tmp);\
        
\f1\b \cf7 else
\f0\b0 \cf5  
\f1\b \cf7 if
\f0\b0 \cf5  (tmp.type == \cf4 "I"\cf5 )\
            i_.push_back(tmp);\
        
\f1\b \cf7 else
\f0\b0 \cf5 \
            j_.push_back(tmp);\
    \}\
    ifs.close();\
    sort(r_.begin() , r_.end() , cmp);\
    sort(i_.begin() , i_.end() , cmp);\
    sort(j_.begin() , j_.end() , cmp);\
\}\
\

\f1\b \cf7 void
\f0\b0 \cf5  \cf6 MipsInvert\cf5 ::\cf6 Convert\cf5 (string path1 , string path2)\{\
    ifstream ifs(path1);\
    ofstream ofs(path2);\
    
\f1\b \cf7 while
\f0\b0 \cf5  (!ifs.eof()) \{\
        string s;\
        ifs >> s;\
        string op = s.substr(\cf8 0\cf5  , \cf8 6\cf5 );\
        
\f1\b \cf7 if
\f0\b0 \cf5  (op == \cf4 "000000"\cf5 ) \{\
            string instructor_name = BinarySearch(r_ , s.substr(\cf8 26\cf5  , \cf8 6\cf5 ));\
            string rs , rt , rd , shamt;\
            rs = s.substr(\cf8 6\cf5  , \cf8 5\cf5 );\
            rt = s.substr(\cf8 11\cf5  , \cf8 5\cf5 );\
            rd = s.substr(\cf8 16\cf5  , \cf8 5\cf5 );\
            shamt = s.substr(\cf8 21\cf5  , \cf8 5\cf5 );\
            ofs << instructor_name << \cf4 " $"\cf5 ;\
            
\f1\b \cf7 if
\f0\b0 \cf5  (instructor_name == \cf4 "sll"\cf5  || instructor_name == \cf4 "srl"\cf5  || instructor_name == \cf4 "sra"\cf5 )\
                ofs << BinaryStringToInt(rd) << \cf4 ",$"\cf5  << BinaryStringToInt(rt) << \cf4 ","\cf5  << BinaryStringToInt(shamt) << endl;\
            
\f1\b \cf7 else
\f0\b0 \cf5  
\f1\b \cf7 if
\f0\b0 \cf5  (instructor_name == \cf4 "sllv"\cf5  || instructor_name == \cf4 "srlv"\cf5  || instructor_name == \cf4 "srav"\cf5 )\
                ofs << BinaryStringToInt(rd) << \cf4 ",$"\cf5  << BinaryStringToInt(rt) << \cf4 ",$"\cf5  << BinaryStringToInt(rs) << endl;\
            
\f1\b \cf7 else
\f0\b0 \cf5  
\f1\b \cf7 if
\f0\b0 \cf5  (instructor_name == \cf4 "jr"\cf5 )\
                ofs << BinaryStringToInt(rs) << endl;\
            
\f1\b \cf7 else
\f0\b0 \cf5 \
                ofs << BinaryStringToInt(rd) << \cf4 ",$"\cf5  << BinaryStringToInt(rs) << \cf4 ",$"\cf5  << BinaryStringToInt(rt) << endl;\
        \}\
        
\f1\b \cf7 else
\f0\b0 \cf5  
\f1\b \cf7 if
\f0\b0 \cf5  (op == \cf4 "000010"\cf5  || op == \cf4 "000011"\cf5 ) \{\
            string instructor_name = BinarySearch(j_ , op);\
            string address = s.substr(\cf8 6\cf5  , \cf8 26\cf5 );\
            ofs << instructor_name << \cf4 " "\cf5  << BinaryStringToInt(address) << endl;\
        \}\
        
\f1\b \cf7 else
\f0\b0 \cf5  \{\
            string instructor_name = BinarySearch(i_ , op);\
            string rs , rt , immediate;\
            rs = s.substr(\cf8 6\cf5  , \cf8 5\cf5 );\
            rt = s.substr(\cf8 11\cf5  , \cf8 5\cf5 );\
            immediate = s.substr(\cf8 16\cf5  , \cf8 16\cf5 );\
            ofs << instructor_name << \cf4 " $"\cf5 ;\
            
\f1\b \cf7 if
\f0\b0 \cf5  (instructor_name == \cf4 "lui"\cf5 )\
                ofs << BinaryStringToInt(rt) << \cf4 ","\cf5  << BinaryStringToInt(immediate) << endl;\
            
\f1\b \cf7 else
\f0\b0 \cf5  
\f1\b \cf7 if
\f0\b0 \cf5  (instructor_name == \cf4 "lw"\cf5  || instructor_name == \cf4 "sw"\cf5 )\
                ofs << BinaryStringToInt(rt) << \cf4 ","\cf5  << BinaryStringToInt(immediate) << \cf4 "($"\cf5  << BinaryStringToInt(rs) << \cf4 ")"\cf5  << endl;\
            
\f1\b \cf7 else
\f0\b0 \cf5  
\f1\b \cf7 if
\f0\b0 \cf5  (instructor_name == \cf4 "beq"\cf5  || instructor_name == \cf4 "bne"\cf5 )\
                ofs << BinaryStringToInt(rs) << \cf4 ",$"\cf5  << BinaryStringToInt(rt) << \cf4 ","\cf5  << BinaryStringToInt(immediate) << endl;\
            
\f1\b \cf7 else
\f0\b0 \cf5 \
                ofs << BinaryStringToInt(rt) << \cf4 ",$"\cf5  << BinaryStringToInt(rs) << \cf4 ","\cf5  << BinaryStringToInt(immediate) << endl;\
        \}\
    \}\
\
    ifs.close();\
    ofs.close();\
\}\
\

\f1\b \cf7 bool
\f0\b0 \cf5  \cf6 MipsInvert\cf5 ::\cf6 cmp\cf5 (info a , info b)\{\
    
\f1\b \cf7 return
\f0\b0 \cf5  a.op < b.op;\
\}\
\
string \cf6 MipsInvert\cf5 ::\cf6 BinarySearch\cf5 (
\f1\b \cf7 const
\f0\b0 \cf5  vector<info> &v , string s)\{\
    
\f1\b \cf7 int
\f0\b0 \cf5  start = \cf8 0\cf5  , end = v.size() - \cf8 1\cf5 ;\
    
\f1\b \cf7 while
\f0\b0 \cf5 (start <= end)\{\
        
\f1\b \cf7 int
\f0\b0 \cf5  mid = (start + end) / \cf8 2\cf5 ;\
        
\f1\b \cf7 if
\f0\b0 \cf5  (v[mid].op == s)\
            
\f1\b \cf7 return
\f0\b0 \cf5  v[mid].name;\
        
\f1\b \cf7 else
\f0\b0 \cf5  
\f1\b \cf7 if
\f0\b0 \cf5  (v[mid].op < s)\
            start = mid + \cf8 1\cf5 ;\
        
\f1\b \cf7 else
\f0\b0 \cf5 \
            end = mid - \cf8 1\cf5 ;\
    \}\
    
\f1\b \cf7 return
\f0\b0 \cf5  \cf4 ""\cf5 ;\
\}\
\

\f1\b \cf7 int
\f0\b0 \cf5  \cf6 MipsInvert\cf5 ::\cf6 BinaryStringToInt\cf5 (string s)\{\
    
\f1\b \cf7 int
\f0\b0 \cf5  res = \cf8 0\cf5 ;\
    
\f1\b \cf7 for
\f0\b0 \cf5  (
\f1\b \cf7 int
\f0\b0 \cf5  i = \cf8 0\cf5 ; i < s.length();++i)\{\
        res = res * \cf8 2\cf5  + (s[i] - \cf8 '0'\cf5 );\
    \}\
    
\f1\b \cf7 return
\f0\b0 \cf5  res;\
\}\
\
\
}O???# i n c l u d e " m i p s _ i n v e r t . h " 
 
 M i p s I n v e r t : : M i p s I n v e r t ( s t r i n g   p a t h ) { 
         i f s t r e a m   i f s ( p a t h ) ; 
         i n f o   t m p ; 
         w h i l e   ( ! i f s . e o f ( ) )   { 
                 i f s   > >   t m p . t y p e   > >   t m p . n a m e   > >   t m p . o p ; 
                 i f   ( t m p . t y p e   = =   " R " ) 
                         r _ . p u s h _ b a c k ( t m p ) ; 
                 e l s e   i f   ( t m p . t y p e   = =   " I " ) 
                         i _ . p u s h _ b a c k ( t m p ) ; 
                 e l s e 
                         j _ . p u s h _ b a c k ( t m p ) ; 
         } 
         i f s . c l o s e ( ) ; 
         s o r t ( r _ . b e g i n ( )   ,   r _ . e n d ( )   ,   c m p ) ; 
         s o r t ( i _ . b e g i n ( )   ,   i _ . e n d ( )   ,   c m p ) ; 
         s o r t ( j _ . b e g i n ( )   ,   j _ . e n d ( )   ,   c m p ) ; 
 } 
 
 v o i d   M i p s I n v e r t : : C o n v e r t ( s t r i n g   p a t h 1   ,   s t r i n g   p a t h 2 ) { 
         i f s t r e a m   i f s ( p a t h 1 ) ; 
         o f s t r e a m   o f s ( p a t h 2 ) ; 
         w h i l e   ( ! i f s . e o f ( ) )   { 
                 s t r i n g   s ; 
                 i f s   > >   s ; 
                 s t r i n g   o p   =   s . s u b s t r ( 0   ,   6 ) ; 
                 i f   ( o p   = =   " 0 0 0 0 0 0 " )   { 
                         s t r i n g   i n s t r u c t o r _ n a m e   =   B i n a r y S e a r c h ( r _   ,   s . s u b s t r ( 2 6   ,   6 ) ) ; 
                         s t r i n g   r s   ,   r t   ,   r d   ,   s h a m t ; 
                         r s   =   s . s u b s t r ( 6   ,   5 ) ; 
                         r t   =   s . s u b s t r ( 1 1   ,   5 ) ; 
                         r d   =   s . s u b s t r ( 1 6   ,   5 ) ; 
                         s h a m t   =   s . s u b s t r ( 2 1   ,   5 ) ; 
                         o f s   < <   i n s t r u c t o r _ n a m e   < <   "   $ " ; 
                         i f   ( i n s t r u c t o r _ n a m e   = =   " s l l "   | |   i n s t r u c t o r _ n a m e   = =   " s r l "   | |   i n s t r u c t o r _ n a m e   = =   " s r a " ) 
                                 o f s   < <   B i n a r y S t r i n g T o I n t ( r d )   < <   " , $ "   < <   B i n a r y S t r i n g T o I n t ( r t )   < <   " , "   < <   B i n a r y S t r i n g T o I n t ( s h a m t )   < <   e n d l ; 
                         e l s e   i f   ( i n s t r u c t o r _ n a m e   = =   " s l l v "   | |   i n s t r u c t o r _ n a m e   = =   " s r l v "   | |   i n s t r u c t o r _ n a m e   = =   " s r a v " ) 
                                 o f s   < <   B i n a r y S t r i n g T o I n t ( r d )   < <   " , $ "   < <   B i n a r y S t r i n g T o I n t ( r t )   < <   " , $ "   < <   B i n a r y S t r i n g T o I n t ( r s )   < <   e n d l ; 
                         e l s e   i f   ( i n s t r u c t o r _ n a m e   = =   " j r " ) 
                                 o f s   < <   B i n a r y S t r i n g T o I n t ( r s )   < <   e n d l ; 
                         e l s e 
                                 o f s   < <   B i n a r y S t r i n g T o I n t ( r d )   < <   " , $ "   < <   B i n a r y S t r i n g T o I n t ( r s )   < <   " , $ "   < <   B i n a r y S t r i n g T o I n t ( r t )   < <   e n d l ; 
                 } 
                 e l s e   i f   ( o p   = =   " 0 0 0 0 1 0 "   | |   o p   = =   " 0 0 0 0 1 1 " )   { 
                         s t r i n g   i n s t r u c t o r _ n a m e   =   B i n a r y S e a r c h ( j _   ,   o p ) ; 
                         s t r i n g   a d d r e s s   =   s . s u b s t r ( 6   ,   2 6 ) ; 
                         o f s   < <   i n s t r u c t o r _ n a m e   < <   "   "   < <   B i n a r y S t r i n g T o I n t ( a d d r e s s )   < <   e n d l ; 
                 } 
                 e l s e   { 
                         s t r i n g   i n s t r u c t o r _ n a m e   =   B i n a r y S e a r c h ( i _   ,   o p ) ; 
                         s t r i n g   r s   ,   r t   ,   i m m e d i a t e ; 
                         r s   =   s . s u b s t r ( 6   ,   5 ) ; 
                         r t   =   s . s u b s t r ( 1 1   ,   5 ) ; 
                         i m m e d i a t e   =   s . s u b s t r ( 1 6   ,   1 6 ) ; 
                         o f s   < <   i n s t r u c t o r _ n a m e   < <   "   $ " ; 
                         i f   ( i n s t r u c t o r _ n a m e   = =   " l u i " ) 
                                 o f s   < <   B i n a r y S t r i n g T o I n t ( r t )   < <   " , "   < <   B i n a r y S t r i n g T o I n t ( i m m e d i a t e )   < <   e n d l ; 
                         e l s e   i f   ( i n s t r u c t o r _ n a m e   = =   " l w "   | |   i n s t r u c t o r _ n a m e   = =   " s w " ) 
                                 o f s   < <   B i n a r y S t r i n g T o I n t ( r t )   < <   " , "   < <   B i n a r y S t r i n g T o I n t ( i m m e d i a t e )   < <   " ( $ "   < <   B i n a r y S t r i n g T o I n t ( r s )   < <   " ) "   < <   e n d l ; 
                         e l s e   i f   ( i n s t r u c t o r _ n a m e   = =   " b e q "   | |   i n s t r u c t o r _ n a m e   = =   " b n e " ) 
                                 o f s   < <   B i n a r y S t r i n g T o I n t ( r s )   < <   " , $ "   < <   B i n a r y S t r i n g T o I n t ( r t )   < <   " , "   < <   B i n a r y S t r i n g T o I n t ( i m m e d i a t e )   < <   e n d l ; 
                         e l s e 
                                 o f s   < <   B i n a r y S t r i n g T o I n t ( r t )   < <   " , $ "   < <   B i n a r y S t r i n g T o I n t ( r s )   < <   " , "   < <   B i n a r y S t r i n g T o I n t ( i m m e d i a t e )   < <   e n d l ; 
                 } 
         } 
 
         i f s . c l o s e ( ) ; 
         o f s . c l o s e ( ) ; 
 } 
 
 b o o l   M i p s I n v e r t : : c m p ( i n f o   a   ,   i n f o   b ) { 
         r e t u r n   a . o p   <   b . o p ; 
 } 
 
 s t r i n g   M i p s I n v e r t : : B i n a r y S e a r c h ( c o n s t   v e c t o r < i n f o >   & v   ,   s t r i n g   s ) { 
         i n t   s t a r t   =   0   ,   e n d   =   v . s i z e ( )   -   1 ; 
         w h i l e ( s t a r t   < =   e n d ) { 
                 i n t   m i d   =   ( s t a r t   +   e n d )   /   2 ; 
                 i f   ( v [ m i d ] . o p   = =   s ) 
                         r e t u r n   v [ m i d ] . n a m e ; 
                 e l s e   i f   ( v [ m i d ] . o p   <   s ) 
                         s t a r t   =   m i d   +   1 ; 
                 e l s e 
                         e n d   =   m i d   -   1 ; 
         } 
         r e t u r n   " " ; 
 } 
 
 i n t   M i p s I n v e r t : : B i n a r y S t r i n g T o I n t ( s t r i n g   s ) { 
         i n t   r e s   =   0 ; 
         f o r   ( i n t   i   =   0 ;   i   <   s . l e n g t h ( ) ; + + i ) { 
                 r e s   =   r e s   *   2   +   ( s [ i ]   -   ' 0 ' ) ; 
         } 
         r e t u r n   r e s ; 
 } 
 
 
 _?#include"mips_invert.h"

MipsInvert::MipsInvert(string path){
    ifstream ifs(path);
    info tmp;
    while (!ifs.eof()) {
        ifs >> tmp.type >> tmp.name >> tmp.op;
        if (tmp.type == "R")
            r_.push_back(tmp);
        else if (tmp.type == "I")
            i_.push_back(tmp);
        else
            j_.push_back(tmp);
    }
    ifs.close();
    sort(r_.begin() , r_.end() , cmp);
    sort(i_.begin() , i_.end() , cmp);
    sort(j_.begin() , j_.end() , cmp);
}

void MipsInvert::Convert(string path1 , string path2){
    ifstream ifs(path1);
    ofstream ofs(path2);
    while (!ifs.eof()) {
        string s;
        ifs >> s;
        string op = s.substr(0 , 6);
        if (op == "000000") {
            string instructor_name = BinarySearch(r_ , s.substr(26 , 6));
            string rs , rt , rd , shamt;
            rs = s.substr(6 , 5);
            rt = s.substr(11 , 5);
            rd = s.substr(16 , 5);
            shamt = s.substr(21 , 5);
            ofs << instructor_name << " $";
            if (instructor_name == "sll" || instructor_name == "srl" || instructor_name == "sra")
                ofs << BinaryStringToInt(rd) << ",$" << BinaryStringToInt(rt) << "," << BinaryStringToInt(shamt) << endl;
            else if (instructor_name == "sllv" || instructor_name == "srlv" || instructor_name == "srav")
                ofs << BinaryStringToInt(rd) << ",$" << BinaryStringToInt(rt) << ",$" << BinaryStringToInt(rs) << endl;
            else if (instructor_name == "jr")
                ofs << BinaryStringToInt(rs) << endl;
            else
                ofs << BinaryStringToInt(rd) << ",$" << BinaryStringToInt(rs) << ",$" << BinaryStringToInt(rt) << endl;
        }
        else if (op == "000010" || op == "000011") {
            string instructor_name = BinarySearch(j_ , op);
            string address = s.substr(6 , 26);
            ofs << instructor_name << " " << BinaryStringToInt(address) << endl;
        }
        else {
            string instructor_name = BinarySearch(i_ , op);
            string rs , rt , immediate;
            rs = s.substr(6 , 5);
            rt = s.substr(11 , 5);
            immediate = s.substr(16 , 16);
            ofs << instructor_name << " $";
            if (instructor_name == "lui")
                ofs << BinaryStringToInt(rt) << "," << BinaryStringToInt(immediate) << endl;
            else if (instructor_name == "lw" || instructor_name == "sw")
                ofs << BinaryStringToInt(rt) << "," << BinaryStringToInt(immediate) << "($" << BinaryStringToInt(rs) << ")" << endl;
            else if (instructor_name == "beq" || instructor_name == "bne")
                ofs << BinaryStringToInt(rs) << ",$" << BinaryStringToInt(rt) << "," << BinaryStringToInt(immediate) << endl;
            else
                ofs << BinaryStringToInt(rt) << ",$" << BinaryStringToInt(rs) << "," << BinaryStringToInt(immediate) << endl;
        }
    }

    ifs.close();
    ofs.close();
}

bool MipsInvert::cmp(info a , info b){
    return a.op < b.op;
}

string MipsInvert::BinarySearch(const vector<info> &v , string s){
    int start = 0 , end = v.size() - 1;
    while(start <= end){
        int mid = (start + end) / 2;
        if (v[mid].op == s)
            return v[mid].name;
        else if (v[mid].op < s)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return "";
}

int MipsInvert::BinaryStringToInt(string s){
    int res = 0;
    for (int i = 0; i < s.length();++i){
        res = res * 2 + (s[i] - '0');
    }
    return res;
}


O?#include"mips_invert.h"MipsInvert::MipsInvert(string path){    ifstream ifs(path);    info tmp;    while (!ifs.eof()) {        ifs >> tmp.type >> tmp.name >> tmp.op;        if (tmp.type == "R")            r_.push_back(tmp);        else if (tmp.type == "I")            i_.push_back(tmp);        else            j_.push_back(tmp);    }    ifs.close();    sort(r_.begin() , r_.end() , cmp);    sort(i_.begin() , i_.end() , cmp);    sort(j_.begin() , j_.end() , cmp);}void MipsInvert::Convert(string path1 , string path2){    ifstream ifs(path1);    ofstream ofs(path2);    while (!ifs.eof()) {        string s;        ifs >> s;        string op = s.substr(0 , 6);        if (op == "000000") {            string instructor_name = BinarySearch(r_ , s.substr(26 , 6));            string rs , rt , rd , shamt;            rs = s.substr(6 , 5);            rt = s.substr(11 , 5);            rd = s.substr(16 , 5);            shamt = s.substr(21 , 5);            ofs << instructor_name << " $";            if (instructor_name == "sll" || instructor_name == "srl" || instructor_name == "sra")                ofs << BinaryStringToInt(rd) << ",$" << BinaryStringToInt(rt) << "," << BinaryStringToInt(shamt) << endl;            else if (instructor_name == "sllv" || instructor_name == "srlv" || instructor_name == "srav")                ofs << BinaryStringToInt(rd) << ",$" << BinaryStringToInt(rt) << ",$" << BinaryStringToInt(rs) << endl;            else if (instructor_name == "jr")                ofs << BinaryStringToInt(rs) << endl;            else                ofs << BinaryStringToInt(rd) << ",$" << BinaryStringToInt(rs) << ",$" << BinaryStringToInt(rt) << endl;        }        else if (op == "000010" || op == "000011") {            string instructor_name = BinarySearch(j_ , op);            string address = s.substr(6 , 26);            ofs << instructor_name << " " << BinaryStringToInt(address) << endl;        }        else {            string instructor_name = BinarySearch(i_ , op);            string rs , rt , immediate;            rs = s.substr(6 , 5);            rt = s.substr(11 , 5);            immediate = s.substr(16 , 16);            ofs << instructor_name << " $";            if (instructor_name == "lui")                ofs << BinaryStringToInt(rt) << "," << BinaryStringToInt(immediate) << endl;            else if (instructor_name == "lw" || instructor_name == "sw")                ofs << BinaryStringToInt(rt) << "," << BinaryStringToInt(immediate) << "($" << BinaryStringToInt(rs) << ")" << endl;            else if (instructor_name == "beq" || instructor_name == "bne")                ofs << BinaryStringToInt(rs) << ",$" << BinaryStringToInt(rt) << "," << BinaryStringToInt(immediate) << endl;            else                ofs << BinaryStringToInt(rt) << ",$" << BinaryStringToInt(rs) << "," << BinaryStringToInt(immediate) << endl;        }    }    ifs.close();    ofs.close();}bool MipsInvert::cmp(info a , info b){    return a.op < b.op;}string MipsInvert::BinarySearch(const vector<info> &v , string s){    int start = 0 , end = v.size() - 1;    while(start <= end){        int mid = (start + end) / 2;        if (v[mid].op == s)            return v[mid].name;        else if (v[mid].op < s)            start = mid + 1;        else            end = mid - 1;    }    return "";}int MipsInvert::BinaryStringToInt(string s){    int res = 0;    for (int i = 0; i < s.length();++i){        res = res * 2 + (s[i] - '0');    }    return res;}     9 D g ? ?y4iP=^(                           l