#pragma once

#include <string>
#include <conio.h>
#include<iostream>
#include <fstream>
#include <io.h>

class Flat {
public:
	int get_Space() {
		return space;
	}
	int get_Number_Of_Rooms() {
		return number_Of_Rooms;
	}
	int get_Floor() {
		return floor;
	}
	std::string get_Address() {
		return address;
	}	
	void set_Space(int userData) {
		space = userData;
	}
	void set_Number_Of_Rooms(int userData) {
		number_Of_Rooms = userData;
	}
	void set_Floor(int userData) {
		floor = userData;
	}
	void set_Address(std::string userData) {
		address = userData;
	}
private:
	std::string address;
	int floor=0;
	int number_Of_Rooms=0;
	int space=0;
};

class Array {
public:
	int get_Len() {
		return arrayLen;
	}
	Flat get_Element(int numberOfElement) {
		return array[numberOfElement];
	}
	void set_Element(Flat userElement,int numberOfElement) {
		array[numberOfElement] = userElement;
	}
	void Set_len(int userLen) {
		arrayLen = userLen;
		delete[] array;
		array = NULL;
		array = new Flat[arrayLen];
	}
private:
	int arrayLen = 0;
	Flat * array =new Flat[arrayLen];
};

namespace Input {
	int user_Int_Input();
	void user_Console_Input(Array* mass);
	int user_File_Input(Array* mass);
};

namespace Checks {
	bool is_Number_Check(std::string inputData);
	int user_Is_Number_Check(std::string inputData);
	bool File_Exists(std::string fileName);
	bool Only_Read(std::string fileName);
};

namespace Output {
	void massOutputSpace(Array* mass);
	void massOutputRoomsAndFloor(Array* mass);
	void massOutputRooms(Array* mass);
	void module_Tests();
	void save_User_Data_To_File(Array* mass);
	void save_User_Data_To_File_Rooms(Array* mass, int userNumber);
	void save_User_Data_To_File_RoomsAndFloor(Array* mass, int number, int begining, int end);
	void save_User_Data_To_File_Space(Array* mass, int userNumber);
}

enum console_Or_File { console = 1, file };

enum yes_Or_No { yes = 1, no };

enum firstUserMenu { massOutputRooms = 1,massOutputRoomsAndFloor,massOutputSpace, newData, moduleTests, exitMenu };

enum { error = 0, allGood };