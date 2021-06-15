/*Amine Ceyda ABAN�K
  1721221024
  BP3 F�NAL ODEV�*/


#ifndef lal_hpp
#define lal_hpp

// Matrix sinifinin icinde kullanabilmek icin tanimlama yaptim
class Vector;

class Matrix
{
	// kalitimde kullanabilmek icin protected
	// eri�sim belirleyicisi kullandim
	protected:
		double* entries;
		int rows;
		int cols;
	public:
		// kurucu fonksiyon
		Matrix();
		// parametreli kurucu fonksiyon
		Matrix(double *, int, int);
		//yikici fonksiyon
		~Matrix();
		//yazdirma
		void print(void);
		//operator asiri y�klemeler
		Matrix operator+(const Matrix&);
		Matrix operator-(const Matrix&);
		Matrix operator*(const Matrix&);
		Vector operator*(const Vector&);
		bool operator==(const Matrix&);
		// Transpose fonksiyonu
		// bu fonksiyondan �ye elamanlarda erisebilmek i�in friend tanimlad�m
		friend Matrix transpose(Matrix);
		// Norm fonksiyonu
		friend double norm(Matrix);
		friend Matrix vectorArray2Matrix(Vector*, int, int);
};


class Vector : public Matrix
{
	private:
		double l2norm;
	public:
		Vector();
		Vector(double *, int);
		~Vector();
		void print(void);
		Vector operator+(const Vector&);
		Vector operator-(const Vector&);
		double operator*(const Vector&);
		friend Vector Matrix::operator*(const Vector&);// vektor matris �arp�m� as�r� y�klenen operator
		bool operator==(const Vector&);
		void operator++();
		void operator++(int);
		friend Matrix vectorArray2Matrix(Vector*, int, int);
};


#endif
