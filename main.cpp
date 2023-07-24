#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Features{  //structure of vector Features(which information it contains)
    double square;
    int bathrooms;
    int bedrooms;
    int dist;
    bool habitableOrCommercial;
    double price;
};

double prediction(vector<Features> feature1) {     //create function to predict price
    double averageValueOfAll = 0;
    int sizeOfVector = feature1.size();
    int i;
    if(sizeOfVector<1) return 0;
    cout<<endl<< "To calculate price of your apartment we must: find sum of all costs for 1 m^2:  ";
    for(i = 0; i < feature1.size()-1; i++){ //create cycle "for" to calculate sum of prices for 1 m^2 of all apartments
        averageValueOfAll += feature1[i].price/feature1[i].square;
    }
    cout<< averageValueOfAll<<endl;
    cout<< endl<<"Then: divide this by number of apartments: "<< averageValueOfAll<<"/"<<(sizeOfVector-1)<<endl;
    double averageValue=averageValueOfAll/(sizeOfVector-1); //calculating average value
    cout<< averageValue<<endl;
    cout<< endl<<"By doing this, we get price for 1m^2 of our new apartment"<<endl;
    cout<< endl<<"The last part is calculating the price: average cost of 1m^2 multiply by square of new apartment: "<< averageValue<< "*"<<feature1[sizeOfVector-1].square<<endl;
    double price = averageValue*feature1[sizeOfVector-1].square; //price for new apartment is multiplying average value by square of our new apartment
    cout<<endl<<"Your predictable price is: ";
    return price;

}

const double MIN_SQUARE = 20;
const double MAX_SQUARE = 10000;
const int MIN_NUMBER_OF_BATHROOMS = 1;
const int MAX_NUMBER_OF_BATHROOMS = 50;
const int MIN_NUMBER_OF_BEDROOMS = 1;
const int MAX_NUMBER_OF_BEDROOMS = 100;
const int MIN_DIST_TO_SUBWAY = 0;
const int MAX_DIST_TO_SUBWAY = 60;
const double MAX_PRICE = 3000000;

bool sanity_check_square (double square){
    return square < MIN_SQUARE || square>MAX_SQUARE;
}

bool sanity_check_numberOfBathrooms( int bathrooms){
    return bathrooms < MIN_NUMBER_OF_BATHROOMS || bathrooms > MAX_NUMBER_OF_BATHROOMS;
}

bool sanity_check_numberOfBedrooms( int bedrooms ){
    return bedrooms < MIN_NUMBER_OF_BEDROOMS || bedrooms > MAX_NUMBER_OF_BEDROOMS;
}

bool sanity_check_dist(int dist){
    return dist < MIN_DIST_TO_SUBWAY || dist > MAX_DIST_TO_SUBWAY;
}

bool sanity_check_habOrCom (string habOrCom){
    return habOrCom != "commercial" && habOrCom != "habitable";
}

bool sanity_check_price(double price){
    return price > MAX_PRICE;
}


