#include <iostream>

using namespace std;

int main()
{
    //constant error codes
    const int SUCCESS = 0;
    const int RANGE_ERROR = -1;
    const int CONVERSION_ERROR = -2;
    const int WEIGHTS_ERROR = -3;

    int intPercentage1,
        intPercentage2,
        intPercentage3 = 0;
    double dblWeight1,
           dblWeight2,
           dblWeight3 = 0.0;

    cout << "Enter the percentage of Power Station 1: \n";

    //Capturing input from the user
    cin >> intPercentage1;
    if (cin.fail())
    {
       cin.clear();
       string strGabage = "";
       cin >> strGabage;
       cerr << "Not valid, Enter a whole number: \n";
       cin >> intPercentage1;

       if(cin.fail()){
        cerr << "Invalid Again, the program will now close.";
        return CONVERSION_ERROR;
       }

    }

    if(intPercentage1 < 0 || intPercentage1 > 100)
    {
        cin.clear();
        cerr << "Number entered is out of range (0 - 100). Try again one more time: \n";
        cin >> intPercentage1;

        if(cin.fail() || (intPercentage1 < 0 || intPercentage1 > 100))
        {
            cerr << "Value entered is out of range (0 - 100) or is Invalid, the program will now close.";
            return RANGE_ERROR;
        }
    }

    cout << "Enter the percentage of Power Station 2: \n";
    cin >> intPercentage2;
        if (cin.fail())
    {
       cin.clear();
       string strGabage = "";
       cin >> strGabage;
       cerr << "Not valid, Enter a whole number: \n";
       cin >> intPercentage2;

       if(cin.fail()){
        cerr << "Invalid Again, the program will now close.";
        return CONVERSION_ERROR;
       }

    }
    if(intPercentage2 < 0 || intPercentage2 > 100)
    {
        cin.clear();
        cerr << "Number entered is out of range (0 - 100). Try again one more time: \n";
        cin >> intPercentage2;

        if( cin.fail() || (intPercentage2 < 0 || intPercentage2 > 100))
        {
            cerr << "Value entered is out of range (0 - 100) or is Invalid, the program will now close.";
            return RANGE_ERROR;
        }
    }


    cout << "Enter the percentage of Power Station 3: \n";
    cin >> intPercentage3;
        if (cin.fail())
    {
       cin.clear();
       string strGabage = "";
       cin >> strGabage;
       cerr << "Not valid, Enter a whole number: \n";
       cin >> intPercentage3;

       if(cin.fail()){
        cerr << "Invalid Again, the program will now close.";
        return CONVERSION_ERROR;
       }

    }
    if(intPercentage3 < 0 || intPercentage3 > 100)
    {
        cin.clear();
        cerr << "Number entered is out of range (0 - 100). Try again one more time: \n";
        cin >> intPercentage3;

        if(cin.fail() || (intPercentage3 < 0 || intPercentage3 > 100))
        {
            cerr << "Value entered is out of range (0 - 100) or is Invalid, the program will now close.";
            return RANGE_ERROR;
        }
    }


        //Get the weights of each assessment
    cout << "Please enter the weight for Power Station 1: \n";
    cin >> dblWeight1;
    if(dblWeight1 < 0.0 || dblWeight1 > 1.0)
        {
            cerr << "Value entered is out of range (0.0 - 1.0).Try again one more time: \n";
            cin >> dblWeight1;
            if (dblWeight1 < 0.0 || dblWeight1 > 1.0)
            {
                cerr << "Again value entered is out of range (0.0 - 1.0). Program will now close";
                return RANGE_ERROR;
            }
        }
    cout << "Please enter the weight for Power Station 2: \n";
    cin >> dblWeight2;
    if (dblWeight2 < 0.0 || dblWeight2 > 1.0)
        {
            cerr << "Value entered is out of range (0.0 - 1.0).Try again one more time: \n";
            cin >> dblWeight2;
            if (dblWeight2 < 0.0 || dblWeight2 > 1.0)
            {
                cerr << "Again value entered is out of range (0.0 - 1.0). Program will now close";
                return RANGE_ERROR;
            }
        }
    cout << "Please enter the weight for Power Station 3: \n";
    cin >> dblWeight3;
    if (dblWeight3 < 0.0 || dblWeight3 > 1.0)
        {
            cerr << "Value entered is out of range (0.0 - 1.0).Try again one more time: \n";
            cin >> dblWeight3;
            if (dblWeight3 < 0.0 || dblWeight3 > 1.0)
            {
                cerr << "Again value entered is out of range (0.0 - 1.0). Program will now close";
                return RANGE_ERROR;
            }
        }

    //See if the weights add up to one
    double dblSumWeigth = dblWeight1 + dblWeight2 + dblWeight3;
    const double dblErrorMargin = 0.000000001;
    //See if the sum of the weights are NOT close to 1
    if(dblSumWeigth > 1+dblErrorMargin ||
       dblSumWeigth < 1-dblErrorMargin)
    {
        cerr << "Sum of the weights are not equal to 1" << endl;
        return WEIGHTS_ERROR;
    }
    int intLoadLikelihood = 0.0;
        /// Calculate the weighted score.
     intLoadLikelihood = (intPercentage1 * dblWeight1)
                       + (intPercentage2 * dblWeight2)
                       + (intPercentage3 * dblWeight3);

//Display Load-shedding likelihood
switch(intLoadLikelihood){
        case 0 ... 59 :
        cout << "Low";
    break;
        case 60 ... 79 :
        cout << "Medium";
    break;
        case 80 ... 100 :
        cout << "High";
    break;
        default :
        cout << "Error";
    }


    return SUCCESS;
}
