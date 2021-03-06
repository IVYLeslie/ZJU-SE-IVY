bplist00?XUTI-Data?	
_public.utf16-plain-textZpublic.rtf_ public.utf16-external-plain-text_public.utf8-plain-text_$com.apple.traditional-mac-plain-textO?# i f n d e f   M I P S _ H _  # d e f i n e   M I P S _ H _  # i n c l u d e < i o s t r e a m >  # i n c l u d e < f s t r e a m >  # i n c l u d e < v e c t o r >  # i n c l u d e < s t r i n g >  # i n c l u d e < s t a c k >  u s i n g   n a m e s p a c e   s t d ;   c l a s s   M I P S {          p u b l i c :          c l a s s   i n s t r u c t o r ;          M I P S ( s t r i n g   p a t h ) ;          v o i d   c o n v e r t T o B i n a r y ( s t r i n g   p a t h 1   ,   s t r i n g   p a t h 2 ) ;          v o i d   p r i n t ( ) ;          p r i v a t e :          s t a t i c   b o o l   c m p ( i n s t r u c t o r   a   ,   i n s t r u c t o r   b ) ;          v e c t o r < i n s t r u c t o r >   v ;          i n t   b i n a r y S e a r c h ( s t r i n g   s ) ;          v o i d   b i n a r y ( i n t   n   ,   v e c t o r < i n t > &   t ) ;          v o i d   b i n a r y _ 1 6 ( i n t   n   ,   v e c t o r < i n t > &   t ) ;          v o i d   b i n a r y _ 2 6 ( i n t   n   ,   v e c t o r < i n t > &   t ) ;          i n t   s o l v e E x p r e s s i o n ( s t r i n g   s ) ;  } ;   c l a s s   M I P S : : i n s t r u c t o r {          p u b l i c :          s t r i n g   t y p e ;          s t r i n g   i n s t r u c t o r N a m e ;          v e c t o r < i n t >   o p ;          v e c t o r < i n t >   f u n c ;  } ;   # e n d i f   _	{\rtf1\ansi\ansicpg936\cocoartf2636
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red255\green255\blue255;\red0\green0\blue0;
\red196\green26\blue22;\red155\green35\blue147;\red11\green79\blue121;\red15\green104\blue160;}
{\*\expandedcolortbl;;\csgenericrgb\c39147\c22031\c12446;\csgenericrgb\c100000\c100000\c100000;\csgenericrgb\c0\c0\c0\c85000;
\csgenericrgb\c77000\c10200\c8600;\csgenericrgb\c60759\c13753\c57628;\csgenericrgb\c4314\c30980\c47451;\csgenericrgb\c5882\c40784\c62745;}
\deftab593
\pard\tx593\pardeftab593\pardirnatural\partightenfactor0

\f0\fs24 \cf2 \cb3 #ifndef MIPS_H_\cf4 \
\cf2 #define MIPS_H_\cf4 \
\cf2 #include\cf5 <iostream>\cf4 \
\cf2 #include\cf5 <fstream>\cf4 \
\cf2 #include\cf5 <vector>\cf4 \
\cf2 #include\cf5 <string>\cf4 \
\cf2 #include\cf5 <stack>\cf4 \

\f1\b \cf6 using
\f0\b0 \cf4  
\f1\b \cf6 namespace
\f0\b0 \cf4  \cf7 std\cf4 ;\
\

\f1\b \cf6 class
\f0\b0 \cf4  \cf7 MIPS\cf4 \{\
    
\f1\b \cf6 public
\f0\b0 \cf4 :\
    
\f1\b \cf6 class
\f0\b0 \cf4  \cf7 instructor\cf4 ;\
    \cf8 MIPS\cf4 (string path);\
    
\f1\b \cf6 void
\f0\b0 \cf4  \cf8 convertToBinary\cf4 (string path1 , string path2);\
    
\f1\b \cf6 void
\f0\b0 \cf4  \cf8 print\cf4 ();\
    
\f1\b \cf6 private
\f0\b0 \cf4 :\
    
\f1\b \cf6 static
\f0\b0 \cf4  
\f1\b \cf6 bool
\f0\b0 \cf4  \cf8 cmp\cf4 (instructor a , instructor b);\
    vector<instructor> v;\
    
\f1\b \cf6 int
\f0\b0 \cf4  \cf8 binarySearch\cf4 (string s);\
    
\f1\b \cf6 void
\f0\b0 \cf4  \cf8 binary\cf4 (
\f1\b \cf6 int
\f0\b0 \cf4  n , vector<
\f1\b \cf6 int
\f0\b0 \cf4 >& t);\
    
\f1\b \cf6 void
\f0\b0 \cf4  \cf8 binary_16\cf4 (
\f1\b \cf6 int
\f0\b0 \cf4  n , vector<
\f1\b \cf6 int
\f0\b0 \cf4 >& t);\
    
\f1\b \cf6 void
\f0\b0 \cf4  \cf8 binary_26\cf4 (
\f1\b \cf6 int
\f0\b0 \cf4  n , vector<
\f1\b \cf6 int
\f0\b0 \cf4 >& t);\
    
\f1\b \cf6 int
\f0\b0 \cf4  \cf8 solveExpression\cf4 (string s);\
\};\
\

