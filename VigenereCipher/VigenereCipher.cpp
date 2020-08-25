#include "pch.h"
#include <iostream>
#include <iomanip>

using namespace std;

char varsayilanalfabe[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char kullanicialfabe[30];
char kullanicisifre[30];
char kullanicimetin[30];

char sifrelimetin[30];
char cozulmusmetin[30];

//kendisine gönderilen harfi, kendisine gönderilen metindeki indis degerini buluyor.
int indisBul(char *alfabe, char harf)
{
	int uzunluk = strlen(alfabe);
	int indis = 0;

	for (int i = 0; i < uzunluk; i++)
	{
		if (alfabe[i] == harf)
		{
			indis = i;
			break;
		}
	}
	return indis;
}

class Sifre
{
private:
	char *alfabe;
	char *sifreKelimesi;

public:
	Sifre(char *alfabe, char *sifre);
	Sifre();

	char *sifrele(char*);
	char *sifrecoz(char*);
	void sifreKelimesiAta(char*);
};

//default olarak alfabe tanımlanıyor.
Sifre::Sifre()
{
	alfabe = varsayilanalfabe;
}



Sifre::Sifre(char *alfabe, char *sifre)
{
	this->alfabe = alfabe;
	sifreKelimesi = sifre;
}

char *Sifre::sifrele(char *kullanicimetin)
{
	int yenikonum;
	int i;

	//konum bul fonksiyonu ile sifrelimetin ve kullanici metinin sirayla tüm harfleri toplanıyor,
	//mod alfabe uzunlugu alınarak yeni konumu alfabede nereye geliyorsa o harfi yeni diziye 
	//atıyoruz;
	for (i = 0; i < strlen(kullanicimetin); i++)
	{
		int kullanicikonum = indisBul(alfabe, kullanicimetin[i]);
		int keykonum = indisBul(alfabe, sifreKelimesi[i]);

		yenikonum = (kullanicikonum + keykonum + 1) % strlen(alfabe);
		sifrelimetin[i] = alfabe[yenikonum];
	}
	sifrelimetin[i] = '\0';

	return sifrelimetin;
}
char *Sifre::sifrecoz(char *sifrelimetin)
{

	int yenikonum;
	int i;

	//sifrele fonksiyonunun tersi gibi islem yapıyoruz bu sefer.
	//yine yeni bir diziye atarak diziyi geri dönderiyoruz.
	for (i = 0; i < strlen(sifrelimetin); i++)
	{
		int sifrelikonum = indisBul(alfabe, sifrelimetin[i]);
		int keykonum = indisBul(alfabe, sifreKelimesi[i]);

		yenikonum = (sifrelikonum - keykonum + -1 + strlen(alfabe)) % strlen(alfabe);
		cozulmusmetin[i] = alfabe[yenikonum];
	}
	cozulmusmetin[i] = '\0';

	return cozulmusmetin;
}
void Sifre::sifreKelimesiAta(char *sifre)
{
	sifreKelimesi = sifre;
}

int alfabe = 0;
int sifre = 0;
int metin = 0;

//girilen alfabedeki harflerin tekrarı kontrol ediliyor.
int alfabekontrol()
{
	int count = 0;
	for (int i = 0; i < strlen(kullanicialfabe); i++)
	{
		for (int j = 0; j < strlen(kullanicialfabe); j++)
		{
			if (kullanicialfabe[i] == kullanicialfabe[j])
			{
				if (i != j)
					count++;
			}
		}
	}
	if (count == 0)
	{
		alfabe = 1;

		int count0 = 0;
		for (int i = 0; i < strlen(kullanicialfabe); i++)
		{
			for (int j = 65; j < 91; j++)
			{
				if (kullanicialfabe[i] == char(j))
				{
					count0++;
				}
			}
		}
		if (count0 < strlen(kullanicialfabe))
		{
			alfabe = 0;
			cout << "Alfabenizde ingilizce ve buyuk karakterler kullaniniz!" << endl;
		}
		else
		{
			alfabe = 1;
		}
	}
	else
	{
		alfabe = 0;
		cout << "Girdiginiz alfabede ayni harfler var!" << endl;
	}
	return alfabe;
}

//girilen şifredeki harflerin alfabede olup olmaması kontrol ediliyor.
int sifrekontrol()
{
	int count1 = 0;
	for (int i = 0; i < strlen(kullanicialfabe); i++)
	{
		for (int j = 0; j < strlen(kullanicisifre); j++)
		{
			if (kullanicialfabe[i] == kullanicisifre[j])
			{
				count1++;
			}
		}
	}

	if (count1 == strlen(kullanicisifre))
	{
		sifre = 1;
	}
	else
		cout << "Girdiginiz sifrede alfabede olmayan harfler var!" << endl;

	return sifre;
}

//girilen metindeki harflerin alfabede olup olmaması kontrol ediliyor.
int metinkontrol()
{
	int count2 = 0;
	for (int i = 0; i < strlen(kullanicialfabe); i++)
	{
		for (int j = 0; j < strlen(kullanicimetin); j++)
		{
			if (kullanicialfabe[i] == kullanicimetin[j])
			{
				count2++;
			}
		}
	}

	if (count2 == strlen(kullanicimetin))
	{
		metin = 1;
	}
	else
		cout << "Girdiginiz metinde alfabede olmayan harfler var!" << endl;

	return metin;
}


int main()
{
	
	//aynı anda alfabe sifre ve metin 1 değerini alırsa kullanıcıdan girilen veriler uygun demek.
	//aksi halde gerekli uyarılarla tekrardan veri girmesini istiyoruz.
	char ch = '\0';
	while (alfabe != 1 || sifre != 1 || metin != 1)
	{	
		cout << endl << "Varsayilan alfabeyi kullanmak icin e'ye basiniz: " << endl;
		cin >> ch;

		if (ch == 'e' || ch == 'E')
		{
			//
			for (int i = 0; i < strlen(varsayilanalfabe); i++)
			{
				kullanicialfabe[i] = varsayilanalfabe[i];
			}
		}

		if (ch != 'e' && ch != 'E')
		{
			cout << setw(20) << left << "ALFABE" << ": ";
			cin >> kullanicialfabe;
		}

		cout << setw(20) << left << "SIFRE" << ": ";
		cin >> kullanicisifre;
		cout << setw(20) << left << "METIN" << ": ";
		cin >> kullanicimetin;
		
		alfabe = alfabekontrol();
		sifre = sifrekontrol();
		metin = metinkontrol();
	}

	//girilen sifrenin, sifreli metine dönüşmesi sağlanıyor. 
	char *newkey = new char[strlen(kullanicimetin)];

	int i, j;
	for (i = 0, j = 0; i < strlen(kullanicimetin); i++, j++)
	{
		if (j == strlen(kullanicisifre))
			j = 0;
		newkey[i] = kullanicisifre[j];
	}
	newkey[i] = '\0';


	//kurucu fonksiyona kullanıcı alfabesini ve kullanıcı şifresini gönderiyoruz
	Sifre s1(kullanicialfabe, kullanicisifre);

	//daha sonra yeni olusturdugumuz şifreyi sifrekelimesiata fonksiyonuna atıyoruz
	s1.sifreKelimesiAta(newkey);

	//sifrele fonksiyonuna kullanicinin girdiği metini gonderiyoruz ve bize sifreli metini dönderiyor.

	cout << setw(20) << left << "SIFRELENMIS METIN" << ": " << s1.sifrele(kullanicimetin) << endl;

	//sifrecoz fonksiyonu aldığı sifreli metni çözerek bize geri gönderiyor.
	cout << setw(20) << left << "DESIFRE METIN" << ": " << s1.sifrecoz(sifrelimetin) << endl;

	system("pause");
	return 0;
}