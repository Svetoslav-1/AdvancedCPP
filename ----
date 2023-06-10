#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
void enterInformation(map<string, pair<double, int>>& details, const string& name, double pricePerProduct, int quantity){
    auto it = details.find(name);
    if (it != details.end()) {   
        it->second.first += pricePerProduct * quantity;  
        it->second.second += quantity;
    }
    else {   
        details.insert(make_pair(name, make_pair(pricePerProduct * quantity, quantity)));
    }
}

int main()
{
    int cities;
    cin >> cities;
    set<string> diffC;  
    map<string, pair<double, int>> details; 
    while (diffC.size() < cities) 
    {
        string name; 
        cin >> name; 
        diffC.insert(name);  

        double pricePerProduct;
        int quantity;
        cin >> pricePerProduct >> quantity;
        enterInformation(details, name, pricePerProduct, quantity);  
    }

    for (const auto& city : details) {
        cout << city.first << " " << city.second.first << endl;
    }

    return 0;
}






#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool CheckIfPrime(int number){
    int sqrtNumber = sqrt(number);
    for (int i = 2; i <= sqrtNumber; i++){    
        if (number % i == 0){
            return false;
        }
    }
    return true;
}
vector<int> getPrimeNumbersBelowDiagonals(const vector<vector<int>>& matrix)
{
    vector<int> primes;

    int size = matrix.size();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int num = matrix[i][j];
            if (j < i && j > size - i - 1 && CheckIfPrime(num))
                primes.push_back(num);
        }
    }
    return primes;
}
int main() 
{
    int rowsCols; 
    cin >> rowsCols; 
    int sum = 0; 
    vector<vector<int>> matrix(rowsCols,vector<int>(rowsCols));  
        for (int i = 0; i < rowsCols; i++){
        for (int j = 0; j < rowsCols; j++){ 
            cin >> matrix[i][j]; 
        }
    }
    vector<int> primes = getPrimeNumbersBelowDiagonals(matrix); 
    for (int prime : primes) {
        sum = sum + prime; 
    }
    cout << sum << endl;
    return 0;
}



#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Product {
public:
    Product()
        : name(""), price(0.0), count(0)
    {
    }

    Product(const string& productName, double productPrice, int productCount)
        : name(productName), price(productPrice), count(productCount)
    {
    }

    double getTotalPrice() const {
        return price * count;
    }

    string getName() const {
        return name;
    }

private:
    string name;
    double price; 
    int count; 
};

bool compareProducts(const Product& product1, const Product& product2) { 
    double productTotalPrice1 = product1.getTotalPrice(); 
    double productTotalPrice2 = product2.getTotalPrice(); 
    if (productTotalPrice1 != productTotalPrice2) 
        return productTotalPrice1 > productTotalPrice2; 
    else
        return product1.getName() < product2.getName(); 
}

int main() {
    int numProducts;
    cin >> numProducts;
    double fullPrice = 0.0;
    map<string, Product> products;

    for (int i = 0; i < numProducts; ++i) {
        string name;
        double price;
        int count;
        cin >> name >> price >> count;
        products[name] = Product(name, price, count);
    }

    vector<Product> sorted;
    for (const auto& pair : products) {
        const Product& product = pair.second;
        fullPrice += product.getTotalPrice();
        sorted.push_back(product);
    }
    sort(sorted.begin(), sorted.end(), compareProducts);

    cout << "The total sum is: " << fullPrice << " lv." << endl;

    for (const auto& product : sorted) {
        cout << product.getName() << " " << product.getTotalPrice() << endl;
    }

    return 0;
}

