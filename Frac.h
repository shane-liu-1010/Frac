
#include<algorithm>
class Frac{
    private:
        int _a;
        int _b;
    public:
        Frac(){_a=0;_b=1;}
        Frac(int a,int b=1){
            int g=__gcd(a,b);
            _a=a/g;
            _b=b/g;
            if(_b<0){
                _b*=-1;
                _a*=-1;
            }
        }
        friend Frac inverse(Frac a){
            int x=a._b;
            int y=a._a;
            Frac b(x,y);
            return b;
        }
        friend ostream & operator<<(ostream &out,const Frac &x){
            if(x._b==1)out<<x._a;
            else out<<x._a<<"/"<<x._b;
            return out;
        }
    	friend istream & operator>>(istream &in,Frac &x){
            int a,b;
            in>>a>>b;
            Frac y(a,b);
            x=y;
            return in;
        }
        friend Frac operator+(Frac a,Frac b){
            int x=a._a*b._b+b._a*a._b;
            int y=a._b*b._b;
            Frac c(x,y);
            return c;
        }
        friend Frac operator-(Frac a,Frac b){
            return a+(-1*b);
        }
        friend Frac operator*(Frac a,Frac b){
            int x=a._a*b._a;
            int y=a._b*b._b;
            Frac c(x,y);
            return c;
        }
        friend Frac operator/(Frac a,Frac b){
            return a*inverse(b);
        }
        friend Frac operator=(Frac a,Frac b){
            a._a=b._a;
            a._b=b._b;
            return a;
        }
        friend void operator+=(Frac a,Frac b){a=a+b;return;}
        friend void operator-=(Frac a,Frac b){a=a-b;return;}
        friend void operator*=(Frac a,Frac b){a=a*b;return;}
        friend void operator/=(Frac a,Frac b){a=a/b;return;}
        friend void operator==(Frac a,Frac b){return a._a==b._a&&a._b==b._b;}
        friend void operator!=(Frac a,Frac b){return !(a==b);}
        friend bool operator<(Frac a,Frac b){return a._a*b._b<b._a*a._b;}
        friend bool operator>(Frac a,Frac b){return b<a;}
		friend bool operator<=(Frac a,Frac b){return !(b<a);}
		friend bool operator>=(Frac a,Frac b){return !(a<b);}
};
