bplist00?XUTI-Data?	
_public.utf16-plain-textZpublic.rtf_ public.utf16-external-plain-text_public.utf8-plain-text_$com.apple.traditional-mac-plain-textO?# i f n d e f   _ C P U _ H  # d e f i n e   _ C P U _ H  # i n c l u d e   " m i p s . h "  # i n c l u d e   " m i p s _ i n v e r t . h "  # i n c l u d e   < i o s t r e a m >  # i n c l u d e   < v e c t o r >  # i n c l u d e   < s t r i n g >  # i n c l u d e   < f s t r e a m >  u s i n g   n a m e s p a c e   s t d ;  c l a s s   C p u   {      p u b l i c :          C p u ( ) ;          v o i d   I n s e r t I n s t r u c t o r ( ) ;          v o i d   R u n B y S t e p ( ) ;          v o i d   C h e c k R e g i s t e r ( ) ;          v o i d   C h e c k M e m o r y ( ) ;          v o i d   C o n v e r t ( ) ;          v o i d   I n v e r t ( ) ;      p r i v a t e :          v e c t o r < s t r i n g >   m e m o r y _ ;          v e c t o r < s t r i n g >   r e g i s t e r _ ;          u n s i g n e d   i n t   P C _ ;          u n s i g n e d   i n t   e n d _ ;          s t r i n g   I R _ ;          s t r i n g   D e c i m a l T o B i n a r y 3 2 ( i n t   n ) ;          i n t   B i n a r y T o D e c i m a l U n s i g n e d ( s t r i n g   s ) ;          i n t   B i n a r y T o D e c i m a l S i g n e d ( s t r i n g   s ) ;          s t r i n g   B i n a r y T o H e x a d e c i m a l ( s t r i n g   s ) ;          s t r i n g   S h i f t L e f t L o g i c ( s t r i n g   s   ,   u n s i g n e d   i n t   s h a m t ) ;          s t r i n g   S h i f t R i g h t L o g i c ( s t r i n g   s   ,   u n s i g n e d   i n t   s h a m t ) ;          s t r i n g   S h i f t R i g h t A r i t h m e t i c ( s t r i n g   s   ,   u n s i g n e d   i n t   s h a m t ) ;          v o i d   E x e c u t e ( s t r i n g   s ) ;          v o i d   I n s e r t ( s t r i n g   s ) ;  } ;   # e n d i f  _
{\rtf1\ansi\ansicpg936\cocoartf2636
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red255\green255\blue255;\red0\green0\blue0;
\red196\green26\blue22;\red155\green35\blue147;\red11\green79\blue121;\red15\green104\blue160;}
{\*\expandedcolortbl;;\csgenericrgb\c39147\c22031\c12446;\csgenericrgb\c100000\c100000\c100000;\csgenericrgb\c0\c0\c0\c85000;
\csgenericrgb\c77000\c10200\c8600;\csgenericrgb\c60759\c13753\c57628;\csgenericrgb\c4314\c30980\c47451;\csgenericrgb\c5882\c40784\c62745;}
\deftab593
\pard\tx593\pardeftab593\pardirnatural\partightenfactor0

\f0\fs24 \cf2 \cb3 #ifndef _CPU_H\cf4 \
\cf2 #define _CPU_H\cf4 \
\cf2 #include \cf5 "mips.h"\cf4 \
\cf2 #include \cf5 "mips_invert.h"\cf4 \
\cf2 #include \cf5 <iostream>\cf4 \
\cf2 #include \cf5 <vector>\cf4 \
\cf2 #include \cf5 <string>\cf4 \
\cf2 #include \cf5 <fstream>\cf4 \

\f1\b \cf6 using
\f0\b0 \cf4  
\f1\b \cf6 namespace
\f0\b0 \cf4  \cf7 std\cf4 ;\

