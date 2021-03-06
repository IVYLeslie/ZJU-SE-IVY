bplist00?XUTI-Data?	
_public.utf16-plain-textZpublic.rtf_ public.utf16-external-plain-text_public.utf8-plain-text_$com.apple.traditional-mac-plain-textO0# i f n d e f   _ M I P S _ I N V E R T _ H  # d e f i n e   _ M I P S _ I N V E R T _ H   # i n c l u d e < i o s t r e a m >  # i n c l u d e < v e c t o r >  # i n c l u d e < s t r i n g >  # i n c l u d e < f s t r e a m >  # i n c l u d e < a l g o r i t h m >  u s i n g   n a m e s p a c e   s t d ;   c l a s s   M i p s I n v e r t {      p u b l i c :          M i p s I n v e r t ( s t r i n g   p a t h ) ;          v o i d   C o n v e r t ( s t r i n g   p a t h 1   ,   s t r i n g   p a t h 2 ) ;      p r i v a t e :          s t r u c t   i n f o {                  s t r i n g   t y p e ;                  s t r i n g   o p ;                  s t r i n g   n a m e ;          } ;          v e c t o r < i n f o >   r _   ,   i _   ,   j _ ;          s t r i n g   B i n a r y S e a r c h ( c o n s t   v e c t o r < i n f o >   & v   ,   s t r i n g   s ) ;          i n t   B i n a r y S t r i n g T o I n t ( s t r i n g   s ) ;          s t a t i c   b o o l   c m p ( i n f o   a   ,   i n f o   b ) ;  } ;   # e n d i f  _?{\rtf1\ansi\ansicpg936\cocoartf2636
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red255\green255\blue255;\red0\green0\blue0;
\red196\green26\blue22;\red155\green35\blue147;\red11\green79\blue121;\red15\green104\blue160;}
{\*\expandedcolortbl;;\csgenericrgb\c39147\c22031\c12446;\csgenericrgb\c100000\c100000\c100000;\csgenericrgb\c0\c0\c0\c85000;
\csgenericrgb\c77000\c10200\c8600;\csgenericrgb\c60759\c13753\c57628;\csgenericrgb\c4314\c30980\c47451;\csgenericrgb\c5882\c40784\c62745;}
\deftab593
\pard\tx593\pardeftab593\pardirnatural\partightenfactor0

\f0\fs24 \cf2 \cb3 #ifndef _MIPS_INVERT_H\cf4 \
\cf2 #define _MIPS_INVERT_H\cf4 \
\
\cf2 #include\cf5 <iostream>\cf4 \
\cf2 #include\cf5 <vector>\cf4 \
\cf2 #include\cf5 <string>\cf4 \
\cf2 #include\cf5 <fstream>\cf4 \
\cf2 #include\cf5 <algorithm>\cf4 \

\f1\b \cf6 using
\f0\b0 \cf4  
\f1\b \cf6 namespace
\f0\b0 \cf4  \cf7 std\cf4 ;\
\

\f1\b \cf6 class
\f0\b0 \cf4  \cf7 MipsInvert\cf4 \{\
  
\f1\b \cf6 public
\f0\b0 \cf4 :\
    \cf8 MipsInvert\cf4 (string path);\
    
\f1\b \cf6 void
\f0\b0 \cf4  \cf8 Convert\cf4 (string path1 , string path2);\
  
\f1\b \cf6 private
\f0\b0 \cf4 :\
    
\f1\b \cf6 struct
\f0\b0 \cf4  \cf7 info\cf4 \{\
        string type;\
        string op;\
        string name;\
    \};\
    vector<info> r_ , i_ , j_;\
    string \cf8 BinarySearch\cf4 (
\f1\b \cf6 const
\f0\b0 \cf4  vector<info> &v , string s);\
    
\f1\b \cf6 int
\f0\b0 \cf4  \cf8 BinaryStringToInt\cf4 (string s);\
    
\f1\b \cf6 static
\f0\b0 \cf4  
\f1\b \cf6 bool
\f0\b0 \cf4  \cf8 cmp\cf4 (info a , info b);\
\};\
\
\cf2 #endif\cf4 \
}O2??# i f n d e f   _ M I P S _ I N V E R T _ H 
 # d e f i n e   _ M I P S _ I N V E R T _ H 
 
 # i n c l u d e < i o s t r e a m > 
 # i n c l u d e < v e c t o r > 
 # i n c l u d e < s t r i n g > 
 # i n c l u d e < f s t r e a m > 
 # i n c l u d e < a l g o r i t h m > 
 u s i n g   n a m e s p a c e   s t d ; 
 
 c l a s s   M i p s I n v e r t { 
     p u b l i c : 
         M i p s I n v e r t ( s t r i n g   p a t h ) ; 
         v o i d   C o n v e r t ( s t r i n g   p a t h 1   ,   s t r i n g   p a t h 2 ) ; 
     p r i v a t e : 
         s t r u c t   i n f o { 
                 s t r i n g   t y p e ; 
                 s t r i n g   o p ; 
                 s t r i n g   n a m e ; 
         } ; 
         v e c t o r < i n f o >   r _   ,   i _   ,   j _ ; 
         s t r i n g   B i n a r y S e a r c h ( c o n s t   v e c t o r < i n f o >   & v   ,   s t r i n g   s ) ; 
         i n t   B i n a r y S t r i n g T o I n t ( s t r i n g   s ) ; 
         s t a t i c   b o o l   c m p ( i n f o   a   ,   i n f o   b ) ; 
 } ; 
 
 # e n d i f 
 _#ifndef _MIPS_INVERT_H
#define _MIPS_INVERT_H

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;

class MipsInvert{
  public:
    MipsInvert(string path);
    void Convert(string path1 , string path2);
  private:
    struct info{
        string type;
        string op;
        string name;
    };
    vector<info> r_ , i_ , j_;
    string BinarySearch(const vector<info> &v , string s);
    int BinaryStringToInt(string s);
    static bool cmp(info a , info b);
};

#endif
O#ifndef _MIPS_INVERT_H#define _MIPS_INVERT_H#include<iostream>#include<vector>#include<string>#include<fstream>#include<algorithm>using namespace std;class MipsInvert{  public:    MipsInvert(string path);    void Convert(string path1 , string path2);  private:    struct info{        string type;        string op;        string name;    };    vector<info> r_ , i_ , j_;    string BinarySearch(const vector<info> &v , string s);    int BinaryStringToInt(string s);    static bool cmp(info a , info b);};#endif     9 D g ? ?????                           