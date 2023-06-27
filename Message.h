#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Message {
    string _text;
    string _sender;
    string _receiver;

public:
	Message(string text, string sender, string receiver) :_text(text), _sender(sender), _receiver(receiver) {}

	friend fstream& operator >>(fstream& is, Message& obj);
	friend ostream& operator <<(ostream& os, const Message& obj);
};

fstream& operator >>(fstream& is, Message& obj) {
	is >> obj._text;
	is >> obj._sender;
	is >> obj._receiver;

	return is;
}
ostream& operator <<(ostream& os, const Message& obj) {
	os << obj._text;
	os << ' ';
	os << obj._sender;
	os << ' ';
	os << obj._receiver;

	return os;
}