\f1\b \cf6 class
\f0\b0 \cf4  \cf7 Cpu\cf4  \{\
  
\f1\b \cf6 public
\f0\b0 \cf4 :\
    \cf8 Cpu\cf4 ();\
    
\f1\b \cf6 void
\f0\b0 \cf4  \cf8 InsertInstructor\cf4 ();\
    
\f1\b \cf6 void
\f0\b0 \cf4  \cf8 RunByStep\cf4 ();\
    
\f1\b \cf6 void
\f0\b0 \cf4  \cf8 CheckRegister\cf4 ();\
    
\f1\b \cf6 void
\f0\b0 \cf4  \cf8 CheckMemory\cf4 ();\
    
\f1\b \cf6 void
\f0\b0 \cf4  \cf8 Convert\cf4 ();\
    
\f1\b \cf6 void
\f0\b0 \cf4  \cf8 Invert\cf4 ();\
  
\f1\b \cf6 private
\f0\b0 \cf4 :\
    vector<string> memory_;\
    vector<string> register_;\
    
\f1\b \cf6 unsigned
\f0\b0 \cf4  
\f1\b \cf6 int
\f0\b0 \cf4  PC_;\
    
\f1\b \cf6 unsigned
\f0\b0 \cf4  
\f1\b \cf6 int
\f0\b0 \cf4  end_;\
    string IR_;\
    string \cf8 DecimalToBinary32\cf4 (
\f1\b \cf6 int
\f0\b0 \cf4  n);\
    
\f1\b \cf6 int
\f0\b0 \cf4  \cf8 BinaryToDecimalUnsigned\cf4 (string s);\
    
\f1\b \cf6 int
\f0\b0 \cf4  \cf8 BinaryToDecimalSigned\cf4 (string s);\
    string \cf8 BinaryToHexadecimal\cf4 (string s);\
    string \cf8 ShiftLeftLogic\cf4 (string s , 
\f1\b \cf6 unsigned
\f0\b0 \cf4  
\f1\b \cf6 int
\f0\b0 \cf4  shamt);\
    string \cf8 ShiftRightLogic\cf4 (string s , 
\f1\b \cf6 unsigned
\f0\b0 \cf4  
\f1\b \cf6 int
\f0\b0 \cf4  shamt);\
    string \cf8 ShiftRightArithmetic\cf4 (string s , 
\f1\b \cf6 unsigned
\f0\b0 \cf4  
\f1\b \cf6 int
\f0\b0 \cf4  shamt);\
    
\f1\b \cf6 void
\f0\b0 \cf4  \cf8 Execute\cf4 (string s);\
    
\f1\b \cf6 void
\f0\b0 \cf4  \cf8 Insert\cf4 (string s);\
\};\
\
\cf2 #endif\cf4 \
}O???# i f n d e f   _ C P U _ H 
 # d e f i n e   _ C P U _ H 
 # i n c l u d e   " m i p s . h " 
 # i n c l u d e   " m i p s _ i n v e r t . h " 
 # i n c l u d e   < i o s t r e a m > 
 # i n c l u d e   < v e c t o r > 
 # i n c l u d e   < s t r i n g > 
 # i n c l u d e   < f s t r e a m > 
 u s i n g   n a m e s p a c e   s t d ; 
 c l a s s   C p u   { 
     p u b l i c : 
         C p u ( ) ; 
         v o i d   I n s e r t I n s t r u c t o r ( ) ; 
         v o i d   R u n B y S t e p ( ) ; 
         v o i d   C h e c k R e g i s t e r ( ) ; 
         v o i d   C h e c k M e m o r y ( ) ; 
         v o i d   C o n v e r t ( ) ; 
         v o i d   I n v e r t ( ) ; 
     p r i v a t e : 
         v e c t o r < s t r i n g >   m e m o r y _ ; 
         v e c t o r < s t r i n g >   r e g i s t e r _ ; 
         u n s i g n e d   i n t   P C _ ; 
         u n s i g n e d   i n t   e n d _ ; 
         s t r i n g   I R _ ; 
         s t r i n g   D e c i m a l T o B i n a r y 3 2 ( i n t   n ) ; 
         i n t   B i n a r y T o D e c i m a l U n s i g n e d ( s t r i n g   s ) ; 
         i n t   B i n a r y T o D e c i m a l S i g n e d ( s t r i n g   s ) ; 
         s t r i n g   B i n a r y T o H e x a d e c i m a l ( s t r i n g   s ) ; 
         s t r i n g   S h i f t L e f t L o g i c ( s t r i n g   s   ,   u n s i g n e d   i n t   s h a m t ) ; 
         s t r i n g   S h i f t R i g h t L o g i c ( s t r i n g   s   ,   u n s i g n e d   i n t   s h a m t ) ; 
         s t r i n g   S h i f t R i g h t A r i t h m e t i c ( s t r i n g   s   ,   u n s i g n e d   i n t   s h a m t ) ; 
         v o i d   E x e c u t e ( s t r i n g   s ) ; 
         v o i d   I n s e r t ( s t r i n g   s ) ; 
 } ; 
 
 # e n d i f 
 _r#ifndef _CPU_H
#define _CPU_H
#include "mips.h"
#include "mips_invert.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
class Cpu {
  public:
    Cpu();
    void InsertInstructor();
    void RunByStep();
    void CheckRegister();
    void CheckMemory();
    void Convert();
    void Invert();
  private:
    vector<string> memory_;
    vector<string> register_;
    unsigned int PC_;
    unsigned int end_;
    string IR_;
    string DecimalToBinary32(int n);
    int BinaryToDecimalUnsigned(string s);
    int BinaryToDecimalSigned(string s);
    string BinaryToHexadecimal(string s);
    string ShiftLeftLogic(string s , unsigned int shamt);
    string ShiftRightLogic(string s , unsigned int shamt);
    string ShiftRightArithmetic(string s , unsigned int shamt);
    void Execute(string s);
    void Insert(string s);
};

#endif
Or#ifndef _CPU_H#define _CPU_H#include "mips.h"#include "mips_invert.h"#include <iostream>#include <vector>#include <string>#include <fstream>using namespace std;class Cpu {  public:    Cpu();    void InsertInstructor();    void RunByStep();    void CheckRegister();    void CheckMemory();    void Convert();    void Invert();  private:    vector<string> memory_;    vector<string> register_;    unsigned int PC_;    unsigned int end_;    string IR_;    string DecimalToBinary32(int n);    int BinaryToDecimalUnsigned(string s);    int BinaryToDecimalSigned(string s);    string BinaryToHexadecimal(string s);    string ShiftLeftLogic(string s , unsigned int shamt);    string ShiftRightLogic(string s , unsigned int shamt);    string ShiftRightArithmetic(string s , unsigned int shamt);    void Execute(string s);    void Insert(string s);};#endif     9 D g ? ????                           k