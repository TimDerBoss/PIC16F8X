#pragma once

enum DataSource
{
	FromUser,
	FromCpu
};

class Request {
public:
	struct RequestData {
		bool initialized{ false };
		int address;
		bool accessBit;
		bool writeRequest;
		int bitIndex;
		int value;
		DataSource source{ FromCpu };
	};

	Request(int address);

	RequestData& writeFullValue(int val);
	RequestData& fullValue();
	RequestData& writeBit(int index, bool val);
	RequestData& getBit(int index);

protected:
	RequestData data;
};

class UserRequest : public Request {
public:
	UserRequest(int address);

	RequestData& writeFullValue(int val);
	RequestData& writeBit(int index, bool val);
};
