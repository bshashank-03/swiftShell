#include<iostream>
#include "EnvironmentVariablesManager.h"

int main(int argc, char* argv[]){
    
    // set environment variables
    extern char** environ; //Access the array of environment variables
    for(char** env= environ; *env!=nullptr; ++env){

        std::string envVariable(*env);
        size_t equalSignPos = envVariable.find('=');

        if (equalSignPos != std::string::npos) 
        {
            std::string envName = envVariable.substr(0, equalSignPos);
            std::string envValue = envVariable.substr(equalSignPos + 1);

            EnvironmentVariablesManager::setEnvironmentVariable(envName, envValue);

    }

}