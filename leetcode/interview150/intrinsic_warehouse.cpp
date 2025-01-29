#include <string>
#include <iostream>
#include <map>
#include <vector>
class Product
{
public:
  int productID;
  std::string name;
  int quantity;

  Product(int id, const std::string& name, int qty) : productID(id), name(name), quantity(qty)
  {
  }

  void display() const
  {
    std::cout << "ID: " << productID << ", Name: " << name << ", Quantity: " << quantity << std::endl;
  }
};

class StorageLocation
{
public:
  int locationID;
  std::string name;
  int capacity;         // max quantity that can be stored in this location
  int currentQuantity;  // current amount of product in this location

  StorageLocation(int id, const std::string& name, int cap)
    : locationID(id), name(name), capacity(cap), currentQuantity(0)
  {
  }

  bool addProduct(const Product& product, int qty)
  {
    if (currentQuantity + qty <= capacity)
    {
      currentQuantity += qty;
      return true;
    }
    return false;
  }

  bool removeProduct(const Product& product, int qty)
  {
    if (currentQuantity >= qty)
    {
      currentQuantity -= qty;
      return true;
    }
    return false;
  }

  void display() const
  {
    std::cout << "Location ID: " << locationID << ", Name: " << name << ", Capacity: " << capacity
              << ", Current Quantity: " << currentQuantity << std::endl;
  }
};

class InventoryTransaction
{
public:
  int transactionID;
  int productID;
  int quantity;
  std::string transactionType;  // "IN" or "OUT"
  int locationID;

  InventoryTransaction(int txnID, int prodID, int qty, const std::string& txnType, int locID)
    : transactionID(txnID), productID(prodID), quantity(qty), transactionType(txnType), locationID(locID)
  {
  }

  void display() const
  {
    std::cout << "Transaction ID: " << transactionID << ", Product ID: " << productID << ", Quantity: " << quantity
              << ", Type: " << transactionType << ", Location ID: " << locationID << std::endl;
  }
};

class WarehouseDatabase
{
private:
  std::map<int, Product> products;
  std::map<int, StorageLocation> locations;
  std::vector<InventoryTransaction> transactions;

public:
  void addProduct(const Product& product)
  {
    products[product.productID] = product;
  }

//   void addStorageLocation(const StorageLocation& location)
//   {
//     locations[location.locationID] = location;
//   }

//   void logTransaction(const InventoryTransaction& txn)
//   {
//     transactions.push_back(txn);
//     if (txn.transactionType == "IN")
//     {
//       locations[txn.locationID].addProduct(products[txn.productID], txn.quantity);
//     }
//     else if (txn.transactionType == "OUT")
//     {
//       locations[txn.locationID].removeProduct(products[txn.productID], txn.quantity);
//     }
//   }

//   void displayInventory() const
//   {
//     std::cout << "Products in Warehouse:" << std::endl;
//     for (const auto& entry : products)
//     {
//       entry.second.display();
//     }

//     std::cout << "\nStorage Locations:" << std::endl;
//     for (const auto& entry : locations)
//     {
//       entry.second.display();
//     }
//   }

//   void displayTransactions() const
//   {
//     std::cout << "\nInventory Transactions:" << std::endl;
//     for (const auto& txn : transactions)
//     {
//       txn.display();
//     }
//   }
};
/*
int main()
{
  WarehouseDatabase db;

  // Create and add some products
  Product prod1(101, "Product A", 50);
  Product prod2(102, "Product B", 30);
  db.addProduct(prod1);
  db.addProduct(prod2);

  // Create and add some storage locations
  StorageLocation loc1(1, "Aisle 1", 100);
  StorageLocation loc2(2, "Aisle 2", 50);
  db.addStorageLocation(loc1);
  db.addStorageLocation(loc2);

  // Log some transactions
  InventoryTransaction txn1(1, 101, 20, "IN", 1);   // Add 20 of Product A to Aisle 1
  InventoryTransaction txn2(2, 102, 10, "OUT", 2);  // Remove 10 of Product B from Aisle 2
  db.logTransaction(txn1);
  db.logTransaction(txn2);

  // Display Inventory and Transactions
  db.displayInventory();
  db.displayTransactions();

  return 0;
}
*/
int main()

{
  Product prod1(101, "Product A", 50);
  Product prod2(102, "Product B", 30);

  StorageLocation loc1(1, "Aisle 1", 100);
  StorageLocation loc2(2, "Aisle 2", 50);

  InventoryTransaction txn1(1, 101, 20, "IN", 1);   // Add 20 of Product A to Aisle 1
  InventoryTransaction txn2(2, 102, 10, "OUT", 2);  // Remove 10 of Product B from Aisle 2
  return 0;
}