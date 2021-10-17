// ============need input=================
// fast_fourier_transform fft;
  // fft.multiply(vector<ll> f, vector<ll> g)
  
// ========================================

// ============fast_fourier_transform===============
struct mycomplex {
	double realvalue, imagvalue;
public:
	mycomplex() :realvalue(0), imagvalue(0) {}
	mycomplex(double realvalue, double imagvalue) : realvalue(realvalue), imagvalue(imagvalue) {}
	mycomplex(double realvalue) : realvalue(realvalue), imagvalue(0) {}
	mycomplex(std::complex<double> c) :realvalue(c.real()), imagvalue(c.imag()) {}
	mycomplex(const mycomplex& rhs) :realvalue(rhs.realvalue), imagvalue(rhs.imagvalue) {}
	double real()const { return this->realvalue; }
	double imag()const { return this->imagvalue; }
	double abs() { return hypot(realvalue, imagvalue); }
	mycomplex& operator=(const mycomplex& obj) {
		if (this != &obj) {
			this->realvalue = obj.realvalue;
			this->imagvalue = obj.imagvalue;
		}
		return *this;
	}
	mycomplex& operator+=(const mycomplex& rhs) {
		this->realvalue += rhs.realvalue;
		this->imagvalue += rhs.imagvalue;
		return *this;
	}
	mycomplex operator+(const mycomplex& rhs)const {return mycomplex(*this)+=rhs;}
	mycomplex& operator-=(const mycomplex& rhs) {
		this->realvalue -= rhs.realvalue;
		this->imagvalue -= rhs.imagvalue;
		return *this;
	}
	mycomplex& operator-=(const double& rhs) {
		this->realvalue -= rhs;
		return *this;
	}
	mycomplex operator-(const mycomplex& rhs)const {return mycomplex(*this)-=rhs;}
	mycomplex& operator*=(const mycomplex& rhs) {
		double pastreal = this->realvalue;
		this->realvalue = this->realvalue * rhs.realvalue - this->imagvalue * rhs.imagvalue;
		this->imagvalue = pastreal * rhs.imagvalue + rhs.realvalue * this->imagvalue;
		return *this;
	}
	mycomplex operator*(const mycomplex& rhs)const {return mycomplex(*this)*=rhs;}
	mycomplex& operator/=(const mycomplex& rhs) {
		*this *= mycomplex(rhs.real(), -rhs.imag());
		double dnm = rhs.real() * rhs.real() - rhs.imag() * rhs.imag();
		this->realvalue /= dnm;
		this->imagvalue /= dnm;
		return *this;
	}
	mycomplex operator/(const mycomplex& rhs)const {return mycomplex(*this)/=rhs;}
};
struct fast_fourier_transform {
private:
	static void dft(std::vector<mycomplex>& func, int inverse) {
		int sz = func.size();
		if (sz == 1)return;
		std::vector<mycomplex> veca(sz>>1), vecb(sz>>1);
    for (ll i = 0; i < sz >> 1; ++i) {
      veca[i]=func[i<<1|0];
      vecb[i]=func[i<<1|1];
    }
		dft(veca, inverse); dft(vecb, inverse);
		mycomplex now = 1, zeta = std::polar(1.0, inverse * 2 * PI / sz);
    for (ll i = 0; i < sz; ++i) {
      if(i<(sz>>1))func[i] = veca[i] + now * vecb[i];
      else func[i]=veca[i-(sz>>1)]+now*vecb[i-(sz>>1)];
      now *= zeta;
    }
	}
public:
	template<typename T>
	static std::vector<double> multiply(const std::vector<T>& f, const std::vector<T>& g) {
		int sz = 1;
		while (sz < f.size() + g.size())sz *= 2;
		std::vector<mycomplex> nf(sz), ng(sz);
		std::copy(f.begin(),f.end(),nf.begin());
		std::copy(g.begin(),g.end(),ng.begin());
		dft(nf, 1);
		dft(ng, 1);
    for (ll i = 0; i < sz; ++i) {
      nf[i] *= ng[i];
    }
		dft(nf, -1);
		std::vector<double> res;
    for (ll i = 0; i < sz; ++i) {
      res.push_back(nf[i].real() / sz);
    }
		return res;
	}
};
// =======================================
