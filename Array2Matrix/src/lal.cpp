/*Amine Ceyda ABAN�K
  1721221024
  BP3 F�NAL �DEV�*/


#include<iostream>
#include<math.h>
#include"lal.hpp"

using namespace std;

//////////////////////  MATR�S �SLEMLER   ///////////////////

Matrix::Matrix(){
	entries = NULL;
	rows = 0;
	cols = 0;
}

Matrix::Matrix(double *entries, int rows, int cols){
	this->entries = entries;
	this->rows = rows;
	this->cols = cols;
}

Matrix::~Matrix(){
	delete [] entries;
}

void Matrix::print(void){
	int i,j;
	// satir ve sutunlar gezilerek matris yazdiriliyor
	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			cout << *(entries + i*cols + j) << "\t";
		}
		cout<<endl;
	}
}

Matrix Matrix::operator+(const Matrix& b) {
	// satirlar ve sutunlar esit degilse
	if (this->rows != b.rows || this->cols != b.cols){
		cout << "GECERS�Z �SLEM : BOYUT UYUMSUZLUGU!" << endl;
		return *this;
	}
	
	double *sonuc = new double[this->rows * this->cols];
	int i,j;
	for (i=0; i<this->rows; i++)
		for (j=0; j<this->cols; j++)
			*(sonuc + i*this->cols + j) = *(this->entries + i*this->cols + j) + *(b.entries + i*this->cols + j);
	
	return Matrix(sonuc, this->rows, this->cols);
}

Matrix Matrix::operator-(const Matrix& b) {
	//satirlar ve sutunlar esit degilse
	if (this->rows != b.rows || this->cols != b.cols){
		cout << "GECERS�Z �SLEM : BOYUT UYUMSUZLUGU!" << endl;
		return *this;
	}
	
	double *sonuc = new double[this->rows * this->cols];
	int i,j;
	for (i=0; i<this->rows; i++)
		for (j=0; j<this->cols; j++)
			*(sonuc + i*this->cols + j) = *(this->entries + i*this->cols + j) - *(b.entries + i*this->cols + j);
	
	return Matrix(sonuc, this->rows, this->cols);
}

Matrix Matrix::operator*(const Matrix& b) {
	// 1. matrisin sutun sayisi 2. matrisin satir say�s�na esit degilse
	if (this->cols != b.rows){
		cout << "GECERS�Z �SLEM : BOYUT UYUMSULUGU!" << endl;
		return *this;
	}
	
	double *sonuc = new double[this->rows * b.cols];
	int i,j,k;
	for (i=0; i<this->rows; i++){
		for (j=0; j<b.cols; j++){
			double toplam = 0;
			for(k=0; k<b.rows; k++){
				toplam += (*(this->entries + i*this->cols + k)) * (*(b.entries + k*b.cols + j));
			}
			*(sonuc + i*b.cols + j) = toplam;
		}
	}
	
	return Matrix(sonuc, this->rows, b.cols);
}

Vector Matrix::operator*(const Vector& b) {
	// 1. matriisn sutunu esit degil 2. matrisin satiri
	if (this->cols != b.rows){
		cout << "GECERS�Z �SLEM : BOYUT UYUMSUZLUGU!" << endl;
		return b;
	}
	
	double *sonuc = new double[this->rows * 1];
	int i,j,k;
	for (i=0; i<this->rows; i++){
		for (j=0; j < 1; j++){
			double toplam = 0;
			for(k=0; k<b.rows; k++){
				toplam += (*(this->entries + i*this->cols + k)) * (*(b.entries + k*b.cols + j));
			}
			*(sonuc + i*b.cols + j) = toplam;
		}
	}
	
	return Vector(sonuc, this->rows);
}

bool Matrix::operator==(const Matrix& b) {
	// Satirlar ya da sutunlar esit degilse
	if (this->rows != b.rows || this->cols != b.cols){
		cout << "GECERS�Z �SLEM : BOYUT UYUMSUZLUGU!" << endl;
		return false;
	}
	
	int i,j;
	for (i=0; i<this->rows; i++)
		for (j=0; j<this->cols; j++)
			if(*(this->entries + i*this->cols + j) != *(b.entries + i*this->cols + j))
				return false;
	
	return true;
}



/////////////////////  VEKTOR �SLEMLER�  /////////////////////////

