bplist00?XUTI-Data?	
_public.utf16-plain-textZpublic.rtf_ public.utf16-external-plain-text_public.utf8-plain-text_$com.apple.traditional-mac-plain-textOa?# i n c l u d e   " c p u . h "   / /   d e f a u l t   c o n s t r u c t o r  C p u : : C p u ( )   {          i n t   i ;          f o r   ( i   =   0 ;   i   <   5 0 0 1 ;   + + i )                    m e m o r y _ . p u s h _ b a c k ( " 0 0 0 0 0 0 0 0 " ) ;          s t r i n g   s   =   " " ;          f o r   ( i   =   0 ;   i   <   3 2 ;   + + i )                    s   + =   " 0 " ;          f o r   ( i   =   0 ;   i   <   3 2 ;   + + i )                    r e g i s t e r _ . p u s h _ b a c k ( s ) ;          s   =   D e c i m a l T o B i n a r y 3 2 ( 5 0 0 1 ) ;          r e g i s t e r _ [ 2 9 ]   =   s ;          P C _   =   0 ;          e n d _   =   0 ;          I R _   =   " " ;  }   / /   i n s e r t   a n   i n s t r u c t o r   i n t o   m e m o r y  v o i d   C p u : : I n s e r t I n s t r u c t o r ( )   {          s t r i n g   s ;          c o u t   < <   " p l e a s e   i n p u t   t h e   a s s e m b l y   c l a u s e . "   < <   e n d l ;          c o u t   < <   " I n p u t   e x a m p l e :   a d d   $ 1 , $ 2 , $ 3 "   < <   e n d l ;          g e t c h a r ( ) ;          g e t l i n e ( c i n   ,   s ) ;          s t r i n g   o p ;          i n t   i   =   0 ;          w h i l e   ( s [ i ]   ! =   '   ' )   {                  o p   + =   s [ i ] ;                  i + + ;          }          i f   ( o p   = =   " m o v e "   | |   o p   = =   " b l t "   | |   o p   = =   " b g t "   | |   o p   = =   " b l e "   | |   o p   = =   " b g e " )   {                  s t r i n g   r r ;                  s t r i n g   r s ;                  s t r i n g   r t ;                  i + + ;                  w h i l e   ( s [ i ]   ! =   ' , ' )   {                          r s   + =   s [ i ] ;                          i + + ;                  }                  i + + ;                  w h i l e   ( i   <   s . l e n g t h ( )   & &   s [ i ]   ! =   ' , ' )   {                          r t   + =   s [ i ] ;                          i + + ;                  }                  i + + ;                  w h i l e   ( i   <   s . l e n g t h ( )   & &   s [ i ]   ! =   ' , ' )   {                          r r   + =   s [ i ] ;                          i + + ;                  }                  i f   ( o p   = =   " m o v e " )   {                          s t r i n g   s 1   =   " a d d   "   +   r s   +   " , "   +   r t   +   " , $ 0 " ;                          I n s e r t ( s 1 ) ;                  }                  e l s e   i f   ( o p   = =   " b l t " )   {                          s t r i n g   s 1   =   " s l t   $ 1 , "   +   r s   +   " , "   +   r t ;                          I n s e r t ( s 1 ) ;                          s 1   =   " b n e   $ 1 , $ 0 , "   +   r r ;                          I n s e r t ( s 1 ) ;                  }                  e l s e   i f   ( o p   = =   " b g t " )   {                          s t r i n g   s 1   =   " s l t   $ 1 , "   +   r t   +   " , "   +   r s ;                          I n s e r t ( s 1 ) ;                          s 1   =   " b n e   $ 1 , $ 0 , "   +   r r ;                          I n s e r t ( s 1 ) ;                  }                  e l s e   i f   ( o p   = =   " b l e " )   {                          s t r i n g   s 1   =   " s l t   $ 1 , "   +   r t   +   " , "   +   r s ;                          I n s e r t ( s 1 ) ;                          s 1   =   " b e q   $ 1 , $ 0 , "   +   r r ;                          I n s e r t ( s 1 ) ;                  }                  e l s e   i f   ( o p   = =   " b g e " )   {                          s t r i n g   s 1   =   " s l t   $ 1 , "   +   r s   +   " , "   +   r t ;                          I n s e r t ( s 1 ) ;                          s 1   =   " b e q   $ 1 , $ 0 , "   +   r r ;                  }          }          e l s e   {                  I n s e r t ( s ) ;          }          c o u t   < <   " i n s e r t   s u c c e s s f u l l y ! "   < <   e n d l ;  }   / /   r u n   t h e   p r o g r a m   s t e p   b y   s t e p  v o i d   C p u : : R u n B y S t e p ( )   {          I R _   =   " " ;          f o r   ( i n t   i   =   0 ;   i   <   4 ;   + + i )   {                  I R _   + =   m e m o r y _ [ P C _   +   i ] ;          }          P C _   + =   4 ;          E x e c u t e ( I R _ ) ;  }   / /   s h o w   t h e   3 2   r e g i s t e r s  v o i d   C p u : : C h e c k R e g i s t e r ( )   {          f o r   ( i n t   i   =   0 ;   i   <   3 2 ;   + + i )   {                  c o u t   < <   " + - - - - - - - - - - - - - - - - - - + - - - - - - - - - - - - - - - - - - - - - - - + "   < <   e n d l ;                  c o u t   < <   " |       R e g i s t e r "   < <   i ;                  i f   ( i   <   1 0 )                          c o u t   < <     "             | " ;                  e l s e                          c o u t   < <     "           | " ;                  s t r i n g   s   =   B i n a r y T o H e x a d e c i m a l ( r e g i s t e r _ [ i ] ) ;                  c o u t   < <   "         0 x "   < <   s   < <   "                   | "   < <   e n d l ;          }          c o u t   < <   " + - - - - - - - - - - - - - - - - - - + - - - - - - - - - - - - - - - - - - - - - - - + "   < <   e n d l ;  }   / /   s h o w   t h e   m e m o r y  v o i d   C p u : : C h e c k M e m o r y ( )   {          c o u t   < <   " P C :   "   < <   P C _   < <   e n d l ;          f o r   ( i n t   i   =   0 ;   i   <   e n d _ ;   + + i )   {                  s t r i n g   s   =   D e c i m a l T o B i n a r y 3 2 ( i ) ;                  s   =   B i n a r y T o H e x a d e c i m a l ( s ) ;                  c o u t   < <   " + - - - - - - - - - - - - - - - - + - - - - - - - - - - - - - - - - + "   < <   e n d l ;                  c o u t   < <   " |     0 x "   < <   s   < <   "         | " ;                  c o u t   < <   "       "   < <   m e m o r y _ [ i ]   < <   "           | "   < <   e n d l ;          }          c o u t   < <   " + - - - - - - - - - - - - - - - - + - - - - - - - - - - - - - - - - + "   < <   e n d l ;  }   v o i d   C p u : : C o n v e r t ( )   {          c o u t   < <   " p l e a s e   i n p u t   t h e   a s s e m b l y   c o d e "   < <   e n d l ;          s t r i n g   s ;          g e t c h a r ( ) ;          g e t l i n e ( c i n   ,   s ) ;          M I P S   m i p s ( " i n s t r u c t o r " ) ;          o f s t r e a m   o f s ( " t m p _ i n s t r u c t o r " ) ;          o f s   < <   s ;          o f s . c l o s e ( ) ;          m i p s . c o n v e r t T o B i n a r y ( " t m p _ i n s t r u c t o r "   ,   " t m p _ b i n a r y _ c o d e " ) ;          i f s t r e a m   i f s ( " t m p _ b i n a r y _ c o d e " ) ;          i f s   > >   s ;          i f s . c l o s e ( ) ;          c o u t   < <   " t h e   b i n a r y   c o d e   i s   "   < <   s   < <   e n d l ;  }  v o i d   C p u : : I n v e r t ( )   {          c o u t   < <   " p l e a s e   i n p u t   t h e   b i n a r y   c o d e "   < <   e n d l ;          s t r i n g   s ;          g e t c h a r ( ) ;          g e t l i n e ( c i n   ,   s ) ;          M i p s I n v e r t   m i p s _ i n v e r t ( " i n f o . t x t " ) ;          o f s t r e a m   o f s ( " b i n a r y . t x t " ) ;          o f s   < <   s ;          o f s . c l o s e ( ) ;          m i p s _ i n v e r t . C o n v e r t ( " b i n a r y . t x t "   ,   " a s s e m b l e . t x t " ) ;          i f s t r e a m   i f s ( " a s s e m b l e . t x t " ) ;          g e t l i n e ( i f s   ,   s ) ;          i f s . c l o s e ( ) ;          c o u t   < <   " t h e   a s s e m b l y   c o d e   i s   "   < <   s   < <   e n d l ;  }   / /   c o n v e r t   a   d e c i m a l   n u m b e r   t o   3 2 - b i t   b i n a r y   s t r i n g  s t r i n g   C p u : : D e c i m a l T o B i n a r y 3 2 ( i n t   n )   {          v e c t o r < i n t >   v ;          i n t   f l a g   =   0 ;          i f   ( n   <   0 )   {                  f l a g   =   1 ;                  n   =   - n ;          }          w h i l e   ( n   >   0 )   {                  v . p u s h _ b a c k ( n   %   2 ) ;                  n   / =   2 ;          }          s t r i n g   r e s   =   " " ;          f o r   ( i n t   i   =   0 ;   i   <   3 2   -   v . s i z e ( ) ;   + + i )   {                  r e s   + =   " 0 " ;          }          f o r   ( i n t   i   =   v . s i z e ( )   -   1 ;   i   > =   0 ;   - - i )   {                  r e s   + =   v [ i ]   +   ' 0 ' ;          }          i f   ( f l a g   = =   1 )   {                  s t r i n g   r e s 1   =   " " ;                  f o r   ( i n t   i   =   0 ;   i   <   r e s . l e n g t h ( ) ;   + + i )   {                          i f   ( r e s [ i ]   = =   ' 0 ' )                                  r e s 1   + =   ' 1 ' ;                          e l s e                                  r e s 1   + =   ' 0 ' ;                  }                  i n t   c a r r y   =   1 ;                  f o r   ( i n t   i   =   r e s 1 . l e n g t h ( )   -   1 ;   i   > =   0 ;   - - i )   {                          i n t   t   =   r e s 1 [ i ]   -   ' 0 ' ;                          t   + =   c a r r y ;                          i f   ( t   >   1 )   {                                  r e s 1 [ i ]   =   ' 0 ' ;                                  c a r r y   =   1 ;                          }                          e l s e   {                                  r e s 1 [ i ]   =   t   +   ' 0 ' ;                                  b r e a k ;                          }                  }                  r e t u r n   r e s 1 ;          }          r e t u r n   r e s ;  }   / /   c o n v e r t   a   b i n a r y   s t r i n g   t o   s i g n e d   d e c i m a l  i n t   C p u : : B i n a r y T o D e c i m a l S i g n e d ( s t r i n g   s )   {          i n t   f l a g   =   0 ;          i f   ( s [ 0 ]   = =   1 )   {                  f l a g   =   1 ;                  f o r   ( i n t   i   =   0 ;   i   <   s . l e n g t h ( ) ;   + + i )   {                          i f   ( s [ i ]   = =   ' 0 ' )                                  s [ i ]   =   ' 1 ' ;                          e l s e                                  s [ i ]   =   ' 0 ' ;                  }                  i n t   c a r r y   =   0 ;                  f o r   ( i n t   i   =   s . l e n g t h ( )   -   1 ;   i   > =   0 ;   - - i )   {                          i n t   t   =   s [ i ]   -   ' 0 ' ;                          t   =   t   +   c a r r y ;                          i f   ( t   >   1 )   {                                  s [ i ]   =   0 ;                                  c a r r y   =   1 ;                          }                          e l s e {                                  s [ i ]   =   t ;                                  c a r r y   =   0 ;                          }                  }          }          i n t   r e s   =   0 ;          f o r   ( i n t   i   =   1 ;   i   <   s . l e n g t h ( ) ;   + + i )   {                  r e s   =   r e s   *   2   +   s [ i ]   -   ' 0 ' ;          }          i f   ( f l a g   = =   1 )                  r e s   =   - r e s ;          r e t u r n   r e s ;  }   / /   c o n v e r t   a   b i n a r y   s t r i n g   t o   u n s i g n e d   d e c i m a l  i n t   C p u : : B i n a r y T o D e c i m a l U n s i g n e d ( s t r i n g   s )   {          i n t   r e s   =   0 ;          f o r   ( i n t   i   =   0 ;   i   <   s . l e n g t h ( ) ;   + + i )   {                  r e s   =   r e s   *   2   +   s [ i ]   -   ' 0 ' ;          }          r e t u r n   r e s ;  }   / /   c o n v e r t   a   b i n a r y   s t r i n g   t o   h e x a d e c i m a l   s t r i n g  s t r i n g   C p u : : B i n a r y T o H e x a d e c i m a l ( s t r i n g   s )   {          s t r i n g   r e s   =   " " ;          f o r   ( i n t   i   =   0 ;   i   <   s . l e n g t h ( ) ;   i   =   i   +   4 )   {                  i n t   t   =   0 ;                  f o r   ( i n t   j   =   0 ;   j   <   4 ;   + + j )   {                          t   =   t   *   2   +   s [ i   +   j ]   -   ' 0 ' ;                  }                  i f   ( t   <   1 0 )                          r e s   + =   t   +   ' 0 ' ;                  e l s e                          r e s   + =   t   -   1 0   +   ' A ' ;          }          r e t u r n   r e s ;  }   / /   s h i f t   l e f t   l o g i c l l y  s t r i n g   C p u : : S h i f t L e f t L o g i c ( s t r i n g   s   ,   u n s i g n e d   i n t   s h a m t )   {          f o r   ( i n t   i   =   0 ;   i   <   s h a m t ;   + + i )   {                  f o r   ( i n t   j   =   0 ;   j   <   s . l e n g t h ( )   -   1 ;   + + j )   {                          s [ j ]   =   s [ j   +   1 ] ;                  }                  s [ s . l e n g t h ( )   -   1 ]   =   ' 0 ' ;          }          r e t u r n   s ;  }   / /   s h i f t   r i g h t   l o g i c l l y  s t r i n g   C p u : : S h i f t R i g h t L o g i c ( s t r i n g   s   ,   u n s i g n e d   i n t   s h a m t )   {          f o r   ( i n t   i   =   0 ;   i   <   s h a m t ;   + + i )   {                  f o r   ( i n t   j   =   s . l e n g t h ( )   -   1 ;   j   >   0 ;   - - j )   {                          s [ j ]   =   s [ j   -   1 ] ;                  }                  s [ 0 ]   =   ' 0 ' ;          }          r e t u r n   s ;  }   / /   s h i f t   r i g h t   a r i t h m e t i c  s t r i n g   C p u : : S h i f t R i g h t A r i t h m e t i c ( s t r i n g   s   ,   u n s i g n e d   i n t   s h a m t )   {          c h a r   c   =   s [ 0 ] ;          f o r   ( i n t   i   =   0 ;   i   <   s h a m t ;   + + i )   {                  f o r   ( i n t   j   =   s . l e n g t h ( )   -   1 ;   j   >   0 ;   - - j )   {                          s [ j ]   =   s [ j   -   1 ] ;                  }                  s [ 0 ]   =   c ;          }          r e t u r n   s ;  }   / /   e x e c u t e   m o d u l e   ( c o r e   m o d u l e )  v o i d   C p u : : E x e c u t e ( s t r i n g   s )   {          i n t   r s   =   B i n a r y T o D e c i m a l U n s i g n e d ( s . s u b s t r ( 6   ,   5 ) ) ;          i n t   r t   =   B i n a r y T o D e c i m a l U n s i g n e d ( s . s u b s t r ( 1 1   ,   5 ) ) ;          i n t   r d   =   B i n a r y T o D e c i m a l U n s i g n e d ( s . s u b s t r ( 1 6   ,   5 ) ) ;          i n t   s h a m t   =   B i n a r y T o D e c i m a l S i g n e d ( s . s u b s t r ( 2 1   ,   5 ) ) ;          i n t   i m m   =   B i n a r y T o D e c i m a l S i g n e d ( s . s u b s t r ( 1 6   ,   1 6 ) ) ;          i n t   t 1   =   B i n a r y T o D e c i m a l S i g n e d ( r e g i s t e r _ [ r s ] ) ;          i n t   t 2   =   B i n a r y T o D e c i m a l S i g n e d ( r e g i s t e r _ [ r t ] ) ;          i n t   t 3   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r s ] ) ;          i n t   a d d r e s s   =   t 3   +   i m m ;          s t r i n g   o p   =   s . s u b s t r ( 0   ,   6 ) ;          / /   R - t y p e   i n s t r u c t i o n          i f   ( o p   = =   " 0 0 0 0 0 0 " )   {                  s t r i n g   f u n c   =   s . s u b s t r ( 2 6   ,   6 ) ;                  / /   a d d                  i f   ( f u n c   = =   " 1 0 0 0 0 0 " )   {                          r e g i s t e r _ [ r d ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   +   t 2 ) ;                  }                        / /   a d d u                  e l s e   i f   ( f u n c   = =   " 1 0 0 0 0 1 " )   {                          t 1   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r s ] ) ;                          t 2   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r t ] ) ;                          r e g i s t e r _ [ r d ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   +   t 2 ) ;                  }                  / /   s u b                  e l s e   i f   ( f u n c   = =   " 1 0 0 0 1 0 " )   {                          r e g i s t e r _ [ r d ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   -   t 2 ) ;                  }                  / /   s u b u                  e l s e   i f   ( f u n c   = =   " 1 0 0 0 1 1 " )   {                          t 1   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r s ] ) ;                          t 2   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r t ] ) ;                          r e g i s t e r _ [ r d ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   -   t 2 ) ;                  }                  / /   a n d                  e l s e   i f   ( f u n c   = =   " 1 0 0 1 0 0 " )   {                          r e g i s t e r _ [ r d ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   &   t 2 ) ;                  }                  / /   o r                  e l s e   i f   ( f u n c   = =   " 1 0 0 1 0 1 " )   {                          r e g i s t e r _ [ r d ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   |   t 2 ) ;                  }                  / /   x o r                  e l s e   i f   ( f u n c   = =   " 1 0 0 1 1 0 " )   {                          r e g i s t e r _ [ r d ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   ^   t 2 ) ;                  }                  / /   n o r                  e l s e   i f   ( f u n c   = =   " 1 0 0 1 1 1 " )   {                          r e g i s t e r _ [ r d ]   =   D e c i m a l T o B i n a r y 3 2 ( ~ ( t 1   |   t 2 ) ) ;                  }                  / /   s l t                  e l s e   i f   ( f u n c   = =   " 1 0 1 0 1 0 " )   {                          r e g i s t e r _ [ r d ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   <   t 2   ?   1   :   0 ) ;                  }                  / /   s l t u                  e l s e   i f   ( f u n c   = =   " 1 0 1 0 1 1 " )   {                          t 1   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r s ] ) ;                          t 2   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r t ] ) ;                          r e g i s t e r _ [ r d ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   <   t 2   ?   1   :   0 ) ;                  }                  / /   s l l                  e l s e   i f   ( f u n c   = =   " 0 0 0 0 0 0 " )   {                          r e g i s t e r _ [ r d ]   =   S h i f t L e f t L o g i c ( r e g i s t e r _ [ r t ]   ,   s h a m t ) ;                  }                  / /   s r l                  e l s e   i f   ( f u n c   = =   " 0 0 0 0 1 0 " )   {                          r e g i s t e r _ [ r d ]   =   S h i f t R i g h t L o g i c ( r e g i s t e r _ [ r t ]   ,   s h a m t ) ;                  }                  / /   s r a                  e l s e   i f   ( f u n c   = =   " 0 0 0 0 1 1 " )   {                          r e g i s t e r _ [ r d ]   =   S h i f t R i g h t A r i t h m e t i c ( r e g i s t e r _ [ r t ]   ,   s h a m t ) ;                  }                  / /   s l l v                  e l s e   i f   ( f u n c   = =   " 0 0 0 1 0 0 " )   {                          t 1   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r s ] ) ;                          r e g i s t e r _ [ r d ]   =   S h i f t L e f t L o g i c ( r e g i s t e r _ [ r t ]   ,   t 1 ) ;                  }                  / /   s r l v                  e l s e   i f   ( f u n c   = =   " 0 0 0 1 1 0 " )   {                          t 1   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r s ] ) ;                          r e g i s t e r _ [ r d ]   =   S h i f t R i g h t L o g i c ( r e g i s t e r _ [ r t ]   ,   t 1 ) ;                  }                  / /   s r a v                  e l s e   i f   ( f u n c   = =   " 0 0 0 1 1 1 " )   {                          t 1   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r s ] ) ;                          r e g i s t e r _ [ r d ]   =   S h i f t R i g h t A r i t h m e t i c ( r e g i s t e r _ [ r t ]   ,   t 1 ) ;                  }                  / /   j r                  e l s e   i f   ( f u n c   = =   " 0 0 1 0 0 0 " )   {                          P C _   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r s ] ) ;                  }          }          / /   a d d i          e l s e   i f   ( o p   = =   " 0 0 1 0 0 0 " )   {                  r e g i s t e r _ [ r t ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   +   i m m ) ;          }          / /   a d d i u          e l s e   i f   ( o p   = =   " 0 0 1 0 0 1 " )   {                  t 1   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r s ] ) ;                  r e g i s t e r _ [ r t ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   +   i m m ) ;          }          / /   a n d i          e l s e   i f   ( o p   = =   " 0 0 1 1 0 0 " )   {                  r e g i s t e r _ [ r t ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   &   i m m ) ;          }          / /   o r i          e l s e   i f   ( o p   = =   " 0 0 1 1 0 1 " )   {                  r e g i s t e r _ [ r t ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   |   i m m ) ;          }          / /   x o r i          e l s e   i f   ( o p   = =   " 0 0 1 1 1 0 " )   {                  r e g i s t e r _ [ r t ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   ^   i m m ) ;          }          / /   l w          e l s e   i f   ( o p   = =   " 1 0 0 0 1 1 " )   {                  r e g i s t e r _ [ r t ]   =   " " ;                  f o r   ( i n t   i   =   0 ;   i <   4 ;   + + i )   {                          r e g i s t e r _ [ r t ]   + =   m e m o r y _ [ a d d r e s s   +   i ] ;                  }          }          / /   s w          e l s e   i f   ( o p   = =   " 1 0 1 0 1 1 " )   {                  f o r   ( i n t   i   =   0 ;   i   <   4 ;   + + i )   {                          m e m o r y _ [ a d d r e s s   +   i ]   =   r e g i s t e r _ [ r t ] . s u b s t r ( 8   *   i   ,   8 ) ;                  }          }          / /   b e q          e l s e   i f   ( o p   = =   " 0 0 0 1 0 0 " )   {                  i f   ( t 1   = =   t 2 )   {                          P C _   =   P C _   +   i m m   *   4 ;                  }          }          / /   b n e          e l s e   i f   ( o p   = =   " 0 0 0 1 0 1 " )   {                  i f   ( t 1   ! =   t 2 )   {                          P C _   =   P C _   +   i m m   *   4 ;                  }          }          / /   s l t i          e l s e   i f   ( o p   = =   " 0 0 1 0 1 0 " )   {                  r e g i s t e r _ [ r t ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   <   i m m   ?   1   :   0 ) ;          }          / /   s l t i u          e l s e   i f   ( o p   = =   " 0 0 1 0 1 1 " )   {                  t 1   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r s ] ) ;                  r e g i s t e r _ [ r t ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   <   i m m   ?   1   :   0 ) ;          }          / /   j   a n d   j a l          e l s e   i f   ( o p   = =   " 0 0 0 0 1 0 "   | |   o p   = =   " 0 0 0 0 1 1 " )   {                  s t r i n g   a d d r e s s   =   s . s u b s t r ( 6   ,   2 6 )   +   " 0 0 " ;                  s t r i n g   p c   =   D e c i m a l T o B i n a r y 3 2 ( P C _ ) ;                  a d d r e s s   =   p c . s u b s t r ( 0   ,   4 )   +   a d d r e s s ;                  P C _   =   B i n a r y T o D e c i m a l U n s i g n e d ( a d d r e s s ) ;                  / /   j a l                  i f   ( o p   = =   " 0 0 0 0 1 1 " )                          r e g i s t e r _ [ 3 1 ]   =   D e c i m a l T o B i n a r y 3 2 ( P C _ ) ;          }  }   v o i d   C p u : : I n s e r t ( s t r i n g   s )   {          o f s t r e a m   o f s ( " t m p _ i n s t r u c t o r " ) ;          o f s   < <   s ;          o f s . c l o s e ( ) ;          M I P S   m ( " i n s t r u c t o r " ) ;          m . c o n v e r t T o B i n a r y ( " t m p _ i n s t r u c t o r "   ,   " t m p _ b i n a r y _ c o d e " ) ;          i f s t r e a m   i f s ( " t m p _ b i n a r y _ c o d e " ) ;          i f s   > >   s ;          i f s . c l o s e ( ) ;          f o r   ( i n t   i   =   0 ;   i   <   4 ;   + + i )   {                  m e m o r y _ [ e n d _   +   i ]   =   s . s u b s t r ( 8   *   i   ,   8 ) ;          }          e n d _   + =   4 ;  }  _UQ{\rtf1\ansi\ansicpg936\cocoartf2636
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red255\green255\blue255;\red196\green26\blue22;
\red0\green0\blue0;\red93\green108\blue121;\red15\green104\blue160;\red155\green35\blue147;\red28\green0\blue207;
}
{\*\expandedcolortbl;;\csgenericrgb\c39147\c22031\c12446;\csgenericrgb\c100000\c100000\c100000;\csgenericrgb\c77000\c10200\c8600;
\csgenericrgb\c0\c0\c0\c85000;\csgenericrgb\c36526\c42188\c47515;\csgenericrgb\c5882\c40784\c62745;\csgenericrgb\c60759\c13753\c57628;\csgenericrgb\c11000\c0\c81000;
}
\deftab593
\pard\tx593\pardeftab593\pardirnatural\partightenfactor0

