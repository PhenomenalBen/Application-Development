#pragma once
using namespace System;

public ref class User {
public:
    int id;
    int studentID;    
    int facultyID;    
    String^ fName;
    String^ lName;
    String^ email;
    String^ password;
    int roleNum;

    User() {
        id = 0;
        studentID = 0;
        facultyID = 0;
        roleNum = 0;
    }
};