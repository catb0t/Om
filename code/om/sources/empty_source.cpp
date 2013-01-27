/*!
\file
	\brief
		Om cpp file.
	\version
		0.1.2
	\date
		2012-2013
	\copyright
		Copyright (c) Jason Erb.
		All rights reserved.  This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\authors
		Jason Erb - Initial API, implementation, and documentation.
*/

#if defined( Om_Sources_EmptySource_ )

// MARK: Om::Sources::EmptySource

	#define Template_ \
	template< typename ThisItem >

	#define Type_ \
	Om::Sources::EmptySource< ThisItem >

// MARK: public (static)

Template_
inline Type_ & Type_::Get()
{
	static Type_ theEmptySource;
	return( theEmptySource );
}

// MARK: public (non-static)

Template_
inline Type_::EmptySource()
{
}

Template_
inline Type_ & Type_::operator =( EmptySource theEmptySource )
{
	return( *this );
}

Template_
inline bool Type_::operator ==( EmptySource const & ) const
{
	return( true );
}

Template_
inline bool Type_::operator !() const
{
	return( true );
}

Template_
inline ThisItem & Type_::operator *() const
{
	assert( 0 );
	throw(
		std::logic_error( "The source is empty." )
	);
}

Template_
inline void Type_::Pop()
{
	assert( 0 );
	throw(
		std::logic_error( "The source is empty." )
	);
}

Template_
inline void Type_::Swap( EmptySource & )
{
}

	#undef Type_
	#undef Template_

// MARK: -
// MARK: boost

template< typename ThisItem >
inline void boost::swap(
	Om::Sources::EmptySource< ThisItem > & theFirst,
	Om::Sources::EmptySource< ThisItem > & theSecond
)
{
	theFirst.Swap( theSecond );
}

#else

	#include "om/sources/empty_source.hpp"

#endif