\f0\fs24 \cf2 \cb3 #include \cf4 "cpu.h"\cf5 \
\
\cf6 // default constructor\cf5 \
\cf7 Cpu\cf5 ::\cf7 Cpu\cf5 () \{\
    
\f1\b \cf8 int
\f0\b0 \cf5  i;\
    
\f1\b \cf8 for
\f0\b0 \cf5  (i = \cf9 0\cf5 ; i < \cf9 5001\cf5 ; ++i) \
        memory_.push_back(\cf4 "00000000"\cf5 );\
    string s = \cf4 ""\cf5 ;\
    
\f1\b \cf8 for
\f0\b0 \cf5  (i = \cf9 0\cf5 ; i < \cf9 32\cf5 ; ++i) \
        s += \cf4 "0"\cf5 ;\
    
\f1\b \cf8 for
\f0\b0 \cf5  (i = \cf9 0\cf5 ; i < \cf9 32\cf5 ; ++i) \
        register_.push_back(s);\
    s = DecimalToBinary32(\cf9 5001\cf5 );\
    register_[\cf9 29\cf5 ] = s;\
    PC_ = \cf9 0\cf5 ;\
    end_ = \cf9 0\cf5 ;\
    IR_ = \cf4 ""\cf5 ;\
\}\
\
\cf6 // insert an instructor into memory\cf5 \

