#pragma once

//Member.h: represents a UCC member
//Written by Ryan Quinlan

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Member.h"

class System {

public:

	//default constructor
	System() {}

	void prompt() {
		int command;
		print_options();
		while (std::cin >> command) {
			switch (command) {
				case(1):
					get_member_info();
					break;
				case(2):
					print_members();
					break;
				default:
					break;
			}
			std::cout << '\n';
			print_options();
		}

	}

	void get_member_info() {
		std::string name;
		std::string s_grad_year; //format: 1MM/YYYY
		int grad_year;
		std::string major;
		std::string uniq;
		std::string position;
		std::string channel_name;
		std::string channel_topic;
		std::string channel_url;
		std::string s_join_date; //format 1MM/DD/YYYY
		int join_date;

		std::cout << "You are now creating a new member\nPlease enter member name: ";
		//std::cin >> name;
		std::cin.get();
		std::getline(std::cin, name);
		std::cout << "Please enter member's intended graduate date (format: MM/YYYY): ";
		std::getline(std::cin, s_grad_year);
		s_grad_year.erase(std::remove(s_grad_year.begin(), s_grad_year.end(), '/'), s_grad_year.end());
		grad_year = stoi(s_grad_year);
		grad_year += 1000000;
		std::cout << "Please enter member's major: ";
		std::getline(std::cin, major);
		std::cout << "Please enter member's uniqname: ";
		std::getline(std::cin, uniq);
		std::cout << "Please enter member's position (member, secretary, treasurer, etc.): ";
		std::getline(std::cin, position);
		std::cout << "Please enter member's channel name: ";
		std::getline(std::cin, channel_name);
		std::cout << "Please enter member's channel topic: ";
		std::getline(std::cin, channel_topic);
		std::cout << "Please enter the url of the member's channel: ";
		std::getline(std::cin, channel_url);
		std::cout << "Please enter the date on which the member joined (format: MM/DD/YYYY): ";
		std::getline(std::cin, s_join_date);
		s_join_date.erase(std::remove(s_join_date.begin(), s_join_date.end(), '/'), s_join_date.end());
		join_date = stoi(s_join_date);
		join_date += 100000000;

		Member m(name, grad_year, major, uniq, channel_name, channel_topic, channel_url, join_date);
		Members.push_back(m);

		std::cout << "New member " << name << " created\n";

		//TEST
		//m.print_member();
		//std::cout << '\n';
	}

	void print_options() {

		std::cout << "What would you like to do?\n" << "1) Create New Member\n2) View List of Members\n";


	}

	void print_members() {
		for (auto m : Members) {
			m.print_member();
		}
	}

private:
	std::vector<Member> Members;
};