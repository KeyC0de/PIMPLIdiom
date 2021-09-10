#pragma once

#include <string>
#include <memory>


// the interface class
class Agent
{
	// This struct represents the implementation.
	// That's all the compiler needs to know about this header file ie the size and layout of the pointer.
	// The actual implementation may change of course but the pointer remains the same.
	// As such we can achieve independent compilation.
	// We only need a forward declaration of the pointer Type - which provides no size info.
	struct Impl;
	std::unique_ptr<Impl> m_pImpl;
public:
	explicit Agent( const std::string& name, int id );
	~Agent() = default;
	Agent( const Agent& rhs ) = delete;
	Agent& operator=( const Agent& rhs ) = delete;
	Agent( Agent&& rhs ) noexcept;
	Agent& operator=( Agent&& rhs ) noexcept;

	std::unique_ptr<struct Impl>&& getImplementation() noexcept
	{
		if ( !m_pImpl )
		{
			return nullptr;
		}
		// returns the ownership of the resource exclusively
		return std::move( m_pImpl );
	}

	friend std::ostream& operator<<( std::ostream& stream, const Agent& rhs );
};
