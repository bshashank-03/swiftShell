#include <iostream>
#include "logger.h"
#include "Parser.h"
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

    Logger::log("Shell started");

    while(true){

        // Display prompt and wait for input
        std::cout << "SwiftShell$ ";
        std::string rawMultiShell;

        // Handle End Of File
        if(!getline(std::cin, rawMultiShell))
        {
            std::cout<<"\nExiting shell\n";
            break;
        }
    }

    // Replace environment variables in the user input
    rawMultiShell = Parser::replaceEnvironmentVariables(rawMultiShell);
}