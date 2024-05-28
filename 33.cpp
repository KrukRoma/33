#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Car 
{
    string name;
    int year;
    float engineVolume;
    double price;

    void display() const 
    {
        cout << "Name: " << name << ", Year: " << year
            << ", Engine Volume: " << engineVolume
            << "L, Price: $" << price << endl;
    }
};

class CarShowroom 
{
private:
    vector<Car> cars;

    void swap(Car& a, Car& b) 
    {
        Car temp = a;
        a = b;
        b = temp;
    }

public:
    void addCar(const Car& car) 
    {
        cars.push_back(car);
    }

    void removeCar(const string& name) 
    {
        for (auto it = cars.begin(); it != cars.end(); ++it) 
        {
            if (it->name == name) 
            {
                cars.erase(it);
                break;
            }
        }
    }

    void displayCars() const 
    {
        for (const auto& car : cars) 
        {
            car.display();
        }
    }

    void sortByName() 
    {
        for (size_t i = 0; i < cars.size(); ++i) 
        {
            for (size_t j = i + 1; j < cars.size(); ++j) 
            {
                if (cars[i].name > cars[j].name) 
                {
                    swap(cars[i], cars[j]);
                }
            }
        }
    }

    void sortByYear() 
    {
        for (size_t i = 0; i < cars.size(); ++i) 
        {
            for (size_t j = i + 1; j < cars.size(); ++j) 
            {
                if (cars[i].year > cars[j].year) 
                {
                    swap(cars[i], cars[j]);
                }
            }
        }
    }

    void sortByEngineVolume() 
    {
        for (size_t i = 0; i < cars.size(); ++i) 
        {
            for (size_t j = i + 1; j < cars.size(); ++j) 
            {
                if (cars[i].engineVolume > cars[j].engineVolume) 
                {
                    swap(cars[i], cars[j]);
                }
            }
        }
    }

    void sortByPrice() 
    {
        for (size_t i = 0; i < cars.size(); ++i) 
        {
            for (size_t j = i + 1; j < cars.size(); ++j) 
            {
                if (cars[i].price > cars[j].price) 
                {
                    swap(cars[i], cars[j]);
                }
            }
        }
    }

    void searchByName(const string& name) const 
    {
        for (const auto& car : cars) 
        {
            if (car.name == name) 
            {
                car.display();
                return;
            }
        }
        cout << "Car with name " << name << " not found." << endl;
    }

    void searchByYear(int year) const 
    {
        for (const auto& car : cars) 
        {
            if (car.year == year) 
            {
                car.display();
                return;
            }
        }
        cout << "Car from year " << year << " not found." << endl;
    }

    void searchByEngineVolume(float engineVolume) const 
    {
        for (const auto& car : cars) 
        {
            if (car.engineVolume == engineVolume) 
            {
                car.display();
                return;
            }
        }
        cout << "Car with engine volume " << engineVolume << "L not found." << endl;
    }

    void searchByPrice(double price) const 
    {
        for (const auto& car : cars) 
        {
            if (car.price == price) 
            {
                car.display();
                return;
            }
        }
        cout << "Car with price $" << price << " not found." << endl;
    }
};

int main() 
{
    CarShowroom showroom;

    showroom.addCar({ "Toyota Camry", 2020, 2.5, 24000 });
    showroom.addCar({ "Honda Accord", 2018, 2.0, 22000 });
    showroom.addCar({ "Ford Mustang", 2021, 5.0, 55000 });

    cout << "All cars in showroom:\n";
    showroom.displayCars();

    cout << "\nCars sorted by name:\n";
    showroom.sortByName();
    showroom.displayCars();

    cout << "\nCars sorted by year:\n";
    showroom.sortByYear();
    showroom.displayCars();

    cout << "\nCars sorted by engine volume:\n";
    showroom.sortByEngineVolume();
    showroom.displayCars();

    cout << "\nCars sorted by price:\n";
    showroom.sortByPrice();
    showroom.displayCars();

    cout << "\nSearch for a car by name 'Honda Accord':\n";
    showroom.searchByName("Honda Accord");

    cout << "\nSearch for a car by year 2020:\n";
    showroom.searchByYear(2020);

    cout << "\nSearch for a car by engine volume 5.0L:\n";
    showroom.searchByEngineVolume(5.0);

    cout << "\nSearch for a car by price $24000:\n";
    showroom.searchByPrice(24000);

    cout << "\nRemove car 'Honda Accord' and display all cars:\n";
    showroom.removeCar("Honda Accord");
    showroom.displayCars();
}

