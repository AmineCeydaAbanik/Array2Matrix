/*Amine Ceyda ABANÝK
  1721221024
  BP3 FÝNAL ODEVÝ*/




#include<iostream>
#include<stdlib.h>
#include<time.h>
#include"lal.hpp"
using namespace std;

Matrix vectorArray2Matrix(Vector*, int p, int m);

int main(){
	srand(time(NULL));

	///kullanicidan p ve m degerleri alinir
	int p,m;
	cout<<"m : ";
	cin >> m;
	cout<<"p : ";
	cin >> p;
	
	///p satira sahip m adet vektor olusturuluyor
	Vector* vectorArray = new Vector[m];
	int i,j;
	double* array;
	Vector *temp;
	for(i=0; i<m; i++){
		array = new double[p];
		for(j=0; j<p; j++){
			/// random degerler atiliyor
			array[j] = rand() % 100;
		}
		temp = new Vector(array, p);
		vectorArray[i] = *temp;
	}

	cout<< endl <<"----------- "<<p<<" elemana sahip "<<m<<" adet vektor-------------\n";
	for(i=0; i<m; i++){
		vectorArray[i].print();
		cout<< endl;
	}


	cout << "\nBu vektorlerin birlestirilmesiyle olusturulan Matrix\n";
	vectorArray2Matrix(vectorArray, p, m).print();
	cout<<endl<<"--------------------------------------------------------------------------\n";

	double *islem1 = new double[3 * 3];
	double *islem2 = new double[3 * 3];
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			///random 3  e 3 matrix olusturuluyýr
			*(islem1 + i*3 + j) = rand() % 100;
			*(islem2 + i*3 + j) = rand() % 100;
		}
	}
	Matrix m_islem1(islem1, 3, 3);
	Matrix m_islem2(islem2, 3, 3);
	cout<<"\nRastgele olusturulan 1.Matris\n";
	m_islem1.print();
	cout<<endl;
	cout<<"\nRastgele olusturulan 2.Matris\n";
	m_islem2.print();

	//// TOPLAMA
	cout<<"\nTOPLAM Matrisi\n";
	(m_islem1 + m_islem2).print();
	cout << endl;

	//// FARK
	cout<<"\nFARK Matrisi\n";
	(m_islem1 - m_islem2).print();
	cout << endl;

	//// CARPIM
	cout<<"\nCARPIM Matrisi\n";
	(m_islem1 * m_islem2).print();
	cout << endl;

	//// 1.Matris Transpoze
	cout<<"\n1.Matris Transpozesi\n";
	(transpose(m_islem1)).print();
	cout << endl;

	//// 2.Matris Transpoze
	cout<<"\n2.Matris Transpozesi\n";
	(transpose(m_islem2)).print();
	cout << endl;


//14. madde vektor de bir matris oldugu icin yeni bir array olusturdum 
	/// Hem Matrix, hem de Vector sýnýfýndan nesneleri bir arada tutabilen bir dizi
    ///oluþturulup içi en az ikiþer matris ve vektörle doldurulacaktýr.

	Matrix karisik[4];
	double *m1 = new double[2 * 3];
	double *m2 = new double[3 * 4];
	double *v1 = new double[6];
	double *v2 = new double[8];
	Matrix mat1(m1, 2, 3);
	Matrix mat2(m2, 3, 4);
	Vector vek1(v1, 6);
	Vector vek2(v2, 8);
	karisik[0] = mat1;
	karisik[1] = mat2;
	karisik[2] = vek1;
	karisik[3] = vek2;
	return 0;
}

Matrix vectorArray2Matrix(Vector* vectorArray, int p, int m){
	double* array = new double[p * m];
	int i,j;
	for(i=0; i<p; i++){
		for(j=0; j<m; j++){
			*(array + i*m + j) = *(vectorArray[j].entries + i);
		}
	}
	return Matrix(array, p, m);
}
