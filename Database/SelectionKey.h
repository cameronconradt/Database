#pragma once
class SelectionKey
{
public:
	SelectionKey();
	virtual ~SelectionKey();
	virtual bool type()=0;
};

