/*
Mantıksal Operatörler

-- Operatör -- Anlamı -- C Sembol -- C Örnek Kod -- Sonuç
	AND        Ve	     &&	       a && b           >> Her ikiside doğru ise 1(True), her ikiside yanlış ise 0(False)
	OR	      Veya	     ||        a || b           >> Herhangi birisi doğru ise 1(True), her ikiside yanlış ise 0(False)
	NOT	      Değil       !          !a	            >> Doğru ise 0(False), Yanlış ise 1(True)


*/


/*
Operatörlerde Öncelik Sırası

Öncelikli Operatör            ()			 soldan sağa

Aritmetik Operatörler         ! ++ --		 SAĞDAN SOLA
							  /  * %		 soldan sağa
							  + -			 soldan sağa

Karşılaştırma Operatörler     > >= < <=		 soldan sağa
(İlişkisel)					  == !=		     soldan sağa

Mantıksal Operatörler         &&			 soldan sağa
							  ||			 soldan sağa

Atama Operatörü               =				 SAĞDAN SOLA

*/


#include <stdio.h>
#include <locale.h>


void main()

{
	setlocale(LC_ALL, "Turkish");

	int a = 5, b = 8, c = 3, d, e, f, g;

	d = a * b / c % a;
	printf("%d\n", d);

	e = (a < 5) || (++b > 4);
	printf("%d\n", !e);

	printf("%d\n", a || c && b % c && e);

	f = a * 2 % (b + 1) - c / (a + b);
	printf("%d\n", f);

	g = (f / e * a - b++ * --c) / -3;
	printf("%d\n", g);

	printf("\n\n");

	int x = 4, y = 7, z = 5, p, r, s, m;

	p = x * y / z % x;
	printf("%d\n", p);

	r = (x < 5) || (++y > 4);
	printf("%d\n", !r);

	printf("%d\n", x || z && y % z && r);

	s = x * 2 % (y + 1) - z / (x + y);
	printf("%d\n", s);

	m = (s / r * x - y++ * --z) / -3;
	printf("%d", m);

}
