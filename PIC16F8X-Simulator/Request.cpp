#include "Request.h"


Request::Request(int address)
{
	data.address = address;
}


Request::RequestData& Request::writeByte(int val)
{
	data.initialized = true;
	data.accessBit = false;
	data.value = val;
	data.writeRequest = true;
	return data;
}


Request::RequestData& Request::getByte()
{
	data.initialized = true;
	data.accessBit = false;
	data.writeRequest = false;
	return data;
}


Request::RequestData& Request::writeBit(int index, bool val)
{
	data.initialized = true;
	data.accessBit = true;
	data.bitIndex = index;
	data.writeRequest = true;
	data.value = val;
	return data;
}


Request::RequestData& Request::getBit(int index)
{
	data.initialized = true;
	data.accessBit = true;
	data.bitIndex = index;
	data.writeRequest = false;
	return data;
}


UserRequest::UserRequest(int address)
	: Request(address)
{
}


Request::RequestData& UserRequest::writeByte(int val)
{
	Request::writeByte(val);
	data.source = DataSource::FromUser;
	return data;
}


Request::RequestData& UserRequest::writeBit(int index, bool val)
{
	Request::writeBit(index, val);
	data.source = DataSource::FromUser;
	return data;
}
