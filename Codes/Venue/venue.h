#include<vector>
using namespace std;

class MainVenue{
public:
    MainVenue(){}
    void showBasicInformation();
    ~MainVenue(){}

private:
    vector<MainVenue> venues;
};

class ClothingVenue:public MainVenue{

};

class SnacksVenue:public MainVenue{

};

class ElectronicVenue:public MainVenue{

};

class FruitsVenue:public MainVenue{

};