\f1\b \cf8 void
\f0\b0 \cf5  \cf7 Cpu\cf5 ::\cf7 InsertInstructor\cf5 () \{\
    string s;\
    cout << \cf4 "please input the assembly clause."\cf5  << endl;\
    cout << \cf4 "Input example: add $1,$2,$3"\cf5  << endl;\
    getchar();\
    getline(cin , s);\
    string op;\
    
\f1\b \cf8 int
\f0\b0 \cf5  i = \cf9 0\cf5 ;\
    
\f1\b \cf8 while
\f0\b0 \cf5  (s[i] != \cf9 ' '\cf5 ) \{\
        op += s[i];\
        i++;\
    \}\
    
\f1\b \cf8 if
\f0\b0 \cf5  (op == \cf4 "move"\cf5  || op == \cf4 "blt"\cf5  || op == \cf4 "bgt"\cf5  || op == \cf4 "ble"\cf5  || op == \cf4 "bge"\cf5 ) \{\
        string rr;\
        string rs;\
        string rt;\
        i++;\
        
\f1\b \cf8 while
\f0\b0 \cf5  (s[i] != \cf9 ','\cf5 ) \{\
            rs += s[i];\
            i++;\
        \}\
        i++;\
        
\f1\b \cf8 while
\f0\b0 \cf5  (i < s.length() && s[i] != \cf9 ','\cf5 ) \{\
            rt += s[i];\
            i++;\
        \}\
        i++;\
        
\f1\b \cf8 while
\f0\b0 \cf5  (i < s.length() && s[i] != \cf9 ','\cf5 ) \{\
            rr += s[i];\
            i++;\
        \}\
        
\f1\b \cf8 if
\f0\b0 \cf5  (op == \cf4 "move"\cf5 ) \{\
            string s1 = \cf4 "add "\cf5  + rs + \cf4 ","\cf5  + rt + \cf4 ",$0"\cf5 ;\
            Insert(s1);\
        \}\
        
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (op == \cf4 "blt"\cf5 ) \{\
            string s1 = \cf4 "slt $1,"\cf5  + rs + \cf4 ","\cf5  + rt;\
            Insert(s1);\
            s1 = \cf4 "bne $1,$0,"\cf5  + rr;\
            Insert(s1);\
        \}\
        
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (op == \cf4 "bgt"\cf5 ) \{\
            string s1 = \cf4 "slt $1,"\cf5  + rt + \cf4 ","\cf5  + rs;\
            Insert(s1);\
            s1 = \cf4 "bne $1,$0,"\cf5  + rr;\
            Insert(s1);\
        \}\
        
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (op == \cf4 "ble"\cf5 ) \{\
            string s1 = \cf4 "slt $1,"\cf5  + rt + \cf4 ","\cf5  + rs;\
            Insert(s1);\
            s1 = \cf4 "beq $1,$0,"\cf5  + rr;\
            Insert(s1);\
        \}\
        
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (op == \cf4 "bge"\cf5 ) \{\
            string s1 = \cf4 "slt $1,"\cf5  + rs + \cf4 ","\cf5  + rt;\
            Insert(s1);\
            s1 = \cf4 "beq $1,$0,"\cf5  + rr;\
        \}\
    \}\
    
\f1\b \cf8 else
\f0\b0 \cf5  \{\
        Insert(s);\
    \}\
    cout << \cf4 "insert successfully!"\cf5  << endl;\
\}\
\
\cf6 // run the program step by step\cf5 \

\f1\b \cf8 void
\f0\b0 \cf5  \cf7 Cpu\cf5 ::\cf7 RunByStep\cf5 () \{\
    IR_ = \cf4 ""\cf5 ;\
    
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  i = \cf9 0\cf5 ; i < \cf9 4\cf5 ; ++i) \{\
        IR_ += memory_[PC_ + i];\
    \}\
    PC_ += \cf9 4\cf5 ;\
    Execute(IR_);\
\}\
\
\cf6 // show the 32 registers\cf5 \

\f1\b \cf8 void
\f0\b0 \cf5  \cf7 Cpu\cf5 ::\cf7 CheckRegister\cf5 () \{\
    
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  i = \cf9 0\cf5 ; i < \cf9 32\cf5 ; ++i) \{\
        cout << \cf4 "+------------------+-----------------------+"\cf5  << endl;\
        cout << \cf4 "|   Register"\cf5  << i;\
        
\f1\b \cf8 if
\f0\b0 \cf5  (i < \cf9 10\cf5 )\
            cout <<  \cf4 "      |"\cf5 ;\
        
\f1\b \cf8 else
\f0\b0 \cf5 \
            cout <<  \cf4 "     |"\cf5 ;\
        string s = BinaryToHexadecimal(register_[i]);\
        cout << \cf4 "    0x"\cf5  << s << \cf4 "         |"\cf5  << endl;\
    \}\
    cout << \cf4 "+------------------+-----------------------+"\cf5  << endl;\
\}\
\
\cf6 // show the memory\cf5 \

\f1\b \cf8 void
\f0\b0 \cf5  \cf7 Cpu\cf5 ::\cf7 CheckMemory\cf5 () \{\
    cout << \cf4 "PC: "\cf5  << PC_ << endl;\
    
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  i = \cf9 0\cf5 ; i < end_; ++i) \{\
        string s = DecimalToBinary32(i);\
        s = BinaryToHexadecimal(s);\
        cout << \cf4 "+----------------+----------------+"\cf5  << endl;\
        cout << \cf4 "|  0x"\cf5  << s << \cf4 "    |"\cf5 ;\
        cout << \cf4 "   "\cf5  << memory_[i] << \cf4 "     |"\cf5  << endl;\
    \}\
    cout << \cf4 "+----------------+----------------+"\cf5  << endl;\
\}\
\

\f1\b \cf8 void
\f0\b0 \cf5  \cf7 Cpu\cf5 ::\cf7 Convert\cf5 () \{\
    cout << \cf4 "please input the assembly code"\cf5  << endl;\
    string s;\
    getchar();\
    getline(cin , s);\
    MIPS mips(\cf4 "instructor"\cf5 );\
    ofstream ofs(\cf4 "tmp_instructor"\cf5 );\
    ofs << s;\
    ofs.close();\
    mips.convertToBinary(\cf4 "tmp_instructor"\cf5  , \cf4 "tmp_binary_code"\cf5 );\
    ifstream ifs(\cf4 "tmp_binary_code"\cf5 );\
    ifs >> s;\
    ifs.close();\
    cout << \cf4 "the binary code is "\cf5  << s << endl;\
\}\

\f1\b \cf8 void
\f0\b0 \cf5  \cf7 Cpu\cf5 ::\cf7 Invert\cf5 () \{\
    cout << \cf4 "please input the binary code"\cf5  << endl;\
    string s;\
    getchar();\
    getline(cin , s);\
    MipsInvert mips_invert(\cf4 "info.txt"\cf5 );\
    ofstream ofs(\cf4 "binary.txt"\cf5 );\
    ofs << s;\
    ofs.close();\
    mips_invert.Convert(\cf4 "binary.txt"\cf5  , \cf4 "assemble.txt"\cf5 );\
    ifstream ifs(\cf4 "assemble.txt"\cf5 );\
    getline(ifs , s);\
    ifs.close();\
    cout << \cf4 "the assembly code is "\cf5  << s << endl;\
\}\
\
\cf6 // convert a decimal number to 32-bit binary string\cf5 \
string \cf7 Cpu\cf5 ::\cf7 DecimalToBinary32\cf5 (
\f1\b \cf8 int
\f0\b0 \cf5  n) \{\
    vector<
\f1\b \cf8 int
\f0\b0 \cf5 > v;\
    
\f1\b \cf8 int
\f0\b0 \cf5  flag = \cf9 0\cf5 ;\
    
\f1\b \cf8 if
\f0\b0 \cf5  (n < \cf9 0\cf5 ) \{\
        flag = \cf9 1\cf5 ;\
        n = -n;\
    \}\
    
\f1\b \cf8 while
\f0\b0 \cf5  (n > \cf9 0\cf5 ) \{\
        v.push_back(n % \cf9 2\cf5 );\
        n /= \cf9 2\cf5 ;\
    \}\
    string res = \cf4 ""\cf5 ;\
    
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  i = \cf9 0\cf5 ; i < \cf9 32\cf5  - v.size(); ++i) \{\
        res += \cf4 "0"\cf5 ;\
    \}\
    
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  i = v.size() - \cf9 1\cf5 ; i >= \cf9 0\cf5 ; --i) \{\
        res += v[i] + \cf9 '0'\cf5 ;\
    \}\
    
\f1\b \cf8 if
\f0\b0 \cf5  (flag == \cf9 1\cf5 ) \{\
        string res1 = \cf4 ""\cf5 ;\
        
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  i = \cf9 0\cf5 ; i < res.length(); ++i) \{\
            
\f1\b \cf8 if
\f0\b0 \cf5  (res[i] == \cf9 '0'\cf5 )\
                res1 += \cf9 '1'\cf5 ;\
            
\f1\b \cf8 else
\f0\b0 \cf5 \
                res1 += \cf9 '0'\cf5 ;\
        \}\
        
\f1\b \cf8 int
\f0\b0 \cf5  carry = \cf9 1\cf5 ;\
        
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  i = res1.length() - \cf9 1\cf5 ; i >= \cf9 0\cf5 ; --i) \{\
            
\f1\b \cf8 int
\f0\b0 \cf5  t = res1[i] - \cf9 '0'\cf5 ;\
            t += carry;\
            
\f1\b \cf8 if
\f0\b0 \cf5  (t > \cf9 1\cf5 ) \{\
                res1[i] = \cf9 '0'\cf5 ;\
                carry = \cf9 1\cf5 ;\
            \}\
            
\f1\b \cf8 else
\f0\b0 \cf5  \{\
                res1[i] = t + \cf9 '0'\cf5 ;\
                
\f1\b \cf8 break
\f0\b0 \cf5 ;\
            \}\
        \}\
        
\f1\b \cf8 return
\f0\b0 \cf5  res1;\
    \}\
    
\f1\b \cf8 return
\f0\b0 \cf5  res;\
\}\
\
\cf6 // convert a binary string to signed decimal\cf5 \

\f1\b \cf8 int
\f0\b0 \cf5  \cf7 Cpu\cf5 ::\cf7 BinaryToDecimalSigned\cf5 (string s) \{\
    
\f1\b \cf8 int
\f0\b0 \cf5  flag = \cf9 0\cf5 ;\
    
\f1\b \cf8 if
\f0\b0 \cf5  (s[\cf9 0\cf5 ] == \cf9 1\cf5 ) \{\
        flag = \cf9 1\cf5 ;\
        
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  i = \cf9 0\cf5 ; i < s.length(); ++i) \{\
            
\f1\b \cf8 if
\f0\b0 \cf5  (s[i] == \cf9 '0'\cf5 )\
                s[i] = \cf9 '1'\cf5 ;\
            
\f1\b \cf8 else
\f0\b0 \cf5 \
                s[i] = \cf9 '0'\cf5 ;\
        \}\
        
\f1\b \cf8 int
\f0\b0 \cf5  carry = \cf9 0\cf5 ;\
        
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  i = s.length() - \cf9 1\cf5 ; i >= \cf9 0\cf5 ; --i) \{\
            
\f1\b \cf8 int
\f0\b0 \cf5  t = s[i] - \cf9 '0'\cf5 ;\
            t = t + carry;\
            
\f1\b \cf8 if
\f0\b0 \cf5  (t > \cf9 1\cf5 ) \{\
                s[i] = \cf9 0\cf5 ;\
                carry = \cf9 1\cf5 ;\
            \}\
            
\f1\b \cf8 else
\f0\b0 \cf5 \{\
                s[i] = t;\
                carry = \cf9 0\cf5 ;\
            \}\
        \}\
    \}\
    
\f1\b \cf8 int
\f0\b0 \cf5  res = \cf9 0\cf5 ;\
    
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  i = \cf9 1\cf5 ; i < s.length(); ++i) \{\
        res = res * \cf9 2\cf5  + s[i] - \cf9 '0'\cf5 ;\
    \}\
    
\f1\b \cf8 if
\f0\b0 \cf5  (flag == \cf9 1\cf5 )\
        res = -res;\
    
\f1\b \cf8 return
\f0\b0 \cf5  res;\
\}\
\
\cf6 // convert a binary string to unsigned decimal\cf5 \

\f1\b \cf8 int
\f0\b0 \cf5  \cf7 Cpu\cf5 ::\cf7 BinaryToDecimalUnsigned\cf5 (string s) \{\
    
\f1\b \cf8 int
\f0\b0 \cf5  res = \cf9 0\cf5 ;\
    
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  i = \cf9 0\cf5 ; i < s.length(); ++i) \{\
        res = res * \cf9 2\cf5  + s[i] - \cf9 '0'\cf5 ;\
    \}\
    
