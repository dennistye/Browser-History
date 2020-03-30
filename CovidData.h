//  CovidData.h
//  EPP actual part 2
//
//  Created by dennis tye on 3/26/20.
//  Copyright © 2020 dennis tye. All rights reserved.
//

/*
 In this project I decided to use a vector to hold my list of confirmed cases.
 I made a struct called List which holds the country name, number of days since last case and number of cases. I then populated the vector with List objects.
 */

#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct List
{
    string country_name;
    int num_days_since_first;
    int num_of_cases;
};

class CovidData
{
private:
    string temp_name;
    string temp_num_days;
    string temp_num_cases;
    int list_size;
public:
    vector<List> vec;
    
    CovidData();
    int readData(string filename);
    int getDays(string country);
};

CovidData::CovidData()
{
    temp_name = " ";
    temp_num_days = " ";
    temp_num_cases = " ";
    list_size = 0;
}

int CovidData::readData(string filename)
{
    ifstream myfile;
    
    myfile.open(filename);

    while(myfile >> temp_name >> temp_num_days >> temp_num_cases)
    {
        List obj;
        obj.country_name = temp_name;
        obj.num_days_since_first = stoi(temp_num_days); // string to int
        obj.num_of_cases = stoi(temp_num_cases); // string to int
        vec.push_back(obj);
        
        list_size++; // gets the size of the list
    }
    myfile.close();
    
    return list_size; // returns the size of the list
}

int CovidData::getDays(string country)
{
    int num = -1; // num is initialized to -1 so that if the country doesnt match the list getDays will return -1;
    

    // this for loop iterates through the list to find maximum number of days for the given coutry
    for(int i = 0; i < list_size; i++)
    {
        if(country == vec[i].country_name)
        {
            if(num < vec[i].num_days_since_first)
            {
                num = vec[i].num_days_since_first;
            }
        }
    }
    return num;
}