int main() {
    cout<<endl;
    cout<<"     /\\\n";
    cout<<"    /  \\\n";
    cout<<"   /    \\\n";
    cout<<"  /______\\\n";
    cout<<" /|      |\\\n";
    cout<<"  |      |"<<endl;
    cout<<"  |______|"<<endl;

    double square;
    int numberOfBedrooms;
    int numberOfBathrooms;
    int distToSubway;
    bool habitableOrCommercial;
    string habOrCom;
    double price=1;
    vector<Features> feature;
    while (price!=0) {
        cout<<endl<<"Enter all the features of your apartment, if you want to start the prediction: IN FEATURE PRICE - ENTER 0 "<<endl<<endl;
        cout << "Enter the square of apartment (if you want to finish-enter 0)  " ;
        cin >> square;
        if(square!=0){
            while(sanity_check_square(square)){
                cout<<"Square must be more than "<<MIN_SQUARE<< " and less than "<<MAX_SQUARE<< endl;
                cout<<"Enter one more time  ";
                cin>>square;
            }
        }
        else return 0;

        cout << "Enter number of bathrooms in apartment  " ;
        cin >> numberOfBathrooms;
        while(sanity_check_numberOfBathrooms(numberOfBathrooms)){
            cout<<"Number of bathrooms must be more than "<<MIN_NUMBER_OF_BATHROOMS<< " and less than "<<MAX_NUMBER_OF_BATHROOMS<<endl;
            cout<<"Enter one more time  " ;
            cin>>numberOfBathrooms;
        }


        cout << "Enter number of bedrooms in apartment  " ;
        cin >> numberOfBedrooms;
        while(sanity_check_numberOfBedrooms(numberOfBedrooms)){
            cout<<"Number of bedrooms must be more than "<<MIN_NUMBER_OF_BEDROOMS<< " and less than "<<MAX_NUMBER_OF_BEDROOMS<<endl;
            cout<<"Enter one more time  ";
            cin>>numberOfBedrooms;
        }


        cout << "Enter the distance to subway from your apartment  " ;
        cin >> distToSubway;
        while(sanity_check_dist(distToSubway)){
            cout<<"Distance to subway must be more than "<< MIN_DIST_TO_SUBWAY<< " and less than"<<MAX_DIST_TO_SUBWAY<<endl;
            cout<<"Enter one more time  ";
            cin>>distToSubway;
        }


        cout << "Enter whether the apartment is habitable or commercial  " ;
        cin >> habOrCom;
        while(sanity_check_habOrCom(habOrCom)){
            cout<< "Apartment must be habitable or commercial"<<endl;
            cout<<"Enter one more time  ";
            cin>>habOrCom;
        }
        if(habOrCom=="commercial"||habOrCom=="habitable"){
            habitableOrCommercial=true;
        }

        cout << "Enter the price of the apartment(in dollars)  " ;
        cin >> price;
        while(sanity_check_price(price)){
            cout<< "Price must be less than "<<fixed<<MAX_PRICE<<endl;
            cout<<"Enter one more time  ";
            cin>>price;
        }

        feature.push_back({square, numberOfBathrooms, numberOfBedrooms, distToSubway, habitableOrCommercial, price});

        cout<<endl<<"Features of entered apartment: "<<endl;
        cout<< "Square: "<<feature[feature.size()-1].square<<endl;
        cout<< "Number of bathrooms: " << feature[feature.size()-1].bathrooms<<endl;
        cout<< "Number of bedrooms: "<< feature[feature.size()-1].bedrooms<<endl;
        cout<< "Distance to subway: "<<feature[feature.size()-1].dist<<endl;
        cout<<"Is your apartment habitable or commercial?(if 1 - yes) "<<feature[feature.size()-1].habitableOrCommercial<<endl;
        cout<< "Price of apartment with these features: "<<fixed<<feature[feature.size()-1].price<<endl;


        if(price!=0) {
            cout << endl << "NEXT APARTMENT" << endl;
        }

    }
    cout<<endl;
    cout<<endl<<"START OF PREDICTION: "<<endl;
    cout<<prediction(feature)<<endl;

    cout<<endl<<"LET'S CONTINUE THE PREDICTION"<<endl;

    while(square!=0){
        cout<<endl<<"Enter features of new apartment ( IF YOU WANT TO FINISH - ENTER 0 IN SQUARE) "<<endl;
        cout << "Enter the square of apartment  " ;
        cin >> square;
        if(square!=0){
            while(sanity_check_square(square)){
                cout<<"Square must be more than "<<MIN_SQUARE<< " and less than "<<MAX_SQUARE<< endl;
                cout<<"Enter one more time  ";
                cin>>square;
            }
        }
        else return 0;

        cout << "Enter number of bathrooms in apartment  " ;
        cin >> numberOfBathrooms;
        while(sanity_check_numberOfBathrooms(numberOfBathrooms)){
            cout<<"Number of bathrooms must be more than "<<MIN_NUMBER_OF_BATHROOMS<< " and less than "<<MAX_NUMBER_OF_BATHROOMS<<endl;
            cout<<"Enter one more time  ";
            cin>>numberOfBathrooms;
        }


        cout << "Enter number of bedrooms in apartment  ";
        cin >> numberOfBedrooms;
        while(sanity_check_numberOfBedrooms(numberOfBedrooms)){
            cout<<"Number of bedrooms must be more than "<<MIN_NUMBER_OF_BEDROOMS<< " and less than "<<MAX_NUMBER_OF_BEDROOMS<<endl;
            cout<<"Enter one more time  ";
            cin>>numberOfBedrooms;
        }


        cout << "Enter the distance to subway from your apartment  " ;
        cin >> distToSubway;
        while(sanity_check_dist(distToSubway)){
            cout<<"Distance to subway must be more than "<< MIN_DIST_TO_SUBWAY<< " and less than"<<MAX_DIST_TO_SUBWAY<<endl;
            cout<< "Enter one more time  ";
            cin>>distToSubway;
        }


        cout << "Enter whether the apartment is habitable or commercial(must be habitable)  " ;
        cin >> habOrCom;
        while(sanity_check_habOrCom(habOrCom)){
            cout<< "Apartment must be habitable or commercial"<<endl;
            cout<<"Enter one more time  ";
            cin>>habOrCom;
        }
        if(habOrCom=="commercial"||habOrCom=="habitable"){
            habitableOrCommercial=true;
        }

        cout << "To start prediction - enter 0" << endl;
        cin >> price;
        while(price!=0){
            cout<<"To start prediction ENTER 0  ";
            cin>>price;
        }

        double averageValueOfAll = 0;
        int sizeOfVector = feature.size();
        int i;
        for(i = 0; i < feature.size()-1; i++){
            averageValueOfAll += feature[i].price/feature[i].square;
        }
        double averageValue=averageValueOfAll/(sizeOfVector-1);
        double price1 = averageValue*square;

        cout<<"Your predictable price is: "<<fixed<<price1 << endl;

    }

}