\f1\b \cf8 return
\f0\b0 \cf5  res;\
\}\
\
\cf6 // convert a binary string to hexadecimal string\cf5 \
string \cf7 Cpu\cf5 ::\cf7 BinaryToHexadecimal\cf5 (string s) \{\
    string res = \cf4 ""\cf5 ;\
    
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  i = \cf9 0\cf5 ; i < s.length(); i = i + \cf9 4\cf5 ) \{\
        
\f1\b \cf8 int
\f0\b0 \cf5  t = \cf9 0\cf5 ;\
        
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  j = \cf9 0\cf5 ; j < \cf9 4\cf5 ; ++j) \{\
            t = t * \cf9 2\cf5  + s[i + j] - \cf9 '0'\cf5 ;\
        \}\
        
\f1\b \cf8 if
\f0\b0 \cf5  (t < \cf9 10\cf5 )\
            res += t + \cf9 '0'\cf5 ;\
        
\f1\b \cf8 else
\f0\b0 \cf5 \
            res += t - \cf9 10\cf5  + \cf9 'A'\cf5 ;\
    \}\
    
\f1\b \cf8 return
\f0\b0 \cf5  res;\
\}\
\
\cf6 // shift left logiclly\cf5 \
string \cf7 Cpu\cf5 ::\cf7 ShiftLeftLogic\cf5 (string s , 
\f1\b \cf8 unsigned
\f0\b0 \cf5  
\f1\b \cf8 int
\f0\b0 \cf5  shamt) \{\
    
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  i = \cf9 0\cf5 ; i < shamt; ++i) \{\
        
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  j = \cf9 0\cf5 ; j < s.length() - \cf9 1\cf5 ; ++j) \{\
            s[j] = s[j + \cf9 1\cf5 ];\
        \}\
        s[s.length() - \cf9 1\cf5 ] = \cf9 '0'\cf5 ;\
    \}\
    
\f1\b \cf8 return
\f0\b0 \cf5  s;\
\}\
\
\cf6 // shift right logiclly\cf5 \
string \cf7 Cpu\cf5 ::\cf7 ShiftRightLogic\cf5 (string s , 
\f1\b \cf8 unsigned
\f0\b0 \cf5  
\f1\b \cf8 int
\f0\b0 \cf5  shamt) \{\
    
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  i = \cf9 0\cf5 ; i < shamt; ++i) \{\
        
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  j = s.length() - \cf9 1\cf5 ; j > \cf9 0\cf5 ; --j) \{\
            s[j] = s[j - \cf9 1\cf5 ];\
        \}\
        s[\cf9 0\cf5 ] = \cf9 '0'\cf5 ;\
    \}\
    
\f1\b \cf8 return
\f0\b0 \cf5  s;\
\}\
\
\cf6 // shift right arithmetic\cf5 \
string \cf7 Cpu\cf5 ::\cf7 ShiftRightArithmetic\cf5 (string s , 
\f1\b \cf8 unsigned
\f0\b0 \cf5  
\f1\b \cf8 int
\f0\b0 \cf5  shamt) \{\
    
\f1\b \cf8 char
\f0\b0 \cf5  c = s[\cf9 0\cf5 ];\
    
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  i = \cf9 0\cf5 ; i < shamt; ++i) \{\
        
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  j = s.length() - \cf9 1\cf5 ; j > \cf9 0\cf5 ; --j) \{\
            s[j] = s[j - \cf9 1\cf5 ];\
        \}\
        s[\cf9 0\cf5 ] = c;\
    \}\
    
\f1\b \cf8 return
\f0\b0 \cf5  s;\
\}\
\
\cf6 // execute module (core module)\cf5 \

\f1\b \cf8 void
\f0\b0 \cf5  \cf7 Cpu\cf5 ::\cf7 Execute\cf5 (string s) \{\
    
\f1\b \cf8 int
\f0\b0 \cf5  rs = BinaryToDecimalUnsigned(s.substr(\cf9 6\cf5  , \cf9 5\cf5 ));\
    
\f1\b \cf8 int
\f0\b0 \cf5  rt = BinaryToDecimalUnsigned(s.substr(\cf9 11\cf5  , \cf9 5\cf5 ));\
    
\f1\b \cf8 int
\f0\b0 \cf5  rd = BinaryToDecimalUnsigned(s.substr(\cf9 16\cf5  , \cf9 5\cf5 ));\
    
\f1\b \cf8 int
\f0\b0 \cf5  shamt = BinaryToDecimalSigned(s.substr(\cf9 21\cf5  , \cf9 5\cf5 ));\
    
\f1\b \cf8 int
\f0\b0 \cf5  imm = BinaryToDecimalSigned(s.substr(\cf9 16\cf5  , \cf9 16\cf5 ));\
    
\f1\b \cf8 int
\f0\b0 \cf5  t1 = BinaryToDecimalSigned(register_[rs]);\
    
\f1\b \cf8 int
\f0\b0 \cf5  t2 = BinaryToDecimalSigned(register_[rt]);\
    
\f1\b \cf8 int
\f0\b0 \cf5  t3 = BinaryToDecimalUnsigned(register_[rs]);\
    
\f1\b \cf8 int
\f0\b0 \cf5  address = t3 + imm;\
    string op = s.substr(\cf9 0\cf5  , \cf9 6\cf5 );\
    \cf6 // R-type instruction\cf5 \
    
\f1\b \cf8 if
\f0\b0 \cf5  (op == \cf4 "000000"\cf5 ) \{\
        string func = s.substr(\cf9 26\cf5  , \cf9 6\cf5 );\
        \cf6 // add\cf5 \
        
\f1\b \cf8 if
\f0\b0 \cf5  (func == \cf4 "100000"\cf5 ) \{\
            register_[rd] = DecimalToBinary32(t1 + t2);\
        \}   \
        \cf6 // addu\cf5 \
        
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (func == \cf4 "100001"\cf5 ) \{\
            t1 = BinaryToDecimalUnsigned(register_[rs]);\
            t2 = BinaryToDecimalUnsigned(register_[rt]);\
            register_[rd] = DecimalToBinary32(t1 + t2);\
        \}\
        \cf6 // sub\cf5 \
        
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (func == \cf4 "100010"\cf5 ) \{\
            register_[rd] = DecimalToBinary32(t1 - t2);\
        \}\
        \cf6 // subu\cf5 \
        
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (func == \cf4 "100011"\cf5 ) \{\
            t1 = BinaryToDecimalUnsigned(register_[rs]);\
            t2 = BinaryToDecimalUnsigned(register_[rt]);\
            register_[rd] = DecimalToBinary32(t1 - t2);\
        \}\
        \cf6 // and\cf5 \
        
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (func == \cf4 "100100"\cf5 ) \{\
            register_[rd] = DecimalToBinary32(t1 & t2);\
        \}\
        \cf6 // or\cf5 \
        
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (func == \cf4 "100101"\cf5 ) \{\
            register_[rd] = DecimalToBinary32(t1 | t2);\
        \}\
        \cf6 // xor\cf5 \
        
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (func == \cf4 "100110"\cf5 ) \{\
            register_[rd] = DecimalToBinary32(t1 ^ t2);\
        \}\
        \cf6 // nor\cf5 \
        
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (func == \cf4 "100111"\cf5 ) \{\
            register_[rd] = DecimalToBinary32(~(t1 | t2));\
        \}\
        \cf6 // slt\cf5 \
        
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (func == \cf4 "101010"\cf5 ) \{\
            register_[rd] = DecimalToBinary32(t1 < t2 ? \cf9 1\cf5  : \cf9 0\cf5 );\
        \}\
        \cf6 // sltu\cf5 \
        
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (func == \cf4 "101011"\cf5 ) \{\
            t1 = BinaryToDecimalUnsigned(register_[rs]);\
            t2 = BinaryToDecimalUnsigned(register_[rt]);\
            register_[rd] = DecimalToBinary32(t1 < t2 ? \cf9 1\cf5  : \cf9 0\cf5 );\
        \}\
        \cf6 // sll\cf5 \
        
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (func == \cf4 "000000"\cf5 ) \{\
            register_[rd] = ShiftLeftLogic(register_[rt] , shamt);\
        \}\
        \cf6 // srl\cf5 \
        
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (func == \cf4 "000010"\cf5 ) \{\
            register_[rd] = ShiftRightLogic(register_[rt] , shamt);\
        \}\
        \cf6 // sra\cf5 \
        
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (func == \cf4 "000011"\cf5 ) \{\
            register_[rd] = ShiftRightArithmetic(register_[rt] , shamt);\
        \}\
        \cf6 // sllv\cf5 \
        
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (func == \cf4 "000100"\cf5 ) \{\
            t1 = BinaryToDecimalUnsigned(register_[rs]);\
            register_[rd] = ShiftLeftLogic(register_[rt] , t1);\
        \}\
        \cf6 // srlv\cf5 \
        
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (func == \cf4 "000110"\cf5 ) \{\
            t1 = BinaryToDecimalUnsigned(register_[rs]);\
            register_[rd] = ShiftRightLogic(register_[rt] , t1);\
        \}\
        \cf6 // srav\cf5 \
        
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (func == \cf4 "000111"\cf5 ) \{\
            t1 = BinaryToDecimalUnsigned(register_[rs]);\
            register_[rd] = ShiftRightArithmetic(register_[rt] , t1);\
        \}\
        \cf6 // jr\cf5 \
        
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (func == \cf4 "001000"\cf5 ) \{\
            PC_ = BinaryToDecimalUnsigned(register_[rs]);\
        \}\
    \}\
    \cf6 // addi\cf5 \
    
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (op == \cf4 "001000"\cf5 ) \{\
        register_[rt] = DecimalToBinary32(t1 + imm);\
    \}\
    \cf6 // addiu\cf5 \
    
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (op == \cf4 "001001"\cf5 ) \{\
        t1 = BinaryToDecimalUnsigned(register_[rs]);\
        register_[rt] = DecimalToBinary32(t1 + imm);\
    \}\
    \cf6 // andi\cf5 \
    
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (op == \cf4 "001100"\cf5 ) \{\
        register_[rt] = DecimalToBinary32(t1 & imm);\
    \}\
    \cf6 // ori\cf5 \
    
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (op == \cf4 "001101"\cf5 ) \{\
        register_[rt] = DecimalToBinary32(t1 | imm);\
    \}\
    \cf6 // xori\cf5 \
    
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (op == \cf4 "001110"\cf5 ) \{\
        register_[rt] = DecimalToBinary32(t1 ^ imm);\
    \}\
    \cf6 // lw\cf5 \
    
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (op == \cf4 "100011"\cf5 ) \{\
        register_[rt] = \cf4 ""\cf5 ;\
        
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  i = \cf9 0\cf5 ; i< \cf9 4\cf5 ; ++i) \{\
            register_[rt] += memory_[address + i];\
        \}\
    \}\
    \cf6 // sw\cf5 \
    
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (op == \cf4 "101011"\cf5 ) \{\
        
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  i = \cf9 0\cf5 ; i < \cf9 4\cf5 ; ++i) \{\
            memory_[address + i] = register_[rt].substr(\cf9 8\cf5  * i , \cf9 8\cf5 );\
        \}\
    \}\
    \cf6 // beq\cf5 \
    
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (op == \cf4 "000100"\cf5 ) \{\
        
\f1\b \cf8 if
\f0\b0 \cf5  (t1 == t2) \{\
            PC_ = PC_ + imm * \cf9 4\cf5 ;\
        \}\
    \}\
    \cf6 // bne\cf5 \
    
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (op == \cf4 "000101"\cf5 ) \{\
        
\f1\b \cf8 if
\f0\b0 \cf5  (t1 != t2) \{\
            PC_ = PC_ + imm * \cf9 4\cf5 ;\
        \}\
    \}\
    \cf6 // slti\cf5 \
    
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (op == \cf4 "001010"\cf5 ) \{\
        register_[rt] = DecimalToBinary32(t1 < imm ? \cf9 1\cf5  : \cf9 0\cf5 );\
    \}\
    \cf6 // sltiu\cf5 \
    
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (op == \cf4 "001011"\cf5 ) \{\
        t1 = BinaryToDecimalUnsigned(register_[rs]);\
        register_[rt] = DecimalToBinary32(t1 < imm ? \cf9 1\cf5  : \cf9 0\cf5 );\
    \}\
    \cf6 // j and jal\cf5 \
    
\f1\b \cf8 else
\f0\b0 \cf5  
\f1\b \cf8 if
\f0\b0 \cf5  (op == \cf4 "000010"\cf5  || op == \cf4 "000011"\cf5 ) \{\
        string address = s.substr(\cf9 6\cf5  , \cf9 26\cf5 ) + \cf4 "00"\cf5 ;\
        string pc = DecimalToBinary32(PC_);\
        address = pc.substr(\cf9 0\cf5  , \cf9 4\cf5 ) + address;\
        PC_ = BinaryToDecimalUnsigned(address);\
        \cf6 // jal\cf5 \
        
\f1\b \cf8 if
\f0\b0 \cf5  (op == \cf4 "000011"\cf5 )\
            register_[\cf9 31\cf5 ] = DecimalToBinary32(PC_);\
    \}\
\}\
\

