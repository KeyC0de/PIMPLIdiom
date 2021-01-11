#include <iostream>
#include "interface.h"


// declare and define the implementation in the .cpp file
struct Agent::Impl
{
	std::string m_name;
	int m_id;
	Impl( const std::string& name, int id )
		:
		m_name{name},
		m_id{id}
	{}
	Impl( const Impl& rhs )
	{
		Impl temp{rhs};
		std::swap( m_name, temp.m_name );
		std::swap( m_id, temp.m_id );
	}
	Impl( Impl&& rhs ) noexcept
		: m_name{std::move( rhs.m_name )},
		m_id{std::move( rhs.m_id )}
	{}
	Impl& operator=( Impl&& rhs ) noexcept
	{
		if ( this != &rhs )
		{
			std::swap( m_name, rhs.m_name );
			std::swap( m_id, rhs.m_id );
		}
		return *this;
	}
};

std::ostream& operator<<( std::ostream& stream,
	Agent& rhs )
{
	auto&& impl = rhs.getImplementation();
	return stream << impl->m_name
		<< ':'
		<< impl->m_id
		<< '\n';
}



Agent::Agent( const std::string& name,
	int id )
	:
	m_pimpl{ std::make_unique<Impl>( name, id ) }
{}

Agent::Agent( Agent&& rhs ) noexcept
	:
	m_pimpl{std::move( rhs.m_pimpl )}
{}

Agent& Agent::operator=( Agent&& rhs ) noexcept
{
	if ( this != &rhs )
	{
		std::swap( m_pimpl, rhs.m_pimpl );
	}
	return *this;
}


int main()
{
	Agent e1{"bradley", 700};
	Agent e2{"john", 425};
	Agent e3{"nikos", 1485};

	std::cout << e1;
	e1.getImplementation()->m_name = "brad";
	std::cout << e1;
	std::cout << e2;
	std::cout << e3;
	e3.getImplementation()->m_name = "NameChanger";
	e3.getImplementation()->m_id = 339;
	std::cout << e3;

	std::system( "pause" );
	return 0;
}