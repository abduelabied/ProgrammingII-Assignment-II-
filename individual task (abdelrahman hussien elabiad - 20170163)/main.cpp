#include <iostream>

using namespace std;
class Odometer{
private:
    double miles;
    double Fuel_Efficiency;
public:
    Odometer()
    {
        miles = 0.0;
        Fuel_Efficiency = 0.0;
    }
    void rest()
    {
        miles = 0.0;
    }
    void Set_Miles(double miles){
       this->miles = miles;

    }
    double GetMiles(){return miles;}

    void Set_Fuel_Efficiency(double Fuel_Efficiency){
        this->Fuel_Efficiency = Fuel_Efficiency;
    }
    double Get_NumberOfGallons(){
        return miles / Fuel_Efficiency;

    }


};

int main()
{
    Odometer trip1,trip2;
    trip1.rest();
    trip1.Set_Fuel_Efficiency(45);
    trip1.Set_Miles(100);
    cout<<"The Number of Gallons of Gasoline that used after "<<trip1.GetMiles()<<" Miles = "<<
    trip1.Get_NumberOfGallons();
    trip1.Set_Miles(50);
    cout<<endl;
    cout<<"After another "<<trip1.GetMiles()<<" Miles = "<<trip1.Get_NumberOfGallons();
    cout<<endl<<endl;
    trip2.rest();
    trip2.Set_Fuel_Efficiency( 17);
    trip2.Set_Miles(70);
    cout<<"The Number of Gallons of Gasoline that used after "<<trip2.GetMiles()<<" Miles = "<<
    trip2.Get_NumberOfGallons();
    trip2.Set_Miles(90);
    cout<<endl;
    cout<<"After another "<<trip2.GetMiles()<<" Miles = "<<trip2.Get_NumberOfGallons();
    cout<<endl<<endl;

    return 0;
}