\f1\b \cf8 void
\f0\b0 \cf5  \cf7 Cpu\cf5 ::\cf7 Insert\cf5 (string s) \{\
    ofstream ofs(\cf4 "tmp_instructor"\cf5 );\
    ofs << s;\
    ofs.close();\
    MIPS m(\cf4 "instructor"\cf5 );\
    m.convertToBinary(\cf4 "tmp_instructor"\cf5  , \cf4 "tmp_binary_code"\cf5 );\
    ifstream ifs(\cf4 "tmp_binary_code"\cf5 );\
    ifs >> s;\
    ifs.close();\
    
\f1\b \cf8 for
\f0\b0 \cf5  (
\f1\b \cf8 int
\f0\b0 \cf5  i = \cf9 0\cf5 ; i < \cf9 4\cf5 ; ++i) \{\
        memory_[end_ + i] = s.substr(\cf9 8\cf5  * i , \cf9 8\cf5 );\
    \}\
    end_ += \cf9 4\cf5 ;\
\}\
}Oa???# i n c l u d e   " c p u . h " 
 
 / /   d e f a u l t   c o n s t r u c t o r 
 C p u : : C p u ( )   { 
         i n t   i ; 
         f o r   ( i   =   0 ;   i   <   5 0 0 1 ;   + + i )   
                 m e m o r y _ . p u s h _ b a c k ( " 0 0 0 0 0 0 0 0 " ) ; 
         s t r i n g   s   =   " " ; 
         f o r   ( i   =   0 ;   i   <   3 2 ;   + + i )   
                 s   + =   " 0 " ; 
         f o r   ( i   =   0 ;   i   <   3 2 ;   + + i )   
                 r e g i s t e r _ . p u s h _ b a c k ( s ) ; 
         s   =   D e c i m a l T o B i n a r y 3 2 ( 5 0 0 1 ) ; 
         r e g i s t e r _ [ 2 9 ]   =   s ; 
         P C _   =   0 ; 
         e n d _   =   0 ; 
         I R _   =   " " ; 
 } 
 
 / /   i n s e r t   a n   i n s t r u c t o r   i n t o   m e m o r y 
 v o i d   C p u : : I n s e r t I n s t r u c t o r ( )   { 
         s t r i n g   s ; 
         c o u t   < <   " p l e a s e   i n p u t   t h e   a s s e m b l y   c l a u s e . "   < <   e n d l ; 
         c o u t   < <   " I n p u t   e x a m p l e :   a d d   $ 1 , $ 2 , $ 3 "   < <   e n d l ; 
         g e t c h a r ( ) ; 
         g e t l i n e ( c i n   ,   s ) ; 
         s t r i n g   o p ; 
         i n t   i   =   0 ; 
         w h i l e   ( s [ i ]   ! =   '   ' )   { 
                 o p   + =   s [ i ] ; 
                 i + + ; 
         } 
         i f   ( o p   = =   " m o v e "   | |   o p   = =   " b l t "   | |   o p   = =   " b g t "   | |   o p   = =   " b l e "   | |   o p   = =   " b g e " )   { 
                 s t r i n g   r r ; 
                 s t r i n g   r s ; 
                 s t r i n g   r t ; 
                 i + + ; 
                 w h i l e   ( s [ i ]   ! =   ' , ' )   { 
                         r s   + =   s [ i ] ; 
                         i + + ; 
                 } 
                 i + + ; 
                 w h i l e   ( i   <   s . l e n g t h ( )   & &   s [ i ]   ! =   ' , ' )   { 
                         r t   + =   s [ i ] ; 
                         i + + ; 
                 } 
                 i + + ; 
                 w h i l e   ( i   <   s . l e n g t h ( )   & &   s [ i ]   ! =   ' , ' )   { 
                         r r   + =   s [ i ] ; 
                         i + + ; 
                 } 
                 i f   ( o p   = =   " m o v e " )   { 
                         s t r i n g   s 1   =   " a d d   "   +   r s   +   " , "   +   r t   +   " , $ 0 " ; 
                         I n s e r t ( s 1 ) ; 
                 } 
                 e l s e   i f   ( o p   = =   " b l t " )   { 
                         s t r i n g   s 1   =   " s l t   $ 1 , "   +   r s   +   " , "   +   r t ; 
                         I n s e r t ( s 1 ) ; 
                         s 1   =   " b n e   $ 1 , $ 0 , "   +   r r ; 
                         I n s e r t ( s 1 ) ; 
                 } 
                 e l s e   i f   ( o p   = =   " b g t " )   { 
                         s t r i n g   s 1   =   " s l t   $ 1 , "   +   r t   +   " , "   +   r s ; 
                         I n s e r t ( s 1 ) ; 
                         s 1   =   " b n e   $ 1 , $ 0 , "   +   r r ; 
                         I n s e r t ( s 1 ) ; 
                 } 
                 e l s e   i f   ( o p   = =   " b l e " )   { 
                         s t r i n g   s 1   =   " s l t   $ 1 , "   +   r t   +   " , "   +   r s ; 
                         I n s e r t ( s 1 ) ; 
                         s 1   =   " b e q   $ 1 , $ 0 , "   +   r r ; 
                         I n s e r t ( s 1 ) ; 
                 } 
                 e l s e   i f   ( o p   = =   " b g e " )   { 
                         s t r i n g   s 1   =   " s l t   $ 1 , "   +   r s   +   " , "   +   r t ; 
                         I n s e r t ( s 1 ) ; 
                         s 1   =   " b e q   $ 1 , $ 0 , "   +   r r ; 
                 } 
         } 
         e l s e   { 
                 I n s e r t ( s ) ; 
         } 
         c o u t   < <   " i n s e r t   s u c c e s s f u l l y ! "   < <   e n d l ; 
 } 
 
 / /   r u n   t h e   p r o g r a m   s t e p   b y   s t e p 
 v o i d   C p u : : R u n B y S t e p ( )   { 
         I R _   =   " " ; 
         f o r   ( i n t   i   =   0 ;   i   <   4 ;   + + i )   { 
                 I R _   + =   m e m o r y _ [ P C _   +   i ] ; 
         } 
         P C _   + =   4 ; 
         E x e c u t e ( I R _ ) ; 
 } 
 
 / /   s h o w   t h e   3 2   r e g i s t e r s 
 v o i d   C p u : : C h e c k R e g i s t e r ( )   { 
         f o r   ( i n t   i   =   0 ;   i   <   3 2 ;   + + i )   { 
                 c o u t   < <   " + - - - - - - - - - - - - - - - - - - + - - - - - - - - - - - - - - - - - - - - - - - + "   < <   e n d l ; 
                 c o u t   < <   " |       R e g i s t e r "   < <   i ; 
                 i f   ( i   <   1 0 ) 
                         c o u t   < <     "             | " ; 
                 e l s e 
                         c o u t   < <     "           | " ; 
                 s t r i n g   s   =   B i n a r y T o H e x a d e c i m a l ( r e g i s t e r _ [ i ] ) ; 
                 c o u t   < <   "         0 x "   < <   s   < <   "                   | "   < <   e n d l ; 
         } 
         c o u t   < <   " + - - - - - - - - - - - - - - - - - - + - - - - - - - - - - - - - - - - - - - - - - - + "   < <   e n d l ; 
 } 
 
 / /   s h o w   t h e   m e m o r y 
 v o i d   C p u : : C h e c k M e m o r y ( )   { 
         c o u t   < <   " P C :   "   < <   P C _   < <   e n d l ; 
         f o r   ( i n t   i   =   0 ;   i   <   e n d _ ;   + + i )   { 
                 s t r i n g   s   =   D e c i m a l T o B i n a r y 3 2 ( i ) ; 
                 s   =   B i n a r y T o H e x a d e c i m a l ( s ) ; 
                 c o u t   < <   " + - - - - - - - - - - - - - - - - + - - - - - - - - - - - - - - - - + "   < <   e n d l ; 
                 c o u t   < <   " |     0 x "   < <   s   < <   "         | " ; 
                 c o u t   < <   "       "   < <   m e m o r y _ [ i ]   < <   "           | "   < <   e n d l ; 
         } 
         c o u t   < <   " + - - - - - - - - - - - - - - - - + - - - - - - - - - - - - - - - - + "   < <   e n d l ; 
 } 
 
 v o i d   C p u : : C o n v e r t ( )   { 
         c o u t   < <   " p l e a s e   i n p u t   t h e   a s s e m b l y   c o d e "   < <   e n d l ; 
         s t r i n g   s ; 
         g e t c h a r ( ) ; 
         g e t l i n e ( c i n   ,   s ) ; 
         M I P S   m i p s ( " i n s t r u c t o r " ) ; 
         o f s t r e a m   o f s ( " t m p _ i n s t r u c t o r " ) ; 
         o f s   < <   s ; 
         o f s . c l o s e ( ) ; 
         m i p s . c o n v e r t T o B i n a r y ( " t m p _ i n s t r u c t o r "   ,   " t m p _ b i n a r y _ c o d e " ) ; 
         i f s t r e a m   i f s ( " t m p _ b i n a r y _ c o d e " ) ; 
         i f s   > >   s ; 
         i f s . c l o s e ( ) ; 
         c o u t   < <   " t h e   b i n a r y   c o d e   i s   "   < <   s   < <   e n d l ; 
 } 
 v o i d   C p u : : I n v e r t ( )   { 
         c o u t   < <   " p l e a s e   i n p u t   t h e   b i n a r y   c o d e "   < <   e n d l ; 
         s t r i n g   s ; 
         g e t c h a r ( ) ; 
         g e t l i n e ( c i n   ,   s ) ; 
         M i p s I n v e r t   m i p s _ i n v e r t ( " i n f o . t x t " ) ; 
         o f s t r e a m   o f s ( " b i n a r y . t x t " ) ; 
         o f s   < <   s ; 
         o f s . c l o s e ( ) ; 
         m i p s _ i n v e r t . C o n v e r t ( " b i n a r y . t x t "   ,   " a s s e m b l e . t x t " ) ; 
         i f s t r e a m   i f s ( " a s s e m b l e . t x t " ) ; 
         g e t l i n e ( i f s   ,   s ) ; 
         i f s . c l o s e ( ) ; 
         c o u t   < <   " t h e   a s s e m b l y   c o d e   i s   "   < <   s   < <   e n d l ; 
 } 
 
 / /   c o n v e r t   a   d e c i m a l   n u m b e r   t o   3 2 - b i t   b i n a r y   s t r i n g 
 s t r i n g   C p u : : D e c i m a l T o B i n a r y 3 2 ( i n t   n )   { 
         v e c t o r < i n t >   v ; 
         i n t   f l a g   =   0 ; 
         i f   ( n   <   0 )   { 
                 f l a g   =   1 ; 
                 n   =   - n ; 
         } 
         w h i l e   ( n   >   0 )   { 
                 v . p u s h _ b a c k ( n   %   2 ) ; 
                 n   / =   2 ; 
         } 
         s t r i n g   r e s   =   " " ; 
         f o r   ( i n t   i   =   0 ;   i   <   3 2   -   v . s i z e ( ) ;   + + i )   { 
                 r e s   + =   " 0 " ; 
         } 
         f o r   ( i n t   i   =   v . s i z e ( )   -   1 ;   i   > =   0 ;   - - i )   { 
                 r e s   + =   v [ i ]   +   ' 0 ' ; 
         } 
         i f   ( f l a g   = =   1 )   { 
                 s t r i n g   r e s 1   =   " " ; 
                 f o r   ( i n t   i   =   0 ;   i   <   r e s . l e n g t h ( ) ;   + + i )   { 
                         i f   ( r e s [ i ]   = =   ' 0 ' ) 
                                 r e s 1   + =   ' 1 ' ; 
                         e l s e 
                                 r e s 1   + =   ' 0 ' ; 
                 } 
                 i n t   c a r r y   =   1 ; 
                 f o r   ( i n t   i   =   r e s 1 . l e n g t h ( )   -   1 ;   i   > =   0 ;   - - i )   { 
                         i n t   t   =   r e s 1 [ i ]   -   ' 0 ' ; 
                         t   + =   c a r r y ; 
                         i f   ( t   >   1 )   { 
                                 r e s 1 [ i ]   =   ' 0 ' ; 
                                 c a r r y   =   1 ; 
                         } 
                         e l s e   { 
                                 r e s 1 [ i ]   =   t   +   ' 0 ' ; 
                                 b r e a k ; 
                         } 
                 } 
                 r e t u r n   r e s 1 ; 
         } 
         r e t u r n   r e s ; 
 } 
 
 / /   c o n v e r t   a   b i n a r y   s t r i n g   t o   s i g n e d   d e c i m a l 
 i n t   C p u : : B i n a r y T o D e c i m a l S i g n e d ( s t r i n g   s )   { 
         i n t   f l a g   =   0 ; 
         i f   ( s [ 0 ]   = =   1 )   { 
                 f l a g   =   1 ; 
                 f o r   ( i n t   i   =   0 ;   i   <   s . l e n g t h ( ) ;   + + i )   { 
                         i f   ( s [ i ]   = =   ' 0 ' ) 
                                 s [ i ]   =   ' 1 ' ; 
                         e l s e 
                                 s [ i ]   =   ' 0 ' ; 
                 } 
                 i n t   c a r r y   =   0 ; 
                 f o r   ( i n t   i   =   s . l e n g t h ( )   -   1 ;   i   > =   0 ;   - - i )   { 
                         i n t   t   =   s [ i ]   -   ' 0 ' ; 
                         t   =   t   +   c a r r y ; 
                         i f   ( t   >   1 )   { 
                                 s [ i ]   =   0 ; 
                                 c a r r y   =   1 ; 
                         } 
                         e l s e { 
                                 s [ i ]   =   t ; 
                                 c a r r y   =   0 ; 
                         } 
                 } 
         } 
         i n t   r e s   =   0 ; 
         f o r   ( i n t   i   =   1 ;   i   <   s . l e n g t h ( ) ;   + + i )   { 
                 r e s   =   r e s   *   2   +   s [ i ]   -   ' 0 ' ; 
         } 
         i f   ( f l a g   = =   1 ) 
                 r e s   =   - r e s ; 
         r e t u r n   r e s ; 
 } 
 
 / /   c o n v e r t   a   b i n a r y   s t r i n g   t o   u n s i g n e d   d e c i m a l 
 i n t   C p u : : B i n a r y T o D e c i m a l U n s i g n e d ( s t r i n g   s )   { 
         i n t   r e s   =   0 ; 
         f o r   ( i n t   i   =   0 ;   i   <   s . l e n g t h ( ) ;   + + i )   { 
                 r e s   =   r e s   *   2   +   s [ i ]   -   ' 0 ' ; 
         } 
         r e t u r n   r e s ; 
 } 
 
 / /   c o n v e r t   a   b i n a r y   s t r i n g   t o   h e x a d e c i m a l   s t r i n g 
 s t r i n g   C p u : : B i n a r y T o H e x a d e c i m a l ( s t r i n g   s )   { 
         s t r i n g   r e s   =   " " ; 
         f o r   ( i n t   i   =   0 ;   i   <   s . l e n g t h ( ) ;   i   =   i   +   4 )   { 
                 i n t   t   =   0 ; 
                 f o r   ( i n t   j   =   0 ;   j   <   4 ;   + + j )   { 
                         t   =   t   *   2   +   s [ i   +   j ]   -   ' 0 ' ; 
                 } 
                 i f   ( t   <   1 0 ) 
                         r e s   + =   t   +   ' 0 ' ; 
                 e l s e 
                         r e s   + =   t   -   1 0   +   ' A ' ; 
         } 
         r e t u r n   r e s ; 
 } 
 
 / /   s h i f t   l e f t   l o g i c l l y 
 s t r i n g   C p u : : S h i f t L e f t L o g i c ( s t r i n g   s   ,   u n s i g n e d   i n t   s h a m t )   { 
         f o r   ( i n t   i   =   0 ;   i   <   s h a m t ;   + + i )   { 
                 f o r   ( i n t   j   =   0 ;   j   <   s . l e n g t h ( )   -   1 ;   + + j )   { 
                         s [ j ]   =   s [ j   +   1 ] ; 
                 } 
                 s [ s . l e n g t h ( )   -   1 ]   =   ' 0 ' ; 
         } 
         r e t u r n   s ; 
 } 
 
 / /   s h i f t   r i g h t   l o g i c l l y 
 s t r i n g   C p u : : S h i f t R i g h t L o g i c ( s t r i n g   s   ,   u n s i g n e d   i n t   s h a m t )   { 
         f o r   ( i n t   i   =   0 ;   i   <   s h a m t ;   + + i )   { 
                 f o r   ( i n t   j   =   s . l e n g t h ( )   -   1 ;   j   >   0 ;   - - j )   { 
                         s [ j ]   =   s [ j   -   1 ] ; 
                 } 
                 s [ 0 ]   =   ' 0 ' ; 
         } 
         r e t u r n   s ; 
 } 
 
 / /   s h i f t   r i g h t   a r i t h m e t i c 
 s t r i n g   C p u : : S h i f t R i g h t A r i t h m e t i c ( s t r i n g   s   ,   u n s i g n e d   i n t   s h a m t )   { 
         c h a r   c   =   s [ 0 ] ; 
         f o r   ( i n t   i   =   0 ;   i   <   s h a m t ;   + + i )   { 
                 f o r   ( i n t   j   =   s . l e n g t h ( )   -   1 ;   j   >   0 ;   - - j )   { 
                         s [ j ]   =   s [ j   -   1 ] ; 
                 } 
                 s [ 0 ]   =   c ; 
         } 
         r e t u r n   s ; 
 } 
 
 / /   e x e c u t e   m o d u l e   ( c o r e   m o d u l e ) 
 v o i d   C p u : : E x e c u t e ( s t r i n g   s )   { 
         i n t   r s   =   B i n a r y T o D e c i m a l U n s i g n e d ( s . s u b s t r ( 6   ,   5 ) ) ; 
         i n t   r t   =   B i n a r y T o D e c i m a l U n s i g n e d ( s . s u b s t r ( 1 1   ,   5 ) ) ; 
         i n t   r d   =   B i n a r y T o D e c i m a l U n s i g n e d ( s . s u b s t r ( 1 6   ,   5 ) ) ; 
         i n t   s h a m t   =   B i n a r y T o D e c i m a l S i g n e d ( s . s u b s t r ( 2 1   ,   5 ) ) ; 
         i n t   i m m   =   B i n a r y T o D e c i m a l S i g n e d ( s . s u b s t r ( 1 6   ,   1 6 ) ) ; 
         i n t   t 1   =   B i n a r y T o D e c i m a l S i g n e d ( r e g i s t e r _ [ r s ] ) ; 
         i n t   t 2   =   B i n a r y T o D e c i m a l S i g n e d ( r e g i s t e r _ [ r t ] ) ; 
         i n t   t 3   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r s ] ) ; 
         i n t   a d d r e s s   =   t 3   +   i m m ; 
         s t r i n g   o p   =   s . s u b s t r ( 0   ,   6 ) ; 
         / /   R - t y p e   i n s t r u c t i o n 
         i f   ( o p   = =   " 0 0 0 0 0 0 " )   { 
                 s t r i n g   f u n c   =   s . s u b s t r ( 2 6   ,   6 ) ; 
                 / /   a d d 
                 i f   ( f u n c   = =   " 1 0 0 0 0 0 " )   { 
                         r e g i s t e r _ [ r d ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   +   t 2 ) ; 
                 }       
                 / /   a d d u 
                 e l s e   i f   ( f u n c   = =   " 1 0 0 0 0 1 " )   { 
                         t 1   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r s ] ) ; 
                         t 2   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r t ] ) ; 
                         r e g i s t e r _ [ r d ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   +   t 2 ) ; 
                 } 
                 / /   s u b 
                 e l s e   i f   ( f u n c   = =   " 1 0 0 0 1 0 " )   { 
                         r e g i s t e r _ [ r d ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   -   t 2 ) ; 
                 } 
                 / /   s u b u 
                 e l s e   i f   ( f u n c   = =   " 1 0 0 0 1 1 " )   { 
                         t 1   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r s ] ) ; 
                         t 2   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r t ] ) ; 
                         r e g i s t e r _ [ r d ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   -   t 2 ) ; 
                 } 
                 / /   a n d 
                 e l s e   i f   ( f u n c   = =   " 1 0 0 1 0 0 " )   { 
                         r e g i s t e r _ [ r d ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   &   t 2 ) ; 
                 } 
                 / /   o r 
                 e l s e   i f   ( f u n c   = =   " 1 0 0 1 0 1 " )   { 
                         r e g i s t e r _ [ r d ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   |   t 2 ) ; 
                 } 
                 / /   x o r 
                 e l s e   i f   ( f u n c   = =   " 1 0 0 1 1 0 " )   { 
                         r e g i s t e r _ [ r d ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   ^   t 2 ) ; 
                 } 
                 / /   n o r 
                 e l s e   i f   ( f u n c   = =   " 1 0 0 1 1 1 " )   { 
                         r e g i s t e r _ [ r d ]   =   D e c i m a l T o B i n a r y 3 2 ( ~ ( t 1   |   t 2 ) ) ; 
                 } 
                 / /   s l t 
                 e l s e   i f   ( f u n c   = =   " 1 0 1 0 1 0 " )   { 
                         r e g i s t e r _ [ r d ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   <   t 2   ?   1   :   0 ) ; 
                 } 
                 / /   s l t u 
                 e l s e   i f   ( f u n c   = =   " 1 0 1 0 1 1 " )   { 
                         t 1   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r s ] ) ; 
                         t 2   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r t ] ) ; 
                         r e g i s t e r _ [ r d ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   <   t 2   ?   1   :   0 ) ; 
                 } 
                 / /   s l l 
                 e l s e   i f   ( f u n c   = =   " 0 0 0 0 0 0 " )   { 
                         r e g i s t e r _ [ r d ]   =   S h i f t L e f t L o g i c ( r e g i s t e r _ [ r t ]   ,   s h a m t ) ; 
                 } 
                 / /   s r l 
                 e l s e   i f   ( f u n c   = =   " 0 0 0 0 1 0 " )   { 
                         r e g i s t e r _ [ r d ]   =   S h i f t R i g h t L o g i c ( r e g i s t e r _ [ r t ]   ,   s h a m t ) ; 
                 } 
                 / /   s r a 
                 e l s e   i f   ( f u n c   = =   " 0 0 0 0 1 1 " )   { 
                         r e g i s t e r _ [ r d ]   =   S h i f t R i g h t A r i t h m e t i c ( r e g i s t e r _ [ r t ]   ,   s h a m t ) ; 
                 } 
                 / /   s l l v 
                 e l s e   i f   ( f u n c   = =   " 0 0 0 1 0 0 " )   { 
                         t 1   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r s ] ) ; 
                         r e g i s t e r _ [ r d ]   =   S h i f t L e f t L o g i c ( r e g i s t e r _ [ r t ]   ,   t 1 ) ; 
                 } 
                 / /   s r l v 
                 e l s e   i f   ( f u n c   = =   " 0 0 0 1 1 0 " )   { 
                         t 1   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r s ] ) ; 
                         r e g i s t e r _ [ r d ]   =   S h i f t R i g h t L o g i c ( r e g i s t e r _ [ r t ]   ,   t 1 ) ; 
                 } 
                 / /   s r a v 
                 e l s e   i f   ( f u n c   = =   " 0 0 0 1 1 1 " )   { 
                         t 1   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r s ] ) ; 
                         r e g i s t e r _ [ r d ]   =   S h i f t R i g h t A r i t h m e t i c ( r e g i s t e r _ [ r t ]   ,   t 1 ) ; 
                 } 
                 / /   j r 
                 e l s e   i f   ( f u n c   = =   " 0 0 1 0 0 0 " )   { 
                         P C _   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r s ] ) ; 
                 } 
         } 
         / /   a d d i 
         e l s e   i f   ( o p   = =   " 0 0 1 0 0 0 " )   { 
                 r e g i s t e r _ [ r t ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   +   i m m ) ; 
         } 
         / /   a d d i u 
         e l s e   i f   ( o p   = =   " 0 0 1 0 0 1 " )   { 
                 t 1   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r s ] ) ; 
                 r e g i s t e r _ [ r t ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   +   i m m ) ; 
         } 
         / /   a n d i 
         e l s e   i f   ( o p   = =   " 0 0 1 1 0 0 " )   { 
                 r e g i s t e r _ [ r t ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   &   i m m ) ; 
         } 
         / /   o r i 
         e l s e   i f   ( o p   = =   " 0 0 1 1 0 1 " )   { 
                 r e g i s t e r _ [ r t ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   |   i m m ) ; 
         } 
         / /   x o r i 
         e l s e   i f   ( o p   = =   " 0 0 1 1 1 0 " )   { 
                 r e g i s t e r _ [ r t ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   ^   i m m ) ; 
         } 
         / /   l w 
         e l s e   i f   ( o p   = =   " 1 0 0 0 1 1 " )   { 
                 r e g i s t e r _ [ r t ]   =   " " ; 
                 f o r   ( i n t   i   =   0 ;   i <   4 ;   + + i )   { 
                         r e g i s t e r _ [ r t ]   + =   m e m o r y _ [ a d d r e s s   +   i ] ; 
                 } 
         } 
         / /   s w 
         e l s e   i f   ( o p   = =   " 1 0 1 0 1 1 " )   { 
                 f o r   ( i n t   i   =   0 ;   i   <   4 ;   + + i )   { 
                         m e m o r y _ [ a d d r e s s   +   i ]   =   r e g i s t e r _ [ r t ] . s u b s t r ( 8   *   i   ,   8 ) ; 
                 } 
         } 
         / /   b e q 
         e l s e   i f   ( o p   = =   " 0 0 0 1 0 0 " )   { 
                 i f   ( t 1   = =   t 2 )   { 
                         P C _   =   P C _   +   i m m   *   4 ; 
                 } 
         } 
         / /   b n e 
         e l s e   i f   ( o p   = =   " 0 0 0 1 0 1 " )   { 
                 i f   ( t 1   ! =   t 2 )   { 
                         P C _   =   P C _   +   i m m   *   4 ; 
                 } 
         } 
         / /   s l t i 
         e l s e   i f   ( o p   = =   " 0 0 1 0 1 0 " )   { 
                 r e g i s t e r _ [ r t ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   <   i m m   ?   1   :   0 ) ; 
         } 
         / /   s l t i u 
         e l s e   i f   ( o p   = =   " 0 0 1 0 1 1 " )   { 
                 t 1   =   B i n a r y T o D e c i m a l U n s i g n e d ( r e g i s t e r _ [ r s ] ) ; 
                 r e g i s t e r _ [ r t ]   =   D e c i m a l T o B i n a r y 3 2 ( t 1   <   i m m   ?   1   :   0 ) ; 
         } 
         / /   j   a n d   j a l 
         e l s e   i f   ( o p   = =   " 0 0 0 0 1 0 "   | |   o p   = =   " 0 0 0 0 1 1 " )   { 
                 s t r i n g   a d d r e s s   =   s . s u b s t r ( 6   ,   2 6 )   +   " 0 0 " ; 
                 s t r i n g   p c   =   D e c i m a l T o B i n a r y 3 2 ( P C _ ) ; 
                 a d d r e s s   =   p c . s u b s t r ( 0   ,   4 )   +   a d d r e s s ; 
                 P C _   =   B i n a r y T o D e c i m a l U n s i g n e d ( a d d r e s s ) ; 
                 / /   j a l 
                 i f   ( o p   = =   " 0 0 0 0 1 1 " ) 
                         r e g i s t e r _ [ 3 1 ]   =   D e c i m a l T o B i n a r y 3 2 ( P C _ ) ; 
         } 
 } 
 
 v o i d   C p u : : I n s e r t ( s t r i n g   s )   { 
         o f s t r e a m   o f s ( " t m p _ i n s t r u c t o r " ) ; 
         o f s   < <   s ; 
         o f s . c l o s e ( ) ; 
         M I P S   m ( " i n s t r u c t o r " ) ; 
         m . c o n v e r t T o B i n a r y ( " t m p _ i n s t r u c t o r "   ,   " t m p _ b i n a r y _ c o d e " ) ; 
         i f s t r e a m   i f s ( " t m p _ b i n a r y _ c o d e " ) ; 
         i f s   > >   s ; 
         i f s . c l o s e ( ) ; 
         f o r   ( i n t   i   =   0 ;   i   <   4 ;   + + i )   { 
                 m e m o r y _ [ e n d _   +   i ]   =   s . s u b s t r ( 8   *   i   ,   8 ) ; 
         } 
         e n d _   + =   4 ; 
 } 
 _0?#include "cpu.h"

