#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct partsType{
    string partName1, partName2;
    string partNum;
    double partPrice;
    int qtyStock;
};


const int SIZE = 100;

void getData(ifstream&, partsType[], int&);
void displayTable(ifstream&, partsType[], int);
int linearSearch(partsType[], int, double);
void bubbleSort(partsType[], int);


int main(){
    
    partsType inventory[SIZE];
    int arraySize = 0;
    
    ifstream inFile;
    inFile.open("/Users/josuerodriguez/Documents/Xcode Projects/TestOnStructureAndSearch/TestOnStructureAndSearch/computerParts.txt");
    
    getData(inFile, inventory, arraySize);
    bubbleSort(inventory, arraySize);
    displayTable(inFile, inventory, arraySize);
    
    cout << "LINEAR SEARCH: Type in a price to search for items of that price: $";
    double linearKey;
    cin >> linearKey;
    int linearIndex;
    
    linearIndex = linearSearch(inventory, arraySize, linearKey);
    
    
    if (linearIndex == -1){
        cout << "\nITEM WITH THAT PRICE WAS NOT FOUND!" << endl;
    }
    else {
        string name = inventory[linearIndex].partName1 + " " + inventory[linearIndex].partName2;
        cout << "\nITEM FOUND WITH PRICE " << linearKey << "!" << endl << endl;
        cout << "Part Name: " << name << endl;
        cout << "Part Number: " << inventory[linearIndex].partNum << endl;
        cout << "Quantity in Stock: " << inventory[linearIndex].qtyStock << endl << endl;;
    }
    
   /*
    for (int j = 0; j < SIZE; j++){
        cout << inventory[j].partName1 << " " << inventory[j].partName2 << " " <<  inventory[j].partNum << " " << inventory[j].partPrice << " " << inventory[j].qtyStock << endl;
    }
    */
    
    
    return 0;
}

//**********************************************************************************************************************************************************************************

void getData(ifstream& inFile, partsType arr[], int& i){
    
    ifstream ins;
    ins.open("/Users/josuerodriguez/Documents/Xcode Projects/TestOnStructureAndSearch/TestOnStructureAndSearch/computerParts.txt");
    
    if (!ins){
        cout << "ERROR: FILE NOT FOUND" << endl;
        cout << endl << endl;
        return;
    }
    else{
        i = -1;
        do{
            i++;
            ins >> arr[i].partName1 >> arr[i].partName2 >> arr[i].partNum >> arr[i].partPrice >> arr[i].qtyStock;
        }while (!ins.eof());
    }
    
    ins.close();
}

//**********************************************************************************************************************************************************************************


void displayTable(ifstream& inFile, partsType arr[], int SIZE){
    
    cout << fixed << left << setprecision(2);
    cout << setw(22) << "PART NAME" << setw(18) << "PART NUMBER" << setw(18) << "PART PRICE" << setw(15) << "QUANTITY IN STOCK" << endl;
    cout << "==============================================================================" << endl;
    
    for (int i = 0; i < SIZE; i++){
        string partName = arr[i].partName1 + " " + arr[i].partName2;
        cout  << setw(22) << partName;
        cout  << setw(18) << arr[i].partNum;
        cout << "$" << setw(19) << arr[i].partPrice;
        cout << arr[i].qtyStock << endl;
    }
}

//**********************************************************************************************************************************************************************************

int linearSearch(partsType arr[], int SIZE, double index){
    for (int i = 0; i < SIZE; i++){
        if (arr[i].partPrice == index){
            return i;
        }
        
    }
    return -1;
}


//**********************************************************************************************************************************************************************************


void bubbleSort(partsType arr[], int SIZE){
    for (int i = 0; i < SIZE -1; i++){
        for (int j = 0; j < (SIZE -1); j++){
            if (arr[j].partPrice > arr[j+1].partPrice){
                partsType temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
