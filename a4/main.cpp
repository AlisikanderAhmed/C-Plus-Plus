//  CPS311 F2015 A4 Gp36 Ahmed, AA; Danh, ND; Dong, SD

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

class shopper{
    protected:
        char *  shopper_name;
        int years_a_member;
        double avg_monthly_purchases;
        double membership_cost;
        double nominal_membership_cost = 50;
    
    public:
        shopper(int yrs_a_mbr, char * sh_nm, double av_mnth_prchs = 250);
        ~shopper();
    
        double get_membership_cost(){ return membership_cost+2; }
        char * get_shopper_name(){ return shopper_name; }
    
    virtual void set_membership_cost(){
        if(years_a_member<5){
                membership_cost = nominal_membership_cost - (0.005 * avg_monthly_purchases) - (nominal_membership_cost * (years_a_member * 0.04));
        }
        
        else
            membership_cost=30;
    };
};

shopper::shopper(int yrs_a_mbr, char * sh_nm, double av_mnth_prchs): years_a_member(yrs_a_mbr){
    shopper_name = new char[10];
    strcpy(shopper_name, sh_nm);
    avg_monthly_purchases = av_mnth_prchs;
}

ostream& operator<<(ostream& os, shopper& shpr){
    os << shpr.get_shopper_name() << " has yearly membership cost of $"	<< shpr.get_membership_cost() << endl;
    
    return os;
}

shopper::~shopper(){
    std::cout << "In the destructor" << std::endl;
    delete [] shopper_name;
}

class family_shopper : public shopper{
    protected:
        double family_discount;
    public:
        family_shopper(char * f_sh_nm, double fam_disc=10, double av_mnth_prchs=100.00, int yrs_a_mbr=2);
        friend ostream& operator << (ostream& os, family_shopper&  f_shpr);

   virtual void set_membership_cost(){
        if(years_a_member<5)
            membership_cost = (1.0 - (family_discount/100.0)) * (nominal_membership_cost - (0.005 * avg_monthly_purchases) - (nominal_membership_cost * (years_a_member * 0.04)));
            else
                membership_cost = 30;
    };
};

ostream& operator<<(ostream& os, family_shopper& f_shpr){
    cout.setf(ios::fixed);
    cout.precision(2);
    os << f_shpr.shopper_name << " is a family shopper whose annual membership with discount of " << (int)f_shpr.family_discount << "% is " << f_shpr.membership_cost << endl;
    
    return os;
}

family_shopper::family_shopper(char * f_sh_nm, double fam_disc, double av_mnth_prchs, int yrs_a_mbr):
    shopper(yrs_a_mbr, f_sh_nm, av_mnth_prchs){
    family_discount = fam_disc;
}

int main(int argc, const char * argv[]) {
    shopper shpr1(3, "ABC", 600) ;
    shopper shpr2(6, "DEF");
    family_shopper f_shpr1("GHI", 12);
    shopper *ptr;
    
    ptr= &shpr1;
    ptr->set_membership_cost();
    cout << shpr1;
    
    ptr= &shpr2;
    ptr->set_membership_cost();
    cout << shpr2;
    
    ptr= &f_shpr1;
    ptr->set_membership_cost();
    cout << f_shpr1;

    return 0;
}