// default constructor
Cpu::Cpu() {
    int i;
    for (i = 0; i < 5001; ++i) 
        memory_.push_back("00000000");
    string s = "";
    for (i = 0; i < 32; ++i) 
        s += "0";
    for (i = 0; i < 32; ++i) 
        register_.push_back(s);
    s = DecimalToBinary32(5001);
    register_[29] = s;
    PC_ = 0;
    end_ = 0;
    IR_ = "";
}

// insert an instructor into memory
void Cpu::InsertInstructor() {
    string s;
    cout << "please input the assembly clause." << endl;
    cout << "Input example: add $1,$2,$3" << endl;
    getchar();
    getline(cin , s);
    string op;
    int i = 0;
    while (s[i] != ' ') {
        op += s[i];
        i++;
    }
    if (op == "move" || op == "blt" || op == "bgt" || op == "ble" || op == "bge") {
        string rr;
        string rs;
        string rt;
        i++;
        while (s[i] != ',') {
            rs += s[i];
            i++;
        }
        i++;
        while (i < s.length() && s[i] != ',') {
            rt += s[i];
            i++;
        }
        i++;
        while (i < s.length() && s[i] != ',') {
            rr += s[i];
            i++;
        }
        if (op == "move") {
            string s1 = "add " + rs + "," + rt + ",$0";
            Insert(s1);
        }
        else if (op == "blt") {
            string s1 = "slt $1," + rs + "," + rt;
            Insert(s1);
            s1 = "bne $1,$0," + rr;
            Insert(s1);
        }
        else if (op == "bgt") {
            string s1 = "slt $1," + rt + "," + rs;
            Insert(s1);
            s1 = "bne $1,$0," + rr;
            Insert(s1);
        }
        else if (op == "ble") {
            string s1 = "slt $1," + rt + "," + rs;
            Insert(s1);
            s1 = "beq $1,$0," + rr;
            Insert(s1);
        }
        else if (op == "bge") {
            string s1 = "slt $1," + rs + "," + rt;
            Insert(s1);
            s1 = "beq $1,$0," + rr;
        }
    }
    else {
        Insert(s);
    }
    cout << "insert successfully!" << endl;
}

