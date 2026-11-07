#include<iostream>
#include<iomanip>

void showbalance(double balance){
    std::cout<<"Bank Balance = "<<std::setprecision(2)<<std::fixed<<balance<<"\n\n";
}

double deposit(){
    std::cout<<"Enter the amount you want to deposit : ";
    double amount;
    if(!(std::cin>>amount)){
        std::cout<<"Enter a valid number.\n";
        std::cin.clear();
        fflush(stdin);
        return 0;
    }
    if(amount<0){
        std::cout<<"Cannot deposit negative value.\n";
        return 0;
    }
    else{
        return amount; 
    }
}

double withdraw(double balance){
    std::cout<<"Enter the amount you want to withdraw : ";
    double amount;
    if(!(std::cin>>amount)){
        std::cout<<"Please enter a valid number.\n";
        std::cin.clear();
        fflush(stdin);
        return 0;
    }
    if(amount>balance){
        std::cout<<"Insufficient Balance.\n";
        return 0;
    }
    
    else if(amount<0){
        std::cout<<"Cannot withdraw negative value.\n";
        return 0;
    }
    else{
        return amount;
    }
}

int main(){
    int choice = 0;
    double balance = 0;
    do{
        
        std::cout<<"\n\t\t********Banking System********\n\n";
        std::cout<<"1.Show Balance.\n";
        std::cout<<"2.Deposit Money.\n";
        std::cout<<"3.Withdraw Money.\n";
        std::cout<<"4.Exit.\n\n";
        std::cout<<"-----------------\n";
        std::cout<<"Enter choice : ";
        if(!(std::cin>>choice)){
            std::cout<<"Enter a valid number.\n";
            std::cin.clear();
            fflush(stdin);
            continue;
        }

        
        switch(choice){
            case 1:
                showbalance(balance);
                break;
            case 2:
                balance += deposit();
                showbalance(balance);
                break;
            case 3:
                balance -= withdraw(balance);
                showbalance(balance);
                break;
            case 4:
                std::cout<<"Thank You.\n\n";
                break;
            default:
                std::cout<<"Invalid input.\n\n";
        }
    }while(choice!=4);
    return 0;
}