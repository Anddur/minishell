/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_logo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:06:49 by aduregon          #+#    #+#             */
/*   Updated: 2021/03/10 19:11:44 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_logo2(void)
{
	printf(GRN"2 ®   ? n¶  –p /  π █+ ███ ██ 0 █a█ █ █ ████ █© █  ███s██3 █");
	printf(" s █ 2 ®   © ¬ = $) n¶  –\n"NRM);
	printf(GRN"v     2 fº  ¶6    † █o █ █ ███  █ƒ} █ █ █ ██ █œ██  █ █+███ █");
	printf("██ ███ v   p   5 œr fº  ¶\n"NRM);
	printf(GRN"r     @ d3  &£    }  5 √ ∑  r    ¬)   } p  p  © π    πs  3  ");
	printf(" 2 µ 1 r   s   @ œ0 d3  &\n"NRM);
	printf(GRN"3     ;  a   œ    ≈  h ∫ œ  ∑    f$   & ;  c  k      µå  œ  ");
	printf(" 1 m ß 3   0   ™ ∑£  a  Y\n"NRM);
	printf(GRN"d     $     ]  x   π    p  l   å  ƒ    ∂u   * |  5  ;      µ");
	printf("œ  q     ? ®     -   1  {\n"NRM);
	printf(GRN"d     ≠      u    z  å   1  √     q     k  7         w1     ");
	printf("   > l R   =     0  œ   ]\n"NRM);
	printf(GRN"œ     ™      0       ≈   7        4        s          1     ");
	printf("     / R         1  ∫   ß\n"NRM);
	printf("\n");
}

void	print_logo(void)
{
	printf("\n");
	printf(GRN"a{ed  5e u.c 5t a  -p® Mattia Cossu  y©p4  √i1ƒ†h5 01w∫2cd  ");
	printf(" ås sa{ed  5p¢ s s1e u.c+\n"NRM);
	printf(GRN"a]5g  6 4>g 61 h  + /≈ olpπ y ßr ®o  ¥a∂®  ˙l0l§n5 0ƒπ≤e∂∂  ");
	printf("a3 ® a]5g  68h W da 4>g 6\n"NRM);
	printf(GRN"∂œˆn  7 go4 c˚ p  * |p hp6{ 6 ƒ∂ p8  ®7∂¢  ¢Andrea Duregon  ");
	printf("d1 ® ∂œˆn  Y*1 ∫ 8å go4 c\n"NRM);
	printf(GRN"ee5$  4 fw§ ¶¥ 3  t ?{ ≈5¬} © f7 0*  6&j§  ©+ ƒ+0@  f¨s  0  ");
	printf(" ! § ee5$  år! § *† fw§ ¶\n"NRM);
	printf(GRN"4r≈   2 a∞  -® å  @  ] ç t  i 7- 1=  4œ œ  n∂ “ |   £k7  1  ");
	printf(" d ± 4r≈   ∆|| • 9[ a∞  -\n"NRM);
	printf(GRN"0tç   g v2  =ß ∑  ™███ █ █ ███® ██∑██ █ ██ █ █¬ ██ █w█3███ █");
	printf(" ß █ 0tç   µ + _ 0} v2  =\n"NRM);
	print_logo2();
}

void	print_exit2(void)
{
	printf(GRN"2 ®   ? n¶  –p /  π █+ ███ ██ 0 █a█ █ █ ████ █© █  ");
	printf("███s██3 █ s █ 2 ®   © ¬ = $) n¶  –\n"NRM);
	printf(GRN"v     2 fº  ¶6    † █o █ █ ███  █ƒ} █ █ █ ██ █œ██  ");
	printf("█ █+███ ███ ███ v   p   5 œr fº  ¶\n"NRM);
	printf(GRN"r     @ d3  &£    }  5 √ ∑  r    ¬)   } p  p  © π  ");
	printf("  πs  3   2 µ 1 r   s   @ œ0 d3  &\n"NRM);
	printf(GRN"3     ;  a   œ    ≈  h ∫ œ  ∑    f$   & ;  c  k    ");
	printf("  µå  œ   1 m ß 3   0   ™ ∑£  a  Y\n"NRM);
	printf(GRN"d     $     ]  x   π    p  l   å  ƒ    ∂u   * |  5 ");
	printf(" ;      µœ  q     ? ®     -   1  {\n"NRM);
	printf(GRN"d     ≠      u    z  å   1  √     q     k  7       ");
	printf("  w1        > l R   =     0  œ   ]\n"NRM);
	printf(GRN"œ     ™      0       ≈   7        4        s       ");
	printf("   1          / R         1  ∫   ß\n"NRM);
	printf("\n");
}

void	print_exit1(void)
{
	printf("\n");
	printf(GRN"a{ed  5e u.c 5t a  -p® Mattia Cossu  y©p4  √i1ƒ†h5 ");
	printf("01w∫2cd  tås sa{ed  5p¢ s s1e u.c+\n"NRM);
	printf(GRN"a]5g  6 4>g 61 h  + /≈ olpπ y ßr ®o  ¥a∂®  ˙l0l§n5 ");
	printf("0ƒπ≤e∂∂  a3 ® a]5g  68h W da 4>g 6\n"NRM);
	printf(GRN"∂œˆn  7 go4 c˚ p  * |p hp6{ 6 ƒ∂ p8  ®7∂¢  ¢Andrea ");
	printf("Duregon  d1 ® ∂œˆn  Y*1 ∫ 8å go4 c\n"NRM);
	printf(GRN"ee5$  4 fw§ ¶¥ 3  t ?{ ≈5¬} © f7 0*  ,==.  ©+ ƒ+0@ ");
	printf(" f¨s  0   ! § ee5$  år! § *† fw§ ¶\n"NRM);
}

void	print_exit(void)
{
	print_exit1();
	printf(GRN"4r≈   2 a∞  -® å  @ ¥] ç t{ i 7- 1  (████)████████ ");
	printf(" £k7  1   d ± 4r≈   ∆|| • 9[ a∞  -\n"NRM);
	printf(GRN"0tç   g v2  =ß ∑  ™ ™π 4 o  t yr i  █|██|█[][][]███");
	printf(" lbg  3   | ' ≠tç   µ + _ 0} v2  =\n"NRM);
	printf(GRN"2 ®   ? n¶  –p /  π †+ † 5  - 98 ∂ 8█|██|█[][][]███");
	printf(" :6&  g   f 5 ™ ®   © ¬ = $) n¶  –\n"NRM);
	printf(GRN"v     2 fº  ¶6    †  ≠ ¥ $  ? œ( f8 █|██|█[][][]███");
	printf(" :§#  )   g + m v   p   5 œr fº  ¶\n"NRM);
	printf(GRN"r     @ d3  &£    }  5 √ ∑  r }* ¬8 (████)████████ ");
	printf("  πs  3   2 µ 1 r   s   @ œ0 d3  &\n"NRM);
	printf(GRN"3     ;  a   œ    ≈  h ∫ œ  ∑  å f 88`==   c  k    ");
	printf("  µå  œ   1 m ß 3   0   ™ ∑£  a  Y\n"NRM);
	printf(GRN"d     $     ]  x   π    p  l   å  ƒ    ∂u   * |  5 ");
	printf(" ;    µ   œ q q f   ®     -   1  {\n"NRM);
	printf(GRN"d     ≠      u    z  å   1  √     q     k  7       ");
	printf("  w1        > l R   =     0   œ  ]\n"NRM);
	printf(GRN"œ     ™      0       ≈   7        4        s       ");
	printf("   1          / R         1   ∫  ß\n"NRM);
	printf("\n");
}
