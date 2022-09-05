#include <iostream>

using namespace std;

int main()
{
    float temp_C, temp_F, weight_kg, weight_lbs, press_Hg, press_Pa, press_bar, press_psi;
    cout << "Enter the temperature in Celsius: " << endl;
    cin >> temp_C;
    const float k_temp = 1.8;
    temp_F = temp_C * k_temp + 32;
    cout << "The temperature in Fahrenheit: " << temp_F << endl;

    cout << "Enter the temperature in Fahrenheit: " << endl;
    cin >> temp_F;
    temp_C = (temp_F - 32)/k_temp;
    cout << "The temperature in Celsius: " << temp_C << endl;

    cout << "Enter the weight in kilograms: " << endl;
    cin >> weight_kg;
    const float k_weight = 2.205;
    weight_lbs = k_weight * weight_kg;
    cout << "The weight in pounds: " << weight_lbs << endl;

    cout << "Enter the pressure in mm Hg: " << endl;
    cin >> press_Hg;
    const float k_press = 133;
    const float k_pressCGS = 1.93/1000;
    press_Pa = k_press * press_Hg;
    press_bar = press_Pa / 100000;
    press_psi = k_pressCGS * press_Hg;
    cout << "The pressure in Pa: " << press_Pa << " in psi: " << press_psi << endl;
    return 0;
}