Vector::Vector(): Matrix(NULL, 0, 0){
	l2norm = 0;
}

Vector::Vector(double * entries, int rows) : Matrix(entries, rows, 1)
{
	double temp = 0.0, deger;
	int i;
	// Vektorlerin sutun adedi 1 oldugu icin sadece sat�rlarda gezebiliriz
	for(i=0; i<rows; i++){
		// dizideki degeri aliyoruz
		deger = *(entries + i*cols);
		//okunan degerin karesini temp degerine ekliyoruz
		temp += deger * deger;
	}
	// karek�k�n� al�yoruz ve i�lem bitiyor
	this->l2norm = sqrt(temp);
}

Vector::~Vector(){
	delete [] entries;
}

void Vector::print(void){
	int i;
	//vek�trlerin sutun say�s� 1 oldugu icin sadece sat�rlarda geziyoruz
	for(i=0; i<rows; i++){
		cout << *(entries + i*cols) << "\t";
	}
}

Vector Vector::operator+(const Vector& b) {
	// satirlar ayni degilse
	if (this->rows != b.rows){
		cout << "GECERS�Z �SLEM : BOYUT UYUMSUZLUGU!" << endl;
		return *this;
	}
	
	double *sonuc = new double[this->rows * 1];
	int i,j;
	for (i=0; i<this->rows; i++)
		for (j=0; j < 1; j++)
			*(sonuc + i*this->cols + j) = *(this->entries + i*this->cols + j) + *(b.entries + i*this->cols + j);
	
	return Vector(sonuc, this->rows);
}

Vector Vector::operator-(const Vector& b) {
	
	if (this->rows != b.rows){
		cout << "GECERS�Z �SLEM : BOYUT UYUMSUZLUGU!" << endl;
		return *this;
	}
	
	double *sonuc = new double[this->rows * 1];
	int i,j;
	for (i=0; i<this->rows; i++)
		for (j=0; j < 1; j++)
			*(sonuc + i*this->cols + j) = *(this->entries + i*this->cols + j) - *(b.entries + i*this->cols + j);
	
	return Vector(sonuc, this->rows);
}

double Vector::operator*(const Vector& b) {
	
	if (this->rows != b.rows){
		cout << "GECERS�Z �SLEM : BOYUT UYUMSUZLUGU!" << endl;
		return 0.0;
	}

	int i;
	double sonuc = 0.0;
	for (i=0; i<this->rows; i++){
		sonuc += (*(this->entries + i)) * (*(b.entries + i));
	}
	
	return sonuc;
}

bool Vector::operator==(const Vector& b) {

	if (this->rows != b.rows){
		cout << "GECERS�Z �SLEM BOYUT UYUMSUZLUGU!" << endl;
		return false;
	}
	
	int i;
	for (i=0; i<this->rows; i++)
		if(*(this->entries + i) != *(b.entries + i))
			return false;
	
	return true;
}

void Vector::operator++() {	//9. MADDE E SIKKI Pre-increment 
	int i;
	for (i=0; i<this->rows; i++)
		++(*(this->entries + i));
}

void Vector::operator++(int) {	//Post-increment
	int i;
	for (i=0; i<this->rows; i++)
		(*(this->entries + i))++;
}



//////////////////////////   ORTAK FONKS�TONLAR   ///////////////////////////


Matrix transpose(Matrix matrix){
	double *sonuc = new double[matrix.cols * matrix.rows];
	int i,j;
	for (i=0; i< matrix.rows; i++){
		for (j=0; j < matrix.cols; j++){
			*(sonuc + i*matrix.rows + j) = *(matrix.entries + j*matrix.rows + i);
		}
	}
	
	return Matrix(sonuc, matrix.rows, matrix.cols);
}

double norm(Matrix matrix){
	double temp = 0.0, deger;
	int i,j;
	//satir ve sutundaki t�m veriyi geziyoruz
	for(i=0; i<matrix.rows; i++){
		for(j=0; j<matrix.cols; j++){
			// Dizideki degerleri aliyoruz
			deger = *(matrix.entries + i*matrix.cols + j);
			// okunan degerin karesini temp degerine ekle
			temp += deger * deger;
		}
	}
	// karek�k�n� aliyoruz
	return sqrt(temp);
}
