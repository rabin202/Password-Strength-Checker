#include <iostream>
#include<string>


int password_strength_check(std::string password);
int pass_length(std::string pass);
int pass_character_variety(std::string pass);
bool is_special(std::string pass);
int pass_patterns(std::string pass);
int pass_repition(std::string pass);
int pass_sequence(std::string pass);

int main(){
    std::string password;
    int result;
    std::cout << "Please Provide the password to check the strength of:"<<std::endl;
    std::getline(std::cin,password);
    std::cout<<password<<std::endl;
    result = password_strength_check(password);
    std::cout << result << std::endl;
    if(result<2){
        std::cout<<"Your password is very weak.\n We suggest you to change the password."<<std::endl;
    }
    else if(result<4){
        std::cout << "Your password is weak and requires some amendment."<<std::endl;
    
    }
    else if(result<6){
        std::cout << "Your password is strong."<<std::endl;
    
    }
    else if (result<9){
        std::cout<<"Your password is very strong"<<std::endl;
    }
    else{
        std::cout << "Sorry, We weren't able to calculate the strength of your password due to some difficulties."<<std::endl;
    }
    return 0;
}

int password_strength_check(std::string password){
    int total = pass_length(password)+pass_character_variety(password)+pass_patterns(password);
    return total;
}
int pass_length(std::string pass){
    if (pass.length() > 8){
        return 1;
    }
    return 0;
}
int pass_character_variety(std::string pass){
    int value = 0;
    for(int i=0 ; i < pass.length() ; i++){
        if (std::isupper(pass[i])){
            value ++;
            break;
        }
    }
    for(int i=0 ; i < pass.length() ; i++){
        if (std::islower(pass[i])){
            value ++;
            break;
        }
    }
    for(int i=0 ; i < pass.length() ; i++){
        if (std::isdigit(pass[i])){
            value ++;
            break;
        }
    }
    value += is_special(pass);
    return value;
    
}
bool is_special(std::string pass){
    int asci_values[]={33,35,36,37,38,42,64,63,46};
    for(int i=0 ; i < pass.length() ; i++){
        for(int value : asci_values){
            if(value == (int)pass[i]){
                return 1;
            }
        } 
    }
    return 0;
    
    
}
int pass_patterns(std::string pass)
{
    int score=0;
    score = pass_repition(pass) + pass_sequence(pass);
    return score;
    
}
int pass_repition(std::string pass){
    for(int i =0 ; i< pass.length()-2; i++)
    {
        if(pass[i]==pass[i+1] && pass[i+1]==pass[i+2])
        {
            return 0;
        }
    }
    return 1;
}
int pass_sequence(std::string pass){
    for(int i=0; i<pass.length()-2; i++)
    {
        if(std::isalnum(pass[i]))
        {
            if((int)((pass[i]))==(((int)pass[i+1])-1) && (((int)pass[i]+1))==(((int)pass[i+2])-1)){
                return 0;
            }
        }
    }
    return 1;
}