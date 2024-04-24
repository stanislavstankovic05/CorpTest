#include <string>

class Nrcomplex
{
    double real;
    double imaginar;
public:

    Nrcomplex()
    {
        real=0;
        imaginar=0;
    }
    Nrcomplex(double a,double b)
    {
        real=a;
        imaginar=b;
    }
    ~Nrcomplex()
    {
        ///cout<<"destruct";
    }
    int getReal()
    {
        return real;
    }
    int getImaginar()
    {
        return imaginar;
    }
    Nrcomplex operator+(const Nrcomplex &b)
    {
        /*int real=a.getReal()+b.getReal();
        int imaginar=a.getImaginar()+b.getImaginar();
        Nrcomplex c(a,b);*/
        return Nrcomplex(this->real+b.real,this->imaginar+b.imaginar);
    }
    Nrcomplex operator-(const Nrcomplex &b)
    {
        /*int real=a.getReal()+b.getReal();
        int imaginar=a.getImaginar()+b.getImaginar();
        Nrcomplex c(a,b);*/
        return Nrcomplex(this->real-b.real,this->imaginar-b.imaginar);
    }
    Nrcomplex operator*(const Nrcomplex &b)
    {
        /*int real=a.getReal()+b.getReal();
        int imaginar=a.getImaginar()+b.getImaginar();
        Nrcomplex c(a,b);-this->imaginar*b.imaginar   +this.real*b.imaginar*/
        return Nrcomplex(this->real*b.real - this->imaginar*b.imaginar , b.real*this->imaginar + this->real*b.imaginar);
    }
    Nrcomplex operator/(const Nrcomplex &b)
    {
        /*int real=a.getReal()+b.getReal();
        int imaginar=a.getImaginar()+b.getImaginar();
        Nrcomplex c(a,b);-this->imaginar*b.imaginar   +this.real*b.imaginar*/
        return Nrcomplex(this->real/b.real - this->imaginar/b.imaginar , b.real/this->imaginar + this->real/b.imaginar);
    }

    bool operator==(const Nrcomplex &b)
    {
        /*int real=a.getReal()+b.getReal();
        int imaginar=a.getImaginar()+b.getImaginar();
        Nrcomplex c(a,b);-this->imaginar*b.imaginar   +this.real*b.imaginar*/
        return (this->real==b.real and this->imaginar==b.imaginar);
    }
    bool operator!=(const Nrcomplex &b)
    {
        /*int real=a.getReal()+b.getReal();
        int imaginar=a.getImaginar()+b.getImaginar();
        Nrcomplex c(a,b);-this->imaginar*b.imaginar   +this.real*b.imaginar*/
        return !(this->real==b.real and this->imaginar==b.imaginar);
    }
    friend istream& operator>>(istream& in, Nrcomplex& nrcomplex)
    {

		return in >> nrcomplex.real >> nrcomplex.imaginar;
	}

    friend ostream& operator<<(ostream& in, Nrcomplex& nrcomplex)
    {

		return in << nrcomplex.real<<" and i" << nrcomplex.imaginar;
	}

    double modul()
    {
        return this->real*this->real + this->imaginar*this->imaginar;
    }
    void printData()
    {
        cout<<real<<" and "<<imaginar<<"\n";
    }
};