\f1\b \cf6 class
\f0\b0 \cf4  \cf7 MIPS\cf4 ::\cf7 instructor\cf4 \{\
    
\f1\b \cf6 public
\f0\b0 \cf4 :\
    string type;\
    string instructorName;\
    vector<
\f1\b \cf6 int
\f0\b0 \cf4 > op;\
    vector<
\f1\b \cf6 int
\f0\b0 \cf4 > func;\
\};\
\
\cf2 #endif\cf4 \
\
}O???# i f n d e f   M I P S _ H _ 
 # d e f i n e   M I P S _ H _ 
 # i n c l u d e < i o s t r e a m > 
 # i n c l u d e < f s t r e a m > 
 # i n c l u d e < v e c t o r > 
 # i n c l u d e < s t r i n g > 
 # i n c l u d e < s t a c k > 
 u s i n g   n a m e s p a c e   s t d ; 
 
 c l a s s   M I P S { 
         p u b l i c : 
         c l a s s   i n s t r u c t o r ; 
         M I P S ( s t r i n g   p a t h ) ; 
         v o i d   c o n v e r t T o B i n a r y ( s t r i n g   p a t h 1   ,   s t r i n g   p a t h 2 ) ; 
         v o i d   p r i n t ( ) ; 
         p r i v a t e : 
         s t a t i c   b o o l   c m p ( i n s t r u c t o r   a   ,   i n s t r u c t o r   b ) ; 
         v e c t o r < i n s t r u c t o r >   v ; 
         i n t   b i n a r y S e a r c h ( s t r i n g   s ) ; 
         v o i d   b i n a r y ( i n t   n   ,   v e c t o r < i n t > &   t ) ; 
         v o i d   b i n a r y _ 1 6 ( i n t   n   ,   v e c t o r < i n t > &   t ) ; 
         v o i d   b i n a r y _ 2 6 ( i n t   n   ,   v e c t o r < i n t > &   t ) ; 
         i n t   s o l v e E x p r e s s i o n ( s t r i n g   s ) ; 
 } ; 
 
 c l a s s   M I P S : : i n s t r u c t o r { 
         p u b l i c : 
         s t r i n g   t y p e ; 
         s t r i n g   i n s t r u c t o r N a m e ; 
         v e c t o r < i n t >   o p ; 
         v e c t o r < i n t >   f u n c ; 
 } ; 
 
 # e n d i f 
 
 _?#ifndef MIPS_H_
#define MIPS_H_
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class MIPS{
    public:
    class instructor;
    MIPS(string path);
    void convertToBinary(string path1 , string path2);
    void print();
    private:
    static bool cmp(instructor a , instructor b);
    vector<instructor> v;
    int binarySearch(string s);
    void binary(int n , vector<int>& t);
    void binary_16(int n , vector<int>& t);
    void binary_26(int n , vector<int>& t);
    int solveExpression(string s);
};

class MIPS::instructor{
    public:
    string type;
    string instructorName;
    vector<int> op;
    vector<int> func;
};

#endif

O?#ifndef MIPS_H_#define MIPS_H_#include<iostream>#include<fstream>#include<vector>#include<string>#include<stack>using namespace std;class MIPS{    public:    class instructor;    MIPS(string path);    void convertToBinary(string path1 , string path2);    void print();    private:    static bool cmp(instructor a , instructor b);    vector<instructor> v;    int binarySearch(string s);    void binary(int n , vector<int>& t);    void binary_16(int n , vector<int>& t);    void binary_26(int n , vector<int>& t);    int solveExpression(string s);};class MIPS::instructor{    public:    string type;    string instructorName;    vector<int> op;    vector<int> func;};#endif     9 D g ? ?/6??                           L