// run the program step by step
void Cpu::RunByStep() {
    IR_ = "";
    for (int i = 0; i < 4; ++i) {
        IR_ += memory_[PC_ + i];
    }
    PC_ += 4;
    Execute(IR_);
}

// show the 32 registers
void Cpu::CheckRegister() {
    for (int i = 0; i < 32; ++i) {
        cout << "+------------------+-----------------------+" << endl;
        cout << "|   Register" << i;
        if (i < 10)
            cout <<  "      |";
        else
            cout <<  "     |";
        string s = BinaryToHexadecimal(register_[i]);
        cout << "    0x" << s << "         |" << endl;
    }
    cout << "+------------------+-----------------------+" << endl;
}

// show the memory
void Cpu::CheckMemory() {
    cout << "PC: " << PC_ << endl;
    for (int i = 0; i < end_; ++i) {
        string s = DecimalToBinary32(i);
        s = BinaryToHexadecimal(s);
        cout << "+----------------+----------------+" << endl;
        cout << "|  0x" << s << "    |";
        cout << "   " << memory_[i] << "     |" << endl;
    }
    cout << "+----------------+----------------+" << endl;
}

void Cpu::Convert() {
    cout << "please input the assembly code" << endl;
    string s;
    getchar();
    getline(cin , s);
    MIPS mips("instructor");
    ofstream ofs("tmp_instructor");
    ofs << s;
    ofs.close();
    mips.convertToBinary("tmp_instructor" , "tmp_binary_code");
    ifstream ifs("tmp_binary_code");
    ifs >> s;
    ifs.close();
    cout << "the binary code is " << s << endl;
}
void Cpu::Invert() {
    cout << "please input the binary code" << endl;
    string s;
    getchar();
    getline(cin , s);
    MipsInvert mips_invert("info.txt");
    ofstream ofs("binary.txt");
    ofs << s;
    ofs.close();
    mips_invert.Convert("binary.txt" , "assemble.txt");
    ifstream ifs("assemble.txt");
    getline(ifs , s);
    ifs.close();
    cout << "the assembly code is " << s << endl;
}

// convert a decimal number to 32-bit binary string
string Cpu::DecimalToBinary32(int n) {
    vector<int> v;
    int flag = 0;
    if (n < 0) {
        flag = 1;
        n = -n;
    }
    while (n > 0) {
        v.push_back(n % 2);
        n /= 2;
    }
    string res = "";
    for (int i = 0; i < 32 - v.size(); ++i) {
        res += "0";
    }
    for (int i = v.size() - 1; i >= 0; --i) {
        res += v[i] + '0';
    }
    if (flag == 1) {
        string res1 = "";
        for (int i = 0; i < res.length(); ++i) {
            if (res[i] == '0')
                res1 += '1';
            else
                res1 += '0';
        }
        int carry = 1;
        for (int i = res1.length() - 1; i >= 0; --i) {
            int t = res1[i] - '0';
            t += carry;
            if (t > 1) {
                res1[i] = '0';
                carry = 1;
            }
            else {
                res1[i] = t + '0';
                break;
            }
        }
        return res1;
    }
    return res;
}

// convert a binary string to signed decimal
int Cpu::BinaryToDecimalSigned(string s) {
    int flag = 0;
    if (s[0] == 1) {
        flag = 1;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '0')
                s[i] = '1';
            else
                s[i] = '0';
        }
        int carry = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            int t = s[i] - '0';
            t = t + carry;
            if (t > 1) {
                s[i] = 0;
                carry = 1;
            }
            else{
                s[i] = t;
                carry = 0;
            }
        }
    }
    int res = 0;
    for (int i = 1; i < s.length(); ++i) {
        res = res * 2 + s[i] - '0';
    }
    if (flag == 1)
        res = -res;
    return res;
}

// convert a binary string to unsigned decimal
int Cpu::BinaryToDecimalUnsigned(string s) {
    int res = 0;
    for (int i = 0; i < s.length(); ++i) {
        res = res * 2 + s[i] - '0';
    }
    return res;
}

// convert a binary string to hexadecimal string
string Cpu::BinaryToHexadecimal(string s) {
    string res = "";
    for (int i = 0; i < s.length(); i = i + 4) {
        int t = 0;
        for (int j = 0; j < 4; ++j) {
            t = t * 2 + s[i + j] - '0';
        }
        if (t < 10)
            res += t + '0';
        else
            res += t - 10 + 'A';
    }
    return res;
}

// shift left logiclly
string Cpu::ShiftLeftLogic(string s , unsigned int shamt) {
    for (int i = 0; i < shamt; ++i) {
        for (int j = 0; j < s.length() - 1; ++j) {
            s[j] = s[j + 1];
        }
        s[s.length() - 1] = '0';
    }
    return s;
}

// shift right logiclly
string Cpu::ShiftRightLogic(string s , unsigned int shamt) {
    for (int i = 0; i < shamt; ++i) {
        for (int j = s.length() - 1; j > 0; --j) {
            s[j] = s[j - 1];
        }
        s[0] = '0';
    }
    return s;
}

// shift right arithmetic
string Cpu::ShiftRightArithmetic(string s , unsigned int shamt) {
    char c = s[0];
    for (int i = 0; i < shamt; ++i) {
        for (int j = s.length() - 1; j > 0; --j) {
            s[j] = s[j - 1];
        }
        s[0] = c;
    }
    return s;
}

// execute module (core module)
void Cpu::Execute(string s) {
    int rs = BinaryToDecimalUnsigned(s.substr(6 , 5));
    int rt = BinaryToDecimalUnsigned(s.substr(11 , 5));
    int rd = BinaryToDecimalUnsigned(s.substr(16 , 5));
    int shamt = BinaryToDecimalSigned(s.substr(21 , 5));
    int imm = BinaryToDecimalSigned(s.substr(16 , 16));
    int t1 = BinaryToDecimalSigned(register_[rs]);
    int t2 = BinaryToDecimalSigned(register_[rt]);
    int t3 = BinaryToDecimalUnsigned(register_[rs]);
    int address = t3 + imm;
    string op = s.substr(0 , 6);
    // R-type instruction
    if (op == "000000") {
        string func = s.substr(26 , 6);
        // add
        if (func == "100000") {
            register_[rd] = DecimalToBinary32(t1 + t2);
        }   
        // addu
        else if (func == "100001") {
            t1 = BinaryToDecimalUnsigned(register_[rs]);
            t2 = BinaryToDecimalUnsigned(register_[rt]);
            register_[rd] = DecimalToBinary32(t1 + t2);
        }
        // sub
        else if (func == "100010") {
            register_[rd] = DecimalToBinary32(t1 - t2);
        }
        // subu
        else if (func == "100011") {
            t1 = BinaryToDecimalUnsigned(register_[rs]);
            t2 = BinaryToDecimalUnsigned(register_[rt]);
            register_[rd] = DecimalToBinary32(t1 - t2);
        }
        // and
        else if (func == "100100") {
            register_[rd] = DecimalToBinary32(t1 & t2);
        }
        // or
        else if (func == "100101") {
            register_[rd] = DecimalToBinary32(t1 | t2);
        }
        // xor
        else if (func == "100110") {
            register_[rd] = DecimalToBinary32(t1 ^ t2);
        }
        // nor
        else if (func == "100111") {
            register_[rd] = DecimalToBinary32(~(t1 | t2));
        }
        // slt
        else if (func == "101010") {
            register_[rd] = DecimalToBinary32(t1 < t2 ? 1 : 0);
        }
        // sltu
        else if (func == "101011") {
            t1 = BinaryToDecimalUnsigned(register_[rs]);
            t2 = BinaryToDecimalUnsigned(register_[rt]);
            register_[rd] = DecimalToBinary32(t1 < t2 ? 1 : 0);
        }
        // sll
        else if (func == "000000") {
            register_[rd] = ShiftLeftLogic(register_[rt] , shamt);
        }
        // srl
        else if (func == "000010") {
            register_[rd] = ShiftRightLogic(register_[rt] , shamt);
        }
        // sra
        else if (func == "000011") {
            register_[rd] = ShiftRightArithmetic(register_[rt] , shamt);
        }
        // sllv
        else if (func == "000100") {
            t1 = BinaryToDecimalUnsigned(register_[rs]);
            register_[rd] = ShiftLeftLogic(register_[rt] , t1);
        }
        // srlv
        else if (func == "000110") {
            t1 = BinaryToDecimalUnsigned(register_[rs]);
            register_[rd] = ShiftRightLogic(register_[rt] , t1);
        }
        // srav
        else if (func == "000111") {
            t1 = BinaryToDecimalUnsigned(register_[rs]);
            register_[rd] = ShiftRightArithmetic(register_[rt] , t1);
        }
        // jr
        else if (func == "001000") {
            PC_ = BinaryToDecimalUnsigned(register_[rs]);
        }
    }
    // addi
    else if (op == "001000") {
        register_[rt] = DecimalToBinary32(t1 + imm);
    }
    // addiu
    else if (op == "001001") {
        t1 = BinaryToDecimalUnsigned(register_[rs]);
        register_[rt] = DecimalToBinary32(t1 + imm);
    }
    // andi
    else if (op == "001100") {
        register_[rt] = DecimalToBinary32(t1 & imm);
    }
    // ori
    else if (op == "001101") {
        register_[rt] = DecimalToBinary32(t1 | imm);
    }
    // xori
    else if (op == "001110") {
        register_[rt] = DecimalToBinary32(t1 ^ imm);
    }
    // lw
    else if (op == "100011") {
        register_[rt] = "";
        for (int i = 0; i< 4; ++i) {
            register_[rt] += memory_[address + i];
        }
    }
    // sw
    else if (op == "101011") {
        for (int i = 0; i < 4; ++i) {
            memory_[address + i] = register_[rt].substr(8 * i , 8);
        }
    }
    // beq
    else if (op == "000100") {
        if (t1 == t2) {
            PC_ = PC_ + imm * 4;
        }
    }
    // bne
    else if (op == "000101") {
        if (t1 != t2) {
            PC_ = PC_ + imm * 4;
        }
    }
    // slti
    else if (op == "001010") {
        register_[rt] = DecimalToBinary32(t1 < imm ? 1 : 0);
    }
    // sltiu
    else if (op == "001011") {
        t1 = BinaryToDecimalUnsigned(register_[rs]);
        register_[rt] = DecimalToBinary32(t1 < imm ? 1 : 0);
    }
    // j and jal
    else if (op == "000010" || op == "000011") {
        string address = s.substr(6 , 26) + "00";
        string pc = DecimalToBinary32(PC_);
        address = pc.substr(0 , 4) + address;
        PC_ = BinaryToDecimalUnsigned(address);
        // jal
        if (op == "000011")
            register_[31] = DecimalToBinary32(PC_);
    }
}

