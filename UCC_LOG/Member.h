#pragma once

//Member.h: represents a UCC member
//Written by Ryan Quinlan

#include <string>
#include <iostream>
#include <vector>

const char * months[12] = { "January", "February", "March", "April", "May", "June", "July",
					        "August", "September", "October", "November", "December" };

class Member {

public:

	//default constructor
	Member() {}

	//non-default constructor
	Member(std::string name_in, int grad_year_in, std::string major_in, std::string uniq_in, std::string channel_name_in, 
		   std::string channel_topic_in, std::string channel_url_in, int join_date_in) : 
	name(name_in), grad_year(grad_year_in), major(major_in), uniq(uniq_in), channel_name(channel_name_in),
	channel_topic(channel_topic_in), channel_url(channel_url_in), join_date(join_date_in) {}

	void print_grad_year() {
		int month = grad_year / 10000 - 100;
		int year = grad_year - ((grad_year / 10000) * 10000);
		std::cout << months[month - 1] << ' ' << year;
	}

	void print_join_date() {
		int month = join_date / 1000000 - 100;
		int day = (join_date - ((join_date / 1000000) * 1000000)) / 10000;
		int year = (join_date - ((join_date / 1000000) * 1000000)) - (day * 10000);
		std::cout << months[month - 1] << " " << day << ", " << year;
	}

	void print_member() {
		std::cout << "\nName: " << name << "\nGraduation Date: ";
		print_grad_year();
		std::cout << "\nMajor: " << major << "\nPosition: " << position << "\nChannel Name: " << channel_name <<
			"\nChannel Topic: " << channel_topic << "\nChannel URL: " << channel_url << "\nDate Joined: ";
		print_join_date();
		std::cout << '\n';
	}


private:
	std::string name = "UNKNOWN";
	int grad_year = 1042019; //format: 1MM/YYYY
	std::string major = "UNKNOWN";
	std::string uniq = "UNKNOWN";
	std::string position = "member";
	std::string channel_name = "UNKNOWN";
	std::string channel_topic = "UNKNOWN";
	std::string channel_url = "UNKNOWN";
	int join_date; //format 1MM/DD/YYYY
	//define media sites as media_type and make this vector hold those instead of strings
	std::vector<std::string> medias;
	std::vector<int> subscriber_count; //first entry is initial sub count, proceeding entries are
	//sub counts on the first of each proceeding month

};