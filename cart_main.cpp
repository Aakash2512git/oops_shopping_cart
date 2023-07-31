#include<iostream>
#include<vector>
#include "datamodel.h"
using namespace std;

vector<Product>allProducts={
    Product(1,"apple",26),
    Product(2,"mango",16),
    Product(3,"guava",34),
    Product(4,"banana",89),
    Product(5,"strawberry",12),
    Product(6,"pineapple",78),
    Product(1,"lemon",76),
};

Product*chooseProduct(){
    string productList;
    cout<<"Available Products"<<endl;
     
     for(auto product:allProducts){
        productList.append(product.getDisplayName());
     }
     cout<<productList<<endl;

     cout<<"-------------------"<<endl;
     string choice;
     cin>>choice;
     for(int i=0;i<allProducts.size();i++){
          if(allProducts[i].getShortName()==choice){
            return &allProducts[i];
          }
     }
     cout<<"Product not found"<<endl;

     return NULL;
};

bool checkout(Cart &cart){
    if(cart.isEmty()){
        return false;
    }

    int total=cart.getTotal();
    cout<<"Pay in cash: ";

    int paid;
    cin>>paid;

    if(paid>=total){
        cout<<"Change "<<paid-total<<endl; 
        cout<<"Thank you for shopping!";
        return true;
    }
    else{
        cout<<"Not enough cash";
        return false;
    }
}
int main(){
    char action;
    Cart cart;
    while(true){
        cout<<"select an action- (a)dd item, (v)iew cart, (c)heckout"<<endl;
         cin>>action;
        if(action=='a'){
            Product *product=chooseProduct();
            if(product!=NULL){
                cout<<"Added to cart"<<product->getDisplayName()<<endl;
                cart.addProduct(*product);
            }
        }
        else if(action=='v'){
            cout<<"--------------"<<endl;
             cout<<cart.viewCart()<<endl;
             cout<<"--------------"<<endl;
        }
        else
        {
            cart.viewCart();
            if(checkout(cart)){
                break;
            }
        }

    }
 return 0;   
}