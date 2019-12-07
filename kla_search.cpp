#include "stub.h"
class Database
{
private:
	map<pair<string,int>,string> m_collection;
public:
	Database()
	{
	}
	void insert(string t_name, int t_eid, string t_address)
	{
		m_collection[make_pair(t_name,t_eid)] =  t_address;
	}
	Database(const Database& rhs)
	{
	}
	Database& operator=(const Database& rhs)
	{
	}
	~Database()
	{
	}
    string searchByName(string in_string)
	{
		if( !in_string.empty()  && !m_collection.empty())
		{
			map<pair<string,int>,string>::const_iterator end_it = m_collection.end();
			map<pair<string,int>,string>::const_iterator element_it = m_collection.find(make_pair(in_string,515378));
			if(end_it != element_it )
			{
				return (*element_it).second;
		    }
		}
		return string("");
	}
	string searchByPhoneNumber()
	{
	}
};
