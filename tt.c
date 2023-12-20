//1.
// #include<stdio.h>
// int main()
// {
// char ch;
// if(ch = printf(""))
// printf("It matters\n");
// else
// printf("It doesn't matters\n");
// return 0;
// }

//2.
// #include<stdio.h>
// int main()
// {
// unsigned int i = 65536; /* Assume 2 byte integer*/
// while(i != 0)
// printf("%d",++i);
// printf("\n");
// return 0;
// }

//3.
// #include<stdio.h>
// int main()
// {
// float a = 0.7;
// if(0.7 > a)
// printf("Hi\n");
// else
// printf("Hello\n");
// return 0;
// }

//4.
// #include<stdio.h>
// int main()
// {
// int a=0, b=1, c=3;
// *((a) ? &b : &a) = a ? b : c;
// printf("%d, %d, %d\n", a, b, c);
// return 0;
// }
//5.
// #include<stdio.h>
// int main(){

// int x=1, y=1;
// for(; y; printf("%d %d\n", x, y)) 
//     { y = x++ <= 5; } 
//     printf("\n");
//     return 0; 
// }
//6.
#include<stdio.h>
int main()
{
printf("%d >> %d %d >> %d\n", 4 >> 1, 8 >> 1);
return 0;
}
//7.
// #include<stdio.h>
// int main()
// {
// char c=48;
// int i, mask=01;
// for(i=1; i<=5; i++)
// {
// printf("%c", c|mask);
// mask = mask<<1;
// }
// return 0;
// }

// #include<stdio.h>
// int main()
// {
// printf("%d %d\n", 32<<1, 32<<0);
// printf("%d %d\n", 32<<-1, 32<<-0);
// printf("%d %d\n", 32>>1, 32>>0);
// printf("%d %d\n", 32>>-1, 32>>-0);
// return 0;
// }

// #include<stdio.h>
// int main()
// {
// unsigned int res;
// res = (64 >>(2+1-2)) & (~(1<<2));
// printf("%d\n", res);
// return 0;
// }

// #include<stdio.h>
// int main()
// {
// int i=4, j=8;
// printf("%d, %d, %d\n", i|j&j|i, i|j&&j|i, i^j);
// return 0;
// }
// #include<stdio.h>
// int main()
// {
// unsigned int num;
// int i;
// scanf("%u", &num);
// for(i=0; i<16; i++)
// {
// printf("%d", (num<<i & 1<<15)?1:0);
// }
// return 0;
// }

// #include<stdio.h>
// int main()
// {
// unsigned int num;
// int c=0;
// scanf("%u", &num);
// for(;num;num>>=1)
// {
// if(num & 1)
// c++;
// }
// printf("%d", c);
// return 0;
// }
// Select one:
// a. It counts the number of bits that are OFF (0) in the number num.
// b. Error
// c. It sets all bits in the number num to 1
// d. It counts the number of bits that are ON (1) in the number num.

// #include<stdio.h>
// int main()
// {
// char s = 3;
// switch (s)
// {
// case '1':
// printf( "Seagherkins\n") ;
// case '2':
// printf( "Saboons\n" ) ;
// default:
// printf( "Sucaneers\n") ;
// }
// printf( "Gallows fodder" ) ;
// return 0;
// }
// #include<stdio.h>
// int main()
// {
// int k = -2, j = 4 ;
// switch ( k /= j / k )
// {
// default:
// printf ( "All are same!\n" ) ;
// case 0:
// printf ( "Happy birthday\n" ) ;
// case 1 :
// printf ( "A punch on the mouth\n" ) ;
// case 2:
// printf ( "A kick in the back\n" ) ;
// }
// return 0;
// // }
// #include<stdio.h>
// int main( )

// {

//             int  j, x = 0;

//             for ( j = 0 ; j <= 5 ; j++)

//             {

//                         switch ( j - 1 )

//                         {

//                                     case 0:

//                                     case -1 :

//                                                 x += 1 ;

//                                                 break;

//                                     case 1 :

//                                     case 2:

//                                     case 3:

//                                                 x += 2;

//                                                 break;

//                                     default:

//                                                 x += 3;

//                         }

//                         printf ( "%d  ", x) ;

//             }

//             return 0;

//}
// #include<stdio.h>
// int main()

// { int i ;for ( i = 2 ; i <= 10 ; i++ )
// {
//   switch (i){ case 2:

//          printf ( "O" );
//   continue;

//   case 3:         break;

//                                     case 4:

//                                     case 5:

//                                                 printf ( "H" ) ;

//                                                 break;

//                                     default:

//                                                 printf ( "!" ) ;

//                         }

//             }

//             return 0;

//}

// #include<stdio.h>
// int main()
// {
// int i ;
// for ( i = 1 ; i <= 5 ; i++ )
// {
// if ( i * i >= 121 )
// goto there;
// else
// printf ( "%d ", i) ;
// }
// there:
// printf ( "\nNo more murphy's laws" ) ;
// return 0;
// }
// #include<stdio.h>
// int main( )
// {
// int i, j;
// for ( j = 1 ; j <= 10 ; j++)
// {
// for ( i = 1 ; i <= 10 ; i++ )
// {
// if(j<10) 
// goto out;
// }
// printf ( "Murphy's first law\n" ) ;
// printf ( "If the price of the PC is a dream ...\n") ;
// printf ( "then the service would be a nightmare" ) ;
// }
// out:
// printf ( "Dream about a nightmare");
// return 0;
// }

// int main( )
// {
// int i, j, k;
// for ( j = 1 ; j <= 4 ; j++ )
// {
// if( j * j== 16)
// goto secretplace ;
// }
// for ( i = 1 ; i <= 5 ; i++)
// {
// k = i * i;
// j = k + 2;
// secretplace :
// printf ( "Murphy's second law\n") ;
// printf ( "Good computers are always priced ...\n");
// printf ( "just beyond your budget\n" ) ;
// }
// return 0;
// }

// int main()
// {
// int i ;
// char j ;
// printf ( "Enter any number ..." ) ;
// scanf ( "%d", &i) ;
// switch(i)
// {
// case 1 :
// printf ( "\nEnter any alphabet ..." ) ;
// fflush ( stdin ) ;
// scanf ( "%c", &j) ;
// switch (j)
// {
// case 'a':
// printf ( "\nlf you want something." ) ;
// goto out;
// case 'b':
// printf ( "\nSet it free ..." ) :
// break;
// }
// break;
// case 2:
// printf ( "\nlf it returns, its yours ...." ) ;
// }
// out:
// printf ( "\nElse it was never meant to be." ) ;
// return 0;
// }

// int main()
// {
// int i, k = 1 ;
// here:
// if (k > 2)
// goto out;
// there:
// for ( i = 1 ; i <= 5 ; i++)
// printf ( "%d" , i ) ;
// k++ ;
// goto there;
// out: ;
// return 0;
// }

// int main()
// {
// int i = 1 ;
// switch (i)
// {
// case 1 :
// goto label;
// label:
// case 2:
// printf ( "He looks like a Saint ..." ) ;
// break;
// }
// printf ( "\nA Saint Bernard!" ) ;
// return 0;
// }