void Cpu::Insert(string s) {
    ofstream ofs("tmp_instructor");
    ofs << s;
    ofs.close();
    MIPS m("instructor");
    m.convertToBinary("tmp_instructor" , "tmp_binary_code");
    ifstream ifs("tmp_binary_code");
    ifs >> s;
    ifs.close();
    for (int i = 0; i < 4; ++i) {
        memory_[end_ + i] = s.substr(8 * i , 8);
    }
    end_ += 4;
}
O0?#include "cpu.h"// default constructorCpu::Cpu() {    int i;    for (i = 0; i < 5001; ++i)         memory_.push_back("00000000");    string s = "";    for (i = 0; i < 32; ++i)         s += "0";    for (i = 0; i < 32; ++i)         register_.push_back(s);    s = DecimalToBinary32(5001);    register_[29] = s;    PC_ = 0;    end_ = 0;    IR_ = "";}// insert an instructor into memoryvoid Cpu::InsertInstructor() {    string s;    cout << "please input the assembly clause." << endl;    cout << "Input example: add $1,$2,$3" << endl;    getchar();    getline(cin , s);    string op;    int i = 0;    while (s[i] != ' ') {        op += s[i];        i++;    }    if (op == "move" || op == "blt" || op == "bgt" || op == "ble" || op == "bge") {        string rr;        string rs;        string rt;        i++;        while (s[i] != ',') {            rs += s[i];            i++;        }        i++;        while (i < s.length() && s[i] != ',') {            rt += s[i];            i++;        }        i++;        while (i < s.length() && s[i] != ',') {            rr += s[i];            i++;        }        if (op == "move") {            string s1 = "add " + rs + "," + rt + ",$0";            Insert(s1);        }        else if (op == "blt") {            string s1 = "slt $1," + rs + "," + rt;            Insert(s1);            s1 = "bne $1,$0," + rr;            Insert(s1);        }        else if (op == "bgt") {            string s1 = "slt $1," + rt + "," + rs;            Insert(s1);            s1 = "bne $1,$0," + rr;            Insert(s1);        }        else if (op == "ble") {            string s1 = "slt $1," + rt + "," + rs;            Insert(s1);            s1 = "beq $1,$0," + rr;            Insert(s1);        }        else if (op == "bge") {            string s1 = "slt $1," + rs + "," + rt;            Insert(s1);            s1 = "beq $1,$0," + rr;        }    }    else {        Insert(s);    }    cout << "insert successfully!" << endl;}// run the program step by stepvoid Cpu::RunByStep() {    IR_ = "";    for (int i = 0; i < 4; ++i) {        IR_ += memory_[PC_ + i];    }    PC_ += 4;    Execute(IR_);}// show the 32 registersvoid Cpu::CheckRegister() {    for (int i = 0; i < 32; ++i) {        cout << "+------------------+-----------------------+" << endl;        cout << "|   Register" << i;        if (i < 10)            cout <<  "      |";        else            cout <<  "     |";        string s = BinaryToHexadecimal(register_[i]);        cout << "    0x" << s << "         |" << endl;    }    cout << "+------------------+-----------------------+" << endl;}// show the memoryvoid Cpu::CheckMemory() {    cout << "PC: " << PC_ << endl;    for (int i = 0; i < end_; ++i) {        string s = DecimalToBinary32(i);        s = BinaryToHexadecimal(s);        cout << "+----------------+----------------+" << endl;        cout << "|  0x" << s << "    |";        cout << "   " << memory_[i] << "     |" << endl;    }    cout << "+----------------+----------------+" << endl;}void Cpu::Convert() {    cout << "please input the assembly code" << endl;    string s;    getchar();    getline(cin , s);    MIPS mips("instructor");    ofstream ofs("tmp_instructor");    ofs << s;    ofs.close();    mips.convertToBinary("tmp_instructor" , "tmp_binary_code");    ifstream ifs("tmp_binary_code");    ifs >> s;    ifs.close();    cout << "the binary code is " << s << endl;}void Cpu::Invert() {    cout << "please input the binary code" << endl;    string s;    getchar();    getline(cin , s);    MipsInvert mips_invert("info.txt");    ofstream ofs("binary.txt");    ofs << s;    ofs.close();    mips_invert.Convert("binary.txt" , "assemble.txt");    ifstream ifs("assemble.txt");    getline(ifs , s);    ifs.close();    cout << "the assembly code is " << s << endl;}// convert a decimal number to 32-bit binary stringstring Cpu::DecimalToBinary32(int n) {    vector<int> v;    int flag = 0;    if (n < 0) {        flag = 1;        n = -n;    }    while (n > 0) {        v.push_back(n % 2);        n /= 2;    }    string res = "";    for (int i = 0; i < 32 - v.size(); ++i) {        res += "0";    }    for (int i = v.size() - 1; i >= 0; --i) {        res += v[i] + '0';    }    if (flag == 1) {        string res1 = "";        for (int i = 0; i < res.length(); ++i) {            if (res[i] == '0')                res1 += '1';            else                res1 += '0';        }        int carry = 1;        for (int i = res1.length() - 1; i >= 0; --i) {            int t = res1[i] - '0';            t += carry;            if (t > 1) {                res1[i] = '0';                carry = 1;            }            else {                res1[i] = t + '0';                break;            }        }        return res1;    }    return res;}// convert a binary string to signed decimalint Cpu::BinaryToDecimalSigned(string s) {    int flag = 0;    if (s[0] == 1) {        flag = 1;        for (int i = 0; i < s.length(); ++i) {            if (s[i] == '0')                s[i] = '1';            else                s[i] = '0';        }        int carry = 0;        for (int i = s.length() - 1; i >= 0; --i) {            int t = s[i] - '0';            t = t + carry;            if (t > 1) {                s[i] = 0;                carry = 1;            }            else{                s[i] = t;                carry = 0;            }        }    }    int res = 0;    for (int i = 1; i < s.length(); ++i) {        res = res * 2 + s[i] - '0';    }    if (flag == 1)        res = -res;    return res;}// convert a binary string to unsigned decimalint Cpu::BinaryToDecimalUnsigned(string s) {    int res = 0;    for (int i = 0; i < s.length(); ++i) {        res = res * 2 + s[i] - '0';    }    return res;}// convert a binary string to hexadecimal stringstring Cpu::BinaryToHexadecimal(string s) {    string res = "";    for (int i = 0; i < s.length(); i = i + 4) {        int t = 0;        for (int j = 0; j < 4; ++j) {            t = t * 2 + s[i + j] - '0';        }        if (t < 10)            res += t + '0';        else            res += t - 10 + 'A';    }    return res;}// shift left logicllystring Cpu::ShiftLeftLogic(string s , unsigned int shamt) {    for (int i = 0; i < shamt; ++i) {        for (int j = 0; j < s.length() - 1; ++j) {            s[j] = s[j + 1];        }        s[s.length() - 1] = '0';    }    return s;}// shift right logicllystring Cpu::ShiftRightLogic(string s , unsigned int shamt) {    for (int i = 0; i < shamt; ++i) {        for (int j = s.length() - 1; j > 0; --j) {            s[j] = s[j - 1];        }        s[0] = '0';    }    return s;}// shift right arithmeticstring Cpu::ShiftRightArithmetic(string s , unsigned int shamt) {    char c = s[0];    for (int i = 0; i < shamt; ++i) {        for (int j = s.length() - 1; j > 0; --j) {            s[j] = s[j - 1];        }        s[0] = c;    }    return s;}// execute module (core module)void Cpu::Execute(string s) {    int rs = BinaryToDecimalUnsigned(s.substr(6 , 5));    int rt = BinaryToDecimalUnsigned(s.substr(11 , 5));    int rd = BinaryToDecimalUnsigned(s.substr(16 , 5));    int shamt = BinaryToDecimalSigned(s.substr(21 , 5));    int imm = BinaryToDecimalSigned(s.substr(16 , 16));    int t1 = BinaryToDecimalSigned(register_[rs]);    int t2 = BinaryToDecimalSigned(register_[rt]);    int t3 = BinaryToDecimalUnsigned(register_[rs]);    int address = t3 + imm;    string op = s.substr(0 , 6);    // R-type instruction    if (op == "000000") {        string func = s.substr(26 , 6);        // add        if (func == "100000") {            register_[rd] = DecimalToBinary32(t1 + t2);        }           // addu        else if (func == "100001") {            t1 = BinaryToDecimalUnsigned(register_[rs]);            t2 = BinaryToDecimalUnsigned(register_[rt]);            register_[rd] = DecimalToBinary32(t1 + t2);        }        // sub        else if (func == "100010") {            register_[rd] = DecimalToBinary32(t1 - t2);        }        // subu        else if (func == "100011") {            t1 = BinaryToDecimalUnsigned(register_[rs]);            t2 = BinaryToDecimalUnsigned(register_[rt]);            register_[rd] = DecimalToBinary32(t1 - t2);        }        // and        else if (func == "100100") {            register_[rd] = DecimalToBinary32(t1 & t2);        }        // or        else if (func == "100101") {            register_[rd] = DecimalToBinary32(t1 | t2);        }        // xor        else if (func == "100110") {            register_[rd] = DecimalToBinary32(t1 ^ t2);        }        // nor        else if (func == "100111") {            register_[rd] = DecimalToBinary32(~(t1 | t2));        }        // slt        else if (func == "101010") {            register_[rd] = DecimalToBinary32(t1 < t2 ? 1 : 0);        }        // sltu        else if (func == "101011") {            t1 = BinaryToDecimalUnsigned(register_[rs]);            t2 = BinaryToDecimalUnsigned(register_[rt]);            register_[rd] = DecimalToBinary32(t1 < t2 ? 1 : 0);        }        // sll        else if (func == "000000") {            register_[rd] = ShiftLeftLogic(register_[rt] , shamt);        }        // srl        else if (func == "000010") {            register_[rd] = ShiftRightLogic(register_[rt] , shamt);        }        // sra        else if (func == "000011") {            register_[rd] = ShiftRightArithmetic(register_[rt] , shamt);        }        // sllv        else if (func == "000100") {            t1 = BinaryToDecimalUnsigned(register_[rs]);            register_[rd] = ShiftLeftLogic(register_[rt] , t1);        }        // srlv        else if (func == "000110") {            t1 = BinaryToDecimalUnsigned(register_[rs]);            register_[rd] = ShiftRightLogic(register_[rt] , t1);        }        // srav        else if (func == "000111") {            t1 = BinaryToDecimalUnsigned(register_[rs]);            register_[rd] = ShiftRightArithmetic(register_[rt] , t1);        }        // jr        else if (func == "001000") {            PC_ = BinaryToDecimalUnsigned(register_[rs]);        }    }    // addi    else if (op == "001000") {        register_[rt] = DecimalToBinary32(t1 + imm);    }    // addiu    else if (op == "001001") {        t1 = BinaryToDecimalUnsigned(register_[rs]);        register_[rt] = DecimalToBinary32(t1 + imm);    }    // andi    else if (op == "001100") {        register_[rt] = DecimalToBinary32(t1 & imm);    }    // ori    else if (op == "001101") {        register_[rt] = DecimalToBinary32(t1 | imm);    }    // xori    else if (op == "001110") {        register_[rt] = DecimalToBinary32(t1 ^ imm);    }    // lw    else if (op == "100011") {        register_[rt] = "";        for (int i = 0; i< 4; ++i) {            register_[rt] += memory_[address + i];        }    }    // sw    else if (op == "101011") {        for (int i = 0; i < 4; ++i) {            memory_[address + i] = register_[rt].substr(8 * i , 8);        }    }    // beq    else if (op == "000100") {        if (t1 == t2) {            PC_ = PC_ + imm * 4;        }    }    // bne    else if (op == "000101") {        if (t1 != t2) {            PC_ = PC_ + imm * 4;        }    }    // slti    else if (op == "001010") {        register_[rt] = DecimalToBinary32(t1 < imm ? 1 : 0);    }    // sltiu    else if (op == "001011") {        t1 = BinaryToDecimalUnsigned(register_[rs]);        register_[rt] = DecimalToBinary32(t1 < imm ? 1 : 0);    }    // j and jal    else if (op == "000010" || op == "000011") {        string address = s.substr(6 , 26) + "00";        string pc = DecimalToBinary32(PC_);        address = pc.substr(0 , 4) + address;        PC_ = BinaryToDecimalUnsigned(address);        // jal        if (op == "000011")            register_[31] = DecimalToBinary32(PC_);    }}void Cpu::Insert(string s) {    ofstream ofs("tmp_instructor");    ofs << s;    ofs.close();    MIPS m("instructor");    m.convertToBinary("tmp_instructor" , "tmp_binary_code");    ifstream ifs("tmp_binary_code");    ifs >> s;    ifs.close();    for (int i = 0; i < 4; ++i) {        memory_[end_ + i] = s.substr(8 * i , 8);    }    end_ += 4;}               9   D   g   ?   ?  b?  ?? ? J?